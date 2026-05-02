
// C Program to check for the balanced parenthesis 

# include <stdio.h> 
# include <string.h>  

#define MAX 100 

char stack[MAX]; 
int top = -1; 

void push(char c){ 
    if (top < MAX - 1){
        stack[++top] = c; 
    }
} 

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
} 

int isMatchingPair(char open, char close){ 
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
} 

int isBalanced(char exp[]) {
    for (int i = 0; i < strlen(exp); i++) {
        char c = exp[i];

        if (c == '(' || c == '{' || c == '[') {
            push(c);
        } 
        else if (c == ')' || c == '}' || c == ']') {
            if (top == -1) return 0;

            char popped = pop();
            if (!isMatchingPair(popped, c)) return 0;
        }
    }
    return (top == -1);
} 

int main() {
    char exp[MAX];

    printf("Enter expression: ");
    scanf("%s", exp);

    if (isBalanced(exp))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}