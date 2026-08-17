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
    vector<int> d;
    d.push_back(-1);
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ',') d.push_back(i);
    }
    map<string, int> mp;
    d.push_back(n);
    for (int i = 1; i < d.size(); i++)
    {
        int len = d[i] - d[i - 1] - 1;
        string cur = s.substr(d[i - 1] + 1, len);
        int st = -1;
        for (int j = 0; j < cur.length(); j++)
        {
            if (cur[j] == ':')
            {
                st = j;
                break;
            }
        }
        string tt = cur.substr(0, st), num = cur.substr(st + 1, cur.length() - st);
        int num2 = stoi(num);
        if (mp.count(tt)) mp[tt] += num2;
        else mp[tt] = num2;
    }
    cout << mp.size() << '\n';
    string ans;
    int mx = 0;
    for (auto [k, v] : mp)
    {
        if (v > mx)
        {
            mx = v;
            ans = k;
        }
        else if (v == mx)
        {
            if (k < ans) ans = k;
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}