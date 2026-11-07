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
    int mx1 = 0, mx2 = 0, mx3 = 0;
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n + 1);
    vector<pair<int, int>> a(m + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].first >> a[i].second;
        cnt[a[i].first]++;
        g[a[i].first].push_back(a[i].second);
    }
    auto check = [&](int idx1, int idx2) -> bool
    {
        if (idx1 == 0) return 0;
        if (idx2 == 0) return 1;
        if (cnt[idx1] != cnt[idx2]) return cnt[idx1] > cnt[idx2];
        return idx1 < idx2;
    };
    vector<int> p(n + 2), s(n + 2);
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1];
        if (check(i, p[i])) p[i] = i;
    }
    for (int i = n; i >= 1; i--)
    {
        s[i] = s[i + 1];
        if (check(i, s[i])) s[i] = i;
    }
    vector<int> vis(n + 1), add(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int l = p[i - 1], r = s[i + 1];
        int bst = 0;
        if (check(l, bst)) bst = l;
        if (check(r, bst)) bst = r;
        int mx = cnt[bst];
        vector<int> cur;
        for (auto j : g[i])
        {
            if (vis[j] != i)
            {
                vis[j] = i;
                cur.push_back(j);
                add[j] = 0;
            }
            add[j]++;
        }
        for (auto j : cur)
        {
            int sum = cnt[j] + add[j];
            if (sum > mx || (sum == mx && j < bst))
            {
                bst = j;
                mx = sum;
            }
        }
        cout << bst << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}