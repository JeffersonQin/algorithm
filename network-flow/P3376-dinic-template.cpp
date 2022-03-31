#include <iostream>
#include <cstring>
#include <queue>
#define int long long

using namespace std;

const int maxn = 2e2+5;
const int maxm = 5e3+5;
const int inf = 9e18;

queue<int> q;
int head[maxn], d[maxn], ecnt = 2, s, t, n, m;
struct edge { int to, next, w; } g[maxm << 1];

void add_edge(int u, int v, int w) {
	g[ecnt] = edge {v, head[u], w};
	head[u] = ecnt ++;
}

void add_edge_res(int u, int v, int w) {
	add_edge(u, v, w);
	add_edge(v, u, 0);
}

bool bfs() {
	memset(d, 0, sizeof(d));
	d[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int e = head[u]; e; e = g[e].next) {
			int v = g[e].to;
			if (d[v] || !g[e].w) continue;
			d[v] = d[u] + 1;
			q.push(v);
		}
	}
	return d[t];
}

int dfs(int u, int in) {
	if (u == t) return in;
	int out = 0;
	for (int e = head[u]; e; e = g[e].next) {
		int v = g[e].to;
		if (d[v] != d[u] + 1 || !g[e].w) continue;
		
		int res = dfs(v, min(in, g[e].w));
		if (!res) continue;
		
		in -= res;
		out += res;

		g[e].w -= res;
		g[e ^ 1].w += res;

		if (!in) break;
	}
	if (!out) d[u] = 0;
	return out;
}

signed main() {
	cin >> n >> m >> s >> t;
	int u, v, w;
	while (m --> 0) {
		cin >> u >> v >> w;
		add_edge_res(u, v, w);
	}
	int ans = 0;
	while (bfs())
		ans += dfs(s, inf);
	cout << ans << endl;
	return 0;
}