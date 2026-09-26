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
vector<vector<int>> R(vector<vector<int>> &t, int r)
{
    vector<vector<int>> a(3, vector<int>(3));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == r) a[i][j] = t[i][(j + 2) % 3];
            else a[i][j] = t[i][j];
        }
    }
    return a;
}
vector<vector<int>> D(vector<vector<int>> &t, int c)
{
    vector<vector<int>> a(3, vector<int>(3));
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (j == c) a[i][j] = t[(i + 2) % 3][j];
            else a[i][j] = t[i][j];
        }
    }
    return a;
}
vector<vector<int>> Z(vector<vector<int>> &t)
{
    vector<vector<int>> a(3, vector<int>(3));
    a[0][2] = t[0][0];
    a[1][2] = t[0][1];
    a[2][2] = t[0][2];
    a[0][1] = t[1][0];
    a[1][1] = t[1][1];
    a[2][1] = t[1][2];
    a[0][0] = t[2][0];
    a[1][0] = t[2][1];
    a[2][0] = t[2][2];
    return a;
}
vector<ll> fac(10, 1);
ll cal(vector<vector<int>> &a)
{
    vector<int> cur;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) cur.push_back(a[i][j]);
    }
    ll res = 0;
    for (int i = 0; i < 9; i++)
    {
        ll cnt = 0;
        for (int j = i + 1; j < 9; j++)
        {
            if (cur[i] > cur[j]) cnt++;
        }
        res += fac[8 - i] * cnt;
    }
    return res;
}
vector<ll> d(362880, -1);
void moth()
{
    vector<string> a(3), b(3);
    for (int i = 0; i < 3; i++) cin >> a[i];
    for (int i = 0; i < 3; i++) cin >> b[i];
    vector<vector<int>> nxt(3, vector<int>(3));
    map<char, int> cnt;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) cnt[a[i][j]] = i * 3 + j + 1;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) nxt[i][j] = cnt[b[i][j]];
    }
    cout << d[cal(nxt)] << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    for (int i = 2; i <= 9; i++) fac[i] = fac[i - 1] * i;
    queue<vector<vector<int>>> q;
    vector<vector<int>> a(3, vector<int>(3));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) a[i][j] = i * 3 + j + 1;
    }
    q.push(a);
    d[cal(a)] = 0;
    while (q.size())
    {
        auto x = q.front();
        q.pop();
        auto x1 = Z(x);
        if (d[cal(x1)] == -1)
        {
            d[cal(x1)] = d[cal(x)] + 1;
            q.push(x1);
        }
        for (int i = 0; i < 3; i++)
        {
            auto x2 = R(x, i);
            auto x3 = D(x, i);
            if (d[cal(x2)] == -1)
            {
                d[cal(x2)] = d[cal(x)] + 1;
                q.push(x2);
            }
            if (d[cal(x3)] == -1)
            {
                d[cal(x3)] = d[cal(x)] + 1;
                q.push(x3);
            }
        }
    }
    cin >> _;
    while (_--) moth();
    return 0;
}