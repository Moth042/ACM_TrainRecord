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
    ll x, y;
    cin >> x >> y;
    auto dis = [&](ll p, ll q) -> ll { return (p - x) * (p - x) + (q - y) * (q - y); };
    ll k = 0;
    while ((k + 1) * (k + 2) / 2 <= x + y) ++k;
    ll p1x = k * (k + 1) / 2 - y, p1y = y, p2x = x, p2y = k * (k + 1) / 2 - x;
    vector<pair<ll, ll>> dot;
    dot.push_back({(p1x + p2x) / 2, k * (k + 1) / 2 - (p1x + p2x) / 2});
    if (p1x + p2x < 0) dot.push_back({(p1x + p2x - 1) / 2, k * (k + 1) / 2 - (p1x + p2x - 1) / 2});
    else dot.push_back({(p1x + p2x + 1) / 2, k * (k + 1) / 2 - (p1x + p2x + 1) / 2});
    auto mn = dot[0];
    for (auto [p, q] : dot)
    {
        p = (p < 0 ? 0 : p);
        q = (q < 0 ? 0 : q);
        if (dis(p, q) < dis(mn.first, mn.second)) mn = {p, q};
    }
    string ans(k, 'Y');
    for (int i = 0; i < k; i++)
    {
        if (mn.first >= k - i)
        {
            ans[i] = 'X';
            mn.first -= k - i;
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}