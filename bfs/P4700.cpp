// CEOI 2011 Traffic
// http://ceoi.inf.elte.hu/tasks-archive/
// https://oi.edu.pl/static/attachment/20110713/ceoi-2011.pdf
// https://www.luogu.com.cn/problem/P4700
#include <iostream>
#include <queue>
#include <algorithm>
#define int long long

using namespace std;

const int maxn = 3e5+5;
const int maxm = 2e6;

struct node { int x, y, ans[2]; } v[maxn];
struct edge { int to, next; } g[maxm], _g[maxm];
int ecnt = 2, _ecnt = 2, head[maxn], _head[maxn];

queue<int> q;
int vis[maxn];
int ans_index = 0;

int n, m, A, B;

int E[maxn], Ecnt = 0;
int W[maxn], Wcnt = 0;

bool cmp(int a, int b) {
	return v[a].y < v[b].y;
}

void add_edge(int u, int v) {
	g[ecnt] = (edge) {v, head[u]};
	head[u] = ecnt ++;
}

void _add_edge(int u, int v) {
	_g[_ecnt] = (edge) {v, _head[u]};
	_head[u] = _ecnt ++;
}

void bfs1() {
	for (int i = 1; i <= n; i ++)
		if (!v[i].x) {
			q.push(i);
			vis[i] = true;
		}
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (int e = head[front]; e != 0; e = g[e].next) {
			int u = g[e].to;
			if (vis[u]) continue;
			q.push(u);
			vis[u] = true;
			if (v[u].x == A) E[++ Ecnt] = u;
		}
	}
	for (int i = 1; i <= n; i ++) vis[i] = false;
}

void bfs2(int u, int pi) {
	if (vis[u]) return;
	q.push(u);
	vis[u] = true;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (int e = _head[front]; e != 0; e = _g[e].next) {
			int vv = _g[e].to;
			if (vis[vv]) continue;
			q.push(vv);
			vis[vv] = true;
			if (!v[vv].x) v[vv].ans[ans_index] = pi;
		}
	}
}

signed main() {
	cin >> n >> m >> A >> B;
	for (int i = 1; i <= n; i ++)
		cin >> v[i].x >> v[i].y;
	int c, d, k;
	for (int i = 1; i <= m; i ++) {
		cin >> c >> d >> k;
		add_edge(c, d);
		_add_edge(d, c);
		if (k != 1) {
			add_edge(d, c);
			_add_edge(c, d);
		}
	}
	bfs1();
	sort(E + 1, E + 1 + Ecnt, cmp);

	for (int i = 1; i <= Ecnt; i ++)
		bfs2(E[i], i);
	ans_index ++;
	for (int i = 1; i <= n; i ++)
		vis[i] = false;
	for (int i = Ecnt; i >= 1; i --)
		bfs2(E[i], i);

	for (int i = 1; i <= n; i ++)
		if (!v[i].x)
			W[++ Wcnt] = i;
	sort(W + 1, W + 1 + Wcnt, cmp);

	for (int i = Wcnt; i >= 1; i --)
		if (!v[W[i]].ans[0] && !v[W[i]].ans[1]) cout << "0" << endl;
		else cout << (v[W[i]].ans[1] - v[W[i]].ans[0] + 1) << endl;
	return 0;
}
