#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lll = __int128;
const int N = 1e5 + 9;
const int mod = 1e9 + 7;
const int MOD = 998244353;
int dx[] = {-1, 0, 1, 0}; // 上右下左
int dy[] = {0, 1, 0, -1};
int ddx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int ddy[] = {0, 1, 1, 1, 0, -1, -1, -1};
// 快读
inline lll read()
{
    char c = getchar();
    lll x = 0, s = 1;
    while (c < '0' || c > '9')
    {
        if (c == '-')
            s = -1;
        c = getchar();
    }
    return x * s;
}
// 快写
void write(lll x)
{
    if (x > 9)
        write(x / 10);
    putchar(x % 10 | 48);
}
void moth()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }
    sort(p.begin() + 1, p.end() - 1);
    ll x = 0;
    for (int i = 1; i <= n; i++)
    {
        cout << p[n] * i - x << " ";
        x += p[i];
    }
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--)
        moth();
    return 0;
}