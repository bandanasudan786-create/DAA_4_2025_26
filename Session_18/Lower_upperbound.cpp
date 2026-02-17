#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    int s=0,e=n-1;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k;
    cout<<"key element\n";
    cin>>k;
    int ans1=n;

    //for lower bound
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(arr[mid]>=k)
        {
            ans1=mid;
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }

    //for upper bound
    s=0,e=n-1;
    int ans2=n;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(arr[mid]>k)
        {
            ans2=mid;
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    if(ans1!=n)
    {
        cout<<"Lower bound of "<<k<<" is at index "<<ans1<<"\n";
    }
    else
    {
        cout<<"Lower bound of "<<k<<" does not exist\n";
    }

    if(ans2!=n)
    {
        cout<<"Upper bound of "<<k<<" is at index "<<ans2<<"\n";
    }
    else
    {
        cout<<"Upper bound of "<<k<<" does not exist\n";
    }
    
}