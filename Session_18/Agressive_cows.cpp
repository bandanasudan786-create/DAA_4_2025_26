class Solution {
public:
    bool ok(vector<int>& a, int k, int d) {
        int cnt = 1, last = a[0];
        for (int i = 1; i < a.size(); i++) {
            if (a[i] - last >= d) {
                cnt++;
                last = a[i];
                if (cnt == k) return true;
            }
        }
        return false;
    }

    int aggressiveCows(vector<int>& stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int l = 1, r = stalls.back() - stalls.front(), ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (ok(stalls, k, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
