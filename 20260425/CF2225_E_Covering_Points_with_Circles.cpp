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
    int n, r;
    cin >> n >> r;
    vector<pair<int, int>> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i].first >> p[i].second;
    auto incircle = [&](int x, int y, int ox, int oy, int r) -> bool
    { return (x - ox) * (x - ox) + (y - oy) * (y - oy) <= r * r; };
    int cov = 0;
    vector<pair<int, int>> ans;
    int l = 2 * r, h = ceil(sqrt(3) * r);
    do
    {
        cov = 0;
        ans.clear();
        int x0 = randint(0, 100000), y0 = randint(0, 100000);
        auto check = [&](int x, int y) -> void
        {
            int nr = (y - y0) / h;
            for (int row = nr - 2; row <= nr + 2; row++)
            {
                int nc = (x - x0 - (row % 2) * r) / l;
                for (int col = nc - 2; col <= nc + 2; col++)
                {
                    int ox = x0 + col * l + (row % 2) * r;
                    int oy = y0 + row * h;
                    if (incircle(x, y, ox, oy, r))
                    {
                        cov++;
                        ans.push_back({ox, oy});
                        return;
                    }
                }
            }
        };
        for (int i = 1; i <= n; i++)
        {
            int x = p[i].first, y = p[i].second;
            check(x, y);
        }
    } while (cov * 100 < n * 89);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << '\n';
    for (auto [x, y] : ans) cout << x << " " << y << "\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}