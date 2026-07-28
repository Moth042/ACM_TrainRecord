#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
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
i64 mul(i64 a, i64 b, i64 m)
{
    return static_cast<__int128>(a) * b % m;
}
i64 power(i64 a, i64 b, i64 m)
{
    i64 res = 1 % m;
    for (; b; b >>= 1, a = mul(a, a, m))
        if (b & 1) res = mul(res, a, m);
    return res;
}
bool isprime(i64 n)
{
    if (n < 2) return false;
    static constexpr int A[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    int s = __builtin_ctzll(n - 1);
    i64 d = (n - 1) >> s;
    for (auto a : A)
    {
        if (a == n) return true;
        i64 x = power(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool ok = false;
        for (int i = 0; i < s - 1; ++i)
        {
            x = mul(x, x, n);
            if (x == n - 1)
            {
                ok = true;
                break;
            }
        }
        if (!ok) return false;
    }
    return true;
}
std::vector<i64> factorize(i64 n)
{
    std::vector<i64> p;
    std::function<void(i64)> f = [&](i64 n)
    {
        if (n <= 10000)
        {
            for (int i = 2; i * i <= n; ++i)
                for (; n % i == 0; n /= i) p.push_back(i);
            if (n > 1) p.push_back(n);
            return;
        }
        if (isprime(n))
        {
            p.push_back(n);
            return;
        }
        auto g = [&](i64 x) { return (mul(x, x, n) + 1) % n; };
        i64 x0 = 2;
        while (true)
        {
            i64 x = x0;
            i64 y = x0;
            i64 d = 1;
            i64 power = 1, lam = 0;
            i64 v = 1;
            while (d == 1)
            {
                y = g(y);
                ++lam;
                v = mul(v, std::abs(x - y), n);
                if (lam % 127 == 0)
                {
                    d = std::gcd(v, n);
                    v = 1;
                }
                if (power == lam)
                {
                    x = y;
                    power *= 2;
                    lam = 0;
                    d = std::gcd(v, n);
                    v = 1;
                }
            }
            if (d != n)
            {
                f(d);
                f(n / d);
                return;
            }
            ++x0;
        }
    };
    f(n);
    std::sort(p.begin(), p.end());
    return p;
}
void moth()
{
    // auto p = factorize(210);
    // for (auto i : p) cout << i << " ";
    i64 n;
    cin >> n;
    auto p = factorize(n);
    map<i64, i64> mp;
    for (auto i : p) mp[i]++;
    i64 ans = 0;
    for (auto [k, v] : mp)
    {
        i64 sum = 0;
        i64 cur = v;
        while (cur)
        {
            cur /= 2;
            sum++;
        }
        ans = max(ans, sum);
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