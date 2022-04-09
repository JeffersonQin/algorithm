#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 1505;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int n, m, sx, sy, vx[maxn][maxn], vy[maxn][maxn];
bool map[maxn][maxn], vis[maxn][maxn], ans;

void dfs(int x, int y, int lx, int ly) {
	if (ans) return;
	if (vis[x][y]) {
		if (vx[x][y] != lx || vy[x][y] != ly) ans = 1;
		return;
	}

	vis[x][y] = 1; vx[x][y] = lx; vy[x][y] = ly;
	
	for (int i = 0; i < 4; i ++) {
		int xx = (x + n + dx[i]) % n; 
		int yy = (y + m + dy[i]) % m;
		int lxx = lx + dx[i], lyy = ly + dy[i];
		if (map[xx][yy])
			dfs(xx, yy, lxx, lyy);
	}
}

int main() {
	char in;
	while (cin >> n >> m) {
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < m; j ++) {
				cin >> in;
				map[i][j] = (in != '#');
				if (in == 'S') sx = i, sy = j;
			}
		memset(vis, 0, sizeof(vis));
		memset(vx, 0, sizeof(vx));
		memset(vy, 0, sizeof(vy));
		ans = 0;

		dfs(sx, sy, sx, sy);

		if (ans) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}