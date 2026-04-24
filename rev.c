#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

int main()
{
    char str[MAX];
    int i, n;

    printf("Enter a string: ");
    scanf("%s", str);   // taking string using scanf

    n = strlen(str);    // length of string

    // push characters into stack
    for(i = 0; i < n; i++)
    {
        push(str[i]);
    }

    // pop characters to reverse
    for(i = 0; i < n; i++)
    {
        str[i] = pop();
    }

    printf("Reversed string: %s", str);

    return 0;
}