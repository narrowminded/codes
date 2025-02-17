#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// void deleteNode(struct node* root, int val){
//     if(root != NULL){

//     }
// }

void addNode(struct node* root, int data){
    struct node* prev;
    while(root != NULL){
        prev = root;
        if(root->data == data){
            printf("Node already Exists");
            return;
        }
        if(root->data > data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    struct node* n = createNode(data);
    if(n->data > prev->data){
        prev->right = n;
        prev->left = NULL;
    }
    else{
        prev->left = n;
        prev->right = NULL;
    }
}

void preorder(struct node* root){
    if(root != NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int main()
{
    struct node *p = createNode(4);
    addNode(p,3);
    addNode(p,5);
    addNode(p,6);
    addNode(p,8);
    addNode(p,2);
    addNode(p,53);
    addNode(p,56);
    addNode(p,59);
    // addNode(p,545);
    // addNode(p,45);
    // addNode(p,454);
    preorder(p);
    printf("\n");
    postorder(p);
    printf("\n");
    inorder(p);
    return 0;
}