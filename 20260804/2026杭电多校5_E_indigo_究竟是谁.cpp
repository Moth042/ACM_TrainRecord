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
    int n, k, m, q;
    cin >> n >> k >> m >> q;
    int lianxu = 1;
    map<string, int> mp;
    vector<string> a(n + 1);
    bool ok2 = 0;
    vector<int> ans;
    map<string, int> app1, ok1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
        if (!app1.count(a[i])) app1[a[i]] = i;
        if (a[i] == a[i - 1]) lianxu++;
        else
        {
            lianxu = 1;
            // ok1 = ok2 = 0;
        }
        // if (mp[a[i]] >= q) mp.erase(a[i]);

        if (ok1.count(a[i]) && ok1[a[i]] == 1 && i - app1[a[i]] >= m + 1 && mp[a[i]] <= q) ans.push_back(i);
        if (lianxu >= k) ok1[a[i]] = 1;
        // if (ok1 && ok2) ans.push_back(i);
    }
    if (ans.size())
    {
        for (auto i : ans) cout << i << " ";
        cout << '\n';
    }
    else cout << "empty\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}