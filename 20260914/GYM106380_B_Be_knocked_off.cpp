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
vector<int> p, vis, phi;
void sieve(int n)
{
    vis.assign(n + 1, 0);
    phi.assign(n + 1, 0);
    p.clear();
    phi[1] = 1;
    for (ll i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            p.push_back(i);
            phi[i] = i - 1;
        }
        for (auto j : p)
        {
            if (i * j > n) break;
            vis[i * j] = 1; // 被标记的不是素数
            if (i % j == 0)
            {
                phi[i * j] = j * phi[i];
                break;
            }
            else phi[i * j] = (j - 1) * phi[i];
        }
    }
}
void moth()
{
    int m, k;
    cin >> m >> k;
    vector<int> can(10, 1);
    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        can[x] = 0;
    }
    auto getphi = [&](ll x) -> ll
    {
        ll res = x;
        for (ll i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                res = res / i * (i - 1);
                while (x % i == 0) x /= i;
            }
        }
        if (x > 1) res = res / x * (x - 1);
        return res;
    };
    int st = -1;
    for (int i = 1; i <= 9; i++)
    {
        if (can[i])
        {
            st = i;
            break;
        }
    }
    if (st == -1)
    {
        if (m) cout << -1 << '\n';
        else
        {
            cout << 1 << '\n';
            cout << 0 << ' ' << 1 << '\n';
        }
    }
    else
    {
        int cnt2 = 0, cnt5 = 0;
        while (m % 2 == 0)
        {
            m /= 2;
            cnt2++;
        }
        while (m % 5 == 0)
        {
            m /= 5;
            cnt5++;
        }
        cout << 1 + (max(cnt2, cnt5) > 0) << '\n';
        cout << st << ' ' << getphi(m) * 9 << '\n';
        if (max(cnt2, cnt5) > 0) cout << 0 << ' ' << max(cnt2, cnt5) << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // sieve(90000000);
    cin >> _;
    while (_--) moth();
    return 0;
}