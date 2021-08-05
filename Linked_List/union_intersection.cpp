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

struct node *Union(struct node *list_1, struct node *list_2)
{
    struct node *result = NULL;
    while (list_1 && list_2)
    {
        if (list_1->data < list_2->data)
        {
            add_end(result, list_2->data);
            list_2 = list_2->next;
        }
        else if (list_1->data > list_2->data)
        {
            add_end(result, list_1->data);
            list_1 = list_1->next;
        }
        else
        {
            add_end(result, list_1->data);
            list_1 = list_1->next;
            list_2 = list_2->next;
        }
    }
    while (list_1 && !list_2)
    {
        add_end(result, list_1->data);
        list_1 = list_1->next;
    }
    while (!list_1 && list_2)
    {
        add_end(result, list_2->data);
        list_2 = list_2->next;
    }
    return result;
}

struct node *intersection(struct node *list_1, struct node *list_2)
{
    struct node *result = NULL;
    while (list_1 && list_2)
    {
        if (list_1->data == list_2->data)
        {
            add_end(result, list_1->data);
            list_1 = list_1->next;
            list_2 = list_2->next;
        }
        else if (list_1->data > list_2->data)
        {
            list_1 = list_1->next;
        }
        else if (list_1->data < list_2->data)
        {
            list_2 = list_2->next;
        }
    }
    return result;
}

int main()
{
    int number;
    struct node *list_1 = NULL;
    struct node *list_2 = NULL;
    cout << "Enter first list in descending order(-1 to terminate):";
    while (1)
    {
        cin >> number;
        if (number == -1)
            break;
        add_end(list_1, number);
    }
    cout << "Enter second list in descending order(-1 to terimate) : ";
    while (1)
    {
        cin >> number;
        if (number == -1)
            break;
        add_end(list_2, number);
    }
    print_list(list_1);
    print_list(list_2);
    cout << "\nUnion : ";
    print_list(Union(list_1, list_2));
    cout << "\nIntersection : ";
    print_list(intersection(list_1, list_2));
    return 0;
}
