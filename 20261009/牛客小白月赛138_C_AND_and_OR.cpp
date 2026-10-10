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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    map<ll, vector<int>> mp;
    vector<vector<int>> wei(n, vector<int>(32));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]].push_back(i);
        for (int bit = 0; bit < 32; bit++) wei[i][bit] = ((a[i] >> bit) & 1);
    }
    vector<int> weik(32);
    for (int bit = 0; bit < 32; bit++) weik[bit] = ((k >> bit)) & 1;
    for (int i = 0; i < n; i++)
    {
        vector<int> d(32), ans(32);
        for (int bit = 0; bit < 32; bit++)
        {
            int x = wei[i][bit] + (bit >= 1 ? d[bit - 1] : 0), y = weik[bit];
            if (x == 2)
            {
                x = 0;
                d[bit] = 1;
            }
            if (x == y) ans[bit] = 0;
            else
            {
                if (x == 1)
                {
                    ans[bit] = 1;
                    d[bit] = 1;
                }
                else ans[bit] = 1;
            }
        }
        ll cur = 0;
        for (int bit = 0; bit < 32; bit++) cur += (1ll << bit) * ans[bit];
        // if (i == 0) cout << cur << '\n';
        if (cur == a[i])
        {
            if (mp[a[i]].size() >= 2)
            {
                for (auto v : mp[a[i]])
                {
                    if (v != i)
                    {
                        int ansx = v, ansy = i;
                        if (ansx > ansy) swap(ansx, ansy);
                        cout << ansx + 1 << ' ' << ansy + 1 << '\n';
                        return;
                    }
                }
            }
            else continue;
        }
        else
        {
            if (mp.count(cur))
            {
                int ansx = i, ansy = mp[cur][0];
                if (ansx > ansy) swap(ansx, ansy);
                cout << ansx + 1 << ' ' << ansy + 1 << '\n';
                return;
            }
            else continue;
        }
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