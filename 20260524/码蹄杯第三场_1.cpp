#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    cout << s << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) solve();
    return 0;
}