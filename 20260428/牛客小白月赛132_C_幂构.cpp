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
vector<ll> ans;
void moth()
{
    ll l, r;
    cin >> l >> r;
    auto it1 = lower_bound(ans.begin(), ans.end(), l), it2 = upper_bound(ans.begin(), ans.end(), r);
    cout << it2 - it1 << '\n';
    // for(auto i:ans)cout<<i<<" ";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for (int i = 1; i <= 60; i++)
    {
        i128 t = (i128)1 << i;
        if (t <= 2e18) ans.push_back((ll)t);
    }
    for (int len = 2; len <= 60; len++)
    {
        for (int i = 2; i <= len; i++)
        {
            for (int j = 1; j < i; j++)
            {
                i128 t = ((i128)1 << (i - 1)) + ((i128)1 << (j - 1));
                if (t <= 2e18) ans.push_back((ll)t);
            }
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}