#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int N = 1e6 + 9;
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
const int B = 13331;
int nex[N][26], cnt[N], idx = 0;
struct Tire
{
    void init()
    {
        memset(nex, 0, sizeof nex);
        memset(cnt, 0, sizeof cnt);
        idx = 0;
    }
    void insert(string s)
    {
        int p = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int j = s[i] - 'a';
            if (!nex[p][j]) nex[p][j] = ++idx;
            p = nex[p][j];
        }
        cnt[p]++;
    }
    int find(string s)
    {
        int p = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int j = s[i] - 'a';
            if (!nex[p][j]) return 0;
            p = nex[p][j];
        }
        return cnt[p];
    }
};
void moth()
{
    // auto isPrime = [&](int x) -> bool
    // {
    //     if (x <= 1) return false;
    //     for (int i = 2; i * i <= x; i++)
    //     {
    //         if (x % i == 0) return false;
    //     }
    //     return true;
    // };
    // auto findPrime = [&](int n) -> int
    // {
    //     while (!isPrime(n)) n++;
    //     return n;
    // };
    // const int P = findPrime(rnd() % 900000000 + 100000000);
    int n;
    cin >> n;
    vector<string> a(n + 1);
    Tire t;
    t.init();
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        reverse(a[i].begin(), a[i].end());
        t.insert(a[i]);
    }
    cout << idx << '\n';
    // vector<vector<ll>> h(n + 1), p(n + 1);
    // for (int i = 1; i <= n; i++)
    // {
    //     int m = a[i].length();
    //     h[i].assign(m + 1, 0), p[i].assign(m + 1, 0);
    //     for (int j = 0; j < m; j++) h[i][j + 1] = (1LL * h[i][j] * B + a[i][j]) % P;
    //     p[i][0] = 1;
    //     for (int j = 0; j < m; j++) p[i][j + 1] = 1LL * p[i][j] * B % P;
    // }
    // auto get = [&](int i, int l, int r) -> ll { return (h[i][r] + 1LL * (P - h[i][l]) * p[i][r - l]) % P; };
    // set<ll> st;
    // for (int i = 1; i <= n; i++)
    // {
    //     int m = a[i].length();
    //     for (int j = 0; j < m; j++) st.insert(get(i, j, m - 1));
    // }
    // cout << st.size() << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}