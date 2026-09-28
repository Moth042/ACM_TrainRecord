#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int N = 2e5 + 9;
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
int nex[N][26], idx = 0;
pair<int, int> cnt[N];
int vis[N];
struct Tire
{
    void init()
    {
        memset(nex, 0, sizeof nex);
        for (int i = 0; i < N; i++) cnt[i] = {0, 0};
        idx = 0;
    }
    void insert(string s, int st, ll c)
    {
        int p = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int j = s[i] - 'a';
            if (!nex[p][j]) nex[p][j] = ++idx;
            p = nex[p][j];
        }
        cnt[p].first = c;
        cnt[p].second = st;
    }
    int find(string s)
    {
        bool ok = 1;
        int p = 0;
        int ii = -1, jj = -1;
        for (int i = 0; i < s.length(); i++)
        {
            int j = s[i] - 'a';
            if (!nex[p][j])
            {
                // if (cnt[p].first == 0) return 0;
                // cnt[p].first--;
                // if (cnt[p].first == 0) vis[p] = 1;
                // return cnt[p].second;
                break;
            }
            // if (vis[nex[p][j]])
            // {
            //     cnt[p].first--;
            //     if (cnt[p].first == 0) vis[p] = 1;
            //     return cnt[p].second;
            // }
            // if (cnt[nex[p][j]].first == 0)
            // {
            //     cnt[p].first--;
            //     return cnt[p].second;
            // }
            p = nex[p][j];
            if (cnt[p].first != 0)
            {
                ii = p;
                jj = cnt[p].second;
            }
        }
        if (ii == -1) return 0;
        if (cnt[ii].first == 0) return 0;
        cnt[ii].first--;
        // if (cnt[p].first == 0) vis[p] = 1;
        return cnt[ii].second;
    }
};
void moth()
{
    int n, q;
    cin >> n >> q;

    Tire t;
    for (int i = 1; i <= n; i++)
    {
        string s;
        ll c;
        cin >> s >> c;
        // cout << s << ' ' << c << '\n';
        if (c) t.insert(s, i, c);
    }
    // cout << idx << '\n';
    // cout << cnt[3].first << " " << cnt[3].second << '\n';
    while (q--)
    {
        string s;
        cin >> s;
        cout << t.find(s) << '\n';
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
