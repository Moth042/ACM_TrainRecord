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
    // ll n;
    // cin >> n;
    // queue<array<ll, 3>> q;
    // map<array<ll, 3>, int> mp;
    // map<array<ll, 3>, array<ll, 3>> lst;
    // auto f = [&](ll n) -> array<ll, 3>
    // {
    //     ll x = 0;
    //     // queue<array<ll, 3>> q;
    //     // map<array<ll, 3>, int> mp;
    //     // map<array<ll, 3>, array<ll, 3>> lst;
    //     q.push({0, 0, 0});
    //     while (q.size())
    //     {
    //         auto [x, lx, t] = q.front();
    //         q.pop();
    //         if (x == n) return {x, lx, t};
    //         if (mp.count({x, lx, t})) continue;
    //         mp[{x, lx, t}] = 1;
    //         if (x < n)
    //         {
    //             q.push({x + (1ll << lx), lx + 1, t + 1});
    //             lst[{x + (1ll << lx), lx + 1, t + 1}] = {x, lx, t};
    //         }
    //         lst[{x - 1, 0, t + 1}] = {x, lx, t};
    //         q.push({x - 1, 0, t + 1});
    //     }
    // };
    // vector<array<ll, 3>> ans;
    // auto cur = f(n);
    // // cout << n << ": " << cur[2] << '\n';
    // while (cur != array<ll, 3>{0, 0, 0})
    // {
    //     ans.push_back(cur);
    //     cur = lst[cur];
    // }
    // cout << n << ": \n";
    // ans.push_back({0, 0, 0});
    // reverse(ans.begin(), ans.end());
    // for (auto [x, y, z] : ans) cout << x << ' ' << y << ' ' << z << '\n';
    ll l, r;
    cin >> l >> r;
    // map<ll, ll> ans;
    // ans[0] = 0;

    auto dfs = [&](auto &&self, ll x) -> ll
    {
        // if (ans.count(x)) return ans[x] % MOD;
        // if (x == 1) return 1;
        if (x == 0) return 0;
        ll res = 1, cur = x + 1;
        ll mi = 0;
        for (int i = 0; i <= 61; i++)
        {
            if ((1ll << i) - 1 > x + 1)
            {
                mi = i;
                break;
            }
        }
        // cout << mi << '\n';
        ll nxtx1 = x + 1 - ((1ll << (mi - 1)) - 1), nxtx2 = x + 1 - ((1ll << mi) - 1);
        // ans[x] = 1 + min(mi - 1 + self(self, nxtx1), mi - nxtx2);
        // ans[x] %= MOD;
        res = 1 + min(mi - 1 + self(self, nxtx1), mi - nxtx2);
        return res;
    };
    ll sum = 0;
    // cout << dfs(dfs, 2) - 1 << '\n';
    for (ll i = l; i <= r; i++)
    {
        // if (i % 2 == 0) cout << i << ' ' << dfs(dfs, i) << '\n';
        // else cout << i << ' ' << dfs(dfs, i - 1) - 1 << '\n';
        if (i % 2 == 0) sum = (sum + dfs(dfs, i)) % MOD;
        else
        {
            if (i == 1) sum = (sum + 1) % MOD;
            else sum = (sum + (dfs(dfs, i - 1) - 1 + MOD)) % MOD;
        }
    }
    cout << sum << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}