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
    string s, t;
    cin >> n >> s >> t;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = (int)(s[i] - 'A');
        b[i] = (int)(t[i] - 'A');
    }
    vector<int> cnt(5);
    for (int i = 0; i < n; i++)
    {
        int cur = (b[i] - a[i] + 5) % 5;
        // cout << cur << " ";
        cnt[cur]++;
    }
    int mx = 0;
    for (int i = 0; i < 5; i++) mx = max(mx, cnt[i]);
    // cout << mx << '\n';
    for (int i = 0; i < n - 1; i++)
    {
        int mx1 = 0, mx2 = 0;
        vector<int> cnt1(5), cnt2(5);
        for (int j = 0; j <= i; j++)
        {
            int cur = (b[j] - a[j] + 5) % 5;
            cnt1[cur]++;
        }
        for (int j = 0; j < 5; j++) mx1 = max(mx1, cnt1[j]);
        for (int j = i + 1; j < n; j++)
        {
            int cur = (b[j] - a[j] + 5) % 5;
            cnt2[cur]++;
        }
        for (int j = 0; j < 5; j++) mx2 = max(mx2, cnt2[j]);
        // cout << i << " " << i + 1 - mx1 << " " << n - i - 1 - mx2 << '\n';
        // cout << mx1 << " " << mx2 << '\n';
        mx = max(mx, mx1 + mx2);
        // mx = max(mx, i + 1 - mx1 + n - i - 1 - mx2);
    }
    cout << n - mx << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}