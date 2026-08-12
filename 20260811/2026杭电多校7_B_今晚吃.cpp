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
    auto get = [&](string s) -> int
    {
        int res = 0;
        for (int i = 0; i < s.length() - 1; i++)
        {
            int a = s[i] - '0', b = s[i + 1] - '0';
            int cur = 2 * a + b;
            res |= (1 << cur);
        }
        return res;
    };
    int ans = get(s);
    auto check = [&](string s, string sub) -> bool
    {
        int j = 0;
        for (auto i : s)
        {
            if (j < sub.length() && i == sub[j]) ++j;
        }
        return j == sub.length();
    };
    for (int len = 2; len <= 6; len++)
    {
        for (int i = 0; i < (1 << len); i++)
        {
            string sub;
            for (int j = 0; j < len; j++)
            {
                if ((i >> j) & 1) sub += '1';
                else sub += '0';
            }
            if (get(sub) == ans && check(s, sub))
            {
                cout << len << '\n';
                return;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}