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
    vector<ll> a(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i], p[i] = p[i - 1] + a[i];
    // ll cur = -1e16, cur2 = cur;
    // vector<ll> v;
    // for (int i = 1; i <= n; i++)
    // {
    //     if (cur + a[i] < a[i])
    //     {
    //         // if(cur!=-1e16)v.push_back(cur);
    //         v.push_back(cur + a[i]);
    //         cur = a[i];
    //         cur2 += a[i];
    //     }
    //     else
    //     {
    //         cur += a[i];
    //         cur2 = a[i];
    //         v.push_back(cur2+a[i]);
    //     }

    //     v.push_back(cur);
    //     v.push_back(cur2);
    // }
    // // sort(v.begin(), v.end());
    // // v.erase(unique(v.begin(), v.end()), v.end());
    // // cout << v[v.size() - 2] << '\n';
    // for (auto i : v) cout << i << ' ';
    set<ll> s;
    vector<ll> v;
    s.insert(0);
    for (int i = 1; i <= n; i++)
    {

        auto it = s.begin();
        // if (*it == p[i]) it++;
        ll mn = -1e18;
        ll nmn = -1e18;
        if (it != s.end()) mn = *it;
        if (it != s.end()) it++;
        if (it != s.end()) nmn = *it;
        if (mn == -1e18) v.push_back(0);
        else v.push_back(p[i] - mn);
        if (nmn != -1e18) v.push_back(p[i] - nmn);
        else v.push_back(p[i]);
        s.insert(p[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << v[v.size() - 2] << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}