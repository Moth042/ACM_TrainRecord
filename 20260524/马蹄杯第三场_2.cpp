#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> cnt(n + 1);
    while (m--)
    {
        string s;
        cin >> s;
        int t = s.length();
        for (int i = 1; i <= n; i++)
        {
            if (a[i].substr(0, t) == s) cnt[i]++;
        }
    }
    for (int i = 1; i <= n; i++) cout << cnt[i] << ' ';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) solve();
    return 0;
}