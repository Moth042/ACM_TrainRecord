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
    vector<vector<char>> a(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    auto inmap = [&](int x, int y) -> int
    {
        if (x >= 1 && x <= n && y >= 1 && y <= m) return 1;
        return 0;
    };
    auto cal = [&](int x, int y) -> int
    {
        int ans = 0;
        // if (inmap(x - 1, y) && inmap(x - 1, y - 1))
        // {
        //     set<int> st;
        //     st.insert(a[x][y]);
        //     st.insert(a[x - 1][y]);
        //     st.insert(a[x - 1][y - 1]);
        //     if (st.size() == 3) ans++;
        // }
        // if (inmap(x - 1, y) && inmap(x - 1, y + 1))
        // {
        //     set<int> st;
        //     st.insert(a[x][y]);
        //     st.insert(a[x - 1][y]);
        //     st.insert(a[x - 1][y + 1]);
        //     if (st.size() == 3) ans++;
        // }
        if (inmap(x - 1, y) && inmap(x, y - 1))
        {
            set<char> st;
            st.insert(a[x][y]);
            st.insert(a[x - 1][y]);
            st.insert(a[x][y - 1]);
            if (st.size() == 3) ans++;
        }
        if (inmap(x - 1, y) && inmap(x, y + 1))
        {
            set<char> st;
            st.insert(a[x][y]);
            st.insert(a[x - 1][y]);
            st.insert(a[x][y + 1]);
            if (st.size() == 3) ans++;
        }
        if (inmap(x, y - 1) && inmap(x + 1, y))
        {
            set<char> st;
            st.insert(a[x][y]);
            st.insert(a[x][y - 1]);
            st.insert(a[x + 1][y]);

            if (st.size() == 3) ans++;
        }
        if (inmap(x, y + 1) && inmap(x + 1, y))
        {
            set<char> st;
            st.insert(a[x][y]);
            st.insert(a[x][y + 1]);
            st.insert(a[x + 1][y]);
            if (st.size() == 3) ans++;
        }
        // if (inmap(x + 1, y) && inmap(x + 1, y - 1))
        // {
        //     set<int> st;
        //     st.insert(a[x][y]);
        //     st.insert(a[x + 1][y]);
        //     st.insert(a[x + 1][y - 1]);
        //     if (st.size() == 3) ans++;
        // }
        // if (inmap(x + 1, y) && inmap(x + 1, y + 1))
        // {
        //     set<int> st;
        //     st.insert(a[x][y]);
        //     st.insert(a[x + 1][y]);
        //     st.insert(a[x + 1][y + 1]);
        //     if (st.size() == 3) ans++;
        // }
        return ans;
    };
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // cout<<cal(i,j)<<' ';
            ans += cal(i, j);
        }
        cout << '\n';
    }
    cout << ans << '\n';
    // cout<<cal(1,2)<<'\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}