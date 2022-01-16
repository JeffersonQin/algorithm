// https://www.luogu.com.cn/problem/P2280
#include <iostream>

using namespace std;

const int maxn = 5005;

int s[maxn][maxn], n, m;

signed main() {
	cin >> n >> m;
	while (n --> 0) {
		int x, y, v; cin >> x >> y >> v;
		s[x + 1][y + 1] += v;
	}
	for (int i = 1; i <= 5003; i ++)
		for (int j = 1; j <= 5003; j ++)
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + s[i][j];
	long long ans = 0;
	for (int i = 1; i + m - 1 <= 5003; i ++)
		for (int j = 1; j + m - 1 <= 5003; j ++)
			ans = max(ans, (long long) s[i + m - 1][j + m - 1] - s[i - 1][j + m - 1] - s[i + m - 1][j - 1] + s[i - 1][j - 1]);
	// for (int i = m; i <= 5003; i ++)
	// 	for (int j = m; j <= 5003; j ++)
	// 		ans = max(ans, (long long) s[i][j] - s[i - m][j] - s[i][j - m] + s[i - m][j - m]);
	// 注释的三行和上面三行等价，都能 AC
	cout << ans << endl;
	return 0;
}
