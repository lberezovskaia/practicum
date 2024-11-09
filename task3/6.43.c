#include <stdio.h> // 6.43
#include <stdlib.h>

struct stack{
    double data;
    struct stack *next;
};

void insert(struct stack **head, double data){
    struct stack *tmp = (struct stack *)malloc(sizeof(struct stack));
    tmp->data = data;
    tmp->next = (*head);
    (*head) = tmp;
}

double extract(struct stack **head){
    double elem;
    elem = (*head)->data;
    if ((*head) == NULL) (*head) = NULL; 
    (*head) = (*head)->next;
    return elem;
}

void print_stack(struct stack *head){
    struct stack *tmp = head;
    printf("stack:");
    while (tmp != NULL) {
        printf("   %lf", tmp->data);
        tmp = tmp->next; 
    }
    printf("\n");
    printf("\n");
}

int main(void){
    struct stack *head = NULL;
    double n;
    printf("enter double number: ");
    scanf("%lf", &n);
    insert(&head, n);
    print_stack(head);
    
    printf("enter double number: ");
    scanf("%lf", &n);
    insert(&head, n);
    print_stack(head);

    printf("enter double number: ");
    scanf("%lf", &n);
    insert(&head, n);
    print_stack(head);

    double elem;
    elem = extract(&head);
    printf("extract elem: %lf\n", elem);
    print_stack(head);

    elem = extract(&head);
    printf("extract elem: %lf\n", elem);
    print_stack(head);

    elem = extract(&head);
    printf("extract elem: %lf\n", elem);
    print_stack(head);

    insert(&head, 5);
    print_stack(head);

    return 0;
}
