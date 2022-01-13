#include <iostream>
#include <string.h>

using namespace std;

const int maxn = 15;
long long t[maxn], f[maxn];

int main() {
	int n = 12;
	for (int i = 1; i <= n; i ++) t[i] = t[i - 1] * 2 + 1;
	memset(f, 0x3f, sizeof(f));
	f[1] = 1;
	for (int i = 2; i <= n; i ++) {
		for (int j = 1; j < i; j ++) {
			f[i] = min(f[i], 2 * f[j] + t[i - j]);
		}
	}
	for (int i = 1; i <= n; i ++) cout << f[i] << endl;
	return 0;
}
