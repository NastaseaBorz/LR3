#include <string>
#include <iostream>

using namespace std;

struct Queue
{
    int data;
    Queue * begin, * end, * next;
};

/**
 \func void push(int _data, Queue * queue)
*/

void push(int _data, Queue * queue)
{
    Queue * temp = new Queue;
    temp->next = nullptr;
    temp->data = _data;
    if(queue->end != nullptr)
    {
        queue->end->next = temp;
    }
    else
        queue->begin = temp;
    queue->end = temp;
}

/**
 \func int get(Queue * queue){
*/

int get(Queue * queue)
{
    return queue->begin->data;
}

/**
 \func int pop(int *_data, Queue *queue)
*/

int pop(int * _data, Queue * queue)
{
    if(queue->begin == nullptr)
    {
        return 0;
    }
    Queue * temp;
    temp = queue->begin;
    *_data = temp->data;
    queue->begin = temp->next;
    free(temp);
    if(queue->begin == nullptr)
    {
        queue->end = nullptr;
    }
    return 1;
}

/**
 \func int main()
*/

int main()
{
    int i, n, a;
    string s;
    Queue * q = new Queue;
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


