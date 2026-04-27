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
    ll n, m;
    cin >> n >> m;
    if (n == 1)
    {
        cout << "NO\n";
        return;
    }
    if (m == 1)
    {
        if (n != 2) cout << "NO\n";
        else cout << 1 << ' ' << 2 << '\n';
        return;
    }
    if (m == 2)
    {
        if (n != 4) cout << "NO\n";
        else
        {
            cout << 1 << ' ' << 2 << '\n';
            cout << 1 << ' ' << 3 << '\n';
            cout << 3 << ' ' << 4 << '\n';
        }
        return;
    }
    if (n < 2 * m || n > m * (m + 1) / 2 + 1)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<int> ceil(m + 1, 2);
    ll sum = 2 * m;
    for (int i = 3; i <= m; i++)
    {
        if (sum == n) break;
        if (sum + i - 2 <= n)
        {
            // cout<<1<<'\n';
            ceil[i] = i;
            sum += (i - 2);
        }
        else
        {
            // cout<<i<<' '<<2<<'\n';
            ceil[i] += (n - sum);
            sum = n;
        }
    }
    // for(int i=1;i<=m;i++)cout<<ceil[i]<<' ';
    vector<vector<int>> dot(m + 2);
    dot[1].push_back(1);
    dot[2].push_back(2);
    dot[2].push_back(3);
    dot[3].push_back(4);
    cout << 1 << ' ' << 2 << '\n';
    cout << 1 << ' ' << 3 << '\n';
    cout << 3 << ' ' << 4 << '\n';
    int cnt = 5;
    for (int i = 3; i <= m; i++)
    {
        int t = ceil[i] - 2;
        cout << cnt << ' ' << dot[i - 1 - t].back() << '\n';
        dot[i - t].push_back(cnt);
        cnt++;
        for (int j = 1; j <= ceil[i] - 1; j++)
        {
            cout << cnt << ' ' << cnt - 1 << '\n';
            dot[i - t + j].push_back(cnt);
            cnt++;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}