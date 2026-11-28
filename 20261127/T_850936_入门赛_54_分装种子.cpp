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
// vector<int> p, vis;
// void sieve(int n)
// {
//     vis.assign(n + 1, 0);
//     p.clear();
//     for (int i = 2; i <= n; i++)
//     {
//         if (!vis[i]) p.push_back(i);
//         for (auto j : p)
//         {
//             if (i * j > n) break;
//             vis[i * j] = 1; // 被标记的不是素数
//             if (i % j == 0) break;
//         }
//     }
// }
void moth()
{
    int n, s;
    cin >> n >> s;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> vis(1000001);
    vector<vector<int>> p(1000001);
    for (int i = 2; i <= 1000000; i++)
    {
        if (vis[i]) continue;
        for (int j = i; j <= 1000000; j += i)
        {
            p[j].push_back(i);
            if (j != i) vis[j] = 1;
        }
    }
    unordered_map<int, vector<pair<int, int>>> mp;
    for (int i = 1; i <= n; i++)
    {
        int cur = a[i];
        for (auto j : p[cur]) mp[j].push_back({i, 0});
        cur--;
        for (auto j : p[cur]) mp[j].push_back({i, 1});
    }
    int ans = -1;
    for (auto [k, v] : mp)
    {
        // cout << k << '\n';
        int res = 0;
        bool ok = 1;
        for (int i = 1; i <= n; i++)
        {
            int l = 0, r = v.size() - 1;
            int st = -1;
            while (l <= r)
            {
                int mid = (l + r) >> 1;
                if (v[mid].first >= i)
                {
                    st = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            if (st == -1 || v[st].first != i)
            {
                ok = 0;
                break;
            }
            res += v[st].second;
        }
        if (ok && res <= s) ans = max(ans, k);
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // sieve(1000000);
    // cout << p.size() << '\n';
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}