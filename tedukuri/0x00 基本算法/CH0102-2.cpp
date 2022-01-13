#include <iostream>
#define int unsigned long long

using namespace std;

signed main() {
	int a, b, p;
	cin >> a >> b >> p;
	a %= p; b %= p;
	int c = (long double) a * b / p;
	int ans = a * b - c * p;
	// ans %= p; // 删掉了也 ok
	cout << ans << endl;
	return 0;
}
