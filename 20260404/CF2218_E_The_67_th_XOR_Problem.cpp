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
        if (c == '-')
            s = -1;
        c = getchar();
    }
    return x * s;
}
// 快写
void write(i128 x)
{
    if (x > 9)
        write(x / 10);
    putchar(x % 10 | 48);
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int randint(int l, int r)
{
    return uniform_int_distribution{l, r}(rnd);
}
struct Node
{
    ll val, son[2];
};

void moth()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    vector<Node> t(n * 62 + 1);
    int idx = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    auto insert = [&](ll x) -> void
    {
        ll o = 0;
        for (int i = 60; i >= 0; i--)
        {
            ll y = x >> i & 1;
            ll &u = t[o].son[y];
            if (!u)
                u = ++idx;
            o = u;
        }
    };
    auto getMax = [&](ll x) -> ll
    {
        ll o = 0, res = 0;
        for (int i = 60; i >= 0; i--)
        {
            ll y = x >> i & 1;
            ll u = t[o].son[y], v = t[o].son[!y];
            if (v)
                o = v, res |= (1ll << i);
            else
                o = u;
        }
        return res;
    };
    insert(a[1]);
    ll ans = a[1] ^ a[2];
    for (int i = 2; i <= n; i++)
    {
        ans = max(ans, getMax(a[i]));
        insert(a[i]);
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--)
        moth();
    return 0;
}