// https://www.luogu.com.cn/problem/P4715
#define fuck cout << __LINE__ << endl
#include <iostream>

using namespace std;

const int maxn = 1e5+5;

struct node { int index, val; } a[maxn], b[maxn];

int main() {
	int n, p; cin >> n;
	for (int i = 1; i <= (1 << n); i ++) {
		cin >> p; a[i].index = i; a[i].val = p;
	}
	struct node *last = a;
	struct node *now = b;
	while (n --> 1) {
		for (int i = 1; i <= (1 << n); i ++)
			now[i] = (node) {
				last[2 * i - 1].val > last[2 * i].val ? last[2 * i - 1].index : last[2 * i].index,
				max(last[2 * i - 1].val, last[2 * i].val)
			};
		last = (struct node *)((unsigned long long) now ^ (unsigned long long) last);
		now = (struct node *)((unsigned long long) now ^ (unsigned long long) last);
		last = (struct node *)((unsigned long long) now ^ (unsigned long long) last);
	}
	struct node first = last[1], second = last[2];
	cout << (first.val < second.val ? first.index : second.index) << endl;
	return 0;
}
