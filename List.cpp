#include <iostream>
#include <string>

using namespace std;

struct List
{
    int index;
    int a;
    List *pNext = nullptr;
};

/**
 \func void add(List ** pF, int ind, int a1)
 */

void add(List ** pF, int ind, int a1)
{
    List * obj = new List;
    obj->a     = a1;
    obj->index = ind;
    if (ind == 0)
    {
        obj->pNext = *pF;
        *pF = obj;
    }
    else
    {
        List * p1 = * pF;
        while ((p1->index != ind - 1) && (p1->pNext != nullptr))
        {
            p1 = p1->pNext;
        }
        obj->pNext = p1->pNext;
        p1->pNext = obj;
    }

    for (List * p2 = obj->pNext; p2; p2 = p2->pNext)
    {
        p2->index++;
    }
}

/**
 \func int get(List ** pF, int ind)
 */

int get(List ** pF, int ind)
{
    List * p1 = *pF;
    while ((p1->index != ind) && (p1->pNext != nullptr))
    {
        p1 = p1->pNext;
    }
    return p1->a;
}

/**
 \func void del(List ** pF, int ind)
 */

void del(List ** pF, int ind)
{
    List * p1 = * pF;
    if (ind == 0)
    {
        *pF = (*pF)->pNext;
    }
    else
    {
    while ((p1->index != ind - 1) && (p1->pNext != nullptr))
    {
        p1->pNext = p1->pNext->pNext;

    }
    }
    for (List * p2 = p1->pNext; p2; p2 = p2->pNext)
    {
        p2->index--;
    }

}

/**
 \func int main()
 */

int main()
{
    string s;
    List *p = nullptr;
    int index, a, n, i, count = 0;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        getline(cin , s);
        if (s.find("add") != string::npos)
        {
            index = stoi(s.substr(s.find("add") + 4, 2));
            if(index > count)
            {
                cout << "bad_alloc" << endl;
                continue;
            }
            count++;
            a = stoi(s.substr(s.find("add") + 6, 30));
            add(&p, index, a);
        }
        if (s.find("get") != string::npos)
        {
            index = stoi(s.substr(s.find("get") + 4, 2));
            if(index > count)
            {
                cout << "bad_alloc" << endl;
                continue;
            }
            cout << get(&p, index) << endl;
        }
        if (s.find("del") != string::npos)
        {
            index = stoi(s.substr(s.find("del") + 4, 2));
            if(index > count)
            {
                cout << "bad_alloc" << endl;
                continue;
            }
            count--;
            del(&p, index);
        }
    }


    return 0;
}

















