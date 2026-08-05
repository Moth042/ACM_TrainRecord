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
    vector<ll> z;
    multiset<ll> fz;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        if (x > 0) z.push_back(x);
        else fz.insert(x);
    }
    sort(z.begin(), z.end());
    ll pre = 0;
    vector<ll> ans;
    int sz = z.size();
    int idx = 0;
    while (idx < sz && fz.size())
    {
        auto it = fz.upper_bound(-pre);
        if (it == fz.end()) pre += z[idx++];
        else
        {
            pre += *it;
            fz.erase(it);
        }
        ans.push_back(pre);
    }
    while (idx < sz)
    {
        pre += z[idx];
        idx++;
        ans.push_back(pre);
    }
    while (fz.size())
    {
        auto it = fz.upper_bound(-pre);
        if (it == fz.end())
        {
            cout << -1 << '\n';
            return;
        }
        pre += *it;
        fz.erase(it);
        ans.push_back(pre);
    }
    for (auto i : ans) cout << i << " ";
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