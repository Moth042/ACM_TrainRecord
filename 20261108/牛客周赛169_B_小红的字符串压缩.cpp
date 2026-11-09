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
    string s;
    cin >> n >> s;
    string ss;
    for (int i = 0; i < n;)
    {
        int r = i;
        while (r < n && s[r] == s[i]) r++;
        ss += s[i];
        ss += to_string(r - i);
        i = r;
    }
    vector<int> cnt(36);
    for (auto i : ss)
    {
        if (i >= 'a' && i <= 'z') cnt[(int)(i - 'a')]++;
        else cnt[i - '0' + 26]++;
    }
    int mx = 0;
    for (int i = 0; i < 36; i++) mx = max(mx, cnt[i]);
    string ans;
    for (int i = 0; i < 36; i++)
    {
        if (cnt[i] == mx)
        {
            if (i < 26) ans += (char)('a' + i);
            else ans += (i - 26) + '0';
        }
    }
    sort(ans.begin(), ans.end());
    for (auto i : ans) cout << i << ' ';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}