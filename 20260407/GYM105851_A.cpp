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
        if (c == '-')
            s = -1;
        c = getchar();
    }
    return x * s;
}
// 快写
void write(i128 x)
{
    if (x > 9)
        write(x / 10);
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
    string s;
    cin >> s;
    int cnt1 = 0, cnt0 = 0;
    int mx1 = 0, mx0 = 0, mn1 = 1e9, mn0 = 1e9;
    for (int i = 0; i < n;)
    {
        int j = i;
        while (j < n && s[j] == s[i])
            j++;
        if (s[i] == '1')
        {
            cnt1++;
            mn1 = min(mn1, j - i);
            mx1 = max(mx1, j - i);
        }
        else
        {
            cnt0++;
            mn0 = min(mn0, j - i);
            mx0 = max(mx0, j - i);
        }
        i = j;
    }
    // if (mn0 == 1e9)
    //     mn0 = 0;
    // if (mn1 == 1e9)
    //     mn1 = 0;
    // cout << cnt0 << ' ' << cnt1 << ' ' << mn0 << ' ' << mn1 << '\n';
    if (cnt0 == cnt1)
        cout << "empty\n";
    else if (cnt0 < cnt1)
    {
        if (mx0 > 1)
            cout << "empty\n";
        else
        {
            for (int i = 1; i <= mn1; i++)
                cout << 1;
            cout << '\n';
        }
    }
    else
    {
        if (mx1 > 1)
            cout << "empty\n";
        else
        {
            for (int i = 1; i <= mn0; i++)
                cout << 0;
            cout << '\n';
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--)
        moth();
    return 0;
}