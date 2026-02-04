#include <stdio.h>
#include <stdlib.h>

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

int isMatching(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

int parenthesisMatch(char *exp) {
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++) {

        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (isEmpty(sp))
                return 0;

            char popped = pop(sp);
            if (!isMatching(popped, exp[i]))
                return 0;
        }
    }

    return isEmpty(sp);
}

int main() {
    // char *exp = "a+(b-c)*(d"; // 
    // char *exp = "m+[a-b*(c+d*{m)]";

    char *exp = "a+(b-c)";
    

    if (parenthesisMatch(exp))
        printf("The parenthesis is matching");
    else
        printf("The parenthesis is not matching");

    return 0;
}
