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
    string s1, s2;
    cin >> s1 >> s2;
    int lst = 0;
    vector<ll> v1, v2;
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] == '.')
        {
            string t = s1.substr(lst, i - lst);
            lst = i + 1;
            v1.push_back(stoll(t));
        }
    }
    string t = s1.substr(lst, s1.length() - lst);
    v1.push_back(stoll(t));
    lst = 0;
    for (int i = 0; i < s2.length(); i++)
    {
        if (s2[i] == '.')
        {
            t = s2.substr(lst, i - lst);
            lst = i + 1;
            v2.push_back(stoll(t));
        }
    }
    t = s2.substr(lst, s2.length() - lst);
    v2.push_back(stoll(t));
    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i] < v2[i])
        {
            cout << "B\n";
            return;
        }
        if (v1[i] > v2[i])
        {
            cout << "A\n";
            return;
        }
    }
    cout << "Equal\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}