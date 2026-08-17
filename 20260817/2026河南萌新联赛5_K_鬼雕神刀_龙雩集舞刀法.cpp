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
    vector<pair<ll, ll>> a(1000001);
    for (int i = 1; i <= 1000000; i++)
    {
        for (int j = i; j <= 1000000; j += i)
        {
            a[j].first += i;
            // a[j].second++;
        }
        a[i].second = i;
    }
    int l, r;
    cin >> l >> r;
    vector<pair<ll, ll>> v;
    for (int i = l; i <= r; i++) v.push_back(a[i]);
    sort(v.begin(), v.end(), [&](pair<ll, ll> &x, pair<ll, ll> &y) { return x.first * y.second > x.second * y.first; });
    cout << 1.0 * v[0].first / v[0].second << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cout << fixed << setprecision(10);
    // cin >> _;
    while (_--) moth();
    return 0;
}