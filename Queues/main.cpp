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

// wrong way of accessing queue but for the sake of practice
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
    int number_of_queries, number;
    struct Queue q;
    q.front = -1;
    q.rear = -1;
    cout << "\nEnter queue size : ";
    cin >> q.size;
    cout << "Enter number of queries : ";
    cin >> number_of_queries;
    while (number_of_queries--)
    {
        switch ((rand() % 100) % 2)
        {
        case 0:
            number = dequeue(q);
            break;
        case 1:
            number = rand() % 100;
            enqueue(q, number);
            break;
        }
        cout << "\nUpdated Queue \n";
        if (!isEmpty(q))
        {
            print(q);
        }
    }
    return 0;
}
