#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Stack structure
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// Function prototypes for stack operations
struct Stack* createStack(unsigned capacity);
int isEmpty(struct Stack* stack);
char peek(struct Stack* stack);
void push(struct Stack* stack, char item);
char pop(struct Stack* stack);

// Function prototypes for expression conversion and evaluation
int isOperator(char ch);
int precedence(char ch);
char* infixToPostfix(char* infix);
int evaluatePostfix(char* postfix);

int main() {
    char infix[100], postfix[100];
    
    // Get infix expression from the user
    printf("Enter an infix expression: ");
    gets(infix);

    // Convert infix to postfix
    strcpy(postfix, infixToPostfix(infix));
    printf("Postfix expression: %s\n", postfix);

    // Evaluate the postfix expression
    int result = evaluatePostfix(postfix);
    printf("Result of evaluation: %d\n", result);

    return 0;
}

// Stack operations

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

char peek(struct Stack* stack) {
    return stack->array[stack->top];
}

void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';  // Placeholder for an empty stack
}

// Expression conversion and evaluation functions

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

char* infixToPostfix(char* infix) {
    struct Stack* stack = createStack(strlen(infix));
    char* postfix = (char*)malloc(strlen(infix) + 1);
    int i, j;
    i = j = 0;

    while (infix[i] != '\0') {
        if (isalnum(infix[i]))
            postfix[j++] = infix[i];
        else if (infix[i] == '(')
            push(stack, infix[i]);
        else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                postfix[j++] = pop(stack);
            pop(stack); // Pop '('
        } else { // Operator
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack)))
                postfix[j++] = pop(stack);
            push(stack, infix[i]);
        }
        i++;
    }

    // Pop remaining operators from the stack
    while (!isEmpty(stack))
        postfix[j++] = pop(stack);

    postfix[j] = '\0'; // Null-terminate the postfix expression

    free(stack->array);
    free(stack);

    return postfix;
}

int evaluatePostfix(char* postfix) {
    struct Stack* stack = createStack(strlen(postfix));
    int i, operand1, operand2, result;
    i = 0;

    while (postfix[i] != '\0') {
        if (isalnum(postfix[i])) {
            push(stack, postfix[i] - '0');
        } else {
            operand2 = pop(stack);
            operand1 = pop(stack);
            switch (postfix[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }
            push(stack, result);
        }
        i++;
    }

    result = pop(stack);
    free(stack->array);
    free(stack);

    return result;
}
