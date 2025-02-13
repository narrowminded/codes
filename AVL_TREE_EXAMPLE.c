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
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1; 
}

int max(int a, int b){ 
    return (a>b)?a:b;
}

int getHeight(struct node* n){
    if(n == NULL) return 0;
    return n->height;
}

int getBalanceFactor(struct node* n){
    if(n == NULL) return 0;
    return getHeight(n->left)-getHeight(n->right);
}



struct node* leftRotation(struct node* x){
    struct node* y = x->right;
    struct node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1+max(getHeight(x->left),getHeight(x->right));
    y->height = 1+max(getHeight(y->left),getHeight(y->right));

    return y;
}

struct node* rightRotation(struct node* y){
    struct node* x = y->left;
    struct node* T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = 1+max(getHeight(x->left),getHeight(x->right));
    y->height = 1+max(getHeight(y->left),getHeight(y->right));

    return x;
}

struct node* insert(struct node*n, int key){
    
    //If node is NULL then a node will be created 
    
    if(n == NULL){
        return createNode(key);
    }
    //Searching the correct position at which insertion is to be performed
    if(n->key < key){
        n->right = insert(n->right, key);
    }
    if(n->key > key){
        n->left = insert(n->left, key);
    }

    //Match is found and the isnertion should be performed at this place
    int bf = getBalanceFactor(n);
    n->height = 1+max(getHeight(n->left),getHeight(n->right));

    //Left-Left Case
    if(bf>1 && n->left->key > key)
        return rightRotation(n);
    //Right-Right Case
    if(bf<-1 && n->right->key < key)
        return leftRotation(n);
    //Left-Right Case
    if(bf>1 && n->left->key < key){
        n->left = leftRotation(n);
        return rightRotation(n);
    }
    //Right-Left Case
    if(bf<-1 && n->right->key > key){
        n->right = rightRotation(n);
        return leftRotation(n);
    }
    return n;
}

void preOrder(struct node* n){
    if(n!=NULL){
        printf("%d ",n->key);
        preOrder(n->left);
        preOrder(n->right);
    }
}

int main()
{
    
    return 0;
}