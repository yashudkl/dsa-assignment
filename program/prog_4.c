#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* previous;
};

struct Node* createNode(int d){
    struct Node * newNode = (struct Node*)malloc(sizeof(struct Node)) ;
    newNode->data = d;
    newNode->next = NULL;
    newNode->previous = NULL;
    return newNode;
};

struct Node* insertNode(struct Node * prev,int d){
    struct Node * newNode = (struct Node*)malloc(sizeof(struct Node)) ;
    newNode->data = d;
    newNode->next = NULL;
    prev->next = newNode;
    newNode->previous = prev;
    return newNode;
};

void deleteNode(struct Node ** ifhead, struct Node * d){
    //If The node is head if else handles it
     if (d->previous != NULL)
        d->previous->next = d->next;
    else
        *ifhead = d->next;

if(d->next != NULL){
    d->next->previous = d->previous;
}

free(d);
}

void printForward(struct Node * head){
    struct Node * temp;
    temp = head;
    printf("This is forward print ");
    while(temp!=0){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printBackward(struct Node * tail){
    struct Node * temp;
    temp = tail;
    printf("This is backward print ");
    while(temp!=0){
        printf("%d ",temp->data);
        temp = temp->previous;
    }
}

int main (){
    struct Node * head = createNode(3);
    struct Node * first = insertNode(head, 5);
    struct Node * tail = insertNode(first , 10);
    // deleteNode(&head , first);
    printForward(head);
    printBackward(tail);

}