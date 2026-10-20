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
    map<ll, priority_queue<ll>> mp;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        mp[x].push(y);
    }
    ll ans = 0;
    bool ok = 1;
    int cnt = 0;
    int lst = -1;
    while (mp.size())
    {
        // cout << mp.size() << '\n';
        // int lst = -1;
        ll b = 1;
        for (auto it = mp.begin(); it != mp.end();)
        {
            // cout << it->first << '\n';
            if (!ok)
            {
                if (it->first - lst == 1) b++;
                else b = 1;
            }
            else ok = 0;
            lst = it->first;
            auto &pq = it->second;
            if (pq.size())
            {
                ans += b * pq.top();
                pq.pop();
            }
            if (pq.empty()) it = mp.erase(it);
            else it++;
        }
        // cout << mp.size() << '\n';
        // cnt++;
        // return;
    }
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