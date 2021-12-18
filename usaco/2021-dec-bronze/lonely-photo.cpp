#include <iostream>

using namespace std;

const int maxn = 5e5 + 5;
int n;
char a[maxn];
int g[maxn], h[maxn];
typedef long long ll;

int main() {
	cin >> n;
	ll ans = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		g[i] = g[i - 1];
		h[i] = h[i - 1];
		if (a[i] == 'G')
			g[i] += 1;
		if (a[i] == 'H')
			h[i] += 1;
	}
	for (int r = 4; r <= n + 1; r ++)
		for (int l = 1; l < r && r - l >= 3; l ++) {
			if (g[r - 1] - g[l - 1] == 1 || h[r - 1] - h[l - 1] == 1)
				ans += 1;
		}
	cout << ans << endl;
	return 0;
}
 
