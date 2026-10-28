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
    ll k;
    cin >> n >> m >> k;
    vector<ll> s(n + 1);
    vector<vector<ll>> p(n + 1, vector<ll>(m + 1));
    vector<array<ll, 3>> tr(n + 1);
    vector<pair<ll, ll>> need(n + 1);
    tr[0] = {-1, 0, 0};
    // map<ll, ll> mx, pmx;
    // set<ll> ss;
    // ss.insert(0);
    vector<ll> ji;
    ji.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        // ss.insert(s[i]);
        ji.push_back(s[i]);
        ll sum = 0, cnt = 0;
        for (int j = 1; j <= m; j++)
        {
            cin >> p[i][j];
            if (p[i][j] == -1) cnt++;
            else sum += p[i][j];
        }
        // if (!mx.count(s[i])) mx[s[i]] = sum;
        // else mx[s[i]] = max(mx[s[i]], sum);
        need[i].first = cnt;
        tr[i] = {sum, 0, cnt * k};
    }
    // int lst = -1e9, lstmx = -1e9;
    // mx[0] = -1;
    // for (auto i : ss)
    // {
    //     pmx[i] = max(lstmx, lst);
    //     lst = mx[i];
    //     lstmx = pmx[i];
    // }
    vector<int> pos(n + 1);
    iota(pos.begin(), pos.end(), 0);
    sort(pos.begin() + 1, pos.end(), [&](int x, int y) { return s[x] < s[y]; });
    // // for (int i = 1; i <= n; i++) cout << pos[i] << " ";
    // // cout << '\n';
    // for (int i = 1; i <= n; i++)
    // {
    //     int nows = s[pos[i]];
    //     if()
    //     if (tr[pos[i]][0] + tr[pos[i]][2] <)
    //         if (s[pos[i]] == s[pos[i - 1]])
    //         {
    //             if (tr[pos[i]][0] < tr[pos[i - 1]][0])
    //             {
    //                 // if (tr[pos[i]][0] + tr[pos[i]][2] < tr[pos[i - 1]][0])
    //                 // {
    //                 //     cout<<tr[pos[i]][0]<<' '<<tr[pos[i]][2]<<' '<<tr[pos[i-1]][0]<<' ';
    //                 //     cout << 1 << ' ' << i << ' ';
    //                 //     cout << "No\n";
    //                 //     return;
    //                 // }
    //                 need[pos[i]].second = tr[pos[i - 1]][0] - tr[pos[i]][0];
    //                 tr[pos[i]][0] = tr[pos[i - 1]][0];
    //             }
    //         }
    //         else
    //         {
    //             if (tr[pos[i]][0] <= tr[pos[i - 1]][0])
    //             {
    //                 if (tr[pos[i]][0] + tr[pos[i]][2] <= tr[pos[i - 1]][0])
    //                 {
    //                     // cout << 2 << ' ' << i << ' ';
    //                     cout << "No\n";
    //                     return;
    //                 }
    //                 need[pos[i]].second = tr[pos[i - 1]][0] + 1 - tr[pos[i]][0];
    //                 tr[pos[i]][0] = tr[pos[i - 1]][0] + 1;
    //             }
    //         }
    // }

    sort(ji.begin(), ji.end());
    ji.erase(unique(ji.begin(), ji.end()), ji.end());
    auto get = [&](ll x) -> int { return lower_bound(ji.begin(), ji.end(), x) - ji.begin(); };
    int sz = ji.size();
    vector<int> lst(sz, -1);
    for (int i = 1; i < sz; i++) lst[i] = ji[i - 1];
    vector<vector<int>> b(sz);
    vector<ll> mx(sz);
    mx[0] = -1;
    for (int i = 1; i <= n; i++) b[get(s[i])].push_back(i);
    for (int i = 1; i < sz; i++)
    {
        ll curj = ji[i], lstj = ji[i - 1];
        for (auto j : b[i])
        {
            mx[i] = max(mx[i], tr[j][0]);
            if (tr[j][0] <= mx[i - 1])
            {
                if (tr[j][0] + tr[j][2] <= mx[i - 1])
                {
                    cout << "No\n";
                    return;
                }
                need[j].second = mx[i - 1] + 1 - tr[j][0];
                mx[i] = max(mx[i], mx[i - 1] + 1);
            }
            // else mx[i]=max(mx[i],tr[j][0]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ll sum = need[i].second;
        for (int j = 1; j <= m; j++)
        {
            if (p[i][j] != -1) continue;
            p[i][j] = min(sum, k);
            sum -= min(sum, k);
        }
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) cout << p[i][j] << " ";
        cout << '\n';
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