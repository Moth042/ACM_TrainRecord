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
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<vector<ll>, int> mp;
    vector<ll> ans;
    ans.push_back(*max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end()));
    mp[a] = 0;
    vector<ll> cur;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++) cur.push_back(a[i] ^ a[j]);
    }
    // for (auto i : cur) cout << i << ' ';
    // cout << '\n';
    sort(cur.begin(), cur.end());
    vector<ll> b;
    for (int i = 0; i < n; i++) b.push_back(cur[i]);
    // for (int i = 0; i < n; i++) cout << b[i] << " ";
    // cout << '\n';
    if (a == b)
    {
        while (q--)
        {
            ll x;
            cin >> x;
            cout << *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end()) << '\n';
        }
        return;
    }
    int t = 1;
    while (!mp.count(b))
    {
        mp[b] = t++;
        ans.push_back(*max_element(b.begin(), b.end()) - *min_element(b.begin(), b.end()));
        cur.clear();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++) cur.push_back(b[i] ^ b[j]);
        }
        b.clear();
        sort(cur.begin(), cur.end());
        for (int i = 0; i < n; i++) b.push_back(cur[i]);
    }
    int len = t - mp[b];
    // cout << t << ' ' << mp[b] << ' ' << len << '\n';
    // cout << ans.size() << '\n';
    while (q--)
    {
        ll x;
        cin >> x;
        if (x < t) cout << ans[x] << '\n';
        else cout << ans[mp[b] + (x - t) % len] << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}