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
    vector<pair<int, int>> a(m + 1);
    vector<vector<int>> vl(n + 1), vr(n + 1);
    int mxl = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].first >> a[i].second;
        if (a[i].first > a[i].second) swap(a[i].first, a[i].second);
        vl[a[i].first].push_back(i);
        vr[--a[i].second].push_back(i);
        mxl = max(mxl, a[i].first);
    }
    int cl = 1, cr = n;
    multiset<int> st;
    for (int i = 1; i < n; i++)
    {
        for (auto j : vl[i]) st.insert(a[j].first);
        for (auto j : vr[i - 1])
        {
            cl = max(cl, a[j].first);
            cr = min(cr, a[j].second);
            st.erase(st.find(a[j].first));
        }
        if (cl > cr || i < mxl) continue;
        if (st.empty() || cl < *st.begin())
        {
            cout << "Yes\n";
            cout << cl + 1 << ' ' << i + 1 << '\n';
            return;
        }
    }
    cout << "No\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}