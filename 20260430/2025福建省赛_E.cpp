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
    vector<ll> a(n * 2 + 1), e(n * 2 + 1), o(n * 2 + 1);
    for (int i = 1; i <= n * 2; i++)
    {
        cin >> a[i];
        e[i] = e[i - 1] + (i % 2 ? a[i] : 0);
        o[i] = o[i - 1] + (i % 2 ? 0 : a[i]);
    }
    set<ll> st;
    st.insert(2 * (e[0] - o[0]));
    ll ans = 0, mn = 1e18;
    for (int r = 2; r <= n * 2; r += 2)
    {
        st.insert(2 * (e[r] - o[r]));
        ll t = o[n * 2] - e[n * 2] + 2 * (e[r] - o[r]);
        auto it = st.lower_bound(t);
        if (it != st.end())
        {
            ans = max(ans, min(o[n * 2] + (e[r] - o[r]) - *it / 2, e[n * 2] - (e[r] - o[r]) + *it / 2));
        }
        if (it == st.begin()) continue;
        it--;
        if (it != st.end())
        {
            ans = max(ans, min(o[n * 2] + (e[r] - o[r]) - *it / 2, e[n * 2] - (e[r] - o[r]) + *it / 2));
        }
    }
    st.clear();
    // st.insert(2 * (e[0] - o[0]));
    for (int r = 1; r <= n * 2; r += 2)
    {
        st.insert(2 * (e[r] - o[r]));
        ll t = o[n * 2] - e[n * 2] + 2 * (e[r] - o[r]);
        auto it = st.lower_bound(t);
        if (it != st.end())
        {
            ans = max(ans, min(o[n * 2] + (e[r] - o[r]) - *it / 2, e[n * 2] - (e[r] - o[r]) + *it / 2));
        }
        if (it == st.begin()) continue;
        it--;
        if (it != st.end())
        {
            ans = max(ans, min(o[n * 2] + (e[r] - o[r]) - *it / 2, e[n * 2] - (e[r] - o[r]) + *it / 2));
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}