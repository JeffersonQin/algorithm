#include <iostream>

using namespace std;

const int maxn = 50;
int head = 0, n, m;
int chosen[maxn];

// 选或者不选第 x 个数
void choose(int x) {
	if (head > m) return;
	if (head + n - x + 1 < m) return;
	if (x == n + 1) {
		if (head != m) return;
		for (int i = 1; i <= head; i ++)
			cout << chosen[i] << " "; // 这里必须要这么写。。。special judge 的坑
			cout << endl;
		return;
	}
	// 选
	chosen[++ head] = x;
	choose(x + 1);
	// 不选
	head --;
	choose(x + 1);
}

int main() {
	cin >> n >> m;
	choose(1);
	return 0;
}
