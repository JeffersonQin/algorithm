#include <iostream>

using namespace std;

const int maxn = 55;
int map[maxn][maxn], f[maxn][maxn][4][2];
int h[maxn], v[maxn];

typedef long long ll;

int main() {
	int T; cin >> T;
	while (T --> 0) {
		int n, k; cin >> n >> k;
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++) {
				char input; cin >> input;
				if (input == '.') map[i][j] = 0;
				else map[i][j] = 1;
			}
		if (k == 1) {
			int rd = 0, dr = 0;
			for (int i = 1; i <= n; i ++) {
				dr += map[i][1];
				dr += map[n][i];
				rd += map[1][i];
				rd += map[i][n];
			} 
			int ans = 0;
			if (rd == 0) ans += 1;
			if (dr == 0) ans += 1;
			cout << ans << endl;
		}
		if (k >= 2) {
			for (int i = 1; i <= n; i ++)
				for (int j = 1; j <= n; j ++)
					for (int k = 0; k <= 3; k ++) {
						if (i == 1 && j == 1 && map[1][1] == 0) {
							f[i][j][0][0] = 1;
							f[i][j][0][1] = 1;
						} else {
							if (!map[i][j]) {
								f[i][j][k][0] = f[i - 1][j][k][0];
								f[i][j][k][1] = f[i][j - 1][k][1];
								if (k >= 1) {
									if (i * j != 2) {
										f[i][j][k][0] += f[i - 1][j][k - 1][1];
										f[i][j][k][1] += f[i][j - 1][k - 1][0];
									}
								}
							}
							else {
								f[i][j][k][0] = 0;
								f[i][j][k][1] = 0;
							}
						}
					}
			if (k == 3)
				cout << f[n][n][3][0] + f[n][n][3][1] + f[n][n][2][0] + f[n][n][2][1] + f[n][n][1][0] + f[n][n][1][1] << endl;
			if (k == 2)
				cout << f[n][n][2][0] + f[n][n][2][1] + f[n][n][1][0] + f[n][n][1][1] << endl;
		}
	}
	return 0;
}
