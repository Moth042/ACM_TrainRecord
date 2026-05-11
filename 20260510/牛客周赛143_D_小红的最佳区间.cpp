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
struct Node
{
    ll x, y;
    bool operator<(const Node &v) const
    {
        return y > v.y;
    }
};
void moth()
{
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> a(n + 1);
    vector<ll> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
        v.push_back(a[i].first);
        v.push_back(a[i].second);
    }
    sort(a.begin() + 1, a.end());
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    ll mx = 0;
    // deque<pair<ll, ll>> q;
    priority_queue<Node> q;
    int idx = 1;
    for (auto i : v)
    {
        while (idx <= n && a[idx].first <= i + k) q.push({a[idx].first, a[idx].second}), idx++;
        while (q.size() && q.top().y < i) q.pop();
        // cout<<i<<":\n";
        // for(auto [x,y]:q)
        // {
        //     cout<<x<<' '<<y<<'\n';
        // }
        mx = max(mx, (ll)q.size());
    }
    cout << mx << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}