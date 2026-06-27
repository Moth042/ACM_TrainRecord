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
    cin >> n;
    vector<ll> a(n + 1), b(n + 1);
    ll mxa = -1e18, mxb = -1e18, mna = 1e18, mnb = 1e18;
    int mxaidx = 0, mxbidx = 0, mnaidx = 0, mnbidx = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > mxa)
        {
            mxa = a[i];
            mxaidx = i;
        }
        if (a[i] < mna)
        {
            mna = a[i];
            mnaidx = i;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        if (b[i] > mxb)
        {
            mxb = b[i];
            mxbidx = i;
        }
        if (b[i] < mnb)
        {
            mnb = b[i];
            mnbidx = i;
        }
    }
    int cntmna = 0, cntmnb = 0, cntmxa = 0, cntmxb = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == mxa) cntmxa++;
        if (a[i] == mna) cntmna++;
        if (b[i] == mxb) cntmxb++;
        if (b[i] == mnb) cntmnb++;
    }

    ll ans = -1;
    if (mxa >= mxb && mna <= mnb)
    {
        ans = 0;
        for (int i = 1; i <= n; i++) ans += abs(a[i] - b[i]);
        if (cntmna == 1 && cntmnb == 1 && cntmxa == 1 && cntmxb == 1 && mxaidx == mnbidx && mnaidx == mxbidx && b[mxaidx] < b[mnaidx])
        {
            if (n == 2)
            {
                cout << -1 << '\n';
                return;
            }
            ll mn = 1e18;
            for (int i = 1; i <= n; i++)
            {
                if (a[i] != mxa && a[i] != mna)
                {
                    ll cur = abs(a[i] - mnb) + abs(mnb - b[i]) - abs(a[i] - b[i]);
                    mn = min(mn, cur);
                    cur = abs(a[i] - mxb) + abs(mxb - b[i]) - abs(a[i] - b[i]);
                    mn = min(mn, cur);
                }
            }
            ans += mn;
        }
    }
    else ans = -1;
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}