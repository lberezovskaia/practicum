#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define BUFF_SIZE 1024

char buffer1[BUFF_SIZE];
char buffer2[BUFF_SIZE];

struct data{
    double f;
    char *s[2];
};

struct node{
    struct data *p;
    struct node *next;
};


struct data* create_data(int a){
    printf("enter double number: ");
    struct data *tmp = (struct data *)malloc(sizeof(struct data));
    scanf("%lf", &(tmp->f));
    //tmp->s[0] = (char *)malloc(100 * sizeof(char));
    //tmp->s[1] = (char *)malloc(100 * sizeof(char));
    scanf("%s %s", buffer1, buffer2);
    tmp->s[0] = (char*)malloc(strlen(buffer1) + 1);
    tmp->s[1] = (char*)malloc(strlen(buffer2) + 1);
    strcpy(tmp->s[0], buffer1);
    strcpy(tmp->s[1], buffer2);
    return tmp;
}

struct node* create_node(int a){
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    struct node *ans = tmp;
    tmp->p = create_data(a);
    //tmp->next = NULL;
    while (tmp->p->f != a){
        tmp->next = (struct node *)malloc(sizeof(struct node));
        tmp = tmp->next;
        tmp->p = create_data(a);
    }
    tmp->next = NULL;
    return ans;
}

struct data* copy_data_hard(struct data *p){
    struct data *tmp = (struct data *)malloc(sizeof(struct data));
    tmp->f = p->f;
    tmp->s[0] = (char *)malloc(strlen(p->s[0]) + 1);
    tmp->s[1] = (char *)malloc(strlen(p->s[1]) + 1);
    strcpy(tmp->s[0], p->s[0]);
    strcpy(tmp->s[1], p->s[1]);

    return tmp;
}

struct node* copy_node(struct node *head1){
    if (head1 == NULL){
       return 0;
    }
    struct node *head2 = (struct node *)malloc(sizeof(struct node));
    struct node *ans = head2;


    //head2->p = head1->p; //Простой способ копирования
    head2->p = copy_data_hard(head1->p);
    head2->next = NULL;

    head1 = head1->next;
    while (head1 != NULL){
        head2->next = (struct node *)malloc(sizeof(struct node));
        head2 = head2->next;
        head2->p = copy_data_hard(head1->p);
        head2->next = NULL;
        head1 = head1->next;
    }

    return ans;
}

int print_list(struct node *head){
    while (head != NULL){
        printf("%lf %s %s\n", head->p->f, head->p->s[0], head->p->s[1]);
        head = head->next;
    }
    return 0;
}

int free_memory_struct_node(struct node *head){
    while(head != NULL){
        free(head->p->s[0]);
        free(head->p->s[1]);
        free(head->p);
        head = head->next;
    }
    return 0;
}

int main(void){
    struct node *head1 = create_node(0);

    printf("\n");
    printf("create complited\n");
    print_list(head1);

    struct node *head2 = copy_node(head1);

    printf("\n");
    printf("copy complited\n");
    print_list(head2);
    free_memory_struct_node(head1);
    free_memory_struct_node(head2);

    return 0; 
}
