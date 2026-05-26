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
    map<ll, vector<ll>> px;
    map<ll, vector<ll>> py;
    map<pair<ll, ll>, int> vis;
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        px[x].push_back(y);
        py[y].push_back(x);
        vis[{x, y}] = 1;
    }
    ll ans = 0;
    for (auto [x, v] : px)
    {
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = i + 1; j < v.size(); j++)
            {
                ll y1 = v[i], y2 = v[j];
                if ((y1 + y2) % 2 == 0)
                {
                    ll my = (y1 + y2) / 2;
                    ans += py[my].size();
                    if (vis.count({x, my})) ans--;
                }
            }
        }
    }
    for (auto [y, v] : py)
    {
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = i + 1; j < v.size(); j++)
            {
                ll x1 = v[i], x2 = v[j];
                if ((x1 + x2) % 2 == 0)
                {
                    ll mx = (x1 + x2) / 2;
                    ans += px[mx].size();
                    if (vis.count({mx, y})) ans--;
                }
            }
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}