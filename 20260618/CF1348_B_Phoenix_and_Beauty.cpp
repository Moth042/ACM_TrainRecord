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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    set<int> tt;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        tt.insert(a[i]);
    }
    if (tt.size() > k)
    {
        cout << -1 << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (tt.size() == k) break;
        tt.insert(i);
    }
    vector<int> ans;

    // int add = 0;
    // for (int i = 0; i < k; i++) ans.push_back(a[i]);
    // for (int i = k; i < n;)
    // {
    //     if (a[i] == a[(i + add) % k]) ans.push_back(a[i]), i++;
    //     else
    //     {
    //         int t = (i + add) % k;
    //         bool ok = 0;
    //         for (int j = t; j < k; j++)
    //         {
    //             if (a[i] == a[j])
    //             {
    //                 ans.push_back(a[i]);
    //                 i++;
    //                 ok = 1;
    //                 break;
    //             }
    //             ans.push_back(a[j]), add++;
    //         }
    //         if (!ok)
    //         {
    //             for (int j = 0; j < t; j++)
    //             {
    //                 if (a[i] == a[j])
    //                 {
    //                     ans.push_back(a[i]);
    //                     i++;
    //                     ok = 1;
    //                     break;
    //                 }
    //                 ans.push_back(a[j]), add++;
    //             }
    //         }
    //         if (!ok)
    //         {
    //             ans.push_back(a[i]);
    //             i++;
    //         }
    //     }
    // }
    // cout << ans.size() << '\n';
    // for (auto i : ans) cout << i << " ";
    // cout << '\n';
    int add = 0;
    for (int i = 0; i < n; i++)
    {
        for (auto j : tt) ans.push_back(j);
    }
    cout << ans.size() << '\n';
    for (auto i : ans) cout << i << ' ';
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