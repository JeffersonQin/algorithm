#include <iostream>

using namespace std;

const int maxn = 5;
const int inf = 2e9+5;

int res[maxn], val[maxn];
bool chosen[maxn];
bool ans = false;

char get_op(int op) {
	if (op == 1) return '+';
	if (op == 2) return '-';
	if (op == 3) return '*';
	if (op == 4) return '/';
	return ' ';
}

int perform_op(int num1, int num2, int op) {
	if (op == 1) return num1 + num2;
	if (op == 2) {
		if (num1 < num2) return inf;
		return num1 - num2;
	}
	if (op == 3) return num1 * num2;
	if (op == 4) {
		if (num2 == 0) return inf;
		if (num1 % num2) return inf;
		return num1 / num2;
	}
	return inf;
}

int calc(int op1, int op2, int op3, int br) {
	if (br == 1) {
		int m = perform_op(val[res[1]], val[res[2]], op1);
		if (m == inf) return 0;
		m = perform_op(m, val[res[3]], op2);
		if (m == inf) return 0;
		m = perform_op(m, val[res[4]], op3);
		if (m == inf) return 0;
		return m;
	} else {
		int m1 = perform_op(val[res[1]], val[res[2]], op1);
		int m2 = perform_op(val[res[3]], val[res[4]], op3);
		if (m1 == inf || m2 == inf) return 0;
		int m = perform_op(m1, m2, op2);
		if (m == inf) return 0;
		return m;
	}
}

void swap(int &a, int &b) {
	a ^= b;
	b ^= a;
	a ^= b;
}

void print(int op1, int op2, int op3, int br) {
	if (br == 1) {
		if (val[res[2]] > val[res[1]]) swap(val[res[2]], val[res[1]]);
		int m = perform_op(val[res[1]], val[res[2]], op1);
		cout << val[res[1]] << get_op(op1) << val[res[2]] << '=' << m << endl;
		if (val[res[3]] > m) swap(val[res[3]], m);
		int m1 = perform_op(m, val[res[3]], op2);
		cout << m << get_op(op2) << val[res[3]] << '=' << m1 << endl;
		if (val[res[4]] > m1) swap(val[res[4]], m1);
		cout << m1 << get_op(op3) << val[res[4]] << "=24" << endl;
	} else if (br == 2) {
		if (val[res[2]] > val[res[1]]) swap(val[res[2]], val[res[1]]);
		if (val[res[4]] > val[res[3]]) swap(val[res[4]], val[res[3]]);
		int m1 = perform_op(val[res[1]], val[res[2]], op1);
		int m2 = perform_op(val[res[3]], val[res[4]], op3);
		cout << val[res[1]] << get_op(op1) << val[res[2]] << '=' << m1 << endl;
		cout << val[res[3]] << get_op(op3) << val[res[4]] << '=' << m2 << endl;
		if (m2 > m1) swap(m1, m2);
		cout << m1 << get_op(op2) << m2 << "=24" << endl;
	}
}

void next_permutation(int x, int n) {
	if (ans) return;
	if (x == n + 1) {
		for (int op1 = 1; op1 <= 4; op1 ++)
			for (int op2 = 1; op2 <= 4; op2 ++)
				for (int op3 = 1; op3 <= 4; op3 ++)
					for (int br = 1; br <= 2; br ++)
						if (calc(op1, op2, op3, br) == 24) {
							print(op1, op2, op3, br);
							ans = true;
							return;
						}
		return;
	}
	for (int i = 1; i <= n; i ++) {
		if (chosen[i]) continue;
		res[x] = i;
		chosen[i] = true;
		next_permutation(x + 1, n);
		chosen[i] = false;
	}
}

int main() {
	cin >> val[1] >> val[2] >> val[3] >> val[4];
	next_permutation(1, 4);
	if (!ans) cout << "No answer!" << endl;
	return 0;
}
