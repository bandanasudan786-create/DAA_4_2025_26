class Solution {
public:
    bool canEat(vector<int>& p, int h, int k) 
    {
        long long hrs = 0;
        for (int b : p) {
            int t = b / k;
            if (b % k != 0) t++;
            hrs += t;
        }
        return hrs <= h;
    }

    int minEatingSpeed(vector<int>& p, int h) {
        int s=1, e=*max_element(p.begin(), p.end()), ans=e;
        while (s <= e) 
        {
            int m=s+(e-s)/2;
            if (canEat(p,h,m)) 
            {
                ans=m;
                e=m-1;
            } 
            else s=m+1;
        }
        return ans;
    }
};
