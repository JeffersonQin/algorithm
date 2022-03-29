#include <iostream>

using namespace std;

const int maxn = 1e5;
struct edge { int next, to; } g[maxn << 1];
int head[maxn], w[maxn], f[maxn], sz[maxn], ecnt = 2;
int ans = 2e9+5;

void add_edge(int u, int v) {
	g[ecnt] = (edge) {head[u], v};
	head[u] = ecnt ++;
}

void dfs1(int u, int fa, int dep) {
	sz[u] = w[u];
	for (int e = head[u]; e; e = g[e].next) {
		int v = g[e].to;
		if (v == fa) continue;
		dfs1(v, u, dep + 1);
		sz[u] += sz[v];
	}
	f[1] += w[u] * dep;
}

void dfs2(int u, int fa) {
	for (int e = head[u]; e; e = g[e].next) {
		int v = g[e].to;
		if (v == fa) continue;
		f[v] = f[u] + sz[1] - 2 * sz[v];
		dfs2(v, u);
	}
	ans = min(ans, f[u]);
}

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) {
		int ww, u, v; cin >> ww >> u >> v;
		if (u) add_edge(u, i), add_edge(i, u);
		if (v) add_edge(v, i), add_edge(i, v);
		w[i] = ww;
	}
	dfs1(1, 0, 0);
	dfs2(1, 0);
	cout << ans << endl;
	return 0;
}