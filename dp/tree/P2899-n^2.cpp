const int maxn = 1e5+5;
const int inf = 2e9+5;

struct edge { int next, to; } g[maxn];
int head[maxn], ecnt = 1;

void add_edge(int u, int v) {
	g[ecnt] = (edge) { head[u], v };
	head[u] = ecnt ++;
}

int f[maxn][3];

void dfs(int u, int fa) {
	f[u][0] = 1;
	for (int e = head[u]; e; e = g[e].next) {
		int v = g[e].to;
		if (fa == v) continue;
		dfs(v, u);
		f[u][0] += min(min(f[v][0], f[v][1]), f[v][2]);
		f[u][2] += min(f[v][0], f[v][1]);
	}

	int ans_1 = inf;

	for (int e = head[u]; e; e = g[e].next) {
		int v1 = g[e].to;
		if (v1 == fa) continue;

		int sum = f[v1][0];

		for (int e = head[u]; e; e = g[e].next) {
			int v2 = g[e].to;
			if (v1 == fa || v2 == v1) continue;
			sum += min(f[v2][0], f[v2][1]);
		}
		ans_1 = min(ans_1, sum);
	}
	f[u][1] = ans_1;
}

// dfs(1, 0);
