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
    struct Queue q1, q2;
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

void push(struct stack &s, int number)
{
    enqueue(s.q1, number);
}

void swap(struct Queue &q1, struct Queue &q2)
{
    struct Queue temp = q1;
    q1 = q2;
    q2 = temp;
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

int pop(struct stack &s)
{
    int return_value;
    while (!isEmpty(s.q1))
    {
        return_value = dequeue(s.q1);
        if (!isEmpty(s.q1))
        {
            enqueue(s.q2, return_value);
        }
    }
    swap(s.q1, s.q2);
    print(s.q2);
    return return_value;
}

// wrong way of accessing queue but for the sake of practice
void print(struct stack s)
{
    int i = s.q1.front;
    while (1)
    {
        cout << s.q1.data[i] << " ";
        if (i == s.q1.rear)
        {
            break;
        }
        i = (i + 1) % s.q1.size;
    }
}

int main()
{
    struct stack s;
    s.q1.front = -1;
    s.q1.rear = -1;
    s.q2.front = -1;
    s.q2.rear = -1;
    s.q1.size = 1000;
    s.q2.size = 1000;
    int choice;
    while (1)
    {
        cout << "\n1.Push\n2.Pop\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            push(s, rand() % 100);
            break;
        case 2:
            int temp = pop(s);
            cout << "\nPopped number " << temp;
            break;
        }
        cout << "\nUpdated Stack : ";
        print(s);
    }
}
