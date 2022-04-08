#include <iostream>

using namespace std;

const int maxn = 1e6+5;
int n, k, a[maxn], q[maxn], head, tail;

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	// min
	head = 1, tail = 0;
	for (int i = 1; i <= n; i ++) {
		while (head <= tail && a[i] <= a[q[tail]]) tail --;
		q[++ tail] = i;
		while (head < tail && q[head] <= i - k) head ++;
		if (i >= k) cout << a[q[head]] << " ";
	} cout << endl;
	// max
	head = 1, tail = 0;
	for (int i = 1; i <= n; i ++) {
		while (head <= tail && a[i] >= a[q[tail]]) tail --;
		q[++ tail] = i;
		while (head < tail && q[head] <= i - k) head ++;
		if (i >= k) cout << a[q[head]] << " ";
	} cout << endl;
	return 0;
}