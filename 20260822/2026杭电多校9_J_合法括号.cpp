#include <bits/stdc++.h>
using namespace std;
#define int long long
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
    string s;
    cin >> s;
    s = " " + s;
    int L = 0, R = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] != '?') continue;
        if (L == 0) L = i;
        R = i;
    }
    if (L == 0)
    {
        cout << s << '\n';
        return;
    }
    // cout << L << ' ' << R << '\n';
    int l = 0, r = 0, h = 0;
    int sum = 0;
    for (int i = 1; i < L; i++)
    {
        if (s[i] == '(')
        {
            l++;
            h++;
        }
        else if (s[i] == ')')
        {
            r++;
            sum += h;
            h--;
        }
    }
    // cout << l << ' ' << r << ' ' << h << '\n';
    for (int i = R + 1; i <= n; i++)
    {
        if (s[i] == '(') l++;
        else if (s[i] == ')') r++;
    }
    int x = n / 2 - l, y = n / 2 - r;
    // cout << x << ' ' << y << '\n';
    ll hh = h + x - y;
    for (int i = R + 1; i <= n; i++)
    {
        if (s[i] == '(') hh++;
        else
        {
            sum += hh;
            hh--;
        }
    }
    // cout << sum << '\n';
    m -= sum;
    vector<int> a(y + 2);
    a[y + 1] = x;
    int ans = 0;
    for (int i = 1; i <= y; i++) a[i] = max(0ll, i - h), ans += h + a[i] - (i - 1);
    for (int i = y; i >= 1; i--)
    {
        if (ans < m)
        {
            int df = min(m - ans, x - a[i]);
            ans += df;
            a[i] += df;
        }
        else break;
    }
    for (int i = y + 1; i >= 1; i--) a[i] -= a[i - 1];
    // for (int i = 1; i <= y + 1; i++) cout << a[i] << " ";
    // cout << '\n';
    string ss;
    for (int i = 1; i <= y + 1; i++)
    {
        for (int j = 1; j <= a[i]; j++) ss += '(';
        if (i != y + 1) ss += ')';
    }
    // cout << ss << '\n';
    cout << s.substr(1, L - 1) << ss << s.substr(R + 1, n - R) << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}