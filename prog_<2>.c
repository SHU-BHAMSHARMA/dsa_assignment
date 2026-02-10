#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

// Stack structure for characters (operators) and integers (evaluation)
struct CalcStack {
    int top;
    float items[MAX];
};

void push(struct CalcStack *s, float val) {
    if (s->top == MAX - 1) return;
    s->items[++(s->top)] = val;
}

float pop(struct CalcStack *s) {
    if (s->top == -1) return 0;
    return s->items[(s->top)--];
}

int getPrecedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isOp(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void infixToPostfix(char* infix, char* postfix) {
    struct CalcStack s;
    s.top = -1;
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        } else if (infix[i] == '(') {
            push(&s, infix[i]);
        } else if (infix[i] == ')') {
            while (s.top != -1 && s.items[s.top] != '(')
                postfix[k++] = (char)pop(&s);
            pop(&s); // Remove '('
        } else if (isOp(infix[i])) {
            while (s.top != -1 && getPrecedence((char)s.items[s.top]) >= getPrecedence(infix[i])) {
                postfix[k++] = (char)pop(&s);
            }
            push(&s, infix[i]);
        }
    }
    while (s.top != -1) postfix[k++] = (char)pop(&s);
    postfix[k] = '\0';
}

float evaluatePostfix(char* postfix) {
    struct CalcStack s;
    s.top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            push(&s, postfix[i] - '0');
        } else if (isOp(postfix[i])) {
            float val2 = pop(&s);
            float val1 = pop(&s);
            switch (postfix[i]) {
                case '+': push(&s, val1 + val2); break;
                case '-': push(&s, val1 - val2); break;
                case '*': push(&s, val1 * val2); break;
                case '/': push(&s, val1 / val2); break;
                case '^': push(&s, pow(val1, val2)); break;
            }
        }
    }
    return pop(&s);
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
    printf("Evaluation Result: %.2f\n", evaluatePostfix(postfix));

    return 0;
}