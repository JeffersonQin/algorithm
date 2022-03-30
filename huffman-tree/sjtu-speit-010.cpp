#include <iostream>
#include <queue>
#define int long long

using namespace std;

const int maxn = 1e3+5;

struct node {
	int c, cnt, l, r;
	friend bool operator < (const node &a, const node &b) {
		return a.cnt > b.cnt;
	}
} t[maxn];

int np = 128;

priority_queue<node> q;

int ans = 0;

void dfs(int u, int depth) {
	if (!t[u].l && !t[u].r)
		ans += depth * t[u].cnt;
	if (t[u].l) dfs(t[u].l, depth + 1);
	if (t[u].r) dfs(t[u].r, depth + 1);
}

signed main() {
	int n; cin >> n;
	while (n) {
		char c; cin >> noskipws >> c;
		if (c >= 0x20 && c <= 0x7E) n --;
		else continue;
		t[c].c = c;
		t[c].cnt ++;
	}
	for (int i = 0; i < 128; i ++)
		if (t[i].cnt)
			q.push(t[i]);
	int root = 0;
	while (!q.empty()) {
		if (q.size() == 1) {
			root = q.top().c;
			q.pop();
			break;
		}
		int m1 = q.top().c; q.pop();
		int m2 = q.top().c; q.pop();
		np ++;
		t[np] = (node) {np, t[m1].cnt + t[m2].cnt, m1, m2};
		q.push(t[np]);
	}
	dfs(root, 0);
	if (ans == 0) ans = t[root].cnt;
	cout << ans << endl;
	return 0;
}