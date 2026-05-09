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
    return x * s;
}
// 快写
void write(i128 x)
{
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
    ll k;
    cin >> n >> k;
    vector<ll> len(n + 1);
    vector<vector<int>> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int l;
        cin >> l;
        len[i] = l;
        for (int j = 1; j <= l; j++)
        {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }
    vector<ll> c(n + 1);
    for (int i = 1; i <= n; i++) cin >> c[i];
    vector<ll> p(n + 1);
    ll sum = 0;
    int t = -1;
    for (int i = 1; i <= n; i++)
    {
        // sum+=len[i]*c[i];
        if (sum + len[i] * c[i] >= k)
        {
            t = i;
            break;
        }
        sum += len[i] * c[i];
    }
    // cout<<t<<'\n';
    k -= sum;
    cout << a[t][k % len[t] == 0 ? len[t] - 1 : k % len[t] - 1] << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}
