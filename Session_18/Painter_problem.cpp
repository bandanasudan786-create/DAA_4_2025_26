class Solution {
public:
    bool ok(vector<int>& a, int k, long long m) {
        long long s = 0;
        int p = 1;
        for (int x : a) {
            if (s + x > m) {
                p++;
                s = x;
                if (p > k) return false;
            } else s += x;
        }
        return true;
    }

    int minTime(vector<int>& a, int k) {
        long long l = *max_element(a.begin(), a.end());
        
        long long r = 0;
        for (int x : a) r += x;
        
        long long ans = r;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (ok(a, k, mid)) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        return (int)ans;
    }
};
