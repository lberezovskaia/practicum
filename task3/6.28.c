#include <stdio.h>
#include <stdlib.h>

struct node{
    double data;
    struct node *next;
};

void change_first_last(struct node *head){ // пункт a
    struct node *tmp = head;
    struct node *last;
    double first;
    
    first = head->data;
    while (head->data != 0){
        last = head;
        head = head->next;
    }
    head = tmp;
    head->data = last->data;
    last->data = first;
}

void remove_first_occurrence1(struct node **head, double elem){ // пункт б2
    struct node* tmp = (*head);
    struct node *prev;
    struct node *dop;
    int check = 0;
    if ((*head)->data == elem){
        check = 1;
    }
    while ((*head)->data != 0){
        if (check == 1){
            (*head) = (*head)->next;
            break;
        }
        else{
            if ((*head)->data == elem){
                dop = (*head)->next;
                (*head) = prev;
                (*head)->next = dop;
                (*head) = tmp;
                break;
            }
        }
        prev = (*head);
        (*head) = (*head)->next;
    }
}

void remove_first_occurrence2(struct node *a, double elem){ // пункт б1
    struct node *tmp = a->next;
    struct node *prev;
    struct node *dop;
    int check = 0;
    if (a->next->data == elem){
        check = 1;
    }
    while (a->next->data != 0){
        if (check == 1){
            a->next = a->next->next;
            break;
        }
        else{
            if (a->next->data == elem){
                dop = a->next->next;
                a->next = prev;
                a->next->next = dop;
                a->next = tmp;
                break;
            }
        }
        prev = a->next;
        a->next=a->next->next;
    }
}

void remove_all_occurrence1(struct node **head, double elem){ // пункт в2
    struct node* tmp = (*head);
    struct node *prev;
    struct node *dop;
    if ((*head)->data == elem){
        (*head) = (*head)->next;
        tmp = (*head);
    }
    while ((*head)->data != 0){
        if ((*head)->data == elem){
            dop = (*head)->next;
            (*head) = prev;
            (*head)->next = dop;
        }
        prev = (*head);
        (*head) = (*head)->next;
    }
    (*head) = tmp;
}

void remove_all_occurrence2(struct node *a, double elem){ // пункт в1
    struct node *tmp = a->next;
    struct node *prev;
    struct node *dop;
    if (a->next->data == elem){
        a->next = a->next->next;
        tmp = a->next;
    }
    while (a->next->data != 0){
        if (a->next->data == elem){
            dop = a->next->next;
            a->next = prev;
            a->next->next = dop;
        }
        prev = a->next;
        a->next = a->next->next;
    }
    a->next = tmp;
}

void duplication(struct node *head, double elem){ // пункт д
    struct node *tmp = head;
    struct node *dop;
    
    while (head->data != 0){
        if (head->data == elem){
            dop = (struct node *)malloc(sizeof(struct node));
            dop->data = elem;
            dop->next = head->next;
            head->next = dop;
            head = head->next->next;
        }
        else head = head->next;
    }
    head = tmp;
}

void print(struct node *head){
    printf("processed list: \n");
    while (head->data != 0){
        printf("%lf\n", head->data);
        head = head->next;
    }
}

int main(void){
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *tmp = head;
    double elem;
    
    scanf("%lf", &(head->data)); 
    while (head->data != 0){
        head->next = (struct node *)malloc(sizeof(struct node));
        head = head->next;
        scanf("%lf", &head->data);
    }
    head->next = NULL;
    head = tmp;
    printf("original list: \n");
    while (head->data != 0){
        printf("%lf\n", head->data);
        head = head->next;
    }
    head = tmp;
    
    change_first_last(head);
   
    print(head);

    printf("enter the elem whose first occurrence you want to remove: ");
    scanf("%lf", &elem);
    
    remove_first_occurrence1(&head, elem);
    print(head);
    
    struct node *a = (struct node *)malloc(sizeof(struct node)); // создание главного звена
    a->next = head;
    remove_first_occurrence2(a, elem);
    print(head);
    
    remove_all_occurrence1(&head, elem);
    print(head);

    remove_all_occurrence2(a, elem);
    print(head);
    
    printf("enter the elem you want to duplicate: ");
    scanf("%lf", &elem);
    duplication(head, elem);
    print(head);
    
    return 0;
}
