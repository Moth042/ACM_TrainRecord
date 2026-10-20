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
    string s;
    cin >> s;
    s = " " + s;
    vector<int> c;
    c.push_back(0);
    int cur = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '(') cur++;
        else
        {
            c.push_back(cur);
            cur = 0;
        }
    }
    ll mx = 0, sum = 0;
    int m = n / 2;
    for (int i = 1; i <= m; i++)
    {
        sum += 1ll * c[i];
        if (i - 1 <= k) mx = max(mx, min(1ll * m, sum + k - (i - 1)));
    }
    vector<ll> p(m + 1);
    for (int i = 1; i <= m; i++) p[i] = p[i - 1] + (c[i] - 1);
    deque<int> dq;
    for (int r = 1; r <= m; r++)
    {
        int l = r - 1;
        while (dq.size() && p[l] <= p[dq.back()]) dq.pop_back();
        dq.push_back(l);
        while (dq.size() && dq.front() < r - (k + 1)) dq.pop_front();
        mx = max(mx, min(1ll * m, p[r] - p[dq.front()] + 1));
    }
    cout << mx << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}