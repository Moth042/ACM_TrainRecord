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
    int n, p;
    cin >> n >> p;
    vector<string> a = {"WrongProblem", "SameProblem", "UnreasonableProblemArrangement", "UnreasonableLimitForProblem", "WeakTestsForProblem", "BadProblem"};
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        if (s.length() == a[0].length() + 1 && s.substr(0, a[0].length()) == a[0] && s.back() >= 'A' && s.back() <= 'L') ans += 100;
        if (s.length() == a[1].length() + 1 && s.substr(0, a[1].length()) == a[1] && s.back() >= 'A' && s.back() <= 'L') ans += 30;
        if (s == a[2]) ans += 10;
        if (s.length() == a[3].length() + 1 && s.substr(0, a[3].length()) == a[3] && s.back() >= 'A' && s.back() <= 'L') ans += 5;
        if (s.length() == a[4].length() + 1 && s.substr(0, a[4].length()) == a[4] && s.back() >= 'A' && s.back() <= 'L') ans += 3;
        if (s.length() == a[5].length() + 1 && s.substr(0, a[5].length()) == a[5] && s.back() >= 'A' && s.back() <= 'L') ans += 1;
    }
    if (ans > p) cout << "Joker\n";
    else cout << "Judger\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}