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
    int n, q;
    cin >> n >> q;
    vector<ll> L(n + 1, 1e18), R(n + 1, 1e18);
    for (int i = 2; i <= n; i++) cin >> L[i];
    for (int i = 1; i < n; i++) cin >> R[i];
    vector<ll> pR(n + 1, 1e18), sL(n + 2, 1e18);
    for (int i = 1; i <= n; i++) pR[i] = min(pR[i - 1], R[i]);
    sL[n] = L[n];
    for (int i = n - 1; i >= 1; i--) sL[i] = min(sL[i + 1], L[i]);
    while (q--)
    {
        int s, t;
        cin >> s >> t;
        if (s < t) cout << min(R[s], L[s] + pR[s - 1]) << '\n';
        else cout << min(L[s], R[s] + sL[s + 1]) << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}