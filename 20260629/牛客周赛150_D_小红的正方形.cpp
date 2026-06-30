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

template <class T> struct Line
{
    Point<T> a;
    Point<T> b;
    // 直线（或线段）由两点 a, b 定义
    Line(const Point<T> &a_ = Point<T>(), const Point<T> &b_ = Point<T>()) : a(a_), b(b_)
    {
    }
};

// 向量点积：a·b = |a||b|cosθ
template <class T> T dot(const Point<T> &a, const Point<T> &b)
{
    return a.x * b.x + a.y * b.y;
}

// 向量叉积：a×b = |a||b|sinθ，正表示 b 在 a 的逆时针方向
template <class T> T cross(const Point<T> &a, const Point<T> &b)
{
    return a.x * b.y - a.y * b.x;
}

// 向量模长的平方
template <class T> T square(const Point<T> &p)
{
    return dot(p, p);
}

// 向量的模长（长度）
template <class T> double length(const Point<T> &p)
{
    return std::sqrt(square(p));
}

// 线段的长度（端点距离）
template <class T> double length(const Line<T> &l)
{
    return length(l.a - l.b);
}

// 返回同向的单位向量
template <class T> Point<T> normalize(const Point<T> &p)
{
    return p / length(p);
}

// 两直线是否平行（叉积为零）
template <class T> bool parallel(const Line<T> &l1, const Line<T> &l2)
{
    return cross(l1.b - l1.a, l2.b - l2.a) == 0;
}

// 两点距离
template <class T> double distance(const Point<T> &a, const Point<T> &b)
{
    return length(a - b);
}

// 点到直线的距离（利用平行四边形面积除以底边长）
template <class T> double distancePL(const Point<T> &p, const Line<T> &l)
{
    return std::abs(cross(l.a - l.b, l.a - p)) / length(l);
}

// 点到线段的距离
template <class T> double distancePS(const Point<T> &p, const Line<T> &l)
{
    // 若投影落在端点外侧，则取端点到该点的距离
    if (dot(p - l.a, l.b - l.a) < 0)
    {
        return distance(p, l.a);
    }
    if (dot(p - l.b, l.a - l.b) < 0)
    {
        return distance(p, l.b);
    }
    // 否则退化为点到直线的距离
    return distancePL(p, l);
}

// 向量逆时针旋转 90°：(x, y) -> (-y, x)
template <class T> Point<T> rotate(const Point<T> &a)
{
    return Point(-a.y, a.x);
}

// 用于极角排序：返回 1 表示向量在上半平面（含正 x 轴），-1 表示下半平面
template <class T> int sgn(const Point<T> &a)
{
    return a.y > 0 || (a.y == 0 && a.x > 0) ? 1 : -1;
}

// 判断点 p 是否在有向直线 l 的左侧（叉积 > 0）
template <class T> bool pointOnLineLeft(const Point<T> &p, const Line<T> &l)
{
    return cross(l.b - l.a, p - l.a) > 0;
}

// 两直线交点（要求不平行，分母非零）
template <class T> Point<T> lineIntersection(const Line<T> &l1, const Line<T> &l2)
{
    return l1.a + (l1.b - l1.a) * (cross(l2.b - l2.a, l1.a - l2.a) / cross(l2.b - l2.a, l1.a - l1.b));
}

// 点 p 是否在线段 l 上（包括端点）
template <class T> bool pointOnSegment(const Point<T> &p, const Line<T> &l)
{
    // 共线且在包围盒内
    return cross(p - l.a, l.b - l.a) == 0 && std::min(l.a.x, l.b.x) <= p.x && p.x <= std::max(l.a.x, l.b.x) && std::min(l.a.y, l.b.y) <= p.y && p.y <= std::max(l.a.y, l.b.y);
}

// 点 a 是否在多边形 p 内部（含边界），采用射线法
template <class T> bool pointInPolygon(const Point<T> &a, const std::vector<Point<T>> &p)
{
    int n = p.size();
    // 先检测是否在某条边上
    for (int i = 0; i < n; i++)
    {
        if (pointOnSegment(a, Line(p[i], p[(i + 1) % n])))
        {
            return true;
        }
    }

    int t = 0;
    // 向右作水平射线，统计与边界的交点次数
    for (int i = 0; i < n; i++)
    {
        auto u = p[i];
        auto v = p[(i + 1) % n];
        if (u.x < a.x && v.x >= a.x && pointOnLineLeft(a, Line(v, u)))
        {
            t ^= 1;
        }
        if (u.x >= a.x && v.x < a.x && pointOnLineLeft(a, Line(u, v)))
        {
            t ^= 1;
        }
    }

    return t == 1;
}

// 线段相交判定，返回 (状态, 交点1, 交点2)
// 状态码：0 不相交，1 严格相交（内部一点），2 重叠（有公共区间），3 交于端点
template <class T> std::tuple<int, Point<T>, Point<T>> segmentIntersection(const Line<T> &l1, const Line<T> &l2)
{
    // 快速排斥实验：包围盒不相交则不可能有交点
    if (std::max(l1.a.x, l1.b.x) < std::min(l2.a.x, l2.b.x))
    {
        return {0, Point<T>(), Point<T>()};
    }
    if (std::min(l1.a.x, l1.b.x) > std::max(l2.a.x, l2.b.x))
    {
        return {0, Point<T>(), Point<T>()};
    }
    if (std::max(l1.a.y, l1.b.y) < std::min(l2.a.y, l2.b.y))
    {
        return {0, Point<T>(), Point<T>()};
    }
    if (std::min(l1.a.y, l1.b.y) > std::max(l2.a.y, l2.b.y))
    {
        return {0, Point<T>(), Point<T>()};
    }
    // 两线段所在直线平行的情况
    if (cross(l1.b - l1.a, l2.b - l2.a) == 0)
    {
        if (cross(l1.b - l1.a, l2.a - l1.a) != 0)
        {
            return {0, Point<T>(), Point<T>()}; // 平行不共线
        }
        else
        {
            // 共线，计算重叠区间
            auto maxx1 = std::max(l1.a.x, l1.b.x);
            auto minx1 = std::min(l1.a.x, l1.b.x);
            auto maxy1 = std::max(l1.a.y, l1.b.y);
            auto miny1 = std::min(l1.a.y, l1.b.y);
            auto maxx2 = std::max(l2.a.x, l2.b.x);
            auto minx2 = std::min(l2.a.x, l2.b.x);
            auto maxy2 = std::max(l2.a.y, l2.b.y);
            auto miny2 = std::min(l2.a.y, l2.b.y);
            Point<T> p1(std::max(minx1, minx2), std::max(miny1, miny2));
            Point<T> p2(std::min(maxx1, maxx2), std::min(maxy1, maxy2));
            if (!pointOnSegment(p1, l1))
            {
                std::swap(p1.y, p2.y); // 保证 p1 在 l1 上
            }
            if (p1 == p2)
            {
                return {3, p1, p2}; // 交于一点（端点重合）
            }
            else
            {
                return {2, p1, p2}; // 重叠区间
            }
        }
    }
    // 计算跨立情况
    auto cp1 = cross(l2.a - l1.a, l2.b - l1.a);
    auto cp2 = cross(l2.a - l1.b, l2.b - l1.b);
    auto cp3 = cross(l1.a - l2.a, l1.b - l2.a);
    auto cp4 = cross(l1.a - l2.b, l1.b - l2.b);

    // 若两次叉积同号，说明线段另一条完全在直线的一侧，不相交
    if ((cp1 > 0 && cp2 > 0) || (cp1 < 0 && cp2 < 0) || (cp3 > 0 && cp4 > 0) || (cp3 < 0 && cp4 < 0))
    {
        return {0, Point<T>(), Point<T>()};
    }

    Point p = lineIntersection(l1, l2);
    if (cp1 != 0 && cp2 != 0 && cp3 != 0 && cp4 != 0)
    {
        return {1, p, p}; // 严格相交
    }
    else
    {
        return {3, p, p}; // 端点在另一线段上
    }
}

// 两线段的最短距离
template <class T> double distanceSS(const Line<T> &l1, const Line<T> &l2)
{
    if (std::get<0>(segmentIntersection(l1, l2)) != 0)
    {
        return 0.0;
    }
    // 取四个端点到另一线段距离的最小值
    return std::min({distancePS(l1.a, l2), distancePS(l1.b, l2), distancePS(l2.a, l1), distancePS(l2.b, l1)});
}

// 线段 l 是否整个位于多边形 p 的内部（含边界）
template <class T> bool segmentInPolygon(const Line<T> &l, const std::vector<Point<T>> &p)
{
    int n = p.size();
    // 两个端点必须都在多边形内
    if (!pointInPolygon(l.a, p))
    {
        return false;
    }
    if (!pointInPolygon(l.b, p))
    {
        return false;
    }
    for (int i = 0; i < n; i++)
    {
        auto u = p[i];
        auto v = p[(i + 1) % n];
        auto w = p[(i + 2) % n];
        auto [t, p1, p2] = segmentIntersection(l, Line(u, v));

        if (t == 1)
        {
            return false; // 严格相交，线段穿出多边形
        }
        if (t == 0)
        {
            continue; // 无交点
        }
        if (t == 2)
        {
            // 重叠，检测重叠部分是否导致线段露在多边形外
            if (pointOnSegment(v, l) && v != l.a && v != l.b)
            {
                if (cross(v - u, w - v) > 0)
                {
                    return false;
                }
            }
        }
        else
        {
            // t == 3，交于一点
            if (p1 != u && p1 != v)
            {
                if (pointOnLineLeft(l.a, Line(v, u)) || pointOnLineLeft(l.b, Line(v, u)))
                {
                    return false;
                }
            }
            else if (p1 == v)
            {
                // 交点恰好是多边形顶点 v，需要结合前后边判断线段是否在内部
                if (l.a == v)
                {
                    if (pointOnLineLeft(u, l))
                    {
                        if (pointOnLineLeft(w, l) && pointOnLineLeft(w, Line(u, v)))
                        {
                            return false;
                        }
                    }
                    else
                    {
                        if (pointOnLineLeft(w, l) || pointOnLineLeft(w, Line(u, v)))
                        {
                            return false;
                        }
                    }
                }
                else if (l.b == v)
                {
                    if (pointOnLineLeft(u, Line(l.b, l.a)))
                    {
                        if (pointOnLineLeft(w, Line(l.b, l.a)) && pointOnLineLeft(w, Line(u, v)))
                        {
                            return false;
                        }
                    }
                    else
                    {
                        if (pointOnLineLeft(w, Line(l.b, l.a)) || pointOnLineLeft(w, Line(u, v)))
                        {
                            return false;
                        }
                    }
                }
                else
                {
                    if (pointOnLineLeft(u, l))
                    {
                        if (pointOnLineLeft(w, Line(l.b, l.a)) || pointOnLineLeft(w, Line(u, v)))
                        {
                            return false;
                        }
                    }
                    else
                    {
                        if (pointOnLineLeft(w, l) || pointOnLineLeft(w, Line(u, v)))
                        {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

// 半平面交：求有向直线左侧半平面的交集，返回凸多边形的顶点（逆时针）
template <class T> std::vector<Point<T>> hp(std::vector<Line<T>> lines)
{
    // 极角排序：先按上半/下半平面，再按极角从小到大
    std::sort(lines.begin(), lines.end(),
              [&](auto l1, auto l2)
              {
                  auto d1 = l1.b - l1.a;
                  auto d2 = l2.b - l2.a;

                  if (sgn(d1) != sgn(d2))
                  {
                      return sgn(d1) == 1;
                  }

                  return cross(d1, d2) > 0;
              });

    std::deque<Line<T>> ls;  // 保存当前使用的直线
    std::deque<Point<T>> ps; // 保存相邻直线的交点
    for (auto l : lines)
    {
        if (ls.empty())
        {
            ls.push_back(l);
            continue;
        }

        // 用当前直线裁剪队尾
        while (!ps.empty() && !pointOnLineLeft(ps.back(), l))
        {
            ps.pop_back();
            ls.pop_back();
        }

        // 用当前直线裁剪队首
        while (!ps.empty() && !pointOnLineLeft(ps[0], l))
        {
            ps.pop_front();
            ls.pop_front();
        }

        // 与上一条直线平行的情况
        if (cross(l.b - l.a, ls.back().b - ls.back().a) == 0)
        {
            if (dot(l.b - l.a, ls.back().b - ls.back().a) > 0)
            {
                // 同向，若当前直线更严格则替换
                if (!pointOnLineLeft(ls.back().a, l))
                {
                    assert(ls.size() == 1);
                    ls[0] = l;
                }
                continue;
            }
            return {}; // 反向平行，交集为空
        }

        // 添加当前直线与上一交点的交点
        ps.push_back(lineIntersection(ls.back(), l));
        ls.push_back(l);
    }

    // 最后用队首的直线裁剪队尾
    while (!ps.empty() && !pointOnLineLeft(ps.back(), ls[0]))
    {
        ps.pop_back();
        ls.pop_back();
    }
    if (ls.size() <= 2)
    {
        return {};
    }
    // 首尾闭合
    ps.push_back(lineIntersection(ls[0], ls.back()));

    return std::vector(ps.begin(), ps.end());
}

// 默认使用 long double 保证精度
using ld = long double;
using P = Point<ll>;

constexpr ld eps = 0; // 由于坐标通常为整数，可用精确比较
void moth()
{
    vector<ll> a(4), b(4);
    for (int i = 0; i < 4; i++) cin >> a[i];
    for (int i = 0; i < 4; i++) cin >> b[i];
    vector<P> pa = {P(a[0], a[1]), P(a[2], a[1]), P(a[2], a[3]), P(a[0], a[3])};
    vector<P> pb = {P(b[0], b[1]), P(b[2], b[1]), P(b[2], b[3]), P(b[0], b[3])};
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int t = get<0>(segmentIntersection(Line(pa[i], pa[(i + 1) % 4]), Line(pb[j], pb[(j + 1) % 4])));
            if (t == 2)
            {
                cout << "inf\n";
                return;
            }
            ans += (t > 0);
        }
    }
    cout << (ans > 2 ? 1 : ans) << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}