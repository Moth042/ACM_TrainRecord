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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), ji, ou;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] % 2) ji.push_back(a[i]);
        else ou.push_back(a[i]);
    }
    if (k == 0)
    {
        if (ji.size() && ou.size()) cout << -1 << '\n';
        else
        {
            for (int i = 1; i <= n; i++) cout << a[i] << " ";
            cout << '\n';
        }
        return;
    }
    vector<vector<int>> seg(k + 2);
    if (ji.size() >= ou.size())
    {
        int mx = (k + 2) / 2, mn = k + 1 - mx;
        if (ji.size() < mx || ou.size() < mn)
        {
            cout << -1 << '\n';
            return;
        }
        for (int i = 1; i <= k + 1; i++)
        {
            if (i % 2)
            {
                if (ji.size())
                {
                    seg[i].push_back(ji.back());
                    ji.pop_back();
                }
            }
            else
            {
                if (ou.size())
                {
                    seg[i].push_back(ou.back());
                    ou.pop_back();
                }
            }
        }
        while (ji.size())
        {
            seg[1].push_back(ji.back());
            ji.pop_back();
        }
        while (ou.size())
        {
            seg[2].push_back(ou.back());
            ou.pop_back();
        }
    }
    else
    {
        int mx = (k + 2) / 2, mn = k + 1 - mx;
        if (ou.size() < mx || ji.size() < mn)
        {
            cout << -1 << '\n';
            return;
        }
        for (int i = 1; i <= k + 1; i++)
        {
            if (i % 2)
            {
                if (ou.size())
                {
                    seg[i].push_back(ou.back());
                    ou.pop_back();
                }
            }
            else
            {
                if (ji.size())
                {
                    seg[i].push_back(ji.back());
                    ji.pop_back();
                }
            }
        }
        while (ji.size())
        {
            seg[2].push_back(ji.back());
            ji.pop_back();
        }
        while (ou.size())
        {
            seg[1].push_back(ou.back());
            ou.pop_back();
        }
    }
    for (int i = 1; i <= k + 1; i++)
    {
        // cout << seg[i].size() << '\n';
        // for (auto j : seg[i]) cout << j << " ";
        if (seg[i].size() == 0)
        {
            cout << -1 << '\n';
            return;
        }
    }
    for (int i = 1; i <= k + 1; i++)
    {
        for (auto j : seg[i]) cout << j << " ";
    }
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}