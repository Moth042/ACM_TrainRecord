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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> dep(n + 1), fa(n + 1);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> order;
    queue<int> q;
    q.push(1);
    while (q.size())
    {
        int x = q.front();
        q.pop();
        order.push_back(x);
        for (auto y : g[x])
        {
            if (y == fa[x]) continue;
            dep[y] = dep[x] + 1;
            fa[y] = x;
            q.push(y);
        }
    }
    reverse(order.begin(), order.end());
    vector<int> x(m + 1), s(m + 1), key(m + 1);
    vector<vector<int>> st(n + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> x[i] >> s[i];
        key[i] = s[i] + dep[x[i]];
        st[x[i]].push_back(i);
    }
    vector<map<int, int>> mp(n + 1);
    set<int> die;
    vector<int> alive(m + 1, 1);
    for (auto u : order)
    {
        int mx = -1;
        for (auto v : g[u])
        {
            if (v == fa[u]) continue;
            if (mx == -1 || mp[v].size() > mp[mx].size()) mx = v;
        }
        set<int> die;
        if (mx != -1) swap(mp[u], mp[mx]);
        for (auto v : g[u])
        {
            if (v == fa[u] || v == mx) continue;
            for (auto [k, id] : mp[v])
            {
                if (die.count(k)) alive[id] = 0;
                else
                {
                    auto it = mp[u].find(k);
                    if (it != mp[u].end())
                    {
                        alive[it->second] = 0;
                        alive[id] = 0;
                        mp[u].erase(it);
                        die.insert(k);
                    }
                    else mp[u][k] = id;
                }
            }
            mp[v].clear();
        }
        for (auto id : st[u])
        {
            int k = key[id];
            if (die.count(k)) alive[id] = 0;
            else
            {
                auto it = mp[u].find(k);
                if (it != mp[u].end())
                {
                    alive[it->second] = 0;
                    alive[id] = 0;
                    mp[u].erase(it);
                    die.insert(k);
                }
                else mp[u][k] = id;
            }
        }
    }
    string ans;
    for (int i = 1; i <= m; i++)
    {
        if (alive[i]) ans += '1';
        else ans += '0';
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