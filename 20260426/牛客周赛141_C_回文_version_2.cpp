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
    string s1;
    int n = s.length();
    int st = 0;
    // for (int i = 0; i < n / 2; i++)
    // {
    //     // cout<<s1[i]<<' '<<s1[m-1-i]<<'\n';
    //     if (s[i+st] == s[n - 1 - i])continue;
    //     if(i<n-1&&s.substr(i,2)=="nn")
    //     {
    //         st++;
    //         continue;
    //     }
    // }
    int l = 0, r = n - 1;
    while (l + 1 <= r)
    {
        if (s[l] == s[r])
        {
            l++;
            r--;
        }
        else
        {
            if (l < n - 1 && s.substr(l, 2) == "nn") l++;
            else if (r - 1 >= 0 && r - 1 < n - 1 && s.substr(r - 1, 2) == "nn") r--;
            else
            {
                cout << "NO\n";
                return;
            }
            l++;
            r--;
        }
    }
    cout << "YES\n";
    // for (int i = 0; i < s.length(); i++)
    // {
    //     if (i < s.length() - 1 && s.substr(i, 2) == "nn")
    //     {
    //         s1 += 'm';
    //         i++;
    //     }
    //     else s1 += s[i];
    // }
    // // cout<<s1;
    // int m = s1.length();
    // // cout<<m<<'\n';
    // for (int i = 0; i < m / 2; i++)
    // {
    //     // cout<<s1[i]<<' '<<s1[m-1-i]<<'\n';
    //     if (s1[i] != s1[m - 1 - i])
    //     {
    //         cout << "NO\n";
    //         return;
    //     }
    // }
    // cout << "YES\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}