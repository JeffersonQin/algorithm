// CEOI 2011 Traffic
// http://ceoi.inf.elte.hu/tasks-archive/
// https://oi.edu.pl/static/attachment/20110713/ceoi-2011.pdf
// https://www.luogu.com.cn/problem/P4700
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 3e5+5;
const int maxm = 2e6;

struct node {
	int x, y;
} v[maxn];

struct edge {
	int to, next;
} g[maxm];

queue<int> q;

int ecnt = 2, head[maxn], vis[maxn], vcnt = 0, bcnt[maxn], p[maxn];
int n, m, A, B;

bool cmp(int a, int b) {
	return v[a].y > v[b].y;
}

void add_edge(int u, int v) {
	g[ecnt] = (edge) {v, head[u]};
	head[u] = ecnt ++;
}

void bfs(int u) {
	// if (vis[u]) return;
	q.push(u);
	vis[u] = true;
	vcnt = 1;
	bcnt[vcnt] = u;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (int e = head[front]; e != 0; e = g[e].next)
			if (!vis[g[e].to]) {
				q.push(g[e].to);
				vis[g[e].to] = true;
				bcnt[++ vcnt] = g[e].to;
			}
	}
	int lans = 0;
	for (int i = 1; i <= vcnt; i ++) {
		vis[bcnt[i]] = false;
		if (v[bcnt[i]].x == A) lans ++;
	}
	cout << lans << endl;
}

signed main() {
	cin >> n >> m >> A >> B;
	for (int i = 1; i <= n; i ++) {
		cin >> v[i].x >> v[i].y;
		p[i] = i;
	}
	int c, d, k;
	for (int i = 1; i <= m; i ++) {
		cin >> c >> d >> k;
		add_edge(c, d);
		if (k != 1) add_edge(d, c);
	}
	
	sort(p + 1, p + 1 + n, cmp);
	for (int i = 1; i <= n; i ++)
		if (!v[p[i]].x)
			bfs(p[i]);
	return 0;
}
