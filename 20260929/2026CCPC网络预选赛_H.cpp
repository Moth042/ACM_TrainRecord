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
    string op;
    int n;
    cin >> op >> n;
    if (op == "first")
    {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<vector<int>> cur(n, vector<int>(n));
        iota(cur[0].begin(), cur[0].end(), 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++) cur[i][j] = cur[i - 1][(j + 1) % n];
        }
        bool ok = 0;
        for (int i = 0; i < n; i++)
        {
            if (a == cur[i])
            {
                ok = 1;
                break;
            }
        }
        vector<vector<int>> ans(n, vector<int>(n));
        ans[0] = a;
        if (!ok)
        {
            for (int i = 1; i < n; i++) ans[i] = cur[i - 1];
        }
        else
        {
            for (int i = 0; i < n; i++) ans[1][i] = n - i;
            for (int i = 2; i < n; i++)
            {
                for (int j = 0; j < n; j++) ans[i][j] = ans[i - 1][(j + 1) % n];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++) cout << ans[i][j] << ' ';
            cout << '\n';
        }
    }
    else
    {
        vector<vector<int>> a(n, vector<int>(n));
        map<vector<int>, int> mp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++) cin >> a[i][j];
            mp[a[i]]++;
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            vector<int> cur1(n), cur2(n);
            for (int j = 0; j < n; j++)
            {
                cur1[j] = a[i][(j - 1 + n) % n];
                cur2[j] = a[i][(j + 1) % n];
            }
            if (!mp.count(cur1) && !mp.count(cur2))
            {
                ans = a[i];
                break;
            }
        }
        for (int i = 0; i < n; i++) cout << ans[i] << " ";
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