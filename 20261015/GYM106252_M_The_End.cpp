#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
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
    vector<ld> a(9), b(9);
    for (int i = 1; i <= 8; i++) cin >> a[i] >> b[i];
    // cout<<b[8]<<'\n';
    vector<ld> sd(9), cnt(9);
    ld ans = 0;
    iota(sd.begin(), sd.end(), 0);
    auto p = [&](int x) -> ld // seed x to final
    {
        if (x == 1)
        {
            // ld
            // x1=1.0*a[cnt[1]]/(a[cnt[1]]+b[cnt[2]]),x2=(1.0*a[cnt[3]]/(a[cnt[3]]+b[cnt[4]])*1.0*a[cnt[1]]/(a[cnt[1]]+b[cnt[3]])+1.0*b[cnt[4]]/(a[cnt[3]]+b[cnt[4]])*a[cnt[1]]/(a[cnt[1]]+b[cnt[4]])),x=x1*x2;
            // cout<<x1<<' '<<x2<<' '<<x1*x2<<'\n';
            // cout<<1.0*a[cnt[1]]/(a[cnt[1]]+b[cnt[2]])<<'
            // '<<(1.0*a[cnt[3]]/(a[cnt[3]]+b[cnt[4]])*1.0*a[cnt[1]]/(a[cnt[1]]+b[cnt[3]])+1.0*b[cnt[4]]/(a[cnt[3]]+b[cnt[4]])*a[cnt[1]]/(a[cnt[1]]+b[cnt[4]]))<<'\n';
            return 1.0 * a[cnt[1]] / (a[cnt[1]] + b[cnt[2]]) *
                   (1.0 * a[cnt[3]] / (a[cnt[3]] + b[cnt[4]]) * a[cnt[1]] / (a[cnt[1]] + b[cnt[3]]) + 1.0 * b[cnt[4]] / (a[cnt[3]] + b[cnt[4]]) * a[cnt[1]] / (a[cnt[1]] + b[cnt[4]]));
        }
        if (x == 2)
        {
            return 1.0 * b[cnt[2]] / (a[cnt[1]] + b[cnt[2]]) *
                   (a[cnt[3]] / (a[cnt[3]] + b[cnt[4]]) * a[cnt[2]] / (a[cnt[2]] + b[cnt[3]]) + 1.0 * b[cnt[4]] / (a[cnt[3]] + b[cnt[4]]) * a[cnt[2]] / (a[cnt[2]] + b[cnt[4]]));
        }
        if (x == 3)
        {
            return 1.0 * a[cnt[3]] / (a[cnt[3]] + b[cnt[4]]) *
                   (1.0 * a[cnt[1]] / (a[cnt[1]] + b[cnt[2]]) * b[cnt[3]] / (a[cnt[1]] + b[cnt[3]]) + 1.0 * b[cnt[2]] / (a[cnt[1]] + b[cnt[2]]) * b[cnt[3]] / (a[cnt[2]] + b[cnt[3]]));
        }
        if (x == 4)
        {
            return 1.0 * b[cnt[4]] / (a[cnt[3]] + b[cnt[4]]) *
                   (1.0 * a[cnt[1]] / (a[cnt[1]] + b[cnt[2]]) * b[cnt[4]] / (a[cnt[1]] + b[cnt[4]]) + 1.0 * b[cnt[2]] / (a[cnt[1]] + b[cnt[2]]) * b[cnt[4]] / (a[cnt[2]] + b[cnt[4]]));
        }
        if (x == 5)
        {
            return 1.0 * a[cnt[5]] / (a[cnt[5]] + b[cnt[6]]) *
                   (1.0 * a[cnt[7]] / (a[cnt[7]] + b[cnt[8]]) * a[cnt[5]] / (a[cnt[5]] + b[cnt[7]]) + 1.0 * b[cnt[8]] / (a[cnt[7]] + b[cnt[8]]) * a[cnt[5]] / (a[cnt[5]] + b[cnt[8]]));
        }
        if (x == 6)
        {
            return 1.0 * b[cnt[6]] / (a[cnt[5]] + b[cnt[6]]) *
                   (1.0 * a[cnt[7]] / (a[cnt[7]] + b[cnt[8]]) * a[cnt[6]] / (a[cnt[6]] + b[cnt[7]]) + 1.0 * b[cnt[8]] / (a[cnt[7]] + b[cnt[8]]) * a[cnt[6]] / (a[cnt[6]] + b[cnt[8]]));
        }
        if (x == 7)
        {
            // ld x1=1.0*a[cnt[7]]/(a[cnt[7]]+b[cnt[8]]),x2=(1.0*a[cnt[5]]/(a[cnt[5]]+b[cnt[6]])*b[cnt[7]]/(a[cnt[5]]+b[cnt[7]])+1.0*b[cnt[6]]/(a[cnt[5]]+b[cnt[6]])*b[cnt[7]]/(a[cnt[6]]+b[cnt[7]]));
            // cout<<"p7:"<<cnt[8]<<' '<<a[cnt[7]]<<' '<<b[cnt[8]]<<' '<<x1<<' '<<x2<<'\n';
            return 1.0 * a[cnt[7]] / (a[cnt[7]] + b[cnt[8]]) *
                   (1.0 * a[cnt[5]] / (a[cnt[5]] + b[cnt[6]]) * b[cnt[7]] / (a[cnt[5]] + b[cnt[7]]) + 1.0 * b[cnt[6]] / (a[cnt[5]] + b[cnt[6]]) * b[cnt[7]] / (a[cnt[6]] + b[cnt[7]]));
        }
        if (x == 8)
        {
            return 1.0 * b[cnt[8]] / (a[cnt[7]] + b[cnt[8]]) *
                   (1.0 * a[cnt[5]] / (a[cnt[5]] + b[cnt[6]]) * b[cnt[8]] / (a[cnt[5]] + b[cnt[8]]) + 1.0 * b[cnt[6]] / (a[cnt[5]] + b[cnt[6]]) * b[cnt[8]] / (a[cnt[6]] + b[cnt[8]]));
        }
    };
    // for(int i=1;i<=8;i++)cout<<sd[i]<<" ";
    // cout<<'\n';
    bool ok = 1;
    // cout<<p(1)<<'\n';
    int cntt = 0;
    do
    {
        ld cur = 0;
        for (int i = 1; i <= 8; i++) cnt[sd[i]] = i;
        int sd1 = sd[1];
        // if(ok)
        // {
        //     cout<<p(1)<<'\n';
        //     ok=0;
        // }
        // if(cntt<=10)for(int i =1;i<=8;i++)cout<<p(i)<<" ";
        // if(cntt<=10)cout<<'\n',cntt++;
        if (sd1 >= 1 && sd1 <= 4)
        {
            for (int i = 5; i <= 8; i++)
            {
                // cout<<p(sd1)<<' '<<p(i)<<' '<<1.0*a[1]/(a[1]+b[cnt[i]])<<'\n';
                cur += p(sd1) * (p(i) * 1.0 * a[1] / (a[1] + b[cnt[i]]));
            }
        }
        else
        {
            for (int i = 1; i <= 4; i++) cur += p(sd1) * (p(i) * 1.0 * b[1] / (a[cnt[i]] + b[1]));
        }
        // cout<<cur<<'\n';
        ans = fmax(ans, cur);
    } while (next_permutation(sd.begin() + 1, sd.end()));
    cout << ans;
    return;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(12);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}