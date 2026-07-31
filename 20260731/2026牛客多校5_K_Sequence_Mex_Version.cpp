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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n * 2);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[n + i] = a[i];
    }
    vector<ll> vis(4);
    vector<ll> cur(n * 2);
    for (int i = 0; i < n * 2; i++) cur[i] = a[i];
    vector<ll> nxt;
    map<vector<ll>, int> mp;
    vector<vector<ll>> ans;
    ans.push_back(cur);
    mp[cur] = 0;
    int st1 = -1, st2 = -1;
    // for (int i = 0; i < n * 2; i++) cout << cur[i] << " ";
    // cout << '\n';
    for (int t = 1; t <= k; t++)
    {
        for (int i = 0; i < n; i++)
        {
            // cout << i << '\n';
            vis.assign(4, 0);
            // cout << cur[i] << " " << cur[i + 1] << " " << cur[i + n - 1] << '\n';
            if (cur[i] <= 3) vis[cur[i]]++;
            if (cur[i + 1] <= 3) vis[cur[i + 1]]++;
            if (cur[i + n - 1] <= 3) vis[cur[i + n - 1]]++;
            int mex = 0;
            for (mex = 0; mex <= 3; mex++)
            {
                // if(i==1)cout<<mex<<' '<<vis[mex]<<" ";
                if (!vis[mex]) break;
            }
            // cout << mex << '\n';
            nxt.push_back(mex);
        }
        for (int i = 0; i < n; i++) nxt.push_back(nxt[i]);
        // for (auto i : nxt) cout << i << " ";
        // cout << '\n';
        if (mp.count(nxt))
        {
            st1 = mp[nxt];
            st2 = t;
            break;
        }
        mp[nxt] = t;
        ans.push_back(nxt);
        cur = nxt;
        nxt.clear();
    }
    if (st1 != -1)
    {
        int len = st2 - st1;
        for (int i = 0; i < n; i++) cout << ans[st1 + (k - st2) % len][i] << " ";
        cout << '\n';
    }
    else
    {
        for (int i = 0; i < n; i++) cout << ans[k][i] << " ";
        cout << '\n';
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