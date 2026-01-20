#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int val;
    Node* next;
    Node(int x)
    { 
        val=x;
        next=nullptr;
    }
    
};
class Solution{
public:
    Node* reverse(Node* head)
    {
        Node* prev=NULL;
        Node* curr=head;
        while(curr!=nullptr)
        {
            Node* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};

int main(){
    Node* n1=new Node(10);
    Node* n2=new Node(20);
    Node* n3=new Node(30);
    Node* n4=new Node(40);
    Node* n5=new Node(50);

    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;

    Solution obj;
    Node* res=obj.reverse(n1);
    while(res!=nullptr)
    {
        cout<<res->val<<" ";
        res=res->next;
    }
    return 0;
}