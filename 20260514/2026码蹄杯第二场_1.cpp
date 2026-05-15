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
    ll mxx = 0, mnx = 1e18, mxy = 0, mny = 1e18;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
        mxx = max(mxx, a[i].first);
        mnx = min(mnx, a[i].first);
        mxy = max(mxy, a[i].second);
        mny = min(mny, a[i].second);
    }
    cout << (mxx - mnx) * (mxy - mny) << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) solve();
    return 0;
}