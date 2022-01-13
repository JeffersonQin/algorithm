#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define int long long

using namespace std;

const int maxn = 1e6+5;

int cnt = 0;
int prime[maxn];
int vis[maxn];
bool mark[maxn];

struct ans_data {
	int p1, p2;

	friend bool operator < (const ans_data &a, const ans_data &b) {
		return (a.p2 - a.p1) < (b.p2 - b.p1);
	}

	friend bool operator == (const ans_data &a, const ans_data &b) {
		return (a.p2 - a.p1) == (b.p2 - b.p1);
	}

	ans_data min(const ans_data &a,  const ans_data &b) {
		return a == b ? a : (a < b ? a : b);
	}

	ans_data max(const ans_data &a, const ans_data &b) {
		return a == b ? a : (a < b ? b : a);
	}
};

void linear_filter(int n) {
	for (int i = 2; i <= n; i ++) {
		if (vis[i] == 0) {
			vis[i] = i; prime[++ cnt] = i;
		}
		for (int j = 1; j <= cnt; j ++) {
			if (prime[j] > vis[i] || prime[j] > n / i) break;
			vis[prime[j] * i] = prime[j];
		}
	}
}

signed main() {
	int L, U;
	linear_filter((int) 1e5);
	while (~scanf("%lld %lld", &L, &U)) {
		memset(mark, 0, sizeof(mark));
		
		for (int i = 1; i <= cnt; i ++) {
			int _p = prime[i];
			for (int j = L / _p; j <= U / _p; j ++) {
				int _n = j * _p;
				if (_n >= L && _n <= U && j > 1)
					mark[_n - L] = 1;
			}
		}

		if (L == 1) mark[0] = 1;
		
		int last_prime = 0;
		int prime_cnt = 0;
		ans_data min_ans = (ans_data) { 0, (int) 1e8 };
		ans_data max_ans = (ans_data) { 0, 0 };
		for (int i = 0; i <= U - L; i ++) {
			if (!mark[i]) {
				prime_cnt ++;
				if (!last_prime) {
					last_prime = i + L;
				} else {
					ans_data new_ans = (ans_data) { last_prime, i + L };
					last_prime = i + L;
					min_ans = min(min_ans, new_ans);
					max_ans = max(max_ans, new_ans);
				}
			}
		}
		if (prime_cnt < 2) cout << "There are no adjacent primes." << endl;
		else cout << min_ans.p1 << "," << min_ans.p2 << " are closest, " 
			<< max_ans.p1 << "," << max_ans.p2 << " are most distant." << endl;
	}
	return 0;
}
