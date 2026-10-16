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
template <class T> struct Point
{
    T x;
    T y;
    Point(const T &x_ = 0, const T &y_ = 0) : x(x_), y(y_)
    {
    }

    // 允许从 Point<U> 隐式转换为 Point<T>，例如 Point<int> -> Point<double>
    template <class U> operator Point<U>()
    {
        return Point<U>(U(x), U(y));
    }
    Point &operator+=(const Point &p) &
    {
        x += p.x;
        y += p.y;
        return *this;
    }
    Point &operator-=(const Point &p) &
    {
        x -= p.x;
        y -= p.y;
        return *this;
    }
    Point &operator*=(const T &v) &
    {
        x *= v;
        y *= v;
        return *this;
    }
    Point &operator/=(const T &v) &
    {
        x /= v;
        y /= v;
        return *this;
    }
    // 取负：向量反向
    Point operator-() const
    {
        return Point(-x, -y);
    }
    friend Point operator+(Point a, const Point &b)
    {
        return a += b;
    }
    friend Point operator-(Point a, const Point &b)
    {
        return a -= b;
    }
    friend Point operator*(Point a, const T &b)
    {
        return a *= b;
    }
    friend Point operator/(Point a, const T &b)
    {
        return a /= b;
    }
    friend Point operator*(const T &a, Point b)
    {
        return b *= a;
    }
    friend bool operator==(const Point &a, const Point &b)
    {
        return a.x == b.x && a.y == b.y;
    }
    friend std::istream &operator>>(std::istream &is, Point &p)
    {
        return is >> p.x >> p.y;
    }
    friend std::ostream &operator<<(std::ostream &os, const Point &p)
    {
        return os << "(" << p.x << ", " << p.y << ")";
    }
};

void moth()
{
    int n, s;
    cin >> n >> s;
    vector<Point<ll>> P(n + 1), Q(n + 1);
    for (int i = 1; i <= n; i++) cin >> P[i].x >> P[i].y >> Q[i].x >> Q[i].y;
    Point<ll> cur = 2 * P[s];
    for (int i = 1; i <= n; i++) cur += Q[i] - P[i];
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (2 * Q[i] == cur)
        {
            ans = i;
            break;
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}