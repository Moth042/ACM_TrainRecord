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
int query(int u, int v)
{
    cout << "? " << u << " " << v << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
}
void moth()
{
    int n;
    cin >> n;
    vector<pair<int, int>> e;
    for (int i = 1; i <= n; i += 2)
    {
        int res = query(i, i % n + 1);
        cout.flush();
        if (res == 1)
        {
            e.push_back({i, i % n + 1});
            break;
        }
    }
    if (e.size() == 1)
    {
        auto [u, v] = e[0];
        // int res=query(v,v+1);
        // cout.flush();
        // if(res==1)
        // {
        //     cout<<"! "<<2<<endl;
        //     cout.flush();
        //     return;
        // }
        // res=query(u,v+1);
        // if(res==1)
        // {
        //     cout<<"! "<<2<<endl;
        //     cout.flush();
        //     return;
        // }
        // cout<<"! "<<1<<endl;
        // cout.flush();
        // return;
        vector<int> t;
        for (int i = 1; i <= n; i++)
        {
            if (i != u && i != v)
            {
                t.push_back(i);
                if (t.size() >= 2) break;
            }
        }
        int sum = 0;
        int res1 = query(u, t[0]);
        if (res1) sum = 1 + query(u, t[1]);
        else sum += query(v, t[0]) + query(v, t[1]);
        if (sum == 2)
        {
            cout << "! " << 2 << endl;
            cout.flush();
        }
        else
        {
            cout << "! " << 1 << endl;
            cout.flush();
        }
        return;
    }
    cout << "! " << 1 << endl;
    cout.flush();
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}