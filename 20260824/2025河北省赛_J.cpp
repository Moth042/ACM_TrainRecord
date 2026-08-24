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
    int n = s.length();
    if (count(s.begin(), s.end(), '0') != count(s.begin(), s.end(), '1'))
    {
        cout << -1 << '\n';
        return;
    }
    vector<int> stk, to(n);
    for (int i = 0; i < n; i++)
    {
        if (stk.size() && s[stk.back()] != s[i])
        {
            to[stk.back()] = i;
            stk.pop_back();
        }
        else stk.push_back(i);
    }
    int cur = 1;
    cout << n / 2 << '\n';
    for (int i = 0; i < n; i++)
    {
        if (to[i]) cout << cur << ' ' << (s[i] == '0' ? 1 : 2) << '\n';
        else cur++;
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