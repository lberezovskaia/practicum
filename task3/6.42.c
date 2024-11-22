#include <stdio.h> 
#include <stdlib.h>

struct queue{
    double data;
    struct queue *next;
};

void insert(struct queue **head, double data){
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

double extract(struct queue **head){
    double elem;
    elem = (*head)->data;
    if ((*head) == NULL) (*head) = NULL; 
    struct queue *tmp = (*head)->next; 
    (*head) = tmp;
    return elem;
}

void print_queue(struct queue *head){
    struct queue *tmp = head;
    printf("queue:");
    if (tmp == NULL){
        printf(" queue is empty!");
    }
    while (tmp != NULL) {
        printf(" %lf", tmp->data);
        tmp = tmp->next; 
    }
    printf("\n");
    printf("\n");
}

void delete_queue(struct queue **head)
{
    if (head == NULL) return;
    struct queue *tmp;
    for (tmp = *head; tmp != NULL; tmp = *head){
        *head = tmp->next;
        free(tmp);
    }
}

int main(void){
    struct queue *head = NULL;
    double n;
    printf("enter double number: ");
    scanf("%lf", &n);
    insert(&head, n);
    print_queue(head);
    
    printf("enter double number: ");
    scanf("%lf", &n);
    insert(&head, n);
    print_queue(head);

    printf("enter double number: ");
    scanf("%lf", &n);
    insert(&head, n);
    print_queue(head);
    
    double elem;
    elem = extract(&head);
    printf("extract elem: %lf\n", elem);
    print_queue(head);

    elem = extract(&head);
    printf("extract elem: %lf\n", elem);
    print_queue(head);

    elem = extract(&head);
    printf("extract elem: %lf\n", elem);
    print_queue(head);

    insert(&head, 5);
    print_queue(head);
    delete_queue(&head);
    print_queue(head);
    return 0;
}
