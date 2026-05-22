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
    ll a, n;
    cin >> a >> n;
    i128 ans = 1e18;
    vector<int> d(n + 1), cnt(10);
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
        cnt[d[i]]++;
    }
    string sa = to_string(a);
    string sb1, sb2, sb3, sb4, pre;
    int st = -2;
    for (int i = 0; i < sa.length(); i++)
    {
        if (cnt[sa[i] - '0']) pre += sa[i];
        else
        {
            st = i;
            break;
        }
    }
    if (st == -2)
    {
        cout << 0 << '\n';
        return;
    }
    auto cal = [&](string s) -> i128
    {
        i128 ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            ans *= (i128)10;
            ans += s[i] - '0';
        }
        return ans;
    };
    auto abs = [&](i128 x) -> i128
    {
        if (x < 0) return -x;
        return x;
    };
    // a < b
    sb1 = pre;
    int st1 = st;
    while (st1 > 0 && sa[st1] - '0' >= d[n])
    {
        st1--;
        sb1.pop_back();
    }
    if (sa[st1] - '0' < d[n])
    {
        for (int i = 1; i <= n; i++)
        {
            if (d[i] > sa[st1] - '0')
            {
                sb1.push_back(d[i] + '0');
                break;
            }
        }
        for (int i = sb1.length(); i < sa.length(); i++) sb1.push_back(d[1] + '0');
        // cout << sb1 << '\n';
        ans = min(ans, abs(cal(sb1) - a));
    }
    // write(ans);
    // putchar('\n');
    if (d[1] == 0)
    {
        if (n == 1) ans = min(ans, (i128)a);
        else
        {
            sb2 += d[2] + '0';
            for (int i = 1; i < sa.length() + 1; i++) sb2 += '0';
        }
    }
    else
    {
        for (int i = 0; i < sa.length() + 1; i++) sb2 += d[1] + '0';
    }
    ans = min(ans, abs(cal(sb2) - a));
    // write(ans);
    // putchar('\n');
    // a > b
    sb3 = pre;
    int st2 = st;
    while (st2 > 0 && sa[st2] - '0' <= d[1])
    {
        st2--;
        sb3.pop_back();
    }
    if (sa[st2] - '0' > d[1])
    {
        for (int i = n; i >= 1; i--)
        {
            if (d[i] < sa[st2] - '0')
            {
                sb3.push_back(d[i] + '0');
                break;
            }
        }
        for (int i = sb3.length(); i < sa.length(); i++) sb3.push_back(d[n] + '0');
        // cout << sb3 << '\n';
        ans = min(ans, abs(cal(sb3) - a));
    }
    // write(ans);
    // putchar('\n');
    if (d[n] == 0) ans = min(ans, (i128)a);
    else if (sa.length() > 1)
    {
        for (int i = 0; i < sa.length() - 1; i++) sb4 += d[n] + '0';
        ans = min(ans, abs(cal(sb4) - a));
    }
    write(ans);
    putchar('\n');
}
int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}