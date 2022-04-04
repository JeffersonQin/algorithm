#include <iostream>
#include <queue>
#include <cstring>
#define int long long

using namespace std;

const int maxn = 1e4+5;
const int maxm = 5e4+5;
const int maxk = 15;

struct edge { int next, to, w; } g[(maxm * maxk) << 2];
int head[maxn * maxk], dis[maxn * maxk], vis[maxn * maxk], ecnt = 2, n, m, k, s, t;

void _add_edge(int u, int v, int w) {
	g[ecnt] = edge { head[u], v, w };
	head[u] = ecnt ++;
}

void add_edge(int u, int v, int w) {
	_add_edge(u, v, w);
	_add_edge(v, u, w);
}

void add_edge(int u, int v, int k, int w) {
	add_edge(k * n + u, k * n + v, w);
}

void add_edge(int u, int v, int k1, int k2, int w) {
	_add_edge(k1 * n + u, k2 * n + v, w);
	_add_edge(k1 * n + v, k2 * n + u, w);
}

struct node {
	int pos, dis;

	friend bool operator < (const node &a, const node &b) {
		return a.dis > b.dis;
	}
};

priority_queue<node> q;

void dijkstra() {
	memset(dis, 0x7f, sizeof(dis));
	dis[s] = 0;
	q.push(node { s, 0 });
	while (!q.empty()) {
		int u = q.top().pos; q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int e = head[u]; e; e = g[e].next) {
			int v = g[e].to;
            if (vis[v]) continue;
			if (dis[v] > dis[u] + g[e].w) {
				dis[v] = dis[u] + g[e].w;
				q.push(node { v, dis[v] });
			}
		}
	}
}

signed main() {
	cin >> n >> m >> k >> s >> t;
	while (m --> 0) {
		int u, v, w; cin >> u >> v >> w;
		for (int i = 0; i <= k; i ++)
			add_edge(u, v, i, w);
		for (int i = 0; i < k; i ++)
			add_edge(u, v, i, i + 1, 0);
	}
	dijkstra();
	int ans = 8e18;
	for (int i = 0; i <= k; i ++)
		ans = min(ans, dis[t + i * n]);
	cout << ans << endl;
	return 0;
}
