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
    vector<int> a(n * 2 + 1);
    vector<pair<int, int>> pos(n, {-1, -1});
    for (int i = 1; i <= n * 2; i++)
    {
        cin >> a[i];
        if (pos[a[i]].first == -1) pos[a[i]].first = i;
        else pos[a[i]].second = i;
    }
    vector<int> vis(n + 1);
    vis[0] = 1;
    int l = pos[0].first, r = pos[0].second;
    int L = l, R = r;
    bool ok = 1;
    int ans = 1;
    while (l <= r)
    {
        // cout<<a[l]<<' '<<a[r]<<'\n';
        if (a[l] == a[r])
        {

            vis[a[l]] = 1;
            l++;
            r--;
        }
        else
        {
            ok = 0;

            for (int i = 0; i <= n; i++) vis[i] = 0;
            break;
        }
    }
    // for(int i=0;i<=n;i++)cout<<vis[i]<<" \n"[i==n];
    // cout<<ok<<'\n';
    // cout<<l<<' '<<r<<'\n';
    if (!ok)
        for (int i = 0; i <= n; i++) vis[i] = 0;
    if (ok)
    {
        // cout<<L<<' '<<R<<'\n';
        while (L >= 1 && R <= n * 2)
        {
            // cout<<1<<'\n';
            if (a[L] == a[R])
            {
                vis[a[L]] = 1;
                // cout << a[L] << ' ' << a[R] << ' ' << L << ' ' << R << '\n';
                L--;
                R++;
            }
            else
            {

                break;
            }
        }
        for (int i = 0; i <= n; i++)
        {
            if (!vis[i])
            {
                ans = max(ans, i);
                break;
            }
        }
        // cout<<ans<<'\n';
    }
    // cout<<ans<<'\n';
    l = r = pos[0].first;

    for (int i = 0; i <= n; i++) vis[i] = 0;
    // for(int i=0;i<=n;i++)cout<<vis[i]<<" ";
    while (l >= 1 && r <= n * 2)
    {
        // cout<<a[l]<<a[r]<<'\n';
        if (a[l] == a[r])
        {
            vis[a[l]] = 1;
            l--;
            r++;
        }
        else break;
    }
    // cout << l << ' ' << r << '\n';
    for (int i = 0; i < n + 1; i++)
    {
        // cout << vis[i] << ' ';
        if (!vis[i])
        {
            ans = max(ans, i);
            break;
        }
    }
    // cout<<ans<<'\n';
    l = r = pos[0].second;
    for (int i = 0; i <= n; i++) vis[i] = 0;
    while (l >= 1 && r <= n * 2)
    {
        if (a[l] == a[r])
        {
            vis[a[l]] = 1;
            l--;
            r++;
        }
        else break;
    }
    for (int i = 0; i < n + 1; i++)
    {
        if (!vis[i])
        {
            ans = max(ans, i);
            break;
        }
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