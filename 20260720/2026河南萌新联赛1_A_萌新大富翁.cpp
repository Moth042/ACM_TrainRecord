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
    int n, m;
    cin >> n >> m;
    vector<ll> c(n), cnt(n); // 剩余金钱和占用土地数量
    for (int i = 0; i < n; i++) cin >> c[i];
    vector<array<ll, 3>> g(m); // 格子状态
    for (int i = 0; i < m; i++)
    {
        cin >> g[i][0];
        if (g[i][0] == 1) cin >> g[i][1] >> g[i][2];
        else g[i][1] = g[i][2] = 0;
    }
    int k;
    cin >> k;
    vector<ll> t(k); // 骰子点数
    for (int i = 0; i < k; i++) cin >> t[i];
    int res = n;               // 剩余人数
    int st = 0;                // 当前轮到的玩家
    vector<int> pos(n);        // 每个玩家的位置
    vector<int> stop(n);       // 是否停牌
    vector<int> td(m, -1);     // 土地被谁占有
    vector<vector<int>> my(n); // 每名玩家拥有的土地编号
    int d = 0;
    for (int i = 0; i < k; i++)
    {
        if (res == 1) break;
        // while (st < n && c[st] < 0) st = (st + 1) % n;
        while (st < n && (stop[st] == 1 || c[st] < 0))
        {
            if (stop[st] == 1) stop[st] = 0;
            st = (st + 1) % n;
            // continue;
        }
        pos[st] = (pos[st] + t[i]) % m;
        // cout << i << ' ' << st << ' ' << pos[st] << '\n';
        int leixing = g[pos[st]][0];
        // cout << leixing << '\n';
        if (leixing == 0) c[st] += 200;
        else if (leixing == 1)
        {
            if (td[pos[st]] == -1)
            {
                if (c[st] >= g[pos[st]][1])
                {
                    c[st] -= g[pos[st]][1];
                    cnt[st]++;
                    td[pos[st]] = st;
                    my[st].push_back(pos[st]);
                }
            }
            else
            {
                if (td[pos[st]] != st)
                {
                    c[td[pos[st]]] += min(c[st], g[pos[st]][2]);
                    c[st] -= g[pos[st]][2];
                }
            }
        }
        else if (leixing == 2) c[st] += 150;
        else if (leixing == 3) c[st] -= 100;
        else stop[st] = 1;
        if (c[st] < 0)
        {
            res--;
            for (auto i : my[st]) td[i] = -1;
        }
        st = (st + 1) % n;
    }
    for (int i = 0; i < n; i++)
    {
        if (c[i] >= 0) cout << c[i] << ' ' << cnt[i] << '\n';
        else cout << "bankrupt 0\n";
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