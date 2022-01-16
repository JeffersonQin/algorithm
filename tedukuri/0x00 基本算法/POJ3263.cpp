#include <iostream>
#include <map>

using namespace std;

const int maxn = 1e4+5;
map<pair<int, int>, bool> existed;
int d[maxn];

int main() {
	int n, I, h, r;
	cin >> n >> I >> h >> r;
	while (r --> 0) {
		int a, b; cin >> a >> b;
		if (a > b) swap(a, b);
		if (existed[make_pair(a, b)]) continue;
		existed[make_pair(a, b)] = true;
		d[a + 1] -= 1; d[b] += 1;
	}
	int c = 0;
	for (int i = 1; i <= n; i ++) {
		c += d[i];
		cout << h + c << endl;
	}
	return 0;
}
