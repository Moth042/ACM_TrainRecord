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
    vector<pair<int, int>> e(m + 1);
    for (int i = 1; i <= m; i++) cin >> e[i].first >> e[i].second;
    int w;
    cin >> w;
    vector<int> hol(n * w);
    auto get = [&](int x, int d) -> int { return (x - 1) * w + d; };
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < w; j++)
        {
            if (s[j] == 'o') hol[get(i, j)] = 1;
        }
    }
    vector<vector<int>> g(n * w);
    vector<int> deg(n * w);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (hol[get(i, j)] && hol[get(i, (j + 1) % w)])
            {
                g[get(i, j)].push_back(get(i, (j + 1) % w));
                deg[get(i, (j + 1) % w)]++;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int u = e[i].first, v = e[i].second;
        for (int j = 0; j < w; j++)
        {
            if (hol[get(u, j)] && hol[get(v, (j + 1) % w)])
            {
                g[get(u, j)].push_back(get(v, (j + 1) % w));
                deg[get(v, (j + 1) % w)]++;
            }
            if (hol[get(v, j)] && hol[get(u, (j + 1) % w)])
            {
                g[get(v, j)].push_back(get(u, (j + 1) % w));
                deg[get(u, (j + 1) % w)]++;
            }
        }
    }
    queue<int> q;
    for (int i = 0; i < n * w; i++)
    {
        if (hol[i] && deg[i] == 0) q.push(i);
    }
    while (q.size())
    {
        auto x = q.front();
        q.pop();
        for (auto y : g[x])
        {
            if (--deg[y] == 0) q.push(y);
        }
    }
    for (int i = 0; i < n * w; i++)
    {
        if (deg[i])
        {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}