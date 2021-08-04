#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct node
{
    int digit;
    int exponent;
    struct node *next;
};

struct node *create_node(int number, int multiplier)
{
    struct node *new_node = NULL;
    new_node = new node();
    new_node->digit = number;
    new_node->exponent = multiplier;
    new_node->next = NULL;
    return new_node;
}

void add_end(struct node *&list, int number, int exponent)
{
    if (!list)
    {
        list = create_node(number, exponent);
        return;
    }
    struct node *temp = list;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = create_node(number, exponent);
}

void create_list(char str[], struct node *&list)
{
    int sign, number, exp;
    int i = 0;
    while (str[i] != '\0')
    {
        //0 for positive number
        sign = 0;
        if (str[i] == '-')
        {
            // changing to negative if negative number
            sign = 1;
            i++;
        }
        else if (i != 0) // for other than first term for positive numbers
        {
            i++;
        }
        number = 0;
        while (str[i] != 'x')
        {
            number *= 10;
            number += str[i] - 48;
            i++;
        }
        exp = 0;
        i++;
        while (1)
        {
            exp *= 10;
            exp += str[i] - 48;
            i++;
            if (str[i] == '\0' || str[i] == '+' || str[i] == '-')
                break;
        }
    label:
        if (sign)
        {
            number *= -1;
        }

        add_end(list, number, exp);
    }
}

void print_polynomial(struct node *list)
{
    if (!list)
    {
        cout << "\nEmpty Polynomial.";
        return;
    }
    while (list)
    {
        if (list->digit > 0)
        {
            cout << "+";
        }
        cout << list->digit << "x^" << list->exponent << " ";
        list = list->next;
    }
}

void add_polynomials(struct node *&result, struct node *list_1, struct node *list_2)
{
    while (list_1 && list_2)
    {
        if (list_1->exponent == list_2->exponent)
        {
            add_end(result, list_1->digit + list_2->digit, list_1->exponent);
            list_1 = list_1->next;
            list_2 = list_2->next;
        }
        else if (list_1->exponent > list_2->exponent)
        {
            add_end(result, list_1->digit, list_1->exponent);
            list_1 = list_1->next;
        }
        else
        {
            add_end(result, list_2->digit, list_2->exponent);
            list_2 = list_2->next;
        }
    }
    if (list_1 && !list_2)
    {
        add_end(result, list_1->digit, list_1->exponent);
        list_1 = list_1->next;
    }
    else if (!list_1 && list_2)
    {
        add_end(result, list_2->digit, list_2->exponent);
        list_2 = list_2->next;
    }
}

int main()
{
    struct node *list_1, *list_2;
    list_1 = NULL;
    list_2 = NULL;
    char list[100];
    cout << "\nEnter first list : ";
    cin >> list;
    create_list(list, list_1);
    cout << "\nEnter second list : ";
    cin >> list;
    create_list(list, list_2);
    struct node *result = NULL;
    add_polynomials(result, list_1, list_2);
    print_polynomial(list_1);
    cout << endl;
    print_polynomial(list_2);
    cout << "\nResult : ";
    print_polynomial(result);
    return 0;
}
