#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    if (n > m)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++) cout << i << ' ' << j << '\n';
        }
    }
    else
    {
        for (int j = 1; j <= m; j++)
        {
            for (int i = 1; i <= n; i++) cout << i << ' ' << j << '\n';
        }
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