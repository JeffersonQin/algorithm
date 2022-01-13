#include <iostream>
#define int long long

using namespace std;

const int maxn = 5e4+5;

int z, m, h;
int a[maxn], b[maxn];

signed main() {
	cin >> z;
	while (z --> 0) {
		cin >> m >> h;
		for (int i = 1; i <= h; i ++)
			cin >> a[i] >> b[i];
		int ans = 0;
		for (int i = 1; i <= h; i ++) {
			int _ans = 1;
			while (b[i]) {
				if (b[i] & 1) _ans *= a[i];
				a[i] *= a[i];
				_ans %= m; a[i] %= m;
				b[i] >>= 1;
			}
			ans += _ans;
			ans %= m;
		}
		cout << ans << endl;
	}
	return 0;
}
