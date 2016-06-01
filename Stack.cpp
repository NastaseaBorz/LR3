#include <string>
#include <iostream>

using namespace std;

struct Stack
{
    int data;
    Stack * begin, * next;
};

/**
 \func void push(int _data, Stack * stack)
*/

void push(int _data, Stack * stack)
{
    Stack * temp = new Stack;
    temp->data = _data;
    temp->next=stack->begin;
    stack->begin=temp;
}

/**
 \func int get(Stack * stack)
*/

int get(Stack * stack)
{
    return stack->begin->data;
}

/**
 \func int pop(int *_data, Stack *stack)
*/

int pop(int * _data, Stack * stack)
{
    if(stack->begin == nullptr)
    {
        return 0;
    }
    Stack * temp = new Stack;
    temp = stack->begin;
    *_data = temp->data;
    stack->begin = temp->next;
    free(temp);
    return 1;
}

/**
 \func int main()
*/

int main()
{
    int i, n, a;
    string s;
    Stack * q = new Stack;
    cin >> n;
    getline(cin, s);
    for(i = 0; i < n; i++)
    {
        getline(cin , s);
        if (s.find("add") != string::npos)
        {
            a = stoi(s.substr(s.find("add") + 4, 2));
            push(a, q);
        }
        if (s.find("get") != string::npos)
        {
            cout << get(q) << endl;
        }
        if (s.find("del") != string::npos)
        {
            pop(&a, q);
        }
    }

    return 0;
}



