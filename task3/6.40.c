#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

struct node{
    char *data;
    struct node *next;
};

int check(struct node *head, char *data){
    int flag = 0;
    struct node *tmp = head;
    while (tmp->data[0] != '0'){
        if (strcmp(tmp->data, data) == 0){ // если совпали
                flag = 1;
        }
        tmp = tmp->next;
    }
    return flag;
}

void create_list(struct node *head1, struct node *head2, struct node **head3){
    struct node *tmp1 = head1;
    struct node *tmp2 = head2;
    struct node *tmp3 = (*head3);
    while (tmp1->data[0] != '0'){
        if (check(head2, tmp1->data) == 0){ // нет повторов
            tmp3->data = (char *)malloc(10 * sizeof(char));
            tmp3->data = tmp1->data;
            tmp3->next = (struct node *)malloc(sizeof(struct node));
            tmp3 = tmp3->next;
        }
        tmp1 = tmp1->next;
    }
    while (tmp2->data[0] != '0'){
        if (check(head1, tmp2->data) == 0){
            tmp3->data = (char *)malloc(10 * sizeof(char));
            tmp3->data = tmp2->data;
            tmp3->next = (struct node *)malloc(sizeof(struct node));
            tmp3 = tmp3->next;
        }
        tmp2 = tmp2->next;
    }
    tmp3->data = (char *)malloc(10 * sizeof(char));
    tmp3->data[0] = '0';
    tmp3->next = NULL;
}

void fill_list(struct node **head){
    struct node *tmp = (*head);
    tmp->data = (char *)malloc(10 * sizeof(char));
    printf("enter elem of list: ");
    scanf("%s", tmp->data);
    while (tmp->data[0] != '0'){
        tmp->next = (struct node *)malloc(sizeof(struct node));
        tmp = tmp->next;
        tmp->data = (char *)malloc(10 * sizeof(char));
        printf("enter elem of list: ");
        scanf("%s", tmp->data);
    }
    tmp->next = NULL;
}

int print_list(struct node *head){
    if (head->data[0] == '0'){
        printf("list is empty!");
        return 0;
    }
    struct node *tmp = head;
    while (tmp->data[0] != '0'){
        printf("%s\n", tmp->data);
        tmp = tmp->next; 
    }
}

int main(void){
    struct node *head1 = (struct node *)malloc(sizeof(struct node));
    printf("first list: \n");
    fill_list(&head1);
    //print_list(head1);

    printf("\n");
    struct node *head2 = (struct node *)malloc(sizeof(struct node));
    printf("second list: \n");
    fill_list(&head2);
    //print_list(head2);

    printf("\n");
    struct node *head3 = (struct node *)malloc(sizeof(struct node));
    create_list(head1, head2, &head3);
    printf("processed list: \n");
    print_list(head3);
    return 0;
}
