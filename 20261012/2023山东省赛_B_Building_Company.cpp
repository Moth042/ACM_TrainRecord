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
    int m, k;
    vector<pair<ll, ll>> x, y;
};
void moth()
{
    int g;
    cin >> g;
    map<ll, ll> mp;
    for (int i = 1; i <= g; i++)
    {
        ll t, u;
        cin >> t >> u;
        mp[t] += u;
    }
    int n;
    cin >> n;
    vector<Node> a(n + 1);
    queue<int> q;
    vector<int> deg(n + 1);
    map<ll, priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>>> mpq;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].m;
        a[i].x.assign(a[i].m + 1, {0, 0});
        bool ok = 1;
        for (int j = 1; j <= a[i].m; j++)
        {
            cin >> a[i].x[j].first >> a[i].x[j].second;
            if (!mp.count(a[i].x[j].first) || mp[a[i].x[j].first] < a[i].x[j].second)
            {
                deg[i]++;
                mpq[a[i].x[j].first].push({a[i].x[j].second, i});
                ok = 0;
            }
        }
        if (ok) q.push(i);
        cin >> a[i].k;
        a[i].y.assign(a[i].k + 1, {0, 0});
        for (int j = 1; j <= a[i].k; j++) cin >> a[i].y[j].first >> a[i].y[j].second;
    }
    int ans = 0;
    while (q.size())
    {
        int idx = q.front();
        q.pop();
        ans++;
        for (int i = 1; i <= a[idx].k; i++)
        {
            mp[a[idx].y[i].first] += a[idx].y[i].second;
            if (mpq.count(a[idx].y[i].first))
            {
                while (mpq[a[idx].y[i].first].size())
                {
                    auto [need, st] = mpq[a[idx].y[i].first].top();
                    if (need <= mp[a[idx].y[i].first])
                    {
                        mpq[a[idx].y[i].first].pop();
                        deg[st]--;
                        if (deg[st] == 0) q.push(st);
                    }
                    else break;
                }
            }
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}