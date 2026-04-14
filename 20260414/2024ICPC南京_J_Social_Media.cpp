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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> vis(k + 1), cnt1(k + 1), cnt2(k + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        vis[x] = 1;
    }
    map<pair<int, int>, int> mp;
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (vis[u] && vis[v]) ans++;
        else if (vis[u]) cnt1[v]++;
        else if (vis[v]) cnt1[u]++;
        else
        {
            if (u > v) swap(u, v);
            if (u == v) cnt1[u]++;
            else mp[{u, v}]++;
        }
    }
    for (auto [k, v] : mp)
    {
        cnt2[k.first] = max(cnt2[k.first], cnt1[k.first] + cnt1[k.second] + v);
        cnt2[k.second] =
            max(cnt2[k.second], cnt1[k.first] + cnt1[k.second] + v);
    }
    int res = 0;
    vector<int> v;
    for (int i = 1; i <= k; i++)
    {
        if (!vis[i])
        {
            res = max(res, cnt2[i]);
            v.push_back(cnt1[i]);
        }
    }
    sort(v.begin(), v.end(), greater());
    if (v.size() >= 2) res = max(res, v[0] + v[1]);
    else if (v.size()) res = max(res, v[0]);
    cout << ans + res << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}