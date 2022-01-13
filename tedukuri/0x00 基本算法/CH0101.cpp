#include <iostream>
#define int long long

using namespace std;

signed main() {
	int a, b, p;
	cin >> a >> b >> p;
	int ans = 1;
	while (b > 0) {
		if (b & 1) ans *= a;
		a *= a;
		ans %= p; a %= p;
		b >>= 1;
	}
	cout << (ans % p) << endl;
	return 0;
}
