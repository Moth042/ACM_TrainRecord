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
    vector<int> a(n + 1), L(n + 1, 0), R(n + 1, n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> stk;
    for (int i = 1; i <= n; i++)
    {
        while (stk.size() && a[stk.back()] <= a[i]) stk.pop_back();
        if (stk.size()) L[i] = stk.back();
        stk.push_back(i);
    }
    stk.clear();
    for (int i = n; i >= 1; i--)
    {
        while (stk.size() && a[stk.back()] <= a[i]) stk.pop_back();
        if (stk.size()) R[i] = stk.back();
        stk.push_back(i);
    }
    for (int i = 1; i <= n; i++) cout << 1ll * (i - L[i]) * (n - i + 1) + 1ll * L[i] * (R[i] - i) << " \n"[i == n];
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}