#include<bits/stdc++.h>
using namespace std;

int longest(vector<int>& nums) {
    int n = nums.size();
    int result=INT_MIN;

    for(int i=0; i<n; i++){
        int count=1;
        for(int j=i+1; j<n; j++){
            if(nums[j]>nums[j-1]){
                count++;
            }
            else{
                break;
            }
        }
        result=max(result, count);
    }
    return result;  
}

int main(){
    vector<int> nums={1,2,3,4,5};
    cout<<longest(nums)<<endl;
    return 0;
}