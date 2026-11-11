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
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    auto check = [&](vector<int> &c) -> bool
    {
        for (int i = 1; i <= n; i++)
        {
            if (c[i] == a[i] || c[i] == b[i] || c[i] == 0) return 0;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (__gcd(a[i], c[i]) > 1 || __gcd(b[i], c[i]) > 1) cnt++;
        }
        return cnt >= n / 2;
    };
    if (n <= 9)
    {
        vector<int> c(n + 1);
        iota(c.begin(), c.end(), 0);
        do
        {
            if (check(c))
            {
                for (int i = 1; i <= n; i++) cout << c[i] << " ";
                cout << '\n';
                return;
            }
        } while (next_permutation(c.begin() + 1, c.end()));
        cout << -1 << '\n';
    }
    else
    {
        vector<int> v1, v2;
        vector<int> c(n + 1), pa(n + 1), pb(n + 1);
        for (int i = 1; i <= n; i++)
        {
            pa[a[i]] = i;
            pb[b[i]] = i;
            if (a[i] % 2 == 0 || b[i] % 2 == 0) v1.push_back(i);
        }
        auto fill = [&](vector<int> v, int st) -> void
        {
            set<int> s;
            for (auto i : v) s.insert(i);
            for (int i = st; i <= n; i += 2)
            {
                int pos = -1;
                for (auto p : s)
                {
                    if (p != pa[i] && p != pb[i])
                    {
                        pos = p;
                        break;
                    }
                }
                if (pos != -1)
                {
                    c[pos] = i;
                    s.erase(pos);
                    continue;
                }
                int pos2 = *s.begin();
                for (auto p : v)
                {
                    if (c[p] && p != pa[i] && p != pb[i] && c[p] != a[pos2] && c[p] != b[pos2])
                    {
                        c[pos2] = c[p];
                        c[p] = i;
                        s.erase(pos2);
                        break;
                    }
                }
            }
        };
        fill(v1, 2);
        for (int i = 1; i <= n; i++)
        {
            if (!c[i]) v2.push_back(i);
        }
        fill(v2, 1);
        for (int i = 1; i <= n; i++) cout << c[i] << ' ';
        cout << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
} 