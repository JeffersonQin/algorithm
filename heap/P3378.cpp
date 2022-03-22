// 模板题 https://www.luogu.com.cn/problem/P3378
#include <iostream>

using namespace std;

const int maxn = 1e6+5;

struct heap {
	int q[maxn];
	int size;

	bool empty() {
		return !size;
	}

	int top() {
		if (!empty()) {
			return q[1];
		} else return 0;
	}

	void swap(int i1, int i2) {
		q[i1] ^= q[i2];
		q[i2] ^= q[i1];
		q[i1] ^= q[i2];
	}

	void pop() {
		swap(1, size);
		size --;
		down(1);
	}

	void push(int x) {
		size ++;
		int i = size;
		while (i >= 2) {
			int fa = i >> 1;
			if (q[fa] < x) break;
			q[i] = q[fa];
			i = fa;
		}
		q[i] = x;
	}

	void down(int i) {
		int j = i * 2;
		if (j + 1 <= size && q[j + 1] < q[j])
			j ++;
		if (j <= size && q[j] < q[i]) {
			swap(i, j);
			down(j);
		}
	}
} h;

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) {
		int opt; cin >> opt;
		if (opt == 1) {
			int x; cin >> x;
			h.push(x);
		} else if (opt == 2) {
			cout << h.top() << endl;
		} else if (opt == 3) {
			h.pop();
		}
	}
	return 0;
}