#include <bits/stdc++.h>
using namespace std;

typedef struct hashtable
{
    int data;
}hashtable;

int hashfun(int key, int n)
{
    key = key % n;
    if (key < 0)
        return (-1) * key;
    return key; //returning index for array
}

int main()
{
    int n;
    cout << "Enter how many number of elements you want to enter:";
    cin >> n;
    hashtable a[n];
    int key, index;
    for(int i=0;i<n;i++)
    {
        a[i].data=0;
    }

    //Insertion of element in hash table by linear probing method
    
    cout<<"Now enter the elements:";
    for (int i = 0; i < n; i++)
    {
        cin >> key;
        index = hashfun(key, n);
        if (a[index].data == 0)
            a[index].data = key;
        else
        {
            for (int j = i + 1;;)
            {
                j = j % n;
                if (a[j].data == 0)
                {
                    a[j].data = key;
                    break;
                }
                j++;
            }
        }
    }

    /*Finding element using linear probing method and delete it by putting the ****
                                                                               ZERO
                                                                               ****
                                                                            at that index */

    cout << "Enter the key you want to find and delete it:";
    cin >> key;
    index = key % n;
    if (a[index].data == key)
    {
        cout << "Found and deleted\n";
        a[index].data=0;
    }
    else
    {
        for (int i = index + 1;;)
        {
            i = i % n;
            if (i == index)
            {
                cout << "Not Found\n";
                break;
            }
            if (a[i].data == key)
            {
                cout << "Found and deleted\n";
                a[index].data=0;
                break;
            }
            i++;
        }
    }
}