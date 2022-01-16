#include <iostream>

using namespace std;

const int maxn = 1e5+5;

int a[maxn], n;

long long sp = 0, sn = 0;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 2; i <= n; i ++) {
		int d = a[i] - a[i - 1];
		if (d > 0) sp += d;
		if (d < 0) sn -= d;
	}
	cout << max(sp, sn) << endl;
	cout << abs(sp - sn) + 1 << endl;
	return 0;
}