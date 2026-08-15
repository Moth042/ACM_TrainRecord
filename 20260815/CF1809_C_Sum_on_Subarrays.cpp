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
    vector<int> cnt(n + 1);
    int j = n;
    for (int i = 1; i <= n; i++)
    {
        while (j > 0 && k < j) --j;
        cnt[i] = j;
        k -= j;
        j = max(j - 1, 0);
    }
    int cnt0 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!cnt[i]) cnt0++;
    }
    // cout << '\n';
    vector<int> ans(n + 1);
    vector<int> suf(n + 2);
    for (int i = n; i >= 1; i--)
    {
        if (cnt[i] == 0) ans[i] = -2;
        else
        {
            cnt[i]--;
            if (cnt[i] == n - i)
            {
                if (suf[i + 1] < 0) ans[i] = abs(suf[i + 1]) + 1;
                else ans[i] = 1;
            }
            else
            {
                int suff = suf[i + 1] - suf[i + 1 + cnt[i]];
                ans[i] = abs(suff) + 1;
            }
        }
        suf[i] = suf[i + 1] + ans[i];
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
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