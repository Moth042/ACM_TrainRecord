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
map<array<int, 4>, int> vis;
void moth()
{
    string a, b;
    cin >> a >> b;
    array<int, 4> t;
    for (int i = 0; i < 4; i++)
    {
        int x = a[i] - '0', y = b[i] - '0';
        t[i] = (y - x + 10) % 10;
    }
    cout << vis[t] << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    array<int, 4> a = {0, 0, 0, 0};
    queue<pair<array<int, 4>, int>> q;
    q.push({a, 0});
    vis[a] = 0;
    while (q.size())
    {
        auto [s, t] = q.front();
        q.pop();
        for (int l = 0; l < 4; l++)
        {
            for (int r = l; r < 4; r++)
            {
                auto s1 = s, s2 = s;
                bool ok1 = 1, ok2 = 1;
                for (int i = l; i <= r; i++)
                {
                    int x = (s[i] + 1) % 10;
                    s1[i] = x;
                    // if (x >= -9 && x <= 9) s1[i] = x;
                    // else ok1 = 0;
                }
                for (int i = l; i <= r; i++)
                {
                    int x = (s[i] + 9) % 10;
                    s2[i] = x;
                    // if (x >= -9 && x <= 9) s2[i] = x;
                    // else ok2 = 0;
                }
                if (!vis.count(s1))
                {
                    vis[s1] = t + 1;
                    q.push({s1, t + 1});
                }
                if (!vis.count(s2))
                {
                    vis[s2] = t + 1;
                    q.push({s2, t + 1});
                }
            }
        }
    }
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}