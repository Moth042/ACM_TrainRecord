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
int A[N], B[N], C[N], la, lb, lc, ans;
void add(int A[], int B[], int C[])
{
    for (int i = 0; i < lc; i++)
    {
        C[i] += A[i] + B[i];
        C[i + 1] += C[i] / 10;
        if (C[i] / 10) ans++;
        C[i] %= 10;
    }
    if (C[lc]) lc++;
}
void moth()
{
    string a, b;
    cin >> a >> b;
    int sta = -1, stb = -1;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == '.')
        {
            sta = i;
            break;
        }
    }
    for (int i = 0; i < b.length(); i++)
    {
        if (b[i] == '.')
        {
            stb = i;
            break;
        }
    }
    if (a.length() - sta != b.length() - stb)
    {
        while (a.length() - sta < b.length() - stb) a += "0";
        while (a.length() - sta > b.length() - stb) b += "0";
    }
    string aa, bb;
    for (auto i : a)
    {
        if (i != '.') aa += i;
    }
    for (auto i : b)
    {
        if (i != '.') bb += i;
    }
    a = aa, b = bb;
    la = a.size(), lb = b.size(), lc = max(la, lb);
    for (int i = la - 1; i >= 0; i--) A[la - i - 1] = a[i] - '0';
    for (int i = lb - 1; i >= 0; i--) B[lb - i - 1] = b[i] - '0';
    add(A, B, C);
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}