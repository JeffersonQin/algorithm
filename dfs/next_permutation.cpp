#include <iostream>

using namespace std;

const int maxn = 40;
bool chosen[maxn]; 
int res[maxn];

void next_permutation(int x, int n) {
	if (x == n + 1) {
		// do more action
		for (int i = 1; i <= n; i ++)
			cout << res[i] << ' ';
		cout << endl;
	}
	for (int i = 1; i <= n; i ++) {
		if (chosen[i]) continue;
		chosen[i] = true;
		res[x] = i;
		next_permutation(x + 1, n);
		chosen[i] = false;
	}
}

int main() {
	next_permutation(1, 10);
	return 0;
}