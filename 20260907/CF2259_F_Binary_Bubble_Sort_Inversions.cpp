#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int N = 1e5 + 9;
const int mod = 1e9 + 7;
const int MOD = 998244353;
int dx[] = {-1, 0, 1, 0}; // 上右下左
int dy[] = {0, 1, 0, -1};
int ddx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int ddy[] = {0, 1, 1, 1, 0, -1, -1, -1};
// 快读
inline i128 read()
{
    char c = getchar();
    i128 x = 0, s = 1;
    while (c < '0' || c > '9')
    {
        if (c == '-') s = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x * s;
}
// 快写
void write(i128 x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 | 48);
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int randint(int l, int r)
{
    return uniform_int_distribution{l, r}(rnd);
}
void moth()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    ll ans = 0;
    ll cnt1 = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt1 += a[i];
        if (!a[i]) ans += cnt1;
    }
    cout << ans << " ";
    string s;
    cin >> s;
    ll cnt0 = count(a.begin() + 1, a.end(), 0);
    deque<int> dq;
    for (int i = 1; i <= n; i++) dq.push_back(a[i]);
    for (int i = 0; i < n; i++)
    {
        while (dq.size() && dq.front() == 0)
        {
            dq.pop_front();
            cnt0--;
        }
        while (dq.size() && dq.back() == 1) dq.pop_back();
        if (dq.size() == 0)
        {
            cout << 0 << " ";
            continue;
        }
        if (s[i] == '0')
        {
            ans -= dq.size() - cnt0;
            cnt0--;
            dq.pop_back();
        }
        else
        {
            ans -= cnt0;
            dq.pop_front();
        }
        cout << ans << " ";
    }
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}