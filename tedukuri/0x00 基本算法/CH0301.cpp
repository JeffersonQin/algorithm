#include <iostream>

using namespace std;

const int maxn = 25;
int head = 0, n;
int chosen[maxn];

// 选或者不选第 x 个数
void choose(int x) {
	if (x == n + 1) {
		for (int i = 1; i <= head; i ++)
			cout << chosen[i] << " "; // 这里必须要这么写。。。special judge 的坑
			cout << endl;
		return;
	}
	// 不选
	choose(x + 1);
	// 选
	chosen[++ head] = x;
	choose(x + 1);
	// clean
	head --;
}

int main() {
	cin >> n;
	choose(1);
	return 0;
}
