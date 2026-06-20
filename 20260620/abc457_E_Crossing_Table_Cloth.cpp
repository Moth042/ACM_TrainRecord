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
    int n, m;
    cin >> n >> m;
    int LOG = __lg(n) + 1;
    vector<vector<ll>> st(n + 1, vector<ll>(LOG + 1));
    vector<multiset<int>> L(n + 1), R(n + 1);
    vector<int> mnr(n + 1, 1e9);
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        cin >> l >> r;
        L[l].insert(r);
        R[r].insert(l);
        mnr[l] = min(mnr[l], r);
    }
    for (int i = 1; i <= n; i++) st[i][0] = mnr[i];
    vector<ll> lg2(n + 1, 0);
    for (int i = 2; i <= n; i++) lg2[i] = lg2[i >> 1] + 1;
    for (int j = 1; j <= LOG; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
    auto getMin = [&](int l, int r) -> ll
    {
        ll k = lg2[r - l + 1];
        return min(st[l][k], st[r - (1 << k) + 1][k]);
    };
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        if (L[l].empty() || R[r].empty()) cout << "No\n";
        else
        {
            if (L[l].find(r) != L[l].end())
            {
                L[l].erase(L[l].find(r));
                if (L[l].find(r) != L[l].end()) cout << "Yes\n";
                else
                {
                    if (mnr[l] < r) cout << "Yes\n";
                    else
                    {
                        if (l + 1 <= r && getMin(l + 1, r) <= r) cout << "Yes\n";
                        else cout << "No\n";
                    }
                }
                L[l].insert(r);
            }
            else
            {
                if (*L[l].begin() > r || *R[r].rbegin() < l) cout << "No\n";
                else
                {
                    auto it1 = L[l].upper_bound(r), it2 = R[r].lower_bound(l);
                    it1--;
                    if (*it1 + 1 >= *it2) cout << "Yes\n";
                    else cout << "No\n";
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}