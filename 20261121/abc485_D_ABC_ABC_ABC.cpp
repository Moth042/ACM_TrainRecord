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
    string s;
    cin >> n >> s;
    s = " " + s;
    vector<vector<int>> p(3, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 3; j++) p[j][i] = p[j][i - 1];
        p[(int)(s[i] - 'A')][i]++;
    }
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (p[0][i] < 1 || p[1][i] < 1 || p[2][i] < 1) continue;
        int ansl = 0, ansr = n + 1;
        int l = i + 1, r = n;
        int ans = i;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (p[0][mid] > p[0][i])
            {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        ansl = max(ansl, ans);
        ans = i;
        l = i + 1, r = n;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (p[1][mid] > p[1][i])
            {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        ansl = max(ansl, ans);
        ans = i;
        l = i + 1, r = n;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (p[2][mid] > p[2][i])
            {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        ansl = max(ansl, ans);
        ans = n;
        l = i + 1, r = n;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (p[0][mid] >= p[0][n])
            {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        ansr = min(ansr, ans);
        ans = n;
        l = i + 1, r = n;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (p[1][mid] >= p[1][n])
            {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        ansr = min(ansr, ans);
        ans = n;
        l = i + 1, r = n;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (p[2][mid] >= p[2][n])
            {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        ansr = min(ansr, ans);
        if (ansl == 0) continue;
        if (ansr < ansl) continue;
        sum += 1ll * (ansr - ansl);
    }
    cout << sum;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}