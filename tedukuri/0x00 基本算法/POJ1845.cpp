#include <iostream>
#include <math.h>
#include <cstring>
#define int long long

using namespace std;

const int maxn = 1e6;
const int maxm = 1e5;
const int P = 9901;
int cnt = 0;
int vis[maxn], prime[maxm], pc[maxm];


void linear_filter(int n) {
	for (int i = 2; i <= n; i ++) {
		if (vis[i] == 0) {
			vis[i] = i; prime[++ cnt] = i;
		}
		for (int j = 1; j <= cnt; j ++) {
			if (prime[j] > vis[i] || prime[j] > n / i) break;
			vis[prime[j] * i] = prime[j];
		}
	}
}

int power(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans *= a;
		a *= a;
		ans %= P; a %= P;
		b >>= 1;
	}
	return ans;
}

int geometry_sum(int p, int c) {
	if (c == 0) return 1;
	if (c & 1) return ((1 + power(p, (c + 1) >> 1)) * geometry_sum(p, (c - 1) >> 1)) % P;
	return ((1 + power(p, c >> 1)) * geometry_sum(p, (c >> 1) - 1) % P + power(p, c)) % P;
}

signed main() {
	int a, b; 
	while (cin >> a >> b) {
		cnt = 0;
		memset(vis, 0, sizeof(vis));
		memset(pc, 0, sizeof(pc));
		if (a == 1) {
			cout << 1 << endl;
			continue;
		}
		linear_filter((int) sqrt(a) + 1);
		int ans = 1;
		for (int i = 1; i <= cnt; i ++) {
			int p = prime[i];
			while (!(a % p)) {
				a /= p; pc[i] ++;
			}
			if (a != 1) prime[++ cnt] = a;
			if (pc[i]) {
				ans *= geometry_sum(p, pc[i] * b);
				ans %= P;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
