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
vector<int> p, vis;
void sieve(int n)
{
    vis.assign(n + 1, 0);
    p.clear();
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i]) p.push_back(i);
        for (auto j : p)
        {
            if (i * j > n) break;
            vis[i * j] = 1; // 被标记的不是素数
            if (i % j == 0) break;
        }
    }
}
void moth()
{
    int a, b;
    cin >> a >> b;
    if (__gcd(a, b - a) == 1)
    {
        cout << 1 << '\n' << b - a << '\n';
        return;
    }
    int t = *upper_bound(p.begin(), p.end(), a);
    if (t > b)
    {
        map<int, int> lst, d;
        map<pair<int, int>, int> vis;
        // vis[{a, 0}] = 1;
        d[a] = 0;
        queue<pair<int, int>> q;
        q.push({a, 0});
        while (q.size())
        {
            auto [x, w] = q.front();
            // cout << x << '\n';
            q.pop();
            if (x == b) break;
            if (vis.count({x, w})) continue;
            vis[{x, w}] = 1;
            for (int i = b - x; i >= 1; i--)
            {
                if (__gcd(x, i) == 1)
                {
                    if (!d.count(x + i) || d[x + i] > d[x] + 1)
                    {
                        if (!vis.count({x + i, d[x] + 1}))
                        {
                            d[x + i] = d[x] + 1;
                            q.push({x + i, d[x + i]});
                            lst[x + i] = x;
                        }
                    }
                }
            }
        }
        // cout << d[b] << '\n';
        vector<int> ans;
        int st = b;
        // ans.push_back(b);
        while (lst.count(st))
        {
            ans.push_back(st);
            st = lst[st];
        }
        ans.push_back(a);
        reverse(ans.begin(), ans.end());
        cout << ans.size() - 1 << '\n';
        if (ans.size() > 1)
        {
            for (int i = 0; i < ans.size() - 1; i++) cout << ans[i + 1] - ans[i] << " ";
            cout << '\n';
        }
    }
    else
    {
        // cout << t << ' ';
        // if (__gcd(t, b - t) == 1) cout << b - t << '\n';
        // else cout << b - 1 - t << ' ' << 1 << '\n';
        // vector<int> ans;
        vector<int> P;
        auto it = upper_bound(p.begin(), p.end(), a);
        while (it != p.end() && *it <= b)
        {
            if (__gcd(*it, b - *it) == 1)
            {
                cout << 2 << '\n' << *it - a << ' ' << b - *it << '\n';
                return;
            }
            it++;
        }
        cout << 3 << '\n' << t - a << ' ' << b - 1 - t << ' ' << 1 << '\n';
        // cout << ans.size() << '\n';
        // for (auto i : ans) cout << i << ' ';
        // cout << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    sieve(1000000);
    cin >> _;
    while (_--) moth();
    return 0;
}