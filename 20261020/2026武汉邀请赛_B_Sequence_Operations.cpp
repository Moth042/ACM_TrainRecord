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
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<pair<int, int>> Q(m + 1);
    int g = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> Q[i].first >> Q[i].second;
    int ok0 = 0, ok1 = 0, ok2 = 0;
    for (int i = 1; i <= m; i++)
    {
        if (Q[i].first == 0)
        {
            ok0++;
            if (ok2)
            {
                cout << "Yes\n";
                return;
            }
        }
        else if (Q[i].first == 1)
        {
            ok1++;
            if (ok0 || ok2)
            {
                cout << "Yes\n";
                return;
            }
        }
        else ok2++;
    }
    if (ok0 >= 2)
    {
        cout << "Yes\n";
        return;
    }
    int st = -1;
    for (int i = 1; i <= m; i++)
    {
        if (Q[i].first != 1)
        {
            st = i;
            break;
        }
    }
    int g1 = 0, g2 = 0;
    if (!ok1 && !ok0)
    {
        for (int i = 1; i <= m; i++) g = __gcd(g, Q[i].second);
        for (int i = 1; i <= n; i++) a[i] = __gcd(a[i], g);
        bool ok = 1;
        for (int i = 2; i <= n; i++)
        {
            if (a[i] != a[i - 1]) ok = 0;
        }
        if (ok) cout << "Yes\n";
        else cout << "No\n";
        return;
    }
    if (!ok2 && st == -1)
    {
        auto c1 = a;
        for (int i = 1; i <= n; i++)
        {
            if (m % 2)
            {
                if (c1[i]) c1[i] = 0;
                else
                {
                    if (Q[m].second == 1) c1[i] = 2;
                    else c1[i] = 1;
                }
            }
            else
            {
                if (c1[i])
                {
                    if (Q[m].second == 1) c1[i] = 2;
                    else c1[i] = 1;
                }
            }
        }
        bool ok = 1;
        for (int i = 2; i <= n; i++)
        {
            if (c1[i] != c1[i - 1]) ok = 0;
            // if (c2[i] != c2[i - 1]) ok2 = 0;
        }
        if (ok) cout << "Yes\n";
        else cout << "No\n";
        return;
    }
    for (int i = m; i >= st; i--)
    {
        g1 = __gcd(g1, Q[i].second);
        if (i != st) g2 = __gcd(g2, Q[i].second);
    }
    if (st == 1)
    {
        auto c1 = a, c2 = a;
        for (int i = 1; i <= n; i++)
        {
            if (Q[1].second > 1)
            {
                if (c1[i] == 0) c1[i] = 1;
                else c1[i] = 0;
            }
            else
            {
                if (c1[i] == 0) c1[i] = 2;
                else c1[i] = 0;
            }
            c1[i] = __gcd(c1[i], g2);
            c2[i] = __gcd(c2[i], g1);
        }
        ok1 = 1, ok2 = 1;
        for (int i = 2; i <= n; i++)
        {
            if (c1[i] != c1[i - 1]) ok1 = 0;
            if (c2[i] != c2[i - 1]) ok2 = 0;
        }
        if ((ok1 && Q[1].first == 0) || ok2)
        {
            cout << "Yes\n";
            return;
        }
    }
    else
    {
        auto c1 = a, c2 = a;
        for (int i = 1; i <= n; i++)
        {
            if (st % 2)
            {
                if (c1[i]) c1[i] = 0;
                else
                {
                    if (Q[st].second == 1) c1[i] = 2;
                    else c1[i] = 1;
                }
                if (c2[i])
                {
                    if (Q[st - 1].second == 1) c2[i] = 2;
                    else c2[i] = 1;
                }
            }
            else
            {
                if (c1[i])
                {
                    if (Q[st].second == 1) c1[i] = 2;
                    else c1[i] = 1;
                }
                if (c2[i]) c2[i] = 0;
                else
                {
                    if (Q[st - 1].second == 1) c2[i] = 2;
                    else c2[i] = 1;
                }
            }
            c1[i] = __gcd(c1[i], g2);
            c2[i] = __gcd(c2[i], g1);
        }
        ok1 = 1, ok2 = 1;
        for (int i = 2; i <= n; i++)
        {
            if (c1[i] != c1[i - 1]) ok1 = 0;
            if (c2[i] != c2[i - 1]) ok2 = 0;
        }
        if (Q[st].first == 0 && (ok1 || ok2))
        {
            cout << "Yes\n";
            return;
        }
        if (Q[st].first == 2 && ok2)
        {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}