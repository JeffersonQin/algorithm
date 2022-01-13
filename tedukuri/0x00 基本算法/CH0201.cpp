// http://noi-test.zzstep.com/contest/0x00%E3%80%8C%E5%9F%BA%E6%9C%AC%E7%AE%97%E6%B3%95%E3%80%8D%E4%BE%8B%E9%A2%98/0201%20%E8%B4%B9%E8%A7%A3%E7%9A%84%E5%BC%80%E5%85%B3
// 和书上不同，书上是变成全零，他是要变成全一

#include <iostream>

using namespace std;

int map[5][5], f[5][5];

int f_cnt = 0;

void copy() {
	for (int i = 0; i < 5; i ++)
		for (int j = 0; j < 5; j ++)
			f[i][j] = map[i][j];
	f_cnt = 0;
}

void flip(int i, int j) {
	f_cnt ++;
	f[i][j] = !f[i][j];
	if (i > 0) f[i - 1][j] = !f[i - 1][j];
	if (j > 0) f[i][j - 1] = !f[i][j - 1];
	if (i < 4) f[i + 1][j] = !f[i + 1][j];
	if (j < 4) f[i][j + 1] = !f[i][j + 1];
}

void clear(int row) {
	for (int i = 0; i < 5; i ++)
		if (f[row][i]) flip(row + 1, i);
}

int main() {
	int n; cin >> n;
	while (n --> 0) {
		int ans = 7;
		for (int i = 0; i < 5; i ++)
			for (int j = 0; j < 5; j ++) {
				char c; cin >> c;
				while (c != '0' && c != '1')
					cin >> c;
				map[i][j] = !(c - '0');
			}
		for (int k = 0; k < (1 << 5); k ++) {
			copy();
			for (int i = 0; i < 5; i ++)
				if (k & (1 << i)) flip(0, i);
			for (int i = 0; i < 4; i ++)
				clear(i);
			if (f_cnt > 6) continue;
			bool flag = false;
			for (int i = 0; i < 5; i ++)
				if (f[4][i]) flag = true;
			if (flag) continue;
			ans = min(ans, f_cnt);
		}
		if (ans == 7) cout << -1 << endl;
		else cout << ans << endl;
	}
	return 0;
}
