#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        if (r - l + 1 < 3)
        {
            cout << "No\n";
            continue;
        }
        bool ok = 0;
        vector<ll> pmn(n + 1, 1e18), smx(n + 1, -1e18);
        pmn[l] = a[l], smx[r] = a[r];
        for (int i = l + 1; i <= r; i++) pmn[i] = min(pmn[i - 1], a[i]);
        for (int i = r - 1; i >= l; i--) smx[i] = max(smx[i + 1], a[i]);
        for (int i = l; i <= min(r, n - 1); i++)
        {
            if (pmn[i - 1] < a[i] && smx[i + 1] > a[i])
            {
                ok = 1;
                break;
            }
        }
        if (!ok) cout << "No\n";
        else cout << "Yes\n";
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) solve();
    return 0;
}