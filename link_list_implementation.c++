#include <bits/stdc++.h>

#include <sstream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct queue{

    Node* front;
    Node* rear;
    int top;
    int rear;
    int size;

    queue(){
        front = NULL;
        size=0;
        rear = NULL;
    }
    void push(int x){
        if(front == NULL){
            rear = new Node(x);
            front = rear;
            size++;
            return ;
        }
        Node* temp = new Node(x);
        rear->next = temp;
        rear = temp;
        size++;
    }
    int pop(){
        if(size==0){
            return -1;
        }
        Node* temp = front;
        front = front->next;
        int x = temp-> data;
        size-=1;
        delete temp;

        return x;
    }

    int size(){
        return size;
    }

    int getFront(){
        if(size==0){
            return 0;
        }else{
            return front -> data;
        }
    }

}