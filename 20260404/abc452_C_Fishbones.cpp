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
        if (c == '-')
            s = -1;
        c = getchar();
    }
    return x * s;
}
// 快写
void write(i128 x)
{
    if (x > 9)
        write(x / 10);
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
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    int m;
    cin >> m;
    vector<string> s(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> s[i];
    vector<vector<vector<int>>> cnt(11, vector<vector<int>>(11, vector<int>(27)));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < s[i].length(); j++)
            cnt[s[i].length()][j + 1][(int)s[i][j] - 96]++;
    }
    // cout << m << '\n';
    for (int i = 1; i <= m; i++)
    {
        // cout << s[i] << '\n';
        bool tag = 1;
        if (s[i].length() != n)
        {
            cout << "No\n";
            continue;
        }
        for (int j = 1; j <= n; j++)
        {
            int x = a[j].first, y = a[j].second;
            if (cnt[x][y][(int)s[i][j - 1] - 96] == 0)
            {
                tag = 0;
                break;
            }
        }
        if (tag)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--)
        moth();
    return 0;
}