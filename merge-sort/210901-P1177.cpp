#include <iostream>
#include <cstdio> 

#define int long long

using namespace std;

const int maxn = 1e5 + 5;
int n, a[maxn], t[maxn];

void merge_sort(int l, int r) {
    // [l, r) 左闭右开
    if (r - l <= 1) return;
    int mid = (l + r) >> 1;

    merge_sort(l, mid);
    merge_sort(mid, r);

    int i = l, j = mid, head = l;
    while (i < mid && j < r)
        t[head ++] = a[i] < a[j] ? a[i ++] : a[j ++];
    while (i < mid)
        t[head ++] = a[i ++];
    while (j < r)
        t[head ++] = a[j ++];
    for (int i = l; i < r; i ++)
        a[i] = t[i];
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    merge_sort(1, n + 1);
    for (int i = 1; i <= n; i ++)
        cout << a[i] << (i == n ? '\n' : ' ');
    return 0;
}
