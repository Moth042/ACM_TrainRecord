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
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    unordered_map<ll, unordered_map<ll, ll>> mp;
    vector<ll> st;
    for (int i = 1; i <= n; i++)
    {
        ll x = a[i];
        int t = 0;
        if (mp.count(x)) continue;
        while (x != 1)
        {
            st.push_back(x);
            mp[a[i]][x] = t;
            t++;
            if (x % 2) x++;
            else x /= 2;
        }
        st.push_back(1);
        mp[a[i]][1] = t;
        if (!mp[a[i]].count(2)) mp[a[i]][2] = t + 1, st.push_back(2);
    }
    sort(st.begin(), st.end());
    st.erase(unique(st.begin(), st.end()), st.end());
    // for(auto i:st)
    // {
    //     cout<<i<<' ';
    // }
    // cout<<'\n';
    ll ans = 1e18;
    bool ok = 1;
    ll ss = -1;
    for (auto i : st)
    {
        ll cur = i;
        ll sum = 0;
        ok = 1;
        for (int j = 1; j <= n; j++)
        {
            if (!mp[a[j]].count(cur))
            {
                ok = 0;
                break;
            }
            // cout << a[j] << ' ' << cur << ' ' << mp[a[j]][cur] << '\n';
            sum += mp[a[j]][cur];
            if (sum > 60 * n)
            {
                ans = min(ans, sum);
                ok = 0;
                break;
            }
        }
        if (!ok) continue;
        if (sum < ans)
        {
            ans = min(ans, sum);
            ss = cur;
        }
    }
    // cout << ss << ' ' << ans << '\n';
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