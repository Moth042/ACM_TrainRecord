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
string s1 = "23456789TJQKA", s2 = "CDHS";
using score = array<int, 6>;
// 给每张牌编号
int id(string s)
{
    return (int)s1.find(s[0]) * 4 + (int)s2.find(s[1]);
}
score gets(array<int, 5> h)
{
    vector<int> cnt(13); // 记录每种数字牌的数量
    vector<int> r;       // 存储牌的数字
    bool flush = 1;      // 同花
    for (auto i : h)
    {
        cnt[i / 4]++;
        r.push_back(i / 4);
        flush &= (i % 4 == h[0] % 4);
    }
    sort(r.rbegin(), r.rend());
    vector<pair<int, int>> g;
    for (int i = 0; i < 13; i++)
    {
        if (cnt[i]) g.push_back({cnt[i], i});
    }
    int straight = -1;                                // 顺子最大数字
    if (adjacent_find(r.begin(), r.end()) == r.end()) // 判断顺子
    {
        if (r == vector<int>{12, 3, 2, 1, 0}) straight = 3; // 处理特殊顺子
        else if (r[0] - r[4] == 4) straight = r[0];
    }
    sort(g.rbegin(), g.rend());
    score s{};                                             // 把s中所有值初始化为0，注意如果不加上后面的{}会导致出现上一块内存留下的脏数据
    if (flush && straight != -1) s[0] = 8;                 // 同花顺
    else if (g[0].first == 4) s[0] = 7;                    // 四条
    else if (g[0].first == 3 && g[1].first == 2) s[0] = 6; // 葫芦
    else if (flush) s[0] = 5;                              // 同花
    else if (straight != -1) s[0] = 4;                     // 顺子
    else if (g[0].first == 3) s[0] = 3;                    // 三条
    else if (g[0].first == 2 && g[1].first == 2) s[0] = 2; // 两对
    else if (g[0].first == 2) s[0] = 1;                    // 一对

    if (straight != -1) s[1] = straight; // 如果是顺子是需要比较顺子的最大数即可
    else
    {
        // 否则按出现次数顺序存下每张牌的数字
        int p = 1;
        for (auto [f, t] : g) s[p++] = t;
    }
    return s;
}
void moth()
{
    vector<int> a(8);
    vector<int> used(52);
    for (int i = 0; i < 8; i++)
    {
        string s;
        cin >> s;
        a[i] = id(s);
        used[a[i]] = 1;
    }
    vector<score> myval(52), hisval(52);

    // 枚举每种暗牌对应得分
    for (int i = 0; i < 52; i++)
    {
        myval[i] = gets({a[0], a[1], a[2], a[3], i});
        hisval[i] = gets({a[4], a[5], a[6], a[7], i});
    }
    bool iwin = 1, hewin = 0;
    for (int his = 0; his < 52; his++)
    {
        if (!used[his])
        {
            score best{-1};
            for (int my = 0; my < 52; my++)
            {
                if (!used[my] && my != his) best = max(best, myval[my]);
            }

            // 我必胜的条件是对于他的每种暗牌我的最大值都能比他大
            // 他必胜的策略是存在一种暗牌使得他的得分大于我的最大值
            // 如果两种情况都不存在，例如出现等于，那就是平局
            iwin &= (best > hisval[his]);
            hewin |= (best < hisval[his]);
        }
    }
    if (iwin) cout << "WoYaoYanPai\n";
    else if (hewin) cout << "GeiWoCaPiXie\n";
    else cout << "PaiMeiYouWenTi\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}