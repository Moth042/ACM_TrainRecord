#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m, t1, t2;
    cin >> n >> m >> t1 >> t2;
    vector<vector<ll>> a(n + 1, vector<ll>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    }
    ll ans = 0;
    // for(int i=1;i<=n;i+=t1)
    // {
    //     ll sum = 0;
    //     for(int r=i;r<i+t1;r++)
    //     {

    //         for(int j=1;j<=m;j+=t2)
    //         {
    //             for(int c=j;c<j+t2;c++)
    //             {
    //                 sum^=a[r][c];
    //             }
    //         }
    //         ans+=sum;
    //     }
    // }
    for (int i = 1; i <= n; i += t1)
    {
        for (int j = 1; j <= m; j += t2)
        {
            ll sum = 0;
            for (int r = i; r < i + t1; r++)
            {
                for (int c = j; c < j + t2; c++) sum ^= a[r][c];
            }
            ans += sum;
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) solve();
    return 0;
}