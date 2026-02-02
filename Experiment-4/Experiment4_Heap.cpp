#include<bits/stdc++.h>
using namespace std;

#define MAX 100
int heapSize = 0;
int heap[MAX];

void heapifyUp(int i)
{
    while(i>0 && heap[i]<heap[(i-1)/2]) 
    {
        swap(heap[i], heap[(i-1)/2]);
        i=(i-1)/2;
    }
}

void insert(int val) 
{
    if(heapSize==MAX) 
    {
        cout<<"Heap is full"<<endl;
        return;
    }
    heap[heapSize]=val;
    heapSize++;
    heapifyUp(heapSize-1);

}

void heapifyDown(int i) 
{
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<heapSize && heap[left]<heap[smallest]) 
    {
        smallest=left;
    }
    if(right<heapSize && heap[right]<heap[smallest]) 
    {
        smallest=right;
    }
    if(smallest!=i) 
    {
        swap(heap[i], heap[smallest]);
        heapifyDown(smallest);
    }
}

void deleteMin() 
{
    if(heapSize==0) 
    {
        cout<<"Heap is empty"<<endl;
        return;
    }
    heap[0]=heap[heapSize-1];
    heapSize--;
    heapifyDown(0);
}

void deleteindex(int i)
{
    if(i<0||i>=heapSize)
    {
        cout<<"the index is not correct"<<endl;
        return;
    }

    heap[i]=heap[heapSize-1];
    heapSize--;
    if(i>0 && heap[i]<heap[(i-1)/2])
    {
        heapifyUp(i);
    }
    else
    {
        heapifyDown(i);
    }
}

void deletemid()
{
    if(heapSize==0) 
    {
        cout<<"Heap is empty"<<endl;
        return;
    }
    int mid=(heapSize-1)/2;
    heap[mid]=heap[heapSize-1];
    heapSize--;
    if(mid>0 && heap[mid]<heap[(mid-1)/2]) 
    {
        heapifyUp(mid);
    } 
    else 
    {
        heapifyDown(mid);
    }
}

int main()
{
    insert(10);
    insert(20);
    insert(7);
    insert(15);
    insert(3);

    cout<<"Heap elements are: ";
    for(int i=0; i<heapSize; i++) 
    {
        cout<<heap[i]<< " ";
    }
    cout<<endl;

    
    cout<<"After deleting minimum element: ";
    deleteMin();
    for(int i=0; i<heapSize; i++) 
    {
        cout<<heap[i]<<" ";
    }
    cout<<endl;

    cout<< "After deleting element at index 3: ";
    deleteindex(3);
    for(int i=0; i<heapSize; i++) 
    {
        cout<<heap[i]<< " ";
    }

    cout<<"After deleting middle element: ";
    deletemid();
    for(int i=0; i<heapSize; i++) 
    {
        cout<<heap[i]<< " ";
    }
    cout<<endl;

    return 0;
}