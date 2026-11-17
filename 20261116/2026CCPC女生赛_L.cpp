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
    vector<int> ok(26, 240);
    int n, m, q;
    cin >> n >> m >> q;
    vector<set<string>> submit(26);
    vector<set<string>> ac(26);
    set<char> ans;
    for (int i = 1; i <= q; i++)
    {
        string name, result;
        int time;
        char num;
        cin >> name >> num >> result >> time;
        submit[num - 'A'].insert(name);
        if (result == "AC") ac[num - 'A'].insert(name);
        if ((submit[num - 'A'].size() > 0 && 5 * ac[num - 'A'].size() >= submit[num - 'A'].size()) || (ac.size() >= 50) || (time >= 240))
        {
            if (ok[num - 'A'] == 240) ok[num - 'A'] = min(ok[num - 'A'], time);
        }
        else
        {
            if (ok[num - 'A'] < 240) ans.insert(num);
        }
    }
    if (ans.size())
    {
        for (auto i : ans) cout << i;
    }
    else cout << '-';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}