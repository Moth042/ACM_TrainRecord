#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n + 1);
    ll ans = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int j = 0; j < m; j++)
    {
        vector<int> cnt(26);
        for (int i = 1; i <= n; i++)
        {
            int t = a[i][j] - 'a';
            cnt[t]++;
        }
        vector<vector<ll>> suf(n + 2, vector<ll>(26));
        for (int k = 0; k < 26; k++) suf[n][k] = (a[n][j] - 'a' == k);
        for (int i = n - 1; i >= 1; i--)
        {
            for (int k = 0; k < 26; k++) suf[i][k] = suf[i + 1][k] + (a[i][j] - 'a' == k);
        }
        for (int i = 1; i <= n; i++) ans += 1ll * (n - i - suf[i + 1][a[i][j] - 'a']);
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