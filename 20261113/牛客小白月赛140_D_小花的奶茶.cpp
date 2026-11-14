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
    vector<ll> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
    // for (int i = 1; i <= n; i++) cin >> b[i];
    // for (int i = 1; i <= n; i++) cin >> c[i];
    vector<int> ord(n + 1);
    iota(ord.begin() + 1, ord.end(), 1);
    sort(ord.begin() + 1, ord.end(), [&](int &x, int &y) { return a[x] < a[y]; });
    // for (int i = 1; i <= n; i++) cout << ord[i] << " ";
    // cout << '\n';
    vector<priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>>> pq(10); // idx ,time
    vector<ll> mx(10), ans(n + 1);
    ll T = 0;
    for (int i = 1; i <= n; i++)
    {
        T = max(T, a[ord[i]]) + c[ord[i]];
        // cout << T << '\n';
        for (int j = 0; j < 10; j++)
        {
            while (pq[j % 10].size() && T >= b[ord[pq[j % 10].top().first]])
            {
                ans[ord[pq[j % 10].top().first]] = max(mx[j % 10], b[ord[pq[j % 10].top().first]]);
                ans[ord[pq[j % 10].top().first]] = max(ans[ord[pq[j % 10].top().first]], pq[j % 10].top().second);
                mx[j % 10] = max(mx[j % 10], ans[ord[pq[j % 10].top().first]]);
                pq[j % 10].pop();
            }
        }
        pq[i % 10].push({i, T});
        while (pq[i % 10].size() && T >= b[ord[pq[i % 10].top().first]])
        {
            ans[ord[pq[i % 10].top().first]] = max(mx[i % 10], b[ord[pq[i % 10].top().first]]);
            ans[ord[pq[i % 10].top().first]] = max(ans[ord[pq[i % 10].top().first]], pq[i % 10].top().second);
            mx[i % 10] = max(mx[i % 10], ans[ord[pq[i % 10].top().first]]);
            pq[i % 10].pop();
        }
    }
    for (int i = 0; i < 10; i++)
    {
        while (pq[i % 10].size())
        {
            ans[ord[pq[i % 10].top().first]] = max(mx[i % 10], b[ord[pq[i % 10].top().first]]);
            ans[ord[pq[i % 10].top().first]] = max(ans[ord[pq[i % 10].top().first]], pq[i % 10].top().second);
            mx[i % 10] = max(mx[i % 10], ans[ord[pq[i % 10].top().first]]);
            pq[i % 10].pop();
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] - b[i] << " ";
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}