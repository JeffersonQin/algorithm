class Solution {
public:
    int pm(int x, int y, int m) {
        if (x == y) return 0;
        int ans = y;
        if (x % y) ans = x % y;
        int ans2 = 0;
        if (ans < m) {
            if (ans == y && m % y == 0) ans2 = m;
            else ans2 = ans + (m / y) * y;
        } else ans2 = ans;
        if (ans2 < x) return ans2;
        return ans;
    }

    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (sx == tx && sy == ty) return true;
            if (ty > tx) ty = pm(ty, tx, sy);
            else tx = pm(tx, ty, sx);
        }
        if (sx == tx && sy == ty) return true;
        return false;
    }
};