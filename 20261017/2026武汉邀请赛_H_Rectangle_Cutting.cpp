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
struct Node
{
    ll x, y;
    bool operator<(const Node &v) const
    {
        if (y - x == v.y - v.x)
        {
            if (x == v.x) return y < v.y;
            return x < v.x;
        }
        return y - x > v.y - v.x;
    }
};
void moth()
{
    ll n, m, q;
    cin >> n >> m >> q;
    // pair<ll, ll> mxx = {1, n}, mxy = {1, m}, mxx2 = {0, 0}, mxy2 = {0, 0};
    set<ll> stx, sty;
    set<Node> sttx, stty;
    stx.insert(1);
    stx.insert(n);
    sty.insert(1);
    sty.insert(m);
    sttx.insert({1, n});
    stty.insert({1, m});
    while (q--)
    {
        int op;
        ll x;
        cin >> op >> x;
        // cout << q << ":\n";
        if (op == 1)
        {
            auto it = stx.upper_bound(x);
            ll r = *it;
            it--;
            ll l = *it;
            // cout << l << ' ' << r << '\n';
            stx.insert(x);
            stx.insert(x + 1);
            sttx.erase({l, r});
            // if (q == 4)
            // {
            sttx.insert({l, x});
            // cout << "sb\n";
            //}
            sttx.insert({x + 1, r});
        }
        else
        {
            auto it = sty.upper_bound(x);
            ll r = *it;
            it--;
            ll l = *it;
            // cout << l << ' ' << r << '\n';
            sty.insert(x);
            sty.insert(x + 1);
            stty.erase({l, r});
            stty.insert({l, x});
            stty.insert({x + 1, r});
        }
        // cout << "x:\n";
        // for (auto [l, r] : sttx) cout << l << ' ' << r << '\n';
        // cout << "y:\n";
        // for (auto [l, r] : stty) cout << l << ' ' << r << '\n';
        auto x1 = sttx.begin(), x2 = stty.begin();

        cout << (x1->y - x1->x + 1) * (x2->y - x2->x + 1) << '\n';
    }
    // set<Node> s;
    // s.insert({2, 2});
    // s.insert({3, 3});
    // cout << s.size() << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}