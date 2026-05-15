#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll dis(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}
void solve()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    ll ans = 1e18;
    for (int i = 1; i <= n; i++)
    {
        int x = a[i].first, y = a[i].second;
        ll sum = 0;
        for (int j = 1; j <= n; j++) sum = max(sum, dis(x, y, a[j].first, a[j].second));
        ans = min(ans, sum);
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