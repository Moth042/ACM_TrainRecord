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
    string s;
    cin >> s;
    int x;
    cin >> x;
    if (s == "0")
    {
        cout << "YES\n";
        return;
    }
    int mn = 1e9;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'A' || s[i] == 'a') mn = min(mn, 1 + 4 * i);
        else if (s[i] == 'B' || s[i] == 'b') mn = min(mn, 4 * i);
        else if (s[i] == 'C' || s[i] == 'c') mn = min(mn, 2 + 4 * i);
        else if (s[i] == 'D' || s[i] == 'd') mn = min(mn, 4 * i);
        else if (s[i] == 'E' || s[i] == 'e') mn = min(mn, 1 + 4 * i);
        else if (s[i] == 'F' || s[i] == 'f') mn = min(mn, 4 * i);
        else
        {
            int t = s[i] - '0';
            if (t == 0) continue;
            int cnt = 0;
            while (t % 2 == 0)
            {
                cnt++;
                t /= 2;
            }
            mn = min(mn, cnt + 4 * i);
        }
    }
    if (mn >= x) cout << "YES\n";
    else cout << "NO\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}