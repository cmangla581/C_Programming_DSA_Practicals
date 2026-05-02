// Convert the infix expression toprefix and the postfix  

# include <stdio.h> 
# include <stdlib.h> 
# include <ctype.h> 
# include <string.h> 

# define MAX 100 

char stack[MAX]; 
int top = -1; 

// Stack Operations 
void push(char c){
    stack[++top] = c; 

}

char pop(){ 
    if (top == -1) return -1; 
    return stack[top --]; 
} 

char peek() { 
    if (top == -1) return -1; 
    return stack[top]; 
} 

// Check precedence
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

// Reverse string
void reverse(char *exp) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(exp) - 1; i < j; i++, j--) {
        temp = exp[i];
        exp[i] = exp[j];
        exp[j] = temp;
    }
}

// Infix to postfix conversion proocess takes place as: 

void infixToPostfix(char *infix, char *postfix) {
    int i, k = 0;
    char ch;

    for (i = 0; infix[i]; i++) {
        ch = infix[i];

        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (peek() != '(')
                postfix[k++] = pop();
            pop(); // remove '('
        }
        else {
            while (precedence(peek()) >= precedence(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }

    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';
}

// Infix to Prefix
void infixToPrefix(char *infix, char *prefix) {
    char revInfix[MAX], postfix[MAX];
    int i;

    strcpy(revInfix, infix);
    reverse(revInfix);

    // Swap brackets
    for (i = 0; revInfix[i]; i++) {
        if (revInfix[i] == '(')
            revInfix[i] = ')';
        else if (revInfix[i] == ')')
            revInfix[i] = '(';
    }

    top = -1; // reset stack
    infixToPostfix(revInfix, postfix);

    reverse(postfix);
    strcpy(prefix, postfix);
}

int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    top = -1;
    infixToPostfix(infix, postfix);

    top = -1;
    infixToPrefix(infix, prefix);

    printf("Postfix: %s\n", postfix);
    printf("Prefix: %s\n", prefix);

    return 0;
}