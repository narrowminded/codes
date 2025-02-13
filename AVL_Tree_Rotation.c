#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int key;
    struct node* left;
    struct node* right;
    int height;
};

struct node* createNode(int key){
    struct node* node = (struct node*) malloc (sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int max(int a, int b){
    return (a>b)?a:b;
}

int getHeight(struct node* root){
    if(root == NULL){
        return 0;
    }
    return root->height;
}

int getBalancefactor(struct node* root){
    if(root == NULL){
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}

struct node* rightRotate(struct node* y){
    struct node *x = y ->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right))+1;
    x->height = max(getHeight(x->left), getHeight(x->right))+1;
    return x;
}

struct node* leftRotate(struct node* x){
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->right),getHeight(x->left))+1;
    y->height = max(getHeight(y->left), getHeight(y->right))+1;
    return y;
}

struct node* insert(struct node* node, int key){
    if(node == NULL) 
        return createNode(key);

    else if(key < node->key) 
        node->left = insert(node->left,key);
    
    else if(key > node->key) 
        node->right = insert(node->right,key);
    
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    
    int bf = getBalancefactor(node);

    //Left Left Case
    if(bf > 1 && key < node->left->key) return rightRotate(node);
    
    
    //Right Right Case
    if(bf<-1 && key > node->right->key) return leftRotate(node);


    //Left Right Case
    if(bf>1 && key < node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    
    
    //Right Left Case
    if(bf<-1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    
    return node;
}

void preOrder(struct node* root){
    if(root != NULL){
    printf("%d ",root->key);
    preOrder(root->left);
    preOrder(root->right);
}}

int main()
{
    struct node * root = NULL;
 
 
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preOrder(root);
    
    return 0;
}