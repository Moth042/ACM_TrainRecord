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
    string s;
    cin >> n >> m;
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) cin >> cnt[i];
    cin >> s;
    s = " " + s;
    set<int> st;
    for (int i = 1; i <= n; i++) st.insert(i);
    int z = 1;
    auto it = st.begin();
    auto L = [&]() -> void
    {
        if (it == st.begin()) it = st.end(), it--;
        else it--;
    };
    auto R = [&]() -> void
    {
        it++;
        if (it == st.end()) it = st.begin();
    };
    for (int i = 1; i <= m; i++)
    {
        if (s[i] == 'S')
        {
            cnt[*it]--;
            if (cnt[*it] == 0)
            {
                it = st.erase(it);
                if (it == st.end()) it = st.begin();
                if (z)
                {
                    R();
                    // R();
                }
                else
                {
                    L();
                    // L();
                }
            }
            else
            {
                if (z)
                {
                    R();
                    R();
                }
                else
                {
                    L();
                    L();
                }
            }
        }
        else if (s[i] == 'R')
        {
            cnt[*it]--;
            z ^= 1;
            if (cnt[*it] == 0)
            {
                it = st.erase(it);
                if (it == st.end()) it = st.begin();
                if (!z) L();
            }
            else
            {
                if (z) R();
                else L();
            }
        }
        else if (s[i] == 'D')
        {
            cnt[*it]--;
            if (cnt[*it] == 0)
            {
                it = st.erase(it);
                if (it == st.end()) it = st.begin();
                if (!z) L();
            }
            else
            {
                if (z) R();
                else L();
            }
            cnt[*it] += 2;
            if (z) R();
            else L();
        }
        else
        {
            // if (i == 5) cout << "UES\n";
            cnt[*it]--;
            if (cnt[*it] == 0)
            {
                // if (i == 5) cout << "juejue\n";
                // if (i == 5) cout << *it << '\n';
                it = st.erase(it);
                if (it == st.end()) it = st.begin();
                // if (i == 5) cout << *it << '\n';
                // if (i == 5) cout << st.size() << '\n';
                if (!z) L();
            }
            else
            {
                if (z) R();
                else L();
            }
        }
        // if (i == 5) cout << 5<<' ' << st.size() << '\n';
        // for (int j = 1; j <= n; j++) cout << cnt[j] << " ";
        // cout << '\n';
        // cout << *it << '\n';
    }
    for (int i = 1; i <= n; i++) cout << max(0, cnt[i]) << "\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}