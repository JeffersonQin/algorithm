#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 12;

int f[1 << maxn], nbr[maxn + 5][3];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> nbr[i][0] >> nbr[i][1] >> nbr[i][2];
		nbr[i][0] --; nbr[i][1] --; nbr[i][2] --;
	}
	memset(f, 0x7f, sizeof(f));
	f[0] = 0;
	for (int i = 1; i < (1 << n); i ++) {
		int pending_links = 0;
		for (int j = 0; j < n; j ++)
			if ((1 << j) & i)
				pending_links += 3 - 
					(((i >> nbr[j][0]) & 1) + 
					((i >> nbr[j][1]) & 1) + 
					((i >> nbr[j][2]) & 1));
		for (int j = 0; j < n; j ++) {
			if ((1 << j) & i) {
				f[i] = min(f[i], f[i & ~(1 << j)] + pending_links - (3 - 
					(((i >> nbr[j][0]) & 1) + 
					((i >> nbr[j][1]) & 1) + 
					((i >> nbr[j][2]) & 1))) + 
					((i >> nbr[j][0]) & 1) + 
					((i >> nbr[j][1]) & 1) + 
					((i >> nbr[j][2]) & 1));
			}
		}
	}
	cout << f[(1 << n) - 1] << endl;
	return 0;
}