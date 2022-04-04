const int maxn = 150005;

class Solution {

int sum = 0;
bool f[maxn], c[maxn][31];

public:
    bool judgeSubset(vector<int>& nums, int n, int s) {
        memset(f, 0, sizeof(f));
        memset(c, 0, sizeof(c));
        f[0] = 1;
        c[0][0] = 1;
        for (int i = 0; i < nums.size(); i ++)
            for (int j = s; j >= nums[i]; j --) {
                f[j] = f[j] || f[j - nums[i]];
                if (f[j - nums[i]])
                    for (int t = 30; t > 0; t --)
                        c[j][t] = c[j - nums[i]][t - 1] || c[j][t];
            }
        return c[s][n];
    }

    bool d(int n, int d) {
        return !(n % d);
    }

    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i ++) sum += nums[i];
        for (int m = 1; m < n; m ++) {
            if (!d((n - m) * sum , n)) continue;
            if (judgeSubset(nums, n - m, (n - m) * sum / n)) return true;
        }
        return false;
    }
};