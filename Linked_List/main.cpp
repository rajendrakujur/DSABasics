#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *create_node(int number)
{
    struct node *temp = NULL;
    temp = new node();
    temp->data = number;
    temp->next = NULL;
    return temp;
}

void add_begin(struct node *&l, int number)
{
    struct node *temp = l;
    l = create_node(number);
    l->next = temp;
}

void add_end(struct node *&l, int number)
{
    if (l == NULL)
    {
        l = create_node(number);
        return;
    }
    struct node *temp = l;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = create_node(number);
}

void add_after(struct node *&l, int after_number, int number)
{
    if (l == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    struct node *temp = l;
    while (temp->data != after_number)
    {
        temp = temp->next;
        if (!temp)
        {
            cout << "Number not found.\n";
            return;
        }
    }

    struct node *new_node = temp->next;
    temp->next = create_node(number);
    temp = temp->next;
    temp->next = new_node;
}

void add_before(struct node *&l, int before_number, int number)
{
    if (!l)
    {
        cout << "\nList is empty.";
        return;
    }
    struct node *new_node = create_node(number);
    if (l->data == before_number)
    {
        new_node->next = l;
        l = new_node;
        return;
    }
    struct node *temp1 = l;
    if (l->next)
    {
        struct node *temp2 = l->next;
        while (temp2->data != before_number)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
            if (!temp2)
            {
                cout << "Number not found.\n";
                return;
            }
        }
        temp1->next = new_node;
        new_node->next = temp2;
    }
    else
    {
        cout << "Number not found.\n";
    }
}

void delete_begin(struct node *&l)
{
    if (!l)
    {
        cout << "\nList is empty.\n";
        return;
    }
    struct node *temp = l;
    l = l->next;
    free(temp);
}

void delete_end(struct node *&l)
{
    if (!l)
    {
        cout << "\nList is empty.";
        return;
    }
    if (l->next)
    {
        struct node *temp1 = l;
        struct node *temp2 = l->next;
        while (temp2->next)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        free(temp2);
        temp1->next = NULL;
    }
    else
    {
        free(l);
    }
}

void print_list(struct node *l)
{
    if (!l)
    {
        cout << "\n------------";
        return;
    }
    while (l)
    {
        cout << l->data << " ";
        l = l->next;
    }
}

int main()
{
    srand(time(NULL));
    int number_of_queries, number;
    struct node *l;
    l = NULL;
    cout << "\nEnter number of queries ";
    cin >> number_of_queries;
    while (number_of_queries--)
    {
        switch (rand() % 6)
        {
        case 0:
            cout << "\nAdd begin : ";
            add_begin(l, rand() % 123);
            break;
        case 1:
            cout << "\nAdd end : ";
            add_end(l, rand() % 100);
            break;
        case 2:
            cout << "\nAdd after : ";
            cin >> number;
            add_after(l, number, rand() % 120);
            break;
        case 3:
            cout << "\nAdd before : ";
            cin >> number;
            add_before(l, number, rand() % 1254);
            break;
        case 4:
            cout << "\nDelete Begin : ";
            delete_begin(l);
            break;
        case 5:
            cout << "\nDelete End : ";
            delete_end(l);
            break;
        }
        cout << "\nUpdated List : ";
        print_list(l);
    }
    return 0;
}
