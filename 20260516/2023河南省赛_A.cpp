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
    string s;
    cin >> s;
    int n = s.length();
    ll base = 13331;
    vector<ll> h1(n + 1), h2(n + 1), b1(n + 1), b2(n + 1);
    s = " " + s;
    b1[0] = b2[0] = 1;
    auto gethash1 = [&](int l, int r) -> ll { return (h1[r] - h1[l - 1] * b1[r - l + 1] % mod + mod) % mod; };
    auto gethash2 = [&](int l, int r) -> ll { return (h2[r] - h2[l - 1] * b2[r - l + 1] % MOD + MOD) % MOD; };
    for (int i = 1; i <= n; i++)
    {
        b1[i] = b1[i - 1] * base % mod;
        b2[i] = b2[i - 1] * base % MOD;
        h1[i] = (h1[i - 1] * base + (s[i] - 'a')) % mod;
        h2[i] = (h2[i - 1] * base + (s[i] - 'a')) % MOD;
    }
    string rev = s;
    reverse(rev.begin() + 1, rev.end());
    vector<ll> rh1(n + 1), rh2(n + 1);
    for (int i = 1; i <= n; i++)
    {
        rh1[i] = (rh1[i - 1] * base + (rev[i] - 'a')) % mod;
        rh2[i] = (rh2[i - 1] * base + (rev[i] - 'a')) % MOD;
    }
    auto getrevhash1 = [&](int l, int r) -> ll { return (rh1[r] - rh1[l - 1] * b1[r - l + 1] % mod + mod) % mod; };
    auto getrevhash2 = [&](int l, int r) -> ll { return (rh2[r] - rh2[l - 1] * b2[r - l + 1] % MOD + MOD) % MOD; };
    set<char> st;
    for (int i = 1; i < n; i++)
    {
        st.insert(s[i]);
        if ((int)st.size() == i)
        {
            if (gethash1(i + 1, n) == getrevhash1(1, n - i) && gethash2(i + 1, n) == getrevhash2(1, n - i))
            {
                cout << "HE\n";
                return;
            }
        }
    }
    cout << "NaN\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}