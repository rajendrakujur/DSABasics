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

void push(struct stack &s, int number)
{
    if (!isFull(s))
    {
        s.data[++s.top] = number;
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

// wrong way of accessing stack still to see updated stack without changing
void print(struct stack s)
{
    for (int i = 0; i <= s.top; i++)
    {
        cout << s.data[i] << " ";
    }
}

int main()
{
    srand(time(NULL));
    struct stack s;
    s.top = -1;
    int number_of_queries, number;
    cout << "Enter stack size : ";
    cin >> s.size;
    cout << "Enter number of queries : ";
    cin >> number_of_queries;
    while (number_of_queries--)
    {
        switch ((rand() % 100) % 2)
        {
        case 0:
            cout << "\nPush Operation : ";
            number = rand() % 100;
            push(s, number);
            break;
        case 1:
            cout << "\nPop Operation : ";
            number = pop(s);
            cout << "\nPopped element from stack : " << number;
        }
        cout << "\nUpdated Stack \n";
        print(s);
    }
    return 0;
}
