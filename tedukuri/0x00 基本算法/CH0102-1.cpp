#include <iostream>
#define int unsigned long long

using namespace std;

signed main() {
	int a, b, p;
	cin >> a >> b >> p;
	int ans = 0;
	while (b > 0) {
		if (b & 1) ans += a;
		a <<= 1;
		a %= p; ans %= p;
		b >>= 1;
	}
	cout << (ans % p) << endl;
	return 0;
}
