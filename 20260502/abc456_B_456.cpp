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
    vector<int> c4(3), c5(3), c6(3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            int x;
            cin >> x;
            if (x == 4) c4[i]++;
            else if (x == 5) c5[i]++;
            else if (x == 6) c6[i]++;
        }
    }
    cout << 1.0 *
                (c4[0] * c5[1] * c6[2] + c4[0] * c5[2] * c6[1] + c4[1] * c5[0] * c6[2] + c4[1] * c5[2] * c6[0] +
                 c4[2] * c5[0] * c6[1] + c4[2] * c5[1] * c6[0]) /
                216
         << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cout << fixed << setprecision(10);
    // cin >> _;
    while (_--) moth();
    return 0;
}