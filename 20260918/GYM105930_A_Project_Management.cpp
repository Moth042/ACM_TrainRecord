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
    vector<vector<pair<ll, ll>>> g(n + 1);
    for (int i = 1; i <= n; i++)
    {
        ll a, b;
        cin >> a >> b;
        g[a].push_back({b, i});
    }
    queue<int> ans;
    for (int i = n; i >= 1; i--)
    {
        ll mx = ans.size(), len = ans.size();
        sort(g[i].begin(), g[i].end());
        int st = -1;
        for (int j = 0; j < g[i].size(); j++)
        {
            if (min(g[i][j].first, len) + g[i].size() - j > mx)
            {
                mx = min(g[i][j].first, len) + g[i].size() - j;
                st = j;
            }
        }
        if (st == -1) continue;
        while (ans.size() > g[i][st].first) ans.pop();
        for (int j = st; j < g[i].size(); j++) ans.push(g[i][j].second);
    }
    cout << ans.size() << '\n';
    while (ans.size())
    {
        cout << ans.front() << ' ';
        ans.pop();
    }
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}