const int maxn = 2e3+5;
const int maxl = 10;

class Solution {

int f[maxn][1 << maxl];
int g[maxn], a[maxn], t[1 << maxl];

public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n; i ++) a[i + 1] = nums[i];
        memset(f, 0x7f, sizeof(f));
        memset(g, 0x7f, sizeof(g));
        
        memset(t, 0, sizeof(t));
        int cnt = 0;
        for (int j = 1; j <= n; j += k)
            t[a[j]] ++, cnt ++;
        for (int j = 0; j < 1024; j ++) {
            f[1][j] = min(f[1][j], cnt - t[j]);
            g[1] = min(g[1], f[1][j]);
        }

        for (int i = 2; i <= k; i ++) {
            memset(t, 0, sizeof(t));
            cnt = 0;
            for (int j = i; j <= n; j += k)
                t[a[j]] ++, cnt ++;
            for (int j = 0; j < 1024; j ++) {
                f[i][j] = g[i - 1] + cnt;
                for (int m = 0; m < cnt; m ++) {
                    f[i][j] = min(f[i][j], f[i - 1][j ^ a[m * k + i]] + cnt - t[a[m * k + i]]);
                }
                g[i] = min(g[i], f[i][j]);
            }
        }
        return f[k][0];
    }
};