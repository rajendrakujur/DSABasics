#include <iostream>
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

void insertion_sort(struct node *&list, int number)
{
    struct node *new_node = create_node(number);
    if (!list)
    {
        list = new_node;
        return;
    }
    if (list->data > number)
    {
        new_node->next = list;
        list = new_node;
    }
    if (!list->next)
    {
        struct node *temp = list;
        if (temp->data < number)
        {
            list->next = new_node;
        }
        else
        {
            new_node->next = list;
            list = new_node;
        }
        return;
    }
    else
    {
        struct node *temp_1 = list;
        struct node *temp_2 = list->next;
        while (temp_2->data < number)
        {
            temp_1 = temp_1->next;
            temp_2 = temp_2->next;
            if (!temp_2)
                break;
        }
        temp_1->next = new_node;
        new_node->next = temp_2;
        return;
    }
}

int main()
{
    struct node *list = NULL;
    cout << "Enter numbers or -1 to terminate : ";
    int number;
    while (1)
    {
        cin >> number;
        if (number == -1)
            break;
        insertion_sort(list, number);
        cout << "\nUpdated List : ";
        print_list(list);
        cout << endl;
    }
}
