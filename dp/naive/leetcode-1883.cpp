// 这个 IO 我直接吐出来
const int maxn = 1e3+5;
long long wait[maxn], d[maxn]; 
long long f[maxn][maxn];
int n = 0;

long long up(long long n, long long d) {
    if (n % d) return (n / d + 1) * d;
    return n;
}

bool exact(long long n, long long d) {
    return !(n % d);
}

class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        n = dist.size();
        for (int i = 0; i < n; i ++) d[i + 1] = dist[i];
        for (int i = 1; i <= n; i ++)
            f[i][0] = up(f[i - 1][0], speed) + d[i];
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j < i; j ++) {
				if (f[i - 1][j] && f[i - 1][j - 1]) {
					f[i][j] = min(up(f[i - 1][j], speed) + d[i], f[i - 1][j - 1] + d[i]);
					continue;
				}
				if (f[i - 1][j]) {
					f[i][j] = up(f[i - 1][j], speed) + d[i];
					continue;
				}
				if (f[i - 1][j - 1]) {
					f[i][j] = f[i - 1][j - 1] + d[i];
					continue;
				}
            }
        int ans = -1;
        long long cmp = (long long)hoursBefore * speed;
        for (int i = 0; i < n; i ++)
            if (f[n][i] <= cmp && f[n][i]) {
                ans = i;
                break;
            }
        return ans;
    }
};