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
    vector<int> stk;
    vector<int> c(n, -1), d(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(') stk.push_back(i);
        else
        {
            if (stk.size())
            {
                d[i] = stk.back();
                c[i] = d[i];
                if (d[i] - 1 >= 0 && c[d[i] - 1] != -1) c[i] = c[d[i] - 1];
                stk.pop_back();
            }
        }
    }
    int mx = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ')' && c[i] != -1)
        {
            int cur = i - c[i] + 1;
            mx = max(mx, cur);
            mp[cur]++;
        }
    }
    if (mx == 0) cout << "0 1\n";
    else cout << mx << ' ' << mp[mx] << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}