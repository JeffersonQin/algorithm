#include <iostream>

using namespace std;

const int maxn = 50;
int n;
int visit[maxn], chosen[maxn];

void next_permutation(int x) {
	if (x == n + 1) {
		for (int i = 1; i <= n; i ++)
			cout << chosen[i] << ' ';
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i ++) {
		if (visit[i]) continue;
		visit[i] = 1;
		chosen[x] = i;
		next_permutation(x + 1);
		visit[i] = 0;
	}
}

int main() {
	cin >> n;
	next_permutation(1);
}