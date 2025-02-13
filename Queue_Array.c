#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct queue{
    int size,f,r,*arr;
};

int isEmpty(struct queue* q){
    if(q->r == q->f){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct queue* q){
    if(q->r == q->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct queue* q, int data){
    if(!isFull(q)){
        q->r++;
        q->arr[q->r] = data;
    }
    else{
        printf("Queue Overflow\n");
    }
}

void dequeue(struct queue* q){
    if(!isEmpty(q)){
        q->f++;
    }
    else{
        printf("Queue is Empty\n");
    }
}

void peek(struct queue* q){
    if(!isEmpty(q)){
        printf("%d\n",q->arr[q->f]);
    }
    else{
        printf("Queue is Empty\n");
    }
}


int main()
{
    struct queue q;
    q.size = 5;
    q.f=q.r=0;
    q.arr = (int*)malloc(q.size*(sizeof(int)));

    if(isEmpty(&q)){
        enqueue(&q,1);
        enqueue(&q,2);
        enqueue(&q,3);
        enqueue(&q,4);
        enqueue(&q,5);
    }    
    else{
        printf("Queue is Empty\n");
    }
    // if(isFull(&q)){
    //     printf("Queue is Full\n");
    // }
    // else{
    //     enqueue(&q,6);
    // }    

    // peek(&q);
    dequeue(&q);
    peek(&q);

    return 0;
}