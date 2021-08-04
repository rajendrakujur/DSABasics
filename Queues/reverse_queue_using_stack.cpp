#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct Queue
{
    int data[10000];
    int front;
    int rear;
    int size;
};

struct stack
{
    int data[1000];
    int top;
    int size;
};
bool isEmpty(struct Queue q)
{
    if (q.front == q.rear && q.front == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull(struct Queue q)
{
    if (q.front == (q.rear + 1) % q.size)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(struct Queue &q, int number)
{
    if (!isFull(q))
    {
        if (isEmpty(q))
        {
            q.front = (q.front + 1) % q.size;
        }
        q.rear = (q.rear + 1) % q.size;
        q.data[q.rear] = number;
    }
}

int dequeue(struct Queue &q)
{
    if (!isEmpty(q))
    {
        int number = q.data[q.front];
        if (q.front == q.rear)
        {
            q.rear = -1;
            q.front = q.rear;
        }
        else
        {
            q.front = (q.front + 1) % q.size;
        }
        return number;
    }
    else
    {
        return -1;
    }
}

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

void reverse_queue(struct Queue &q, struct stack &s)
{
    while (!isEmpty(q))
    {
        push(s, dequeue(q));
    }
    while (!isEmpty(s))
    {
        enqueue(q, pop(s));
    }
}

void print(struct Queue q)
{
    int i = q.front;
    while (1)
    {
        cout << q.data[i] << " ";
        if (i == q.rear)
        {
            break;
        }
        i = (i + 1) % q.size;
    }
}

int main()
{
    srand(time(NULL));
    struct stack s;
    s.top = -1;
    struct Queue q;
    q.front = -1;
    q.rear = -1;
    int number_of_elements;
    cout << "Enter number of elements you want to insert in queue:";
    cin >> number_of_elements;
    int number;
    while (number_of_elements--)
    {
        number = rand() % 100;
        enqueue(q, number);
    }
    cout << "\nBefore reversing : ";
    print(q);
    reverse_queue(q, s);
    cout << "\nAfter reversing : ";
    print(q);
    return 0;
}
