#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin >> n;

    unordered_map<int,int>map;
    if(map.empty()) 
    {
        map[0]=-1;
    }
    
    int sum=0;
    int mx=0;
    for(int i=0; i<n; i++) 
    {
        char c;
        cin>>c;

        if(c=='P')
        {
            sum++;
        }
        else
        {
            sum--;
        }   

        if(map.count(sum)) 
        {
            int l=i-map[sum];
            if(l>mx)
            {
                mx=l;
            }    
        }
        else 
        {
            map[sum]=i;
        }
    }
    map.clear();

    cout << mx;
    return 0;
}