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
    string s;
    cin >> s;
    int n = s.length();
    vector<int> ab, ba;
    for (int i = 0; i < n - 1; i++)
    {
        if (s.substr(i, 2) == "AB")
        {
            // cout << i << " ";
            // ok1 = 1;
            // vis[i] = vis[i + 1] = 1;
            ab.push_back(i);
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (s.substr(i, 2) == "BA")
        {
            // cout << i << " ";
            // ok2 = 1;
            // if (!vis[i] && !vis[i + 1]) ok3 = 1;
            ba.push_back(i);
        }
    }
    int n1 = ab.size(), n2 = ba.size();
    if (!n1 || !n2)
    {
        cout << "NO\n";
        return;
    }
    if (ab[0] + 1 < ba[n2 - 1])
    {
        cout << "YES\n";
        return;
    }
    if (ba[0] + 1 < ab[n1 - 1])
    {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}