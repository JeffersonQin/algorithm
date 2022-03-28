const int maxn = 105;

class Solution {

int f[maxn];

public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        f[0] = 1;
        int ans = m - 1;
        for (int i = 1; i < m; i ++) {
            f[i] = 1;
            for (int j = 0; j < i; j ++) {
                bool cap = true;
                for (int p = 0; p < n; p ++)
                    if (strs[p][j] > strs[p][i])
                        cap = false;
                if (!cap) continue;
                f[i] = max(f[i], f[j] + 1);
            }
            ans = min(ans, m - f[i]);
        }
        return ans;
    }
};