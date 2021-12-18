#include <iostream>

using namespace std;

typedef long long ll;
const int maxn = 5e5 + 5;
int n;
char a[maxn];
ll g[maxn], h[maxn];
ll ga[maxn], ha[maxn];

int main() {
	cin >> n;
	ll ans = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (a[i] == 'G') g[i] = 1;
		if (a[i] == 'H') h[i] = 1;
	}
	ll gac = 0, hac = 0;
	ll gc = 0, hc = 0;
	for (int i = 1; i <= n; i ++) {
		if (g[i] == 0) gc ++;
		if (g[i] == 1) {
			ga[++ gac] = gc;
			gc = 0;
		}
		if (h[i] == 0) hc ++;
		if (h[i] == 1) {
			ha[++ hac] = hc;
			hc = 0;
		}
	}
	ga[++ gac] = gc;
	ha[++ hac] = hc;
//	for (int i = 1; i <= gac; i ++) 
//		cout << ga[i] << " ";
//	cout << endl;
//	for (int i = 1; i <= hac; i ++)
//		cout << ha[i] << " ";
//	cout << endl;
	for (int i = 1; i < gac; i ++) {
		if (ga[i] > 0 && ga[i + 1] > 0) {
			ans += ga[i] + ga[i + 1] - 2 + ga[i] * ga[i + 1];
		} else if (ga[i] > 0) {
			ans += ga[i] - 1;
		} else if (ga[i + 1] > 0) {
			ans += ga[i + 1] - 1;
		}
	}
	for (int i = 1; i < hac; i ++) {
		if (ha[i] > 0 && ha[i + 1] > 0) {
			ans += ha[i] + ha[i + 1] - 2 + ha[i] * ha[i + 1];
		} else if (ha[i] > 0) {
			ans += ha[i] - 1;
		} else if (ha[i + 1] > 0) {
			ans += ha[i + 1] - 1;
		}
	}
	cout << ans << endl;
	return 0;
}
 
