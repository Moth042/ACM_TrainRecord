#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    ll ans = 0;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i], ans += a[i];
    ans /= n;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > ans) cnt++;
    }
    cout << cnt << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) solve();
    return 0;
}