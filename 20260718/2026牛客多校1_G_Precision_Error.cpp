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
vector<pair<double, double>> dot;
double len = 0.0101;
void moth()
{
    int n;
    cin >> n;
    cout << 2 * n << '\n';
    for (int i = 0; i < n; i++)
    {
        cout << len * dot[i].first << ' ' << len * dot[i].second << ' ' << 0 << '\n';
        cout << len * dot[i].first << ' ' << len * dot[i].second << ' ' << 1 << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for (int i = -10; i <= 10; i++)
    {
        for (int j = -10; j <= 10; j++)
        {
            double x = i + 0.5 * j, y = j * 0.5 * sqrt(3);
            if (x * x + y * y < 30) dot.push_back({x, y});
        }
    }
    cout << fixed << setprecision(10);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}