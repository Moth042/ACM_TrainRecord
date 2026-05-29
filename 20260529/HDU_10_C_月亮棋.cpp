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
    vector<vector<int>> vis1(4, vector<int>(4)), vis2(4, vector<int>(4));
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second, vis2[a[i].first][a[i].second] = 1;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        vis2[x][y] = 1;
    }
    auto inmap = [&](int x, int y) -> int
    {
        if (x >= 1 && x <= 3 && y >= 1 && y <= 3) return 1;
        return 0;
    };
    if (n < 2)
    {
        cout << "Columbina Hyposelenia\n";
        return;
    }
    if (n == 2)
    {
        int x1 = a[1].first, y1 = a[1].second;
        int x2 = a[2].first, y2 = a[2].second;
        if (x1 == x2)
        {
            for (int i = 1; i <= 3; i++)
            {
                if (!vis1[x1][i] && !vis2[x1][i])
                {
                    cout << x1 << ' ' << i << '\n';
                    return;
                }
            }
        }
        if (y1 == y2)
        {
            for (int i = 1; i <= 3; i++)
            {
                if (!vis1[i][y1] && !vis2[i][y1])
                {
                    cout << i << ' ' << y1 << '\n';
                    return;
                }
            }
        }
        if (x1 == y1 && x2 == y2)
        {
            for (int i = 1; i <= 3; i++)
            {
                if (!vis1[i][i] && !vis2[i][i])
                {
                    cout << i << ' ' << i << '\n';
                    return;
                }
            }
        }
        if (x1 + y1 == 4 && x2 + y2 == 4)
        {
            for (int i = 1; i <= 3; i++)
            {
                if (!vis1[i][4 - i] && !vis2[i][4 - i])
                {
                    cout << i << ' ' << 4 - i << '\n';
                    return;
                }
            }
        }
        cout << "Columbina Hyposelenia\n";
        return;
    }
    // vector<pair<int, int>> v;
    // for (int i = 1; i <= 2; i++)
    // {
    //     for (int j = i + 1; j <= 3; j++)
    //     {
    //         int x1 = a[i].first, y1 = a[i].second, x2 = a[j].first, y2 = a[j].second;
    //         if (x1 == x2)
    //         {
    //             for (int k = 1; k <= 3; k++)
    //             {
    //                 if (!vis1[x1][k] && !vis2[x1][k])
    //                 {
    //                     // cout << x1 << ' ' << i << '\n';
    //                     v.push_back({x1, k});
    //                     break;
    //                     // return;
    //                 }
    //             }
    //         }
    //         if (y1 == y2)
    //         {
    //             for (int k = 1; k <= 3; k++)
    //             {
    //                 if (!vis1[k][y1] && !vis2[k][y1])
    //                 {
    //                     // cout << i << ' ' << y1 << '\n';
    //                     // return;
    //                     v.push_back({k, y1});
    //                     break;
    //                 }
    //             }
    //         }
    //         if (x1 == y1 && x2 == y2)
    //         {
    //             for (int k = 1; k <= 3; k++)
    //             {
    //                 if (!vis1[k][k] && !vis2[k][k])
    //                 {
    //                     // cout << i << ' ' << i << '\n';
    //                     // return;
    //                     v.push_back({k, k});
    //                     break;
    //                 }
    //             }
    //         }
    //         if (x1 + y1 == 4 && x2 + y2 == 4)
    //         {
    //             for (int k = 1; k <= 3; k++)
    //             {
    //                 if (!vis1[k][4 - k] && !vis2[k][4 - k])
    //                 {
    //                     // cout << i << ' ' << 4 - i << '\n';
    //                     // return;
    //                     v.push_back({k, 4 - k});
    //                 }
    //             }
    //         }
    //     }
    // }
    // if (v.size() == 0)
    // {
    //     cout << "Columbina Hyposelenia\n";
    //     return;
    // }
    // sort(v.begin(), v.end());
    // cout << v[0].first << ' ' << v[0].second << '\n';
    int x1 = a[2].first, y1 = a[2].second;
    int x2 = a[3].first, y2 = a[3].second;
    if (x1 == x2)
    {
        for (int i = 1; i <= 3; i++)
        {
            if (!vis1[x1][i] && !vis2[x1][i])
            {
                cout << x1 << ' ' << i << '\n';
                return;
            }
        }
    }
    if (y1 == y2)
    {
        for (int i = 1; i <= 3; i++)
        {
            if (!vis1[i][y1] && !vis2[i][y1])
            {
                cout << i << ' ' << y1 << '\n';
                return;
            }
        }
    }
    if (x1 == y1 && x2 == y2)
    {
        for (int i = 1; i <= 3; i++)
        {
            if (!vis1[i][i] && !vis2[i][i])
            {
                cout << i << ' ' << i << '\n';
                return;
            }
        }
    }
    if (x1 + y1 == 4 && x2 + y2 == 4)
    {
        for (int i = 1; i <= 3; i++)
        {
            if (!vis1[i][4 - i] && !vis2[i][4 - i])
            {
                cout << i << ' ' << 4 - i << '\n';
                return;
            }
        }
    }
    cout << "Columbina Hyposelenia\n";
    // return;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}