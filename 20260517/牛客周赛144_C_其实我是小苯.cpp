#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int N = 2e5 + 9;
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
int A[N], B[N], C[N], la, lb, lc;
bool cmp(int A[], int B[])
{
    if (la != lb) return la > lb;
    for (int i = la - 1; i >= 0; i--)
    {
        if (A[i] != B[i]) return A[i] > B[i];
    }
    return true;
}
void sub(int A[], int B[], int C[])
{
    for (int i = 0; i < lc; i++)
    {
        if (A[i] < B[i])
        {
            A[i] += 10;
            A[i + 1]--;
        }
        C[i] = A[i] - B[i];
    }
    while (lc && C[lc] == 0) lc--;
}
int main()
{
    int n, m;
    cin >> n >> m;
    string a, b;
    if (n > m) swap(n, m);
    if (n == m) cout << 0 << ' ';
    else
    {
        for (int i = 1; i <= n; i++) a += "9";
        b += "1";
        for (int i = 1; i < m; i++) b += "0";
        la = a.size(), lb = b.size(), lc = max(la, lb);
        for (int i = la - 1; i >= 0; i--) A[la - i - 1] = a[i] - '0';
        for (int i = lb - 1; i >= 0; i--) B[lb - i - 1] = b[i] - '0';
        // if (!cmp(A, B))
        // {
        //     swap(A, B);
        //     cout << "-";
        // }
        sub(B, A, C);
        for (int i = lc; i >= 0; i--) cout << C[i];
        cout << " ";
    }
    memset(A, 0, sizeof A);
    memset(B, 0, sizeof B);
    memset(C, 0, sizeof C);
    a.clear();
    b.clear();
    a += "1";
    for (int i = 1; i < n; i++) a += "0";
    for (int i = 1; i <= m; i++) b += "9";
    // cout<<a<<' '<<b<<'\n';
    la = a.size(), lb = b.size(), lc = max(la, lb);
    for (int i = la - 1; i >= 0; i--) A[la - i - 1] = a[i] - '0';
    for (int i = lb - 1; i >= 0; i--) B[lb - i - 1] = b[i] - '0';
    // for(int i = 0;i<la;i++)cout<<A[i];
    // for(int i=0;i<lb;i++)cout<<B[i];
    // if (!cmp(A, B))
    // {
    //     swap(A, B);
    //     cout << "-";
    // }
    sub(B, A, C);
    for (int i = lc; i >= 0; i--) cout << C[i];
    return 0;
}