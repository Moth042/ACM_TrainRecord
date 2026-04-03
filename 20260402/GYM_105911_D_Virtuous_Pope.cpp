#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PLL = pair<ll, ll>;
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
        if (c == '-')
            s = -1;
        c = getchar();
    }
    return x * s;
}
// 快写
void write(i128 x)
{
    if (x > 9)
        write(x / 10);
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
    ll a, b, c;
    cin >> n >> a >> b >> c;
    vector<PLL> x(n + 1), y(n + 1), z(n + 1);
    vector<ll> px, py, pz;
    for (int i = 1; i <= n; i++)
    {
        ll x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        px.push_back(x1);
        px.push_back(x2);
        py.push_back(y1);
        py.push_back(y2);
        pz.push_back(z1);
        pz.push_back(z2);
        if (x1 > x2)
            swap(x1, x2);
        x[i] = {x1, x2};
        if (y1 > y2)
            swap(y1, y2);
        y[i] = {y1, y2};
        if (z1 > z2)
            swap(z1, z2);
        z[i] = {z1, z2};
    }
    sort(px.begin(), px.end());
    px.erase(unique(px.begin(), px.end()), px.end());
    sort(py.begin(), py.end());
    py.erase(unique(py.begin(), py.end()), py.end());
    sort(pz.begin(), pz.end());
    pz.erase(unique(pz.begin(), pz.end()), pz.end());
    vector<ll> dfx(px.size() + 2), dfy(py.size() + 2), dfz(pz.size() + 2);
    for (int i = 1; i <= n; i++)
    {
        int l = lower_bound(px.begin(), px.end(), x[i].first) - px.begin() + 1;
        int r = lower_bound(px.begin(), px.end(), x[i].second) - px.begin() + 1;
        dfx[l]++;
        dfx[r + 1]--;
        l = lower_bound(py.begin(), py.end(), y[i].first) - py.begin() + 1;
        r = lower_bound(py.begin(), py.end(), y[i].second) - py.begin() + 1;
        dfy[l]++;
        dfy[r + 1]--;
        l = lower_bound(pz.begin(), pz.end(), z[i].first) - pz.begin() + 1;
        r = lower_bound(pz.begin(), pz.end(), z[i].second) - pz.begin() + 1;
        dfz[l]++;
        dfz[r + 1]--;
    }
    ll ans = 0;
    for (int i = 1; i <= px.size(); i++)
    {
        dfx[i] += dfx[i - 1];
        ans = max(ans, dfx[i]);
    }
    for (int i = 1; i <= py.size(); i++)
    {
        dfy[i] += dfy[i - 1];
        ans = max(ans, dfy[i]);
    }
    for (int i = 1; i <= pz.size(); i++)
    {
        dfz[i] += dfz[i - 1];
        ans = max(ans, dfz[i]);
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--)
        moth();
    return 0;
}