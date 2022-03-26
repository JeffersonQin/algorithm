// https://leetcode-cn.com/problems/n-queens-ii/
const int maxn = 15;

class Solution {
public:

    bool chosen[maxn];
    int res[maxn];

    int ans = 0;

    void next_permutation(int x, int n) {
        if (x == n + 1) {
            // judge
            for (int i = 1; i < n; i ++)
                for (int j = i + 1; j <= n; j ++)
                    if (res[i] + j - i == res[j] || res[i] + i - j == res[j])
                        return;
            ans ++;
        }
        for (int i = 1; i <= n; i ++) {
            if (chosen[i]) continue;
            chosen[i] = true;
            res[x] = i;
            next_permutation(x + 1, n);
            chosen[i] = false;
        }
    }

    int totalNQueens(int n) {
        next_permutation(1, n);
        return ans;
    }
};
