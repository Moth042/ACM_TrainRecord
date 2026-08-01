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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<set<int>> s(3);
    for (int i = 0; i < 3; i++)
    {
        s[i].insert(0);
        s[i].insert(n + 1);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[a[i]].insert(i);
    }
    while (q--)
    {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1)
        {
            s[a[l]].erase(l);
            a[l] = r;
            s[a[l]].insert(l);
        }
        else
        {
            int s2 = *s[2].lower_bound(l);
            int s1 = *s[1].lower_bound(s2);
            int s0 = *s[0].lower_bound(s1);
            if (s0 <= r)
            {
                cout << 2 << '\n';
                continue;
            }
            if (s1 <= r)
            {
                cout << 1 << '\n';
                continue;
            }
            s0 = *s[0].lower_bound(s2);
            if (s0 <= r)
            {
                cout << 1 << '\n';
                continue;
            }
            s1 = *s[1].lower_bound(l);
            s0 = *s[0].lower_bound(s1);
            if (s0 <= r)
            {
                cout << 1 << '\n';
                continue;
            }
            cout << 0 << '\n';
        }
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