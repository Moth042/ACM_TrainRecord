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
    vector<int> a(n + 1), b(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) p[a[i]] = b[i];
    int c = 0;
    vector<int> vis(n + 1);
    auto dfs = [&](auto &&self, int idx) -> void
    {
        if (vis[idx])
        {
            c++;
            return;
        }
        vis[idx] = 1;
        self(self, p[idx]);
    };
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i]) dfs(dfs, i);
    }
    c = n - c;
    int num = c % 2;
    if (num) cout << "A";
    else cout << "B";
    for (int i = 1; i < n; i++)
    {
        char c;
        ll d, l, r;
        cin >> c >> l >> r >> d;
        num ^= ((r - l) * d % 2);
        if (num) cout << "A";
        else cout << "B";
    }
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