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
    int n, k;
    ll d;
    cin >> n >> k >> d;
    vector<ll> a(n + 1);
    int LOG = __lg(n) + 1;
    vector<vector<ll>> stMin(n + 1, vector<ll>(LOG + 1)), stMax(n + 1, vector<ll>(LOG + 1));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        stMin[i][0] = stMax[i][0] = a[i];
    }
    vector<ll> lg2(n + 1, 0);
    ll ans = 0;
    for (int i = 2; i <= n; i++) lg2[i] = lg2[i >> 1] + 1;
    for (int j = 1; j <= LOG; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            stMin[i][j] = min(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]);
            stMax[i][j] = max(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
        }
    }
    auto getMin = [&](int l, int r) -> ll
    {
        ll k = lg2[r - l + 1];
        return min(stMin[l][k], stMin[r - (1 << k) + 1][k]);
    };
    auto getMax = [&](int l, int r) -> ll
    {
        ll k = lg2[r - l + 1];
        return max(stMax[l][k], stMax[r - (1 << k) + 1][k]);
    };
    auto cal = [&](int t) -> vector<int>
    {
        vector<int> pos(n + 1, n + 1);
        map<ll, ll> mp;
        int r = 0;
        for (int l = 1; l <= n; l++)
        {
            while (r < n && mp.size() < t)
            {
                r++;
                mp[a[r]]++;
            }
            if (mp.size() >= t) pos[l] = r;
            mp[a[l]]--;
            if (mp[a[l]] == 0) mp.erase(a[l]);
        }
        return pos;
    };
    auto L = cal(k), R = cal(k + 1);
    // for (int i = 1; i <= n; i++) cout << L[i] << ' ' << R[i] << '\n';
    for (int i = 1; i <= n; i++)
    {
        int lo = L[i], hi = R[i] - 1;
        if (lo > n) continue;
        while (lo < hi)
        {
            int mid = (lo + hi + 1) / 2;
            if (getMax(i, mid) - getMin(i, mid) <= d) lo = mid;
            else hi = mid - 1;
        }
        if (getMax(i, lo) - getMin(i, lo) <= d) ans += lo - L[i] + 1;
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