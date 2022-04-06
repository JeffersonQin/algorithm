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
		for (int j = 0; j < n; j ++) {
			if ((1 << j) & i) {
				int pending_links = 0;
				int ii = i & ~(1 << j);
				for (int k = 0; k < n; k ++)
					if ((1 << k) & ii)
						pending_links += 3 - 
							(((ii >> nbr[k][0]) & 1) + 
							((ii >> nbr[k][1]) & 1) + 
							((ii >> nbr[k][2]) & 1));
				f[i] = min(f[i], f[ii] + pending_links);
			}
		}
	}
	cout << f[(1 << n) - 1] << endl;
	return 0;
}