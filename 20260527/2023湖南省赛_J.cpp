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
struct Node
{
    double pos;
    int t;
};
void moth()
{
    int n;
    cin >> n;
    vector<int> x(n + 1), y(n + 1), z(n + 1);
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i] >> z[i];
    auto check = [&](double r) -> bool
    {
        vector<Node> v;
        for (int i = 1; i <= n; i++)
        {
            double res = r * r - y[i] * y[i] - z[i] * z[i];
            if (res < 0) continue;
            res = sqrt(res);
            v.push_back({x[i] - res, 1});
            v.push_back({x[i] + res, -1});
        }
        sort(v.begin(), v.end(), [&](Node &i, Node &j) { return i.pos < j.pos; });
        int sum = 0;
        for (auto [x, y] : v)
        {
            sum += y;
            if (sum >= n / 2) return true;
        }
        v.clear();
        for (int i = 1; i <= n; i++)
        {
            double res = r * r - x[i] * x[i] - z[i] * z[i];
            if (res < 0) continue;
            res = sqrt(res);
            v.push_back({y[i] - res, 1});
            v.push_back({y[i] + res, -1});
        }
        sort(v.begin(), v.end(), [&](Node &i, Node &j) { return i.pos < j.pos; });
        sum = 0;
        for (auto [x, y] : v)
        {
            sum += y;
            if (sum >= n / 2) return true;
        }
        v.clear();
        for (int i = 1; i <= n; i++)
        {
            double res = r * r - y[i] * y[i] - x[i] * x[i];
            if (res < 0) continue;
            res = sqrt(res);
            v.push_back({z[i] - res, 1});
            v.push_back({z[i] + res, -1});
        }
        sort(v.begin(), v.end(), [&](Node &i, Node &j) { return i.pos < j.pos; });
        sum = 0;
        for (auto [x, y] : v)
        {
            sum += y;
            if (sum >= n / 2) return true;
        }
        return false;
    };
    double l = 0, r = 1e6 + 10;
    for (int i = 0; i <= 50; i++)
    {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << l << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cout << fixed << setprecision(10);
    // cin >> _;
    while (_--) moth();
    return 0;
}
