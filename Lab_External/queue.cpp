#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};
class MyQueue{
    node* front;
    node* back;

    public:
    MyQueue(){
        front=NULL;
        back=NULL;
    }

    void push(int val){
        node* n=new node(val);
        if(front==NULL){
            front=n;
            back=n;
            return;
        }
        back->next=n;
        back=n;
    }

    void pop(){
        if(front==NULL){
            cout<<"Queue is empty"<<endl;
            return;
        }
        node* todelete=front;
        front=front->next;

        delete todelete;
    }

    int peek(){
        if(front==NULL){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return front->data;
    }

    bool empty(){
        return front==NULL;
    }
};

int main(){
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.empty()<<endl;
    return 0;
}