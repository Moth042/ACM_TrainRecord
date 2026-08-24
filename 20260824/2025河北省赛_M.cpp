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
    vector<string> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];
    vector<int> num(m), mi2(n, 1);
    for (int i = 1; i < n; i++) mi2[i] = mi2[i - 1] * 2;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            num[i] |= (a[i][j] - '0') * mi2[j];
        }
    }
    // for (int i = 0; i < m; i++) cout << num[i] << " ";
    int rg, rs, rb, pg, ps, pb;
    cin >> rg >> rs >> rb >> pg >> ps >> pb;
    vector<int> ans;
    for (int i = 0; i < (1 << n); i++)
    {
        int t = __builtin_popcount(i);
        if (t < 10 || t > 13) continue;
        vector<int> cnt;
        for (int j = 0; j < m; j++) cnt.push_back(__builtin_popcount(num[j] & i));
        sort(cnt.begin(), cnt.end(), greater());
        // if (i == 4095)
        // {
        //     for (auto j : cnt) cout << j << ' ';
        //     cout << '\n';
        // }
        if (cnt[rg - 1] == pg && cnt[rs - 1] == ps && cnt[rb - 1] == pb)
        {
            // cout << i << '\n';
            cout << t << '\n';
            for (int j = 0; j < n; j++)
            {
                if ((i >> j) & 1) cout << j + 1 << ' ';
            }
            cout << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}