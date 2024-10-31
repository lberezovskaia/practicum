#include <stdio.h>
#include <stdlib.h>

struct node{
    char data;
    struct node *next;
};

int eleme_occurrence(struct node *head, char elem){
    int a = 0;
    struct node *tmp = head;
    while (head->data != '0'){
        if (head->data == elem) a = 1;
        head = head->next;
    }
    head = tmp;
    return a;
}

void create_list(struct node *head1, struct node *head2, struct node *head3){
    struct node *tmp1 = head1;
    struct node *tmp2 = head2;
    struct node *tmp3 = head3;
    
    while (head1->next != NULL){
        if (eleme_occurrence(head2, head1->data) == 0){
            head3->data = head1->data;
            head3->next = (struct node *)malloc(sizeof(struct node));
            head3 = head3->next;   
        }
        head1 = head1->next;
    }
    head3->next = (struct node *)malloc(sizeof(struct node));
    head3->data = '0';
    head3->next = NULL;
    head1 = tmp1;
    head2 = tmp2;
    head3 = tmp3;
}

int main(void){
    struct node *head1 = (struct node *)malloc(sizeof(struct node));
    struct node *tmp1 = head1;
    
    printf("Enter elements of the first list: ");
    scanf("%c", &(head1->data));
    while (head1->data != '0'){
        head1->next = (struct node *)malloc(sizeof(struct node));
        head1 = head1->next;
        scanf("%c", &head1->data);
    }
    head1->next = NULL;
    head1 = tmp1;
    
    struct node *head2 = (struct node *)malloc(sizeof(struct node));
    struct node *tmp2 = head2;
    
    printf("Enter elem of the second list: ");
    scanf("%c", &(head2->data));
    while (head2->data != '0'){
        head2->next = (struct node *)malloc(sizeof(struct node));
        head2 = head2->next;
        scanf("%c", &head2->data);
    }
    head2->next = NULL;
    head2 = tmp2;
    
    printf("first list: \n");
    while (head1->data != '0'){
        printf("%c", head1->data);
        head1 = head1->next;
    }
    head1 = tmp1;
    
    printf("second list: ");
    while (head2->data != '0'){
        printf("%c", head2->data);
        head2 = head2->next;
    }
    head2 = tmp2;
    
    struct node *head3 = (struct node *)malloc(sizeof(struct node));
    struct node *tmp3 = head3;
    
    create_list(head1, head2, head3);
    printf("\n");
    printf("third list: \n");
    while (head3->data != '0'){
        printf("%c\n", head3->data);
        head3 = head3->next;
    }
    head3 = tmp3;
    return 0;
}
