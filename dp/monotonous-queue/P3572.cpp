#include <iostream>

using namespace std;

const int maxn = 1e6+5;

int qq, n, k, head, tail, a[maxn], f[maxn], q[maxn];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	cin >> qq;
	while (qq --> 0) {
		cin >> k;
		head = 1; tail = 1; q[1] = 1;
		for (int i = 2; i <= n; i ++) {
			while (head <= tail && q[head] < i - k) head ++;
			f[i] = f[q[head]] + (a[i] >= a[q[head]]);
			while (head <= tail && (
				f[i] < f[q[tail]] || (
					f[i] == f[q[tail]] && a[i] >= a[q[tail]]
				)
			)) tail --;
			q[++ tail] = i;
		}
		cout << f[n] << endl;
	}
	return 0;
}