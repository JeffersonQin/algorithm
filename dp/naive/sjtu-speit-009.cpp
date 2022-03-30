#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 1e2+5;
int a[maxn], s[maxn], f[maxn][maxn];

int up(int n, int d) {
	if (n % d) return n / d + 1;
	return n / d;
}

signed main() {
	int n, m, C; cin >> n >> m >> C;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	memset(f, 0x7f, sizeof(f));
	for (int i = 1; i <= n; i ++) s[i] = s[i - 1] + a[i];
	for (int i = 0; i <= n; i ++) f[i][1] = s[i];
	for (int i = 1; i <= n; i ++)
		for (int j = 2; j <= m; j ++)
			for (int k = 0; k <= i; k ++)
				f[i][j] = min(f[i][j], max(f[i - k][j - 1], s[i] - s[i - k]));
	cout << up(f[n][m], C) << endl;
	return 0;
}
