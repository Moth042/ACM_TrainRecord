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
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i <= n; i++) cin >> a[i];
    string s;
    int st = -1;
    for (int i = 0; i <= n - 1; i++)
    {
        s += 'R';
        a[i + 1]--;
        while (a[i] > 1)
        {
            s += "LR";
            a[i]--;
            a[i + 1]--;
        }
        if (a[i + 1] < 0)
        {
            // cout << i << '\n';
            cout << "Impossible\n";
            return;
        }
        if (a[i + 1] == 0)
        {
            st = i + 1;
            break;
        }
    }
    if (st != -1)
    {
        for (int i = st; i <= n; i++)
        {
            if (a[i])
            {
                cout << "Impossible\n";
                return;
            }
        }
        for (int i = st - 1; i >= 0; i--) s += 'L';
        cout << s << '\n';
        return;
    }

    while (a[n] > 0)
    {
        s += "LR";
        a[n - 1]--;
        a[n]--;
    }
    if (a[n - 1] != 1)
    {
        cout << "Impossible\n";
        return;
    }
    for (int i = n - 1; i >= 0; i--) s += 'L';
    cout << s << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}