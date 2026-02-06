#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int d){
    struct Node * newNode = (struct Node*)malloc(sizeof(struct Node)) ;
    newNode->data = d;
    newNode->next = NULL;
    return newNode;
};


void reverseTraverse(struct Node* head){
    if(head == NULL)
    return;   //If there is null then head next or head data cannot be accessed so it's handled
    reverseTraverse(head->next);
    printf("%d",head->data);

};

int main(){
    struct Node * head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    reverseTraverse(head);
};