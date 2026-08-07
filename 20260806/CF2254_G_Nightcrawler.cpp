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
    vector<ll> a(n + 1), ans(n + 1, -1);
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) cin >> p[i];
    vector<ll> wt;
    vector<priority_queue<ll, vector<ll>, greater<ll>>> pq(n + 1);
    for (int i = n; i >= 1; i--)
    {
        if (pq[i].empty()) pq[i].push(a[i]);
        else
        {
            ll x = pq[i].top();
            pq[i].pop();
            wt.push_back(min(x, a[i]));
            pq[i].push(max(x, a[i]));
        }
        if (i > 1)
        {
            int fa = p[i];
            if (pq[fa].size() < pq[i].size()) swap(pq[fa], pq[i]);
            while (pq[i].size())
            {
                pq[fa].push(pq[i].top());
                pq[i].pop();
            }
        }
    }
    int l = pq[1].size();
    ans[l] = 0;
    while (pq[1].size())
    {
        ans[l] += pq[1].top();
        pq[1].pop();
    }
    sort(wt.begin(), wt.end(), greater());
    for (int i = l + 1; i <= n; i++) ans[i] = ans[i - 1] + wt[i - (l + 1)];
    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}