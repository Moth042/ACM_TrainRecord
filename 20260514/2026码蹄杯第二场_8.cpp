#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int f(int x)
{
    int res = 0;
    int ans = 0;
    int t = x;
    while (x && res < 4)
    {
        ans += (1 << res) * (x & 1);
        x >>= 1;
        res++;
    }
    // cout<<ans<<'\n';
    return ans * 16 + (t - ans) / 16;
}
void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        ans += f(x);
    }
    cout << ans << '\n';
    // cout<<f(225)<<'\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) solve();
    return 0;
}