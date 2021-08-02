#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
struct stack
{
    char data[1000];
    int top;
    int size;
};

bool isFull(struct stack s)
{
    if (s.top == s.size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmpty(struct stack s)
{
    if (s.top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(struct stack &s, char ch)
{
    if (!isFull(s))
    {
        s.data[++s.top] = ch;
    }
}

int pop(struct stack &s)
{
    if (!isEmpty(s))
    {
        return s.data[s.top--];
    }
    return -1;
}

int power(char ch)
{
    switch (ch)
    {
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;
    case '^':
        return 3;
        break;
    }
}

bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return true;
    return false;
}

int main()
{
    struct stack s;
    s.top = -1;
    s.size = 100;
    char infix[100], postfix[100];
    cout << "\nEnter infix :";
    cin >> infix;
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (!isOperator(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else
        {
            if (isEmpty(s))
            {
                cout << infix[i] << "pushed because stack was empty ";
                push(s, infix[i]);
            }
            else
            {
                if (power(infix[i]) < power(s.data[s.top]))
                {
                    postfix[j++] = pop(s);
                    push(s, infix[i]);
                }
                else
                {
                    push(s, infix[i]);
                }
            }
        }
        postfix[j] = '\0';
        cout << "\nPostfix : " << postfix << endl;
    }
    while (!isEmpty(s))
    {
        postfix[j++] = pop(s);
    }
    postfix[j] = '\0';
    cout << "\nPostfix : " << postfix << endl;
    return 0;
}
