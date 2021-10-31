#include <bits/stdc++.h>

#include <sstream>
using namespace std;

struct queue{

    int arr[100000];
    int top;
    int rear;
    int size;

    queue(){
        top =0;
        size=0;
        rear = 0;
    }
    void push(int x){
        arr[top % 100000] = x;
        top++;
        size+=1;
    }
    int pop(){
        if(size==0){
            return -1;
        }
        int x = arr[rear%100000];
        rear = (rear%100000) +1;
        size-=1;
        return x;
    }

    int size(){
        return size;
    }

}

int main(){

}