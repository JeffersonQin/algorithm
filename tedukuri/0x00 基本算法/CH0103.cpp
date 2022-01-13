#include <iostream>
#include <string.h>

using namespace std;

const int maxn = 20;
int f[1 << maxn][maxn], w[maxn][maxn], n;

int main() {
	memset(f, 0x3f, sizeof(f));
	int n; cin >> n;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			cin >> w[i][j];
	f[1][0] = 0;
	for (int i = 1; i < (1 << n); i ++)
		for (int j = 0; j < n; j ++)
			if ((1 << j) & i)
				for (int k = 0; k < n; k ++)
					if ((i ^ (1 << j)) & (1 << k))
						f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[j][k]);
	cout << f[(1 << n) - 1][n - 1] << endl;
	return 0;
}
