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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dep(n + 1), f(n + 1);
    queue<int> q;
    q.push(1);
    vector<int> ord;
    while (q.size())
    {
        int x = q.front();
        q.pop();
        ord.push_back(x);
        for (auto y : g[x])
        {
            if (y == f[x]) continue;
            q.push(y);
            f[y] = x;
            dep[y] = dep[x] + 1;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int x = ord[i];
        if (a[x] == 0)
        {
            if (dep[x] >= 2)
            {
                a[x] ^= 1;
                a[f[x]] ^= 1;
                a[f[f[x]]] ^= 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += a[i];
    if (a[1] == 0)
    {
        for (auto y : g[1])
        {
            if (a[y] == 0 && g[y].size() > 1)
            {
                ans++;
                break;
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