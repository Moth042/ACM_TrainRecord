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
    // vector<int> a(n * m);
    // iota(a.begin(), a.end(), 0);
    // do
    // {
    //     vector<vector<int>> t(n, vector<int>(m));
    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = 0; j < m; j++) t[i][j] = a[i * m + j];
    //     }
    //     bool ok = 1;
    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = 0; j < m; j++)
    //         {
    //             for (int k = 0; k < 4; k++)
    //             {
    //                 int nx = i + dx[k], ny = j + dy[k];
    //                 if (nx >= 0 && nx < n && ny >= 0 && ny < m)
    //                 {
    //                     if (t[nx][ny] == (t[i][j] + 1) % (n * m) || (t[nx][ny] + 1) % (n * m) == t[i][j]) ok = 0;
    //                 }
    //             }
    //         }
    //     }
    //     if (ok)
    //     {
    //         cout << "Yes\n";
    //         for (int i = 0; i < n; i++)
    //         {
    //             for (int j = 0; j < m; j++) cout << t[i][j] << " ";
    //             cout << '\n';
    //         }
    //         return;
    //     }
    // } while (next_permutation(a.begin(), a.end()));
    // cout << "No\n";
    bool ok = 0;
    if (n > m) swap(n, m), ok = 1;
    assert(n <= 200000);
    vector<vector<int>> t(n, vector<int>(m));
    int idx = 0;
    int cur = 0;
    while (idx < n * m)
    {
        if (cur >= n * m) cur = 1;

        t[idx / m][idx % m] = cur;
        // cout << cur << ' ';
        idx++;
        cur += 2;
        // if (cur == n * m - 1 && n * m % 2) cur = 1;
        // if (cur == n * m) cur = 1;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++) cout << t[i][j] << " ";
    //     cout << '\n';
    // }
    if (n == 2)
    {
        auto sw = t[1];
        for (int j = 0; j < m; j++) sw[j] = t[1][(j + 1) % m];
        t[1] = sw;
    }
    bool okk = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                {
                    if (t[nx][ny] == (t[i][j] + 1) % (n * m) || (t[nx][ny] + 1) % (n * m) == t[i][j]) okk = 0;
                }
            }
        }
    }
    if (!okk)
    {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    if (ok)
    {
        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n; i++) cout << t[i][j] << " ";
            cout << '\n';
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++) cout << t[i][j] << " ";
            cout << '\n';
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}