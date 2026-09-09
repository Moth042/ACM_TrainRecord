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
struct Trie
{
    int nex[N][26], cnt[N], idx = 0;
    void init()
    {
        memset(nex, 0, sizeof nex);
        memset(cnt, 0, sizeof cnt);
        idx = 0;
    }
    vector<pair<int, int>> insert(string s)
    {
        vector<pair<int, int>> cur;
        int p = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int j = s[i] - 'a';
            if (!nex[p][j]) nex[p][j] = ++idx;
            p = nex[p][j];
            cnt[p]++;
            cur.push_back({cnt[p], i + 1});
        }
        return cur;
    }
};
void moth()
{
    int n;
    cin >> n;
    ll ans = 0;
    Trie trie;
    trie.init();
    vector<ll> f(n + 1);
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        ans += i;
        auto cur = trie.insert(s);
        for (auto [j, depth] : cur)
        {
            if (depth > f[j])
            {
                ans += (depth ^ j) - (f[j] ^ j);
                f[j] = depth;
            }
        }
        cout << ans << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}