#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
    double f;
    char *s[2];
};

struct node{
    struct data *p;
    struct node *next;
};

void copy_list(){
    
}

int main(void){
    struct node *head = (struct node *)malloc(sizeof(struct node));
    (head->p) = malloc(sizeof(struct data));
    struct node *tmp = head;
    
    scanf("%lf", &(head->p->f));
    while (head->p->f != 0){ // заполнение структуры
        head->next = (struct node *)malloc(sizeof(struct node));
        (head->next->p) = malloc(sizeof(struct data));
        head = head->next;
        scanf("%lf", &(head->p->f));
    }
    head->next = NULL;
    head = tmp;
    
    while (head->p->f != 0){ // печать структуры
        printf("%lf\n", head->p->f);
        head = head->next;
    }
    
    return 0; 
}
