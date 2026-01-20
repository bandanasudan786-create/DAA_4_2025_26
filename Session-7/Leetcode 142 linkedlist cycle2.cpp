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
    Node* dc(Node* head)
    {
        if(head==nullptr||head->next==nullptr)
        {
            return nullptr;
        }

        Node*s=head,*f=head;

        while(f!=nullptr && f->next!=nullptr)
        {
            s=s->next;
            f=f->next->next;
            if(s==f)
            {
                break;
            }
        }

        if(f==nullptr||f->next==nullptr)
        {
            return nullptr;
        }

        s=head;
        while(s!=f)
        {
            s=s->next;
            f=f->next;
        }
        return s;
    }
};
int main(){
    Node*n1=new Node(5);
    Node*n2=new Node(3);
    Node*n3=new Node(1);
    Node*n4=new Node(-4);

    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n1;

    Solution obj;
    Node* res = obj.dc(n1);

    if(res)
    {
        cout<<"Cycle starts at node with value: "<<res->val;
    }
    else 
    {
        cout<<"No cycle";
    }

    return 0;
}
