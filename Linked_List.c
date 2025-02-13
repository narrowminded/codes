#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* insert(struct node* head){
    if(head != NULL){
        struct node* newnode = (struct node*) malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d",&newnode->data);
        struct node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
        return head;
    }
    else{
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newnode->data); 
        head = newnode;
        return head;
    }
}

void display(struct node* head){
    struct node*temp = head;
    while(temp->next != NULL){
        printf("%d ->",temp->data);
    }
}

void main(){
    struct node *newnode,*head,*curr,*prev,*nextNode;
    int n;
    printf("Number of entries : ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        head = insert(head);
    }
    display(head);
}