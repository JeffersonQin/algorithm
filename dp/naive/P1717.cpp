#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 30;
const int maxt = 1e5+5;

int f[maxn], d[maxn], t[maxn], g[maxt][maxn];

int calc(int i, int j, int k) {
	int ret = g[i - t[j] - k][j - 1];
	if (ret == -1) return ret;
	for (int i = 0; i < k; i ++)
		ret += max(0, f[j] - i * d[j]);
	return ret;
}

int main() {
	int n, h; cin >> n >> h;
	h *= 12;
	for (int i = 1; i <= n; i ++) cin >> f[i];
	for (int i = 1; i <= n; i ++) cin >> d[i];
	for (int i = 2; i <= n; i ++) cin >> t[i];
	memset(g, -1, sizeof(g));
	g[0][0] = 0;
	for (int i = 1; i <= h; i ++)
		for (int j = 1; j <= n; j ++)
			for (int k = 0; k <= i - t[j]; k ++)
				g[i][j] = max(g[i][j], calc(i, j, k));
	int ans = 0;
	for (int i = 1; i <= n; i ++)
		ans = max(ans, g[h][i]);
	cout << ans << endl;
	return 0;
}
