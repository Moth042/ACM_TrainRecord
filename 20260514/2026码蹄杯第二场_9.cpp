#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> a(m + 1);
    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= m; i++) cin >> a[i].first >> a[i].second;
    sort(a.begin() + 1, a.end());
    int idx = n;
    ll ans = 0;
    multiset<ll> s;
    priority_queue<ll> q;
    for (int i = m; i >= 1; i--)
    {
        ll st = a[i].first;
        // cout<<st<<'\n';
        while (idx >= st)
        {
            s.insert(v[idx]);
            --idx;
        }
        // cout<<idx<<' '<<s.size()<<' '<<a[i].second<<'\n';
        auto it = s.upper_bound(a[i].second);
        if (it == s.begin()) continue;
        it--;
        // cout<<*it<<'\n';
        ans += (*it);
        s.erase(it);
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) solve();
    return 0;
}