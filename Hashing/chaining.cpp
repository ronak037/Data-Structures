/*
*THIS IS CODE TO INSERT,FIND,PRINT THE ELEMENTS IN HASHTABLE

***ASSUMING THAT "0" IS NOT ENTERED AS DATA IN THIS CODE***
*/

#include <bits/stdc++.h>
using namespace std;

typedef struct hashtable
{
    int data;
    struct hashtable *next;
} hashtable;

int hashfun(int index, int n)
{
    index = index % n;
    if (index < 0)
        return (-1) * index;
    return index;
}

//FUNCTION FOR INSERTION OF DATA USING CHAINING METHOD
int counter = 0;
void insert(hashtable a[], int data, int n)
{
    if (counter > n)
    {
        cout << "You already entered enough data so now hashtable is full\nChoose another choice\n";
        return;
    }
    int index;
    index = hashfun(data, n);
    hashtable *newnode = (hashtable *)malloc(sizeof(hashtable));
    newnode->data = data;
    newnode->next = NULL;
    hashtable *start = &a[index];
    if (start->data == 0)
    {
        start->data = data;
    }
    else
    {
        while (start->next != NULL)
        {
            start = start->next;
        }
        start->next = newnode;
    }
    cout << "Inserted\n";
}

//FUNCTION TO FIND THE DATA USING CHAINING METHOD
void find(hashtable a[], int data, int n)
{
    int index;
    index = hashfun(data, n);
    hashtable *start = &a[index];
    if (start->data == data)
    {
        cout << "Found";
    }
    else
    {
        while (start->next != NULL)
        {
            start = start->next;
            if (start->data == data)
            {
                cout << "Found";
                return;
            }
        }
        cout << "Not Found";
    }
}

//FUNCTION TO PRINT THE HASH TABLE
void print(hashtable a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        hashtable *start = &a[i];
        while (start != nullptr)
        {
            if (start->data != 0)
                cout << start->data << endl;
            start = start->next;
        }
    }
}

int main()
{
    int n;
    cout << "Enter how many data you want to enter:";
    cin >> n;
    hashtable a[n];
    for (int i = 0; i < n; i++)
    {
        a[i].data = 0;
        a[i].next = NULL;
    }
    int data;
    while (1)
    {
        cout << "\n1. insert\n2. find\n3. print hashtable\nAny other number to exit\nEnter choice:";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter element:";
            cin >> data;
            counter++;
            insert(a, data, n);
            cout << endl;
            break;
        case 2:
            cout << "Enter element you want to find:";
            cin >> data;
            find(a, data, n);
            cout << endl;
            break;
        case 3:
            print(a, n);
            break;
        default:
            exit(0);
        }
    }
}