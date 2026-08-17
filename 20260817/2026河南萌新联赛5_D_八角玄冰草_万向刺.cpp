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
    int h, n, m;
    cin >> h >> n >> m;
    // vector<vector<vector<char>>>a(h+1,vector<vector<char>>(n+1,vector<char>(m+1)));
    int x, y, z;
    vector<array<int, 3>> t;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= m; k++)
            {
                char c;
                cin >> c;
                if (c == 'H')
                {
                    x = i;
                    y = j;
                    z = k;
                }
                else if (c == 'T') t.push_back({i, j, k});
            }
        }
    }
    map<array<int, 4>, int> mp;
    for (auto [i, j, k] : t)
    {
        int dx = i - x, dy = j - y, dz = k - z;
        int dt;
        if (dx) dt = dx / abs(dx);
        else if (dy) dt = dy / abs(dy);
        else if (dz) dt = dz / abs(dz);
        // cout << dx << ' ' << dy << ' ' << dz << '\n';
        int g = __gcd(abs(dx), __gcd(abs(dy), abs(dz)));
        dx /= g;
        dy /= g;
        dz /= g;

        // cout << dx << ' ' << dy << ' ' << dz << ' ' << dt << '\n';
        mp[{dx, dy, dz, dt}]++;
    }
    cout << mp.size() << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}