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
    string s;
    cin >> s;
    int n = s.length();
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = s[i - 1] - '0';
    vector<int> stk;
    vector<pair<int, int>> pre(n + 1);
    pre[0] = {0, -1};
    for (int i = 1; i <= n; i++)
    {
        if (stk.size() && a[i] == stk.back()) stk.pop_back();
        else stk.push_back(a[i]);
        if (stk.size()) pre[i] = {stk.size(), stk.back()};
        else pre[i] = {0, -1};
    }
    if (pre[n].first == 0)
    {
        cout << s << '\n';
        return;
    }
    bool ok = 0;
    int st = -1, num = -1;
    for (int i = n; i >= 1; i--)
    {
        if (a[i] == 0) continue;
        if (ok) break;
        for (int j = a[i] - 1; j >= (i == 1); j--)
        {
            int sz;
            if (j == pre[i - 1].second) sz = pre[i - 1].first - 1;
            else sz = pre[i - 1].first + 1;
            if (n - i >= sz && (n - i - sz) % 2 == 0)
            {
                st = i;
                num = j;
                ok = 1;
                break;
            }
        }
    }
    // cout << st << ' ' << num << '\n';
    if (ok)
    {
        vector<int> ans;
        for (int i = 1; i <= st - 1; i++) ans.push_back(a[i]);
        ans.push_back(num);
        stk.clear();
        for (int i = 1; i <= st - 1; i++)
        {
            if (stk.size() && a[i] == stk.back()) stk.pop_back();
            else stk.push_back(a[i]);
        }
        if (stk.size() && num == stk.back()) stk.pop_back();
        else stk.push_back(num);
        int sz = stk.size();
        for (int i = 1; i <= n - st - sz; i++) ans.push_back(9);
        while (stk.size())
        {
            ans.push_back(stk.back());
            stk.pop_back();
        }
        for (auto i : ans) cout << i;
        cout << '\n';
    }
    else
    {
        if (n % 2 == 0) n -= 2;
        else n--;
        for (int i = 1; i <= n; i++) cout << 9;
        cout << '\n';
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