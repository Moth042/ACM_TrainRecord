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
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<vector<char>> aa(n + 1, vector<char>(m + 1));
    vector<vector<int>> cnt(n + a + 1, vector<int>(m + b + 1)), d(n + a + 1, vector<int>(m + b + 1)), p(n + a + 1, vector<int>(m + b + 1));
    auto op = [&](int x, int y) -> void
    {
        d[x][y]++;
        d[x][y + b]--;
        d[x + a][y]--;
        d[x + a][y + b]++;
    };
    auto cal = [&](int x, int y) -> bool
    {
        int t = cnt[x + a - 1][y + b - 1] - cnt[x + a - 1][y - 1] - cnt[x - 1][y + b - 1] + cnt[x - 1][y - 1];
        // cout<<x<<' '<<y<<' '<<t<<'\n';
        if (t) return 0;
        return 1;
    };
    int stx = -1, sty = -1, edx = -1, edy = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> aa[i][j];
            if (aa[i][j] == '#') d[i][j]++;
            if (aa[i][j] == 'S')
            {
                stx = i;
                sty = j;
            }
            if (aa[i][j] == 'E')
            {
                edx = i;
                edy = j;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) cnt[i][j] = cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1] + d[i][j];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + cnt[i][j];
    }
    vector<vector<int>> vis(n + 1, vector<int>(m + 1));
    queue<pair<int, int>> q;
    q.push({stx, sty});
    vis[stx][sty] = 1;
    while (q.size())
    {
        auto [u, l] = q.front();
        q.pop();
        if (u == edx && l == edy)
        {
            cout << "Yes\n";
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int nxu = u + dx[i], nxd = u + a - 1 + dx[i], nxl = l + dy[i], nxr = l + b - 1 + dy[i];
            if (nxu >= 1 && nxu <= n && nxd >= 1 && nxd <= n && nxl >= 1 && nxl <= m && nxr >= 1 && nxr <= m && !vis[nxu][nxl] && cal(nxu, nxl))
            {
                q.push({nxu, nxl});
                vis[nxu][nxl] = 1;
            }
        }
    }
    cout << "No\n";
    // int U = stx, L = sty, D = stx + a - 1, R = sty + b - 1;
    // // cout << U << ' ' << D << ' ' << L << ' ' << R << '\n';
    // queue<array<int, 4>> q;
    // vector<vector<vector<vector<int>>>> vis(n + 1, vector<vector<vector<int>>>(n + 1, vector<vector<int>>(m + 1, vector<int>(m + 1))));
    // q.push({U, D, L, R});
    // while (q.size())
    // {
    //     auto [U, D, L, R] = q.front();
    //     q.pop();
    //     if (U == edx && L == edy)
    //     {
    //         cout << "Yes\n";
    //         return;
    //     }
    //     if (vis[U][D][L][R]) continue;
    //     vis[U][D][L][R] = 1;
    //     for (int i = 0; i < 4; i++)
    //     {
    //         int nxU = U + dx[i], nxD = D + dx[i], nxL = L + dy[i], nxR = R + dy[i];
    //         bool ok = 0;
    //         if (nxU >= 1 && nxU <= n && nxD >= 1 && nxD <= n && nxL >= 1 && nxL <= m && nxR >= 1 && nxR <= m)
    //         {
    //             if (i == 0)
    //             {
    //                 auto tt = r[nxU];
    //                 auto it = lower_bound(tt.begin(), tt.end(), nxL);
    //                 if (it == tt.end()) ok = 1;
    //                 else
    //                 {
    //                     if (*it > nxR) ok = 1;
    //                 }
    //                 if (ok) q.push({nxU, nxD, nxL, nxR});
    //             }
    //             if (i == 1)
    //             {
    //                 auto tt = c[nxR];
    //                 auto it = lower_bound(tt.begin(), tt.end(), nxU);
    //                 if (it == tt.end()) ok = 1;
    //                 else
    //                 {
    //                     if (*it > nxD) ok = 1;
    //                 }
    //                 if (ok) q.push({nxU, nxD, nxL, nxR});
    //             }
    //             if (i == 2)
    //             {
    //                 auto tt = r[nxD];
    //                 auto it = lower_bound(tt.begin(), tt.end(), nxL);
    //                 if (it == tt.end()) ok = 1;
    //                 else
    //                 {
    //                     if (*it > nxR) ok = 1;
    //                 }
    //                 if (ok) q.push({nxU, nxD, nxL, nxR});
    //             }
    //             if (i == 3)
    //             {
    //                 auto tt = c[nxL];
    //                 auto it = lower_bound(tt.begin(), tt.end(), nxU);
    //                 if (it == tt.end()) ok = 1;
    //                 else
    //                 {
    //                     if (*it > nxR) ok = 1;
    //                 }
    //                 if (ok) q.push({nxU, nxD, nxL, nxR});
    //             }
    //         }
    //     }
    // }
    // cout << "No\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}