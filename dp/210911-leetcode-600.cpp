const int maxn = 35;

class Solution {
public:
    int d[maxn], dc = 0;
    int f[maxn][2];

    int findIntegers(int n) {
        while (n > 0) {
            d[dc ++] = n & 1;
            n >>= 1;
        }

        f[0][1] = 1;
        f[0][0] = 1;
        for (int i = 1; i < dc + 2; i ++) {
            f[i][1] = f[i - 1][0];
            f[i][0] = f[i - 1][1] + f[i - 1][0];
        }

        int ans = 0;
        int last = dc - 1;
        bool flag = false;
        ans += f[last][0];
        for (int i = dc - 2; i >= 0; i --) {
            if (d[i]) {
                ans += f[i][0];
                if (i == last - 1) {
                    flag = true;
                    break;
                }
                else last = i;
            }
        }
        if (!flag) ans ++;
        return ans;
    }
};

