#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int N = 2e5 + 9;
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
struct Q
{
    int id, k;
    bool operator<(const Q &x) const
    {
        return k > x.k;
    }
};
struct Node
{
    int num, cnt;
    bool operator<(const Node &v) const
    {
        return cnt == v.cnt ? num > v.num : cnt > v.cnt;
    }
};
ll f[N], g[N];
ll ksm(ll a, ll b, ll c)
{
    ll res = 1;
    while (b)
    {
        if (b & 1) res = res * a % c;
        a = a * a % c;
        b >>= 1;
    }
    return res;
}
void init()
{
    f[0] = g[0] = 1;
    for (int i = 1; i < N; i++)
    {
        f[i] = f[i - 1] * i % mod;
        g[i] = g[i - 1] * ksm(i, mod - 2, mod) % mod;
    }
}
ll C(ll n, ll m)
{
    if (n < m) return 0;
    if (n < 0 || m < 0) return 0;
    return f[n] * g[m] % mod * g[n - m] % mod;
}
void moth()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    map<int, int> mp;
    auto cal = [&]() -> void
    {
        for (int i = 1; i <= n; i++)
        {
            int cur = a[i];
            for (int j = 1; j * j <= cur; j++)
            {
                if (cur % j == 0)
                {
                    mp[j]++;
                    if (cur / j != j) mp[cur / j]++;
                }
            }
        }
    };
    cal();
    int q;
    cin >> q;
    vector<Q> qa(q + 1);
    for (int i = 1; i <= q; i++)
    {
        cin >> qa[i].k;
        qa[i].id = i;
    }
    sort(qa.begin() + 1, qa.end());
    set<Node> st;
    for (auto [k, v] : mp) st.insert({k, v});
    vector<int> ans(q + 1);
    int mx = 0;
    for (int i = 1; i <= q; i++)
    {
        auto [id, k] = qa[i];
        while (st.size() && st.begin()->cnt >= k)
        {
            mx = max(mx, st.begin()->num);
            st.erase(st.begin());
        }
        ans[id] = C(mp[mx], k);
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}