#include <iostream>
#define fuck cout << __LINE__ << endl

using namespace std;

const int maxn = 1e5+5;
int cnt = 0, rt = 0;
struct node { int val, cnt, sz, fa, ch[2]; } t[maxn];

void print(int u) {
	if (!u) return;
	print(t[u].ch[0]);
	for (int i = 0; i < t[u].cnt; i ++) cout << t[u].val << ' ';
	print(t[u].ch[1]);
}

void update_sz(int u) {
	t[u].sz = t[t[u].ch[0]].sz + t[u].cnt + t[t[u].ch[1]].sz;
}

int identify(int u) {
	return t[t[u].fa].ch[1] == u;
}

void clear(int u) {
	t[u] = (node) {0, 0, 0, 0, 0, 0};
}

// let u be fa's [ch] son
// 让 u 成为 fa 的 [ch] (0, 1 左右) 儿子
void connect(int u, int fa, int ch) {
	t[u].fa = fa;
	t[fa].ch[ch] = u;
}

void rotate(int x) {
	int y = t[x].fa;
	int R = t[y].fa;
	int R_ch = identify(y), y_ch = identify(x);
	// B 为 x 的儿子
	// 若 x 为 y 的左儿子，则 B 为 x 的右儿子，执行右旋 zig
	// 若 x 为 y 的右儿子，则 B 为 x 的左儿子，执行左旋 zag
	int B = t[x].ch[y_ch ^ 1];
	connect(B, y, y_ch);
	connect(y, x, y_ch ^ 1);
	connect(x, R, R_ch);
	update_sz(y); update_sz(x);
}

void splay(int u) {
	// 解释一下下面这个循环：
	// 1. 只要有父亲就至少会旋 1 次 (先 rotate(u) 再更新 fa 然后判断新 fa)
	// 2. 如果父亲没有父亲就只旋 1 次
	// 这个循环对应了 splay 的三种操作
	// 1. 若父亲是根，也就是父亲没有父亲，只旋 1 次
	// 2. 若父亲不是根，且当前节点的儿子类型和父亲的儿子类型相同，先旋父亲再旋自己
	// 3. 若父亲不是根，且当前节点的儿子类型和父亲的儿子类型不同，旋两次自己
	for (int fa = t[u].fa; fa = t[u].fa, fa; rotate(u))
		if (t[fa].fa) rotate(identify(u) == identify(fa) ? fa : u);
	rt = u;
}

int insert(int &u, int fa, int val) {
	if (!u) {
		t[u = ++ cnt] = (node) {val, 1, 1, fa, 0, 0};
		return u;
	}
	t[u].sz ++;
	if (t[u].val == val) {
		t[u].cnt ++;
		return u;
	}
	else return insert(t[u].ch[val > t[u].val], u, val);
}

void insert_splay(int val) {
	if (!cnt) {
		rt ++;
		t[++ cnt] = (node) {val, 1, 1, 0, 0, 0};
		return;
	}
	int u = insert(rt, 0, val);
	splay(u);
}

int pre() {
	int cur = t[rt].ch[0];
	if (!cur) return cur;
	while (t[cur].ch[1]) cur = t[cur].ch[1];
	splay(cur);
	return cur;
}

int nxt() {
	int cur = t[rt].ch[1];
	if (!cur) return cur;
	while (t[cur].ch[0]) cur = t[cur].ch[0];
	splay(cur);
	return cur;
}

int query_rank(int u, int val) {
	if (u == 0) {
		splay(t[u].fa);
		return 1;
	}
	if (t[u].val == val) {
		int ans = t[t[u].ch[0]].sz + 1;
		splay(u);
		return ans;
	}
	if (val < t[u].val) return query_rank(t[u].ch[0], val);
	return t[t[u].ch[0]].sz + t[u].cnt + query_rank(t[u].ch[1], val);
}

int query_val(int u, int rank) {
	if (rank > t[t[u].ch[0]].sz && rank <= t[t[u].ch[0]].sz + t[u].cnt) return t[u].val;
	if (rank <= t[t[u].ch[0]].sz) return query_val(t[u].ch[0], rank);
	return query_val(t[u].ch[1], rank - t[t[u].ch[0]].sz - t[u].cnt);
}

void del(int k) {
	query_rank(rt, k);
	if (t[rt].cnt > 1) {
		t[rt].cnt --; t[rt].sz --;
		return;
	}
	// 全没了
	if (!t[rt].ch[0] && !t[rt].ch[1]) {
		clear(rt);
		rt = cnt = 0;
		return;
	}
	if (!t[rt].ch[0]) {
		int old_rt = rt;
		rt = t[rt].ch[1];
		t[rt].fa = 0;
		clear(old_rt);
		return;
	}
	if (!t[rt].ch[1]) {
		int old_rt = rt;
		rt = t[rt].ch[0];
		t[rt].fa = 0;
		clear(old_rt);
		return;
	}
	int old_rt = rt, y = t[rt].ch[1];
	int x = pre();
	t[x].ch[1] = y; t[y].fa = x;
	clear(old_rt);
	update_sz(rt);
}

int main() {
	int n, opt, x; cin >> n;
	while (n --> 0) {
		cin >> opt >> x;
		if (opt == 1)
			insert_splay(x);
		else if (opt == 2)
			del(x);
		else if (opt == 3)
			cout << query_rank(rt, x) << endl;
		else if (opt == 4)
			cout << query_val(rt, x) << endl;
		else if (opt == 5) {
			insert_splay(x);
			cout << t[pre()].val << endl;
			del(x);
		} else {
			insert_splay(x);
			cout << t[nxt()].val << endl;
			del(x);
		}
	}
	return 0;
}
