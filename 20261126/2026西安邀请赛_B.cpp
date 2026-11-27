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
    ll n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    ll p = (x + y) / n, r = (x + y) % n;
    ll c0 = count(s.begin(), s.end(), '0'), c1 = count(s.begin(), s.end(), '1'), c2 = count(s.begin(), s.end(), '2');
    ll c01 = count(s.begin(), s.begin() + r, '0'), c11 = count(s.begin(), s.begin() + r, '1'), c21 = count(s.begin(), s.begin() + r, '2');
    for (ll i = c21; i >= 0; i--)
    {
        // cout << i << '\n';
        ll tx = i + c01, ty = r - tx;
        ll lx = tx * (p + 1), ly = ty * (p + 1);
        // cout << lx << ' ' << ly << '\n';
        if (lx > x || ly > y) continue;
        ll nx = x - lx, ny = y - ly;
        // if (nx == 0 && ny == 0)
        // {
        //     ll sum0 = i, sum1 = c21 - sum0;
        //     // cout << sum0 << ' ' << sum1 << '\n';
        //     for (int j = 0; j < n; j++)
        //     {
        //         if (s[j] == '1')
        //         {
        //             cout << s[j];
        //             // sum1--;
        //         }
        //         else if (s[j] == '0')
        //         {
        //             cout << s[j];
        //             // sum0--;
        //         }
        //         else
        //         {
        //             if (sum0)
        //             {
        //                 sum0--;
        //                 cout << '0';
        //             }
        //             else
        //             {
        //                 sum1--;
        //                 cout << '1';
        //             }
        //         }
        //     }
        //     cout << '\n';
        //     return;
        // }
        if (p == 0)
        {
            ll sum0 = i, sum1 = c21 - sum0;
            for (int j = 0; j < r; j++)
            {
                if (s[j] == '1') cout << '1';
                else if (s[j] == '0') cout << '0';
                else
                {
                    if (sum0)
                    {
                        cout << '0';
                        sum0--;
                    }
                    else
                    {
                        cout << '1';
                        sum1--;
                    }
                }
            }
            for (int j = r; j < n; j++)
            {
                if (s[j] == '1') cout << '1';
                else cout << '0';
            }
            cout << '\n';
            return;
        }
        if (nx % p || ny % p) continue;
        nx /= p, ny /= p;
        // cout << nx << ' ' << ny << '\n';
        ll c02 = c0 - c01, c12 = c1 - c11, c22 = c2 - c21;
        // cout << c02 << ' ' << c12 << ' ' << c22 << '\n';
        ll n0 = 0, n1 = 0;
        if (c22 < nx - (n0 + c02)) continue;
        ll df = max(0ll, nx - (n0 + c02));
        c22 -= df;
        n0 += df;
        // cout << n0 << '\n';
        if (c22 < ny - (n1 + c12)) continue;
        df = max(0ll, ny - (n1 + c12));
        c22 -= df;
        n1 += df;
        // cout << n1 << '\n';
        ll sum0p = i, sum0s = n0, sum1p = c21 - i, sum1s = n1;
        for (int j = 0; j < r; j++)
        {
            if (s[j] == '1')
            {
                cout << s[j];
                // sum1--;
            }
            else if (s[j] == '0')
            {
                cout << s[j];
                // sum0--;
            }
            else
            {
                if (sum0p)
                {
                    sum0p--;
                    cout << '0';
                }
                else
                {
                    sum1p--;
                    cout << '1';
                }
            }
        }
        for (int j = r; j < n; j++)
        {
            if (s[j] == '1')
            {
                cout << s[j];
                // sum1--;
            }
            else if (s[j] == '0')
            {
                cout << s[j];
                // sum0--;
            }
            else
            {
                if (sum0s)
                {
                    sum0s--;
                    cout << '0';
                }
                else
                {
                    sum1s--;
                    cout << '1';
                }
            }
        }
        cout << '\n';
        return;
    }
    cout << -1 << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}