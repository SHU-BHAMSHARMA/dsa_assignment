#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct BracketStack {
    int top;
    char items[MAX];
};

void push(struct BracketStack *s, char val) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = val;
}

char pop(struct BracketStack *s) {
    if (s->top == -1) {
        return '\0';
    }
    return s->items[(s->top)--];
}

void checkBalance(char *expr) {
    struct BracketStack s;
    s.top = -1;
    int flag = 1;

    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(&s, expr[i]);
        } 
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            char open = pop(&s);
            if ((expr[i] == ')' && open != '(') ||
                (expr[i] == '}' && open != '{') ||
                (expr[i] == ']' && open != '[')) {
                flag = 0;
                break;
            }
        }
    }

    if (flag && s.top == -1) {
        printf("The expression is balanced\n");
    } else {
        printf("The expression is not balanced\n");
    }
}

int main() {
    char input[MAX];
    printf("Enter expression: ");
    scanf("%s", input);
    checkBalance(input);
    return 0;
    
}
