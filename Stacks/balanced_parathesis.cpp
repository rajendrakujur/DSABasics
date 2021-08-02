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

void print(struct stack s)
{
    for (int i = 0; i <= s.top; i++)
    {
        cout << s.data[i] << " ";
    }
}

int main()
{
    char string[100];
    struct stack s;
    int flag = 0;
    s.size = 100;
    s.top = -1;
    cout << "\nEnter expression : ";
    cin >> string;
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == '(' || string[i] == '{' || string[i] == '[')
        {
            push(s, string[i]);
        }
        if (string[i] == ')')
        {
            if (pop(s) != '(')
            {
                flag = 1;
                break;
            }
        }
        if (string[i] == ']')
        {
            if (pop(s) != '[')
            {
                flag = 1;
                break;
            }
        }
        if (string[i] == '}')
        {
            if (pop(s) != '{')
            {
                flag = 1;
                break;
            }
        }
    }
    if (!isEmpty(s))
    {
        flag = 1;
    }
    if (flag)
    {
        cout << "\nNot balanced parathesis.";
    }
    else
    {
        cout << "\nBalanced Paranthesis.";
    }
    return 0;
}
