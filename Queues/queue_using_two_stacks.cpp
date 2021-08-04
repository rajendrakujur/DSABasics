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

void enqueue(struct stack &s1, int number)
{
    push(s1, number);
}

int dequeue(struct stack &s1, struct stack &s2)
{
    int number, return_number;
    while (!isEmpty(s1))
    {
        push(s2, pop(s1));
    }
    if (!isEmpty(s2))
    {
        return_number = pop(s2);
    }
    else
    {
        return -1;
    }
    while (!isEmpty(s2))
    {
        push(s1, pop(s2));
    }
    return return_number;
}

//wrong way of accessing but still for practice
void print(struct stack s)
{
    for (int i = 0; i <= s.top; i++)
    {
        cout << s.data[i] << " ";
    }
}

int main()
{
    struct stack s1, s2;
    s1.top = -1;
    s2.top = -1;
    s1.size = 1000;
    s2.size = 1000;
    int choice;
    while (1)
    {
        cout << "\n1.Enqueue\n2.Dequeue\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            enqueue(s1, rand() % 100);
            break;
        case 2:
            int temp = dequeue(s1, s2);
            cout << "\nDequeued number " << temp;
            break;
        }
        cout << "\nUpdated Queue : ";
        print(s1);
    }
    return 0;
}
