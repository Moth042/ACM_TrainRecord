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
ll ksm(ll a, ll b, ll c)
{
    ll res = 1;
    while (b)
    {
        if (b & 1) res = res * a % c;
        a = a * a % c;
        b >>= 1;
    }
    return res;
}
void moth()
{
    // ll n, m;
    // cin >> n >> m;
    // if (n > m) swap(n, m);
    // if (n == 2)
    // {
    //     if (m % 2) cout << 2 << '\n';
    //     else cout << 1 << '\n';
    //     return;
    // }
    // cout << ksm(2ll, n - 1, MOD) * ksm(2ll, m - 1, MOD) % MOD << '\n';
    // cout<<ksm(2,455,MOD)<<'\n';
    // for(ll t=1;t<=1000;t++)
    // {
    //     if(ksm(2ll,t,MOD)==400944928)
    //     {
    //         cout<<t<<'\n';
    //         break;
    //     }
    // }
    ll n, m;
    cin >> n >> m;
    // int ans=0;

    // for(int i=0;i<(1ll<<(n*m));i++)
    // {
    //     vector<vector<int>> a(n, vector<int>(m));
    //     for(int j=0;j<n*m;j++)
    //     {
    //         if((i>>j)&1)
    //         {
    //             int r=j/m,c=j%m;
    //             a[r][c]=1;
    //         }
    //     }
    //     bool ok=1;
    //     vector<int>r1(n),c1(m);
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<m;j++)
    //         {
    //             if(a[i][j]==1)
    //             {
    //                 r1[i]++;
    //                 c1[j]++;
    //             }
    //         }
    //     }
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<m;j++)
    //         {
    //             if(a[i][j]==1&&(r1[i]+c1[j]-2)%2==0)
    //             {
    //                 ok=0;
    //                 break;
    //             }
    //             if(a[i][j]==0&&(r1[i]+c1[j])%2)
    //             {
    //                 ok=0;
    //                 break;
    //             }
    //         }
    //         if(!ok)break;
    //     }
    //     if(ok)ans++;
    // }
    // cout<<ans<<'\n';
    // if(n<m)swap(n,m);
    if (n % 2 == 0 && m % 2 == 0)
    {
        cout << 1 << '\n';
        return;
    }
    if (n % 2 == 0) swap(n, m);
    if (m % 2 == 0) cout << ksm(2ll, (m - 1) % (MOD - 1) + (MOD - 1), MOD) << '\n';
    else cout << ksm(2ll, (n - 1) % (MOD - 1) + (MOD - 1), MOD) * ksm(2ll, (m - 1) % (MOD - 1) + (MOD - 1), MOD) % MOD << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}