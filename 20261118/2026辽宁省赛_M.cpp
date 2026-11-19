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
    vector<int> fa(n + 1);
    vector<vector<int>> cnt(4);
    cnt[1].push_back(1);
    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n; i++)
    {
        cin >> fa[i];
        g[fa[i]].push_back(i);
        if (fa[i] == 1) cnt[2].push_back(i);
        else cnt[3].push_back(i);
    }
    int sum = 0;
    cout << cnt[2].size() << '\n';
    for (auto i : cnt[2])
    {
        sum += g[i].size() + 1;
        cout << sum << " ";
    }
    cout << endl;
    cout.flush();
}
void moth2()
{
    int m;
    cin >> m;
    vector<int> a(m + 1);
    for (int i = 1; i <= m; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    cout << a[m] + 1 << '\n';
    vector<int> fa(m + 1);
    for (int i = 1; i <= m; i++) cout << 1 << ' ';
    for (int i = 1; i <= m; i++)
    {
        int cnt = a[i] - a[i - 1] - 1;
        // cout << cnt << '\n';
        for (int j = 1; j <= cnt; j++) cout << i + 1 << ' ';
    }
    cout << endl;
    cout.flush();
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    int _ = 1;
    cin >> _;
    if (s == "first")
    {
        while (_--) moth();
    }
    else
    {
        while (_--) moth2();
    }
    return 0;
}