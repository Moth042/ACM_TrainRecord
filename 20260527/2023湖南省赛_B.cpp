#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int N = 1e6 + 9;
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
int f[N];
void init()
{
    for (int i = 1; i < N; i++)
    {
        int t = sqrt(i);
        map<int, int> mp;
        if (t * t == i || t * t + 1 == i)
        {
            for (int j = 0; j < i; j += t) mp[f[j]] = 1;
            int mex = 0;
            for (auto [k, v] : mp)
            {
                if (k == mex) mex++;
            }
            f[i] = mex;
        }
        else f[i] = f[i - 1];
    }
}
void moth()
{
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        ans ^= f[x];
    }
    if (ans == 0) cout << "Second\n";
    else cout << "First\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}