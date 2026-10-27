#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int N = 1e5 + 9;
const int mod = 1e9 + 7;
const int MOD = 998244353;
int dx[] = {-1, 0, 1, 0}; // ????
int dy[] = {0, 1, 0, -1};
int ddx[] = {-1, 1, 2, 2, 1, -1, -2, -2};
int ddy[] = {2, 2, 1, -1, -2, -2, -1, 1};
// ??
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
// ??
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
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    // if (x1 == x2)
    // {
    //     if (y1 == 1 && y2 == 2) cout << "YES\n";
    //     else if (y1 == 10 && y2 == 9) cout << "YES\n";
    //     else cout << "NO\n";
    // }
    // else if (y1 == y2)
    // {
    //     if (x1 == 1 && x2 == 2) cout << "YES\n";
    //     else if (x1 == 9 && x2 == 8) cout << "YES\n";
    //     else cout << "NO\n";
    // }
    // else cout << "NO\n";
    for (int i = 0; i < 8; i++)
    {
        int nx = x1 + ddx[i], ny = y1 + ddy[i];
        if (nx == x2 && ny == y2)
        {
            cout << "NO\n";
            return;
        }
    }
    bool ok = 1;
    for (int i = 0; i < 8; i++)
    {
        if (x2 == x1 + 1 && y1 == y2)
        {
            if (i == 2 || i == 3) continue;
        }
        if (x2 == x1 - 1 && y1 == y2)
        {
            if (i == 6 || i == 7) continue;
        }
        if (y2 == y1 + 1 && x1 == x2)
        {
            if (i == 0 || i == 1) continue;
        }
        if (y2 == y1 - 1 && x1 == x2)
        {
            if (i == 4 || i == 5) continue;
        }
        int nx = x1 + ddx[i], ny = y1 + ddy[i];
        if (nx < 1 || nx > 9 || ny < 1 || ny > 10) continue;
        if (nx != x2 && ny != y2) ok = 0;
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}