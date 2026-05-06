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
    string s1, s2;
    cin >> s1 >> s2;
    if (s1[0] == ')' || s2[0] == ')' || s1[n - 1] == '(' || s2[n - 1] == '(')
    {
        cout << "NO\n";
        return;
    }
    int ans1 = 0, ans2 = 0;
    int lft1 = 0, lft2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == '(')
        {
            ans1++;
            lft1++;
        }
        else ans1--;
        if (s2[i] == '(')
        {
            ans2++;
            lft2++;
        }
        else ans2--;
        if (ans1 < 0 || ans2 < 0)
        {
            // if (s1[i-1] == '(')
            // {
            //     ans1--;
            //     lft1--;
            //     ans2++;
            //     lft2++;
            //     s2[i-1]='(';
            // }
            // else
            // {
            //     ans1++;
            //     ans2--;
            //     s2[i-1]=')';
            // }
            // if (s2[i-1] == '(')
            // {
            //     ans2--;
            //     lft2--;
            //     ans1++;
            //     lft1++;
            //     s1[i-1]='(';
            // }
            // else
            // {
            //     ans2++;
            //     ans1--;
            //     s1[i-1]=')';
            // }
            if (ans1 < 0)
            {
                if (ans2 > 0)
                {
                    ans2 -= 2;
                    ans1 += 2;
                    if (ans2 < 0 || ans1 > n / 2)
                    {
                        cout << "NO\n";
                        return;
                    }
                }
                else
                {
                    cout << "NO\n";
                    return;
                }
            }
            else
            {
                if (ans1 > 0)
                {
                    ans1 -= 2;
                    ans2 += 2;
                    if (ans1 < 0 || ans2 > n / 2)
                    {
                        cout << "NO\n";
                        return;
                    }
                }
                else
                {
                    cout << "NO\n";
                    return;
                }
            }
            // if (ans1 < 0 || ans2 < 0)
            // {
            //     cout<<111<<' '<<i<<' '<<ans1<<' '<<ans2<<'\n';
            //     cout << "NO\n";
            //     return;
            // }
        }
        if (ans1 > n / 2 || ans2 > n / 2)
        {
            //     if (s1[i-1] == '(')
            //     {
            //         ans1--;
            //         lft1--;
            //         ans2++;
            //         lft2++;
            //     }
            //     else
            //     {
            //         ans1++;
            //         ans2--;
            //     }
            //     if (s2[i-1] == '(')
            //     {
            //         ans2--;
            //         lft2--;
            //         ans1++;
            //         lft1++;
            //     }
            //     else
            //     {
            //         ans2++;
            //         ans1--;
            //     }
            //     if ((ans1 < 0 || ans2 < 0) || (lft1 > n / 2 || lft2 > n / 2))
            //     {
            //         cout << "NO\n";
            //         return;
            //     }
            if (ans1 > n / 2)
            {
                if (ans2 < n / 2)
                {
                    ans2 += 2;
                    ans1 -= 2;
                    if (ans1 < 0 || ans2 > n / 2)
                    {
                        cout << "NO\n";
                        return;
                    }
                }
                else
                {
                    cout << "NO\n";
                    return;
                }
            }
            else
            {
                if (ans1 < n / 2)
                {
                    ans1 += 2;
                    ans2 -= 2;
                    if (ans2 < 0 || ans1 > n / 2)
                    {
                        cout << "NO\n";
                        return;
                    }
                }
                else
                {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    if (ans1 || ans2) cout << "NO\n";
    else cout << "YES\n";
    // s1=" "+s1;
    // s2=" "+s2;
    // vector<vector<pair<int,int>>>dp(n+1,vector<pair<int,int>>(2,{-1,-1}));
    // if(s1[0])
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}