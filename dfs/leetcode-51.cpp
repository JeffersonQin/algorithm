// https://leetcode-cn.com/problems/n-queens/
const int maxn = 15;

class Solution {
public:

    bool chosen[maxn];
    int res[maxn];

    vector<vector<string>> ans;

    string get_string(int pos, int n) {
        string s = "";
        for (int i = 1; i < pos; i ++)
            s += ".";
        s += "Q";
        for (int i = pos + 1; i <= n; i ++)
            s += ".";
        return s;
    }

    void next_permutation(int x, int n) {
        if (x == n + 1) {
            // judge
            for (int i = 1; i < n; i ++)
                for (int j = i + 1; j <= n; j ++)
                    if (res[i] + j - i == res[j] || res[i] + i - j == res[j])
                        return;
            // output
            vector<string> ret = vector<string>();
            for (int i = 1; i <= n; i ++) 
                ret.push_back(get_string(res[i], n));
            ans.push_back(ret);
        }
        for (int i = 1; i <= n; i ++) {
            if (chosen[i]) continue;
            chosen[i] = true;
            res[x] = i;
            next_permutation(x + 1, n);
            chosen[i] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        next_permutation(1, n);
        return ans;
    }
};