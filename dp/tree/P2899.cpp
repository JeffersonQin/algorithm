#include <iostream>

using namespace std;

const int maxn = 2e4+5;

// [u][0] -> u
// [u][1] -> son
// [u][2] -> fa
int n, head[maxn], f[maxn][3], ecnt = 2;
struct edge { int to, next; } g[maxn];

void add_edge(int u, int v) {
	g[ecnt] = (edge) {v, head[u]};
	head[u] = ecnt ++;
}

void dfs(int u, int fa) {
	f[u][0] = 1;
	int x = 0;
	for (int e = head[u]; e; e = g[e].next) {
		int v = g[e].to;
		if (v == fa) continue;
		dfs(v, u);
		f[u][0] += min(min(f[v][0], f[v][1]), f[v][2]);
		f[u][2] += min(f[v][0], f[v][1]);
		if (f[x][0] - min(f[x][0], f[x][1]) > f[v][0] - min(f[v][0], f[v][1]))
			x = v;
	}
	f[u][1] = f[x][0];
	for (int e = head[u]; e; e = g[e].next) {
		int v = g[e].to;
		if (v == fa) continue;
		if (v == x) continue;
		f[u][1] += min(f[v][0], f[v][1]);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i < n; i ++) {
		int u, v; cin >> u >> v;
		add_edge(u, v); add_edge(v, u);
	}
	f[0][0] = 2e9;
	dfs(1, 0);
	cout << min(f[1][0], f[1][1]) << endl;
	return 0;
}
