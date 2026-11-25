#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int N = 1e5 + 9;
const int mod = 1e9 + 7;
const int MOD = 998244353;
int dx[] = {-1, 0, 1, 0}; // 上右下左
int dy[] = {0, 1, 0, -1};
int ddx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int ddy[] = {0, 1, 1, 1, 0, -1, -1, -1};
// 快读
inline i128 read()
{
    char c = getchar();
    i128 x = 0, s = 1;
    while (c < '0' || c > '9')
    {
        if (c == '-') s = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x * s;
}
// 快写
void write(i128 x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 | 48);
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int randint(int l, int r)
{
    return uniform_int_distribution{l, r}(rnd);
}
void moth()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    for (auto &x : c) cin >> x;
    int m;
    cin >> m;
    int st1 = 0, st2 = 0, st3 = 0;
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        int cur = 0;
        int x, y, z;
        cin >> x >> y >> z;
        st1 = (st1 + x) % n;
        st2 = (st2 + y) % n;
        st3 = (st3 + z) % n;
        int t1 = a[st1], t2 = b[st2], t3 = c[st3];
        if (t1 + 1 == t2 && t2 + 1 == t3) cur = max(cur, 200);
        if (t1 > t2) swap(t1, t2);
        if (t1 > t3) swap(t1, t3);
        if (t2 > t3) swap(t2, t3);
        if (t1 == t3) cur = max(cur, 200);
        if (t1 == t2 || t2 == t3) cur = max(cur, 100);
        if (t1 + 1 == t2 && t2 + 1 == t3) cur = max(cur, 100);
        ans += cur;
    }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}