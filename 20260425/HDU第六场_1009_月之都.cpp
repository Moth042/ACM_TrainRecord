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
template <class T> struct Basis
{
    constexpr static int K = 30;
    std::vector<T> e;

    Basis()
    {
        e.assign(K, 0);
    }

    bool add(T x)
    {
        for (int i = K - 1; i >= 0 && x; i--)
        {
            if (x >> i & 1)
            {
                if (e[i])
                {
                    x ^= e[i];
                }
                else
                {
                    e[i] = x;
                    return true;
                }
            }
        }
        return false;
    }

    T max(T x = 0)
    {
        for (int i = K - 1; i >= 0; i--)
        {
            x = std::max(x, x ^ e[i]);
        }
        return x;
    }
    T min(T x)
    {
        for (int i = K - 1; i >= 0; i--)
        {
            x = std::min(x, x ^ e[i]);
        }
        return x;
    }

    void work()
    {
        for (int i = 0; i < K; i++)
        {
            for (int j = i + 1; j < K; j++)
            {
                if (e[j] >> i & 1)
                {
                    e[j] ^= e[i];
                }
            }
        }
    }

    constexpr Basis &operator|=(const Basis &rhs) &
    {
        for (int i = 0; i < rhs.K; i++)
        {
            add(rhs.e[i]);
        }
        return *this;
    }
    constexpr Basis &operator&=(const Basis &rhs) &
    {
        Basis ans;
        std::vector<T> b(rhs.K);
        for (int i = rhs.K - 1; i >= 0; i--)
        {
            T x = rhs.e[i], v = x;
            for (int k = i; k >= 0 && x; k--)
            {
                if (x >> k & 1)
                {
                    if (!e[k])
                    {
                        e[k] = x;
                        b[k] = v;
                    }
                    x ^= e[k];
                    v ^= b[k];
                }
            }
            ans.add(v);
        }

        *this = std::move(ans);
        return *this;
    }

    constexpr friend Basis operator|(Basis lhs, const Basis &rhs)
    {
        lhs |= rhs;
        return lhs;
    }
    constexpr friend Basis operator&(Basis lhs, const Basis &rhs)
    {
        lhs &= rhs;
        return lhs;
    }
};

void moth()
{
    int n, m;
    cin >> n >> m;
    Basis<ll> b;
    for (int i = 1; i <= m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        b.add(u ^ v ^ w);
    }
    cout << b.min((1ll ^ n)) << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}