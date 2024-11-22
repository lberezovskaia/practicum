#include <stdio.h> 
#include <stdlib.h>

struct queue{
    int data;
    struct queue *next;
};

void insert(struct queue **head, int data){
    if ((*head) == NULL){
        (*head) = (struct queue *)malloc(sizeof(struct queue));
        (*head)->data = data;
        (*head)->next = NULL;
    }
    else{
        struct queue *tmp = (*head);
        while (tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = (struct queue *)malloc(sizeof(struct queue));
        tmp = tmp->next;
        tmp->data = data;
        tmp->next = NULL;
    }
}

void print_queue(struct queue *head){
    struct queue *tmp = head;
    printf("queue:");
    if (tmp == NULL){
        printf(" queue is empty!");
    }
    while (tmp != NULL){
        printf(" %d", tmp->data);
        tmp = tmp->next; 
    }
    printf("\n");
    printf("\n");
}

void delete_queue(struct queue **head){
    if (head == NULL) return;
    struct queue *tmp;
    for(tmp = *head; tmp != NULL; tmp = *head){
        *head = tmp->next;
        free(tmp);
    }
}

struct tree{
    int data;
    struct tree *left;
    struct tree *right;
};

struct tree* create_tree(struct tree **root, int data){
    if ((*root) == NULL){
        (*root) = (struct tree *)malloc(sizeof(struct tree));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else{
        if (data > (*root)->data) create_tree(&((*root)->right),data);
        else create_tree(&((*root)->left),data);
    }
}

int max_height(struct tree *root){
    if (root == NULL){
        return 0;
    }
    int left_height = max_height(root->left);
    int right_height = max_height(root->right);
    return (left_height > right_height ? left_height : right_height) + 1;
}

void insert_level(struct queue **head, struct tree *root, int level){
    if (root == NULL) return;
    if (level == 1){
        insert(head, root->data);
    } else if (level > 1){
        insert_level(head, root->left, level - 1);
        insert_level(head, root->right, level - 1);
    }
}

int node_count(struct queue **head, struct tree *root, int level){
    if (root == NULL || level <= 0 || level > max_height(root)) return 0;
    if (level == 1) return 1; 
    for (int i = 1; i <= max_height(root); i++){
        insert_level(head, root, i);
    }
    insert(head, 0);
    int i = 1;
    int node;
    struct queue *tmp = (*head);
    tmp = tmp->next;
    while (i != level){
        node = 1;
        while (tmp->data < tmp->next->data){
            tmp = tmp->next;
            node++;
        }
        i++;
        tmp= tmp->next;
    }
    return node;
}

void delete_tree(struct tree **root){
    if ((*root) == NULL) return;
    delete_tree(&((*root)->left));
    delete_tree(&((*root)->right));
    free(*root);
}

void print_tree(struct tree *root, int level){
    if (root == NULL) return;
    if (level == 1){
        printf("%d ", root->data);
    } else if (level > 1){
        print_tree(root->left, level - 1);
        print_tree(root->right, level - 1);
    }
}

int main(void){
    struct tree *root = NULL;
    create_tree(&root, 10);
    create_tree(&root, 12);
    create_tree(&root, 11);
    create_tree(&root, 15);
    create_tree(&root, 6);
    create_tree(&root, 5);
    create_tree(&root, 7);
    create_tree(&root, 3);
    create_tree(&root, 2);
    create_tree(&root, 4);
    struct queue *head = NULL;
    int level = 5;
    printf("constructed tree: \n");
    for (int i = 1; i <= max_height(root); i++){
        print_tree(root, i);
        printf("\n");
    }
    printf("the number of nodes at the %d level: %d\n", level, node_count(&head, root, level));
    //print_queue(head); // очередь после заполения элементами дерева 
    delete_queue(&head);
    //print_queue(head); // очередь после удаления 
    //printf("%d\n", root->data); // корень дерева
    delete_tree(&root);
    //printf("%d\n", root->data); // проверка
    return 0;
}
