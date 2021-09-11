#include <iostream>
#include <algorithm>
#include <queue>
#define int long long

using namespace std;

const int maxn = 500005;
int head[maxn], dis[maxn];
bool vis[maxn];
struct edge { int to, next, w; } g[maxn];
struct node {
    int dis, pos;
    friend bool operator < (const node &a, const node &b) {
        return a.dis > b.dis;
    }
};

int ecnt = 2;
int n, m, s;

void add_edge(int u, int v, int w) {
    g[ecnt] = (edge) {v, head[u], w};
    head[u] = ecnt ++;
}

priority_queue<node> q;

void dijkstra() {
    for (int i = 1; i <= n; i ++) dis[i] = 1e10;
    dis[s] = 0;
    q.push((node) {0, s});
    while (!q.empty()) {
        int u = q.top().pos; q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int e = head[u]; e != 0; e = g[e].next) {
            int v = g[e].to;
            if (vis[v]) continue;
            if (dis[v] > dis[u] + g[e].w) {
                dis[v] = dis[u] + g[e].w;
                q.push((node) {dis[v], v});
            }
        }
    }
}

signed main() {
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i ++) {
        int u, v, w; cin >> u >> v >> w;
        add_edge(u, v, w);
    }
    dijkstra();
    for (int i = 1; i <= n; i ++)
        cout << (dis[i] == 1e10 ? 2147483647 : dis[i]) << (i == n ? "\n" : " ");
    return 0;
}

