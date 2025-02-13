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

int max(int a, int b){
    return a>b?a:b;
}

int BSTHeight(struct node* root){
    if(root != NULL){
        return (1+max(BSTHeight(root->left),BSTHeight(root->right)));
    }
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
        printf("Node does not exist");
    }
}

void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

struct node* isPredecesor(struct node* root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

struct node* delete(struct node* root, int data){
    struct node * isPre;
    if(root == NULL){
        return NULL;
    }
    //Deleting the leaf Node
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    //Searching of node
    if(root->data >  data){
        root->left = delete(root->left,data);
    }
    else if(root->data < data){
        root->right = delete(root->right, data);
    }

    //Deletion if Node is found
    else{
        isPre = isPredecesor(root);
        root->data = isPre->data;
        root->left = delete(root->left, data);
    }
    return root;
}

// struct node *inOrderPredecessor(struct node* root){
//     root = root->left;
//     while (root->right!=NULL)
//     {
//         root = root->right;
//     }
//     return root;
// }

// struct node *deleteNode(struct node *root, int value){

//     struct node* iPre;
//     if (root == NULL){
//         return NULL;
//     }
//     if (root->left==NULL&&root->right==NULL){
//         free(root);
//         return NULL;
//     }

//     //searching for the node to be deleted
//     if (value < root->data){
//         root->left = deleteNode(root->left,value);
//     }
//     else if (value > root->data){
//         root->right = deleteNode(root->right,value);
//     }
//     //deletion strategy when the node is found
//     else{
//         iPre = inOrderPredecessor(root);
//         root->data = iPre->data;
//         root->left = deleteNode(root->left, iPre->data);
//     }
//     return root;
// }


int main()
{
    struct node *p = createNode(4);
    p = addNode(p,1);
    p = addNode(p,3);
    p = addNode(p,7);
    p = addNode(p,5);
    p = addNode(p,6);
    p = addNode(p,59);
    p = addNode(p,545);
    // preorder(p);
    // printf("\n");
    // postorder(p);
    // printf("\n");
    // struct node *p = createNode(5);
    // struct node *p1 = createNode(3);
    // struct node *p2 = createNode(6);
    // struct node *p3 = createNode(1);
    // struct node *p4 = createNode(4);
    // p->left = p1;
    // p->right = p2;
    // p1->left = p3;
    // p1->right = p4;
    inorder(p);
    printf("\n");
    searchBST(p,4);
    printf("\n");
    p = delete(p,545);
    printf("\n");
    inorder(p);
    printf("\n");
    printf("Height of the BST is %d",BSTHeight(p));
    return 0;
}