// 二叉树深度计算
#include <iostream>

using namespace std;

const int maxn = 1e6+5;
struct node { int left, right; } t[maxn];

int g_depth = 0;

void dfs(int father, int depth) {
	g_depth = max(depth, g_depth);
	if (t[father].left == 0 && t[father].right == 0) return;
	dfs(t[father].left, depth + 1);
	dfs(t[father].right, depth + 1);
}

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> t[i].left >> t[i].right;
	dfs(1, 1);
	cout << g_depth << endl;
	return 0;
}
