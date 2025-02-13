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

struct node* addNode(struct node* p, int data){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = n->right = NULL;
    if(n->data > p->data){
        p->right = n;
        return p;
    }
    else{
        p->left = n;
        return p;
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

void searchBST(struct node* root, int data){
    if(root != NULL){
        if(data == root->data){
            printf("Node Exists");
        }
        else if(root->data > data){
            searchBST(root->left, data);
        }
        else{
            searchBST(root->right, data);
        }
    }
    else{
        printf("Root does not exist");
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
    p = addNode(p,3);
    p = addNode(p,5);
    p = addNode(p,2);
    p = addNode(p,53);
    p = addNode(p,56);
    p = addNode(p,59);
    p = addNode(p,545);
    preorder(p);
    printf("\n");
    postorder(p);
    printf("\n");
    inorder(p);
    printf("\n");
    searchBST(p,55);
    return 0;
}