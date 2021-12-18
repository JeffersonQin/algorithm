#include <iostream>

using namespace std;

const int maxn = 1e5+5;
int n;
int p[maxn], t[maxn], d[maxn], dd[maxn];
typedef long long ll;
ll ans = 0;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> p[i];
	for (int i = 1; i <= n; i ++)
		cin >> t[i];
	for (int i = 1; i <= n; i ++) 
		d[i] = t[i] - p[i];
//	for (int i = 1; i <= n ; i ++)
//		cout << d[i] << " ";
//	cout << endl;
	bool positive = true;
	for (int i = 1; i <= n; i ++) {
		if (positive) {
			if (d[i] < 0) ans += -d[i];
			else if (d[i] > d[i - 1]) ans += d[i] - d[i - 1];
		} else {
			if (d[i] > 0) ans += d[i];
			else if (d[i] < d[i - 1]) ans += d[i - 1] - d[i];
		}
		positive = d[i] >= 0;
	}
	cout << ans << endl;
	return 0;
}
