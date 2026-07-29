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
/*
1<=x1<q,1<=x2<p
x1^2%q=p%q
x2*2%p=q%p
(x1^2-p)=kq,令k=1,x1^2=p+q
x2^2%p=q%p=(x1^2-p)%p=x1^2%p,令x1=x2=x
x<q=x^2-p -> x^2-x-p>0 && x<p
*/
void moth()
{
    ll p;
    cin >> p;
    if (p == 2) cout << "12 1 71\n";
    else if (p == 3) cout << "4 1 13\n";
    else
    {
        int x = 0;
        while (x * x - x - p <= 0) x++;
        cout << x << ' ' << x << ' ' << x * x - p << '\n';
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