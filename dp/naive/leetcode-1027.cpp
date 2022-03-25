const int maxn = 1e3+5;

class Solution {

int f[maxn][maxn], n, a[maxn];

public:
    int longestArithSeqLength(vector<int>& nums) {
        n = nums.size();
        for (int i = 0; i < n; i ++) a[i + 1] = nums[i];
        int ans = 0;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j < i; j ++) {
                int d = a[i] - a[j] + 500;
                f[i][d] = max(f[i][d], f[j][d] + 1);
                ans = max(ans, f[i][d]);
            }
        return ans + 1;
    }
};
