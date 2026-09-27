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
    int n, q;
    cin >> n >> q;
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 1; i <= n; i++) g[i].push_back({0, 0});
    vector<pair<int, char>> T;
    vector<char> col(n + 1, 'a');
    for (int i = 1; i <= q; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x;
            cin >> x;
            int t = g[x].back().second;
            g[x].push_back({i, t ^ 1});
        }
        else
        {
            char c;
            cin >> c;
            T.push_back({i, c});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < g[i].size(); j += 2)
        {
            // auto it = upper_bound(T.begin(), T.end(), g[i][j]);
            // if (it == T.end()) continue;
            // if (j + 1 >= g[i].size() || (*it).first <= g[i][j + 1].first) col[i] = (*it).second;
            int st = -1;
            int l = 0, r = T.size() - 1;
            int t;
            if (j + 1 < g[i].size()) t = g[i][j + 1].first;
            else t = q + 1;
            while (l <= r)
            {
                int mid = (l + r) >> 1;
                if (T[mid].first < t)
                {
                    st = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            if (st == -1 || T[st].first >= t || T[st].first < g[i][j].first) continue;
            col[i] = T[st].second;
        }
    }
    for (int i = 1; i <= n; i++) cout << col[i];
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}