#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int N = 1e6 + 9;
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
int A[20], B[20], C[20], la, lb, lc;
void add(int A[], int B[], int C[])
{
    for (int i = 0; i < lc; i++)
    {
        C[i] += A[i] + B[i];
        C[i + 1] += C[i] / 10;
        C[i] %= 10;
    }
    if (C[lc]) lc++;
}
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    if (n <= 7)
    {
        cout << s << '\n';
        return 0;
    }
    int t = 6;
    // for (int i = 0; i + t <= n;)
    // {
    // }
    // string a, b;
    // cin >> a >> b;
    auto cal = [&](string a, string b) -> void
    {
        memset(A, 0, sizeof A);
        memset(B, 0, sizeof B);
        memset(C, 0, sizeof C);
        la = a.size(), lb = b.size(), lc = max(la, lb);
        for (int i = la - 1; i >= 0; i--) A[la - i - 1] = a[i] - '0';
        for (int i = lb - 1; i >= 0; i--) B[lb - i - 1] = b[i] - '0';
        add(A, B, C);
    };
    string a = "", b = s.substr(0, 7);
    for (int i = 7; i < n;)
    {
        cal(a, b);
        // for (int i = lc - 1; i >= 0; i--) cout << C[i];
        // cout<<'\n';
        string c;
        for (int i = lc - 1; i >= 0; i--) c += C[i] + '0';
        string d = s.substr(i, min(t, n - i));
        // cout << c << '\n';
        // cout << d << '\n';
        i += t;
        if (t == 6) t = 7;
        else t = 6;
        a = c, b = d;
    }
    cal(a, b);
    // cal("7543210","133310");
    for (int i = lc - 1; i >= 0; i--) cout << C[i];
    return 0;
}