#include <iostream>
#include <math.h>
#define int long long

using namespace std;

pair<int, int> calc(int n, int p) {
	if (n == 0) return make_pair(0, 0);
	int unit_size = 1 << (2 * n - 2);
	int unit_len = 1 << (n - 1);
	int div = p / unit_size;
	pair<int, int> sub_pos = calc(n - 1, p % unit_size);
	if (div == 0) return make_pair(sub_pos.second, sub_pos.first);
	if (div == 1) return make_pair(sub_pos.first + unit_len, sub_pos.second);
	if (div == 2) return make_pair(sub_pos.first + unit_len, sub_pos.second + unit_len);
	return make_pair(unit_len - sub_pos.second - 1, unit_len * 2 - sub_pos.first - 1);
}

int dist(pair<int, int> a, pair<int, int> b) {
	return round(sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second)) * 10);
}

signed main() {
	int T; cin >> T;
	while (T --> 0) {
		int n, s, d; cin >> n >> s >> d;
		s --; d --;
		cout << dist(calc(n, s), calc(n, d)) << endl;
	}
	return 0;
}
