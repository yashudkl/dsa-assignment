#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr) {
    return ptr->top == -1;
}

int isFull(struct stack *ptr) {
    return ptr->top == ptr->size - 1;
}

void push(struct stack *ptr, char val) {
    if (isFull(ptr)) {
        printf("Stack Overflow!\n");
    } else {
        ptr->arr[++ptr->top] = val;
    }
}

char pop(struct stack *ptr) {
    if (isEmpty(ptr)) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        return ptr->arr[ptr->top--];
    }
}

char stackTop(struct stack *sp){
    if(sp->top == -1) return -1;
    return sp->arr[sp->top];
}

int isOperator(char ch){
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/')
         return 1;
    else
        return 0;
}

int precedence(char ch){
    if(ch == '*' || ch=='/')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2;

    else
        return 0;
}

char* infixToPostfix(char* infix){
    struct stack * sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));
    int i=0; // Track infix traversal
    int j = 0; // Track postfix addition

    while (infix[i]!='\0')
    {
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if(precedence(infix[i])> precedence(stackTop(sp))){
                push(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
        {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int evaluatePostfix(char *postfix){
    int st[100];
    int top = -1;
    int i = 0;
    while(postfix[i] != '\0'){
        if(postfix[i] >= '0' && postfix[i] <= '9'){
            st[++top] = postfix[i] - '0';
        } else if(isOperator(postfix[i])){
            int b = st[top--];
            int a = st[top--];
            if(postfix[i] == '+') st[++top] = a + b;
            else if(postfix[i] == '-') st[++top] = a - b;
            else if(postfix[i] == '*') st[++top] = a * b;
            else if(postfix[i] == '/') st[++top] = a / b;
        }
        i++;
    }
    return st[top];
}

void inputInfix(char *infix){
    printf("Enter infix expression: ");
    scanf("%99s", infix);
}

int main() {
    char infix[100];
    inputInfix(infix);

    char *post = infixToPostfix(infix);
    printf("postfix is %s\n", post);
    printf("value is %d", evaluatePostfix(post));
    return 0;
}
