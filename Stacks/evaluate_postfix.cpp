#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
struct stack
{
    int data[1000];
    int top;
    int size;
};

bool isFull(struct stack s)
{
    if (s.top == s.size - 1)
    {
        cout << "\nStack is full.";
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
        cout << "\nStack is empty.";
        return true;
    }
    else
    {
        return false;
    }
}

void push(struct stack &s, int ch)
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

int result(int num1, char oper, int num2)
{
    switch (oper)
    {
    case '+':
        return num1 + num2;
        break;
    case '-':
        return num1 - num2;
        break;
    case '*':
        return num1 * num2;
        break;
    case '/':
        return num1 / num2;
        break;
    case '^':
        return num1 ^ num2;
        break;
    }
}

int main()
{
    struct stack s;
    s.top = -1;
    s.size = 1000;
    char expression[100];
    cout << "Enter expression : ";
    cin >> expression;
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (int(expression[i]) >= 48 && int(expression[i]) <= 57)
        {
            push(s, int(expression[i] - 48));
        }
        else
        {
            int b = pop(s);
            int a = pop(s);
            push(s, result(a, expression[i], b));
        }
    }
    cout << "\nFinal Result : " << pop(s) << endl;
    return 0;
}
