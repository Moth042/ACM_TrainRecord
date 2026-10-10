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
    string s;
    cin >> n >> s;
    s = " " + s;
    int lstr = -1, lsts = -1, lstp = -1;
    for (int i = n; i >= 1; i--)
    {
        if (s[i] == 'R' && lstr == -1) lstr = i;
        if (s[i] == 'S' && lsts == -1) lsts = i;
        if (s[i] == 'P' && lstp == -1) lstp = i;
    }
    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'R' && lsts != -1 && lsts > i) v.push_back({i, lsts});
        if (s[i] == 'S' && lstp != -1 && lstp > i) v.push_back({i, lstp});
        if (s[i] == 'P' && lstr != -1 && lstr > i) v.push_back({i, lstr});
    }
    int sz = v.size();
    for (int i = 0; i < sz; i++)
    {
        int R = v[i].second;
        int l = i + 1, r = sz - 1;
        int st = -1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (v[mid].first > R)
            {
                st = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        if (st == -1 || v[st].first <= R)
        {
            cout << "Alice\n";
            return;
        }
    }
    cout << "Bob\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}