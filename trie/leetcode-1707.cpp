const int maxn = 2e6+5;

class Solution {

int child[maxn][2];
int d[31];
int m[maxn];
bool ch[2];

int sz = 1;

void add(int n) {
    int p = 1;
    m[p] = min(m[p], n);
    for (int i = 30; i >= 0; i --) {
        int b = !!(n & (1LL << i));
        if (!child[p][b])
            child[p][b] = ++ sz;
        p = child[p][b];
        m[p] = min(m[p], n);
    }
}

public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        memset(m, 0x7f, sizeof(m));
        vector<int> a = vector<int>();
        for (int i = 0; i < nums.size(); i ++)
            add(nums[i]);
        for (int i = 0; i < queries.size(); i ++) {
            int x = queries[i][0], mm = queries[i][1];
            int p = 1;
            bool ans = true;

            if (m[p] > mm) ans = false;
            else
                for (int i = 30; i >= 0; i --) {
                    int xbc = !(x & (1LL << i));
                    int choose = 0;
                    ch[0] = !!child[p][0]; ch[1] = !!child[p][1];
                    if (m[child[p][1]] > mm) ch[1] = false;
                    if (m[child[p][0]] > mm) ch[0] = false;
                    if (ch[xbc]) {
                        choose = xbc;
                    } else if (ch[xbc ^ 1]) {
                        choose = xbc ^ 1;
                    } else {
                        choose = -1;
                        ans = false;
                        break;
                    }
                    p = child[p][choose];
                    d[i] = choose;
                }
            if (ans) {
                int b = 0;
                for (int i = 30; i >= 0; i --) {
                    b <<= 1LL; b += d[i];
                }
                a.push_back(b ^ x);
            } else {
                a.push_back(-1);
            }
        }
        return a;
    }
};