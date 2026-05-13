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
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> a(m + 1);
    for (int i = 1; i <= m; i++) cin >> a[i].first >> a[i].second;
    a[0] = {0, 0};
    sort(a.begin() + 1, a.end());
    map<ll, ll> mp;
    ll cur = 0;
    for (int i = 1; i <= m; i++)
    {
        if (mp.count(a[i].first) && mp[a[i].first] != a[i].second)
        {
            // cout<<i<<' '<<1<<'\n';
            cout << "No\n";
            return;
        }
        // cout<<a[i].second<<' '<<cur<<'\n';
        if (a[i].second > cur)
        {
            ll t = a[i].first - a[i - 1].first;
            // if(i == 2)cout<<t<<' '<<1+a[i].second<<'\n';
            if (t == a[i].second - cur)
            {
                cur = a[i].second;
                // cout<<cur<<'\n';
                mp[a[i].first] = a[i].second;
                continue;
            }
            if (t < a[i].second - cur)
            {
                // cout << i << ' ' << 2 << '\n';
                cout << "No\n";
                return;
            }
            if (t < 1 + a[i].second)
            {
                // cout<<1<<'\n';
                // cout << i << ' ' << 3 << '\n';
                cout << "No\n";
                return;
            }
        }
        else if (a[i].second == cur)
        {
            if (a[i].first != a[i - 1].first)
            {
                ll t = a[i].first - a[i - 1].first;
                if (t < cur + 1)
                {
                    // cout << i << ' ' << 4 << '\n';
                    cout << "No\n";
                    return;
                }
            }
        }
        else
        {
            ll t = a[i].first - a[i - 1].first;
            if (t < 1 + a[i].second)
            {
                // cout << i << ' ' << 5 << '\n';
                cout << "No\n";
                return;
            }
        }
        cur = a[i].second;
        // cout<<cur<<'\n';
        mp[a[i].first] = a[i].second;
    }
    cout << "Yes\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}