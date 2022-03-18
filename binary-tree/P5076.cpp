// 普通二叉搜索树模板
#include <iostream>
#define fuck cout << __LINE__ << endl

using namespace std;

const int maxn = 1e4+5;
int cnt = 0;
struct node { int val, cnt, size, l, r; } t[maxn];

void print(int u) {
	if (!u) return;
	print(t[u].l);
	for (int i = 0; i < t[u].cnt; i ++) cout << t[u].val << " ";
	print(t[u].r);
}

// 引用 u 的好处是能够在最后直接把新建的节点的编号赋给父亲的某个儿子
void insert(int &u, int val) {
	if (!u) {
		t[u = ++ cnt] = (node) {val, 1, 1, 0, 0};
		return;
	}
	t[u].size ++;
	if (t[u].val == val)
		t[u].cnt ++;
	else if (val < t[u].val)
		insert(t[u].l, val);
	else
		insert(t[u].r, val); 
}

int query_last(int u, int val, int ans) {
	if (val > t[u].val) {
		if (!t[u].r) return t[u].val;
		return query_last(t[u].r, val, t[u].val);
	} else {
		if (!t[u].l) return ans;
		return query_last(t[u].l, val, ans);
	}
}

int query_next(int u, int val, int ans) {
	if (val < t[u].val) {
		if (!t[u].l) return t[u].val;
		return query_next(t[u].l, val, t[u].val);
	} else {
		if (!t[u].r) return ans;
		return query_next(t[u].r, val, ans);
	}
}

int query_rank(int u, int val) {
	if (u == 0) return 1;
	if (t[u].val == val) return t[t[u].l].size + 1;
	if (val < t[u].val) return query_rank(t[u].l, val);
	return t[u].cnt + t[t[u].l].size + query_rank(t[u].r, val);
}

int query(int u, int rank) {
	if (rank > t[t[u].l].size && rank <= t[t[u].l].size + t[u].cnt) return t[u].val;
	if (rank <= t[t[u].l].size) return query(t[u].l, rank);
	return query(t[u].r, rank - t[t[u].l].size - t[u].cnt);
}

signed main() {
	int n; cin >> n;
	while (n --> 0) {
		int a, m; cin >> a >> m;
		if (a == 1) {
			cout << query_rank(1, m) << endl;
		} else if (a == 2) {
			cout << query(1, m) << endl;
		} else if (a == 3) {
			cout << query_last(1, m, -2147483647) << endl;
		} else if (a == 4) {
			cout << query_next(1, m, 2147483647) << endl;
		} else if (a == 5) {
			if (!cnt) {
				t[++ cnt] = (node) {m, 1, 1, 0, 0};
			} else {
				int a = 1;
				insert(a, m);
			}
		}
		// print(1);
	}
	return 0;
}
