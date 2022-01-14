#include <iostream>
#define int long long

using namespace std;

const int maxn = 1e6;
const int maxm = 1e5;
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

signed main() {
	int n; cin >> n;
	linear_filter(n);
	for (int i = 1; i <= cnt; i ++) {
		int p = prime[i], q = n;
		while (q) {
			pc[i] += q / p;
			q /= p;
		}
		if (pc[i]) cout << p << " " << pc[i] << endl;
	}
	return 0;
}
