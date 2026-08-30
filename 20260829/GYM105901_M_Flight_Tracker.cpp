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
using ld = long double;

struct Point
{
    ld x = 0;
    ld y = 0;
    ld z = 0;
};

Point operator+(const Point &a, const Point &b)
{
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}

Point operator-(const Point &a, const Point &b)
{
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

Point operator*(const Point &a, ld b)
{
    return {a.x * b, a.y * b, a.z * b};
}

Point operator/(const Point &a, ld b)
{
    return {a.x / b, a.y / b, a.z / b};
}

ld length(const Point &a)
{
    return std::hypot(a.x, a.y, a.z);
}

Point normalize(const Point &a)
{
    ld l = length(a);
    return {a.x / l, a.y / l, a.z / l};
}

ld getAng(ld a, ld b, ld c)
{
    return std::acos((a * a + b * b - c * c) / 2 / a / b);
}

std::ostream &operator<<(std::ostream &os, const Point &a)
{
    return os << "(" << a.x << ", " << a.y << ", " << a.z << ")";
}

ld dot(const Point &a, const Point &b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Point cross(const Point &a, const Point &b)
{
    return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}
void moth()
{
    ld r;
    Point p, s, t;
    cin >> r >> p.x >> p.y >> p.z >> s.x >> s.y >> s.z >> t.x >> t.y >> t.z;
    Point n = cross(s, t);
    if (dot(cross(n, s), p) > 0 && dot(cross(n, t), p) < 0)
    {
        ld sind = fabs(dot(n, p) / length(n)) / length(p);
        sind = max(sind, -1.0l);
        sind = min(sind, 1.0l);
        cout << asinl(sind) * r << '\n';
    }
    else
    {
        ld cosds = dot(p, s) / length(p) / length(s);
        cosds = max(cosds, -1.0l);
        cosds = min(cosds, 1.0l);
        ld cosdt = dot(p, t) / length(p) / length(t);
        cosdt = max(cosdt, -1.0l);
        cosdt = min(cosdt, 1.0l);
        ld ds = acosl(cosds), dt = acosl(cosdt);
        cout << min(ds, dt) * r << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cout << fixed << setprecision(10);
    cin >> _;
    while (_--) moth();
    return 0;
}