/*************************
 Author: Defy logic guy
14:47:29 - 17/01/2026
*************************/
#include <bits/stdc++.h>
using namespace std;
ostream &operator<<(ostream &os, const string &s)
{
    os.write(s.data(), s.size());
    return os;
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <typename T>
auto operator<<(ostream &os, const T &c) -> typename enable_if<!is_same<T, string>::value, decltype(c.begin(), c.end(), os)>::type
{
    for (auto it = c.begin(); it != c.end(); it++)
        os << (it == c.begin() ? "{" : ", ") << *it;
    return os << "}";
}
#define dbg(x) cerr << #x << " = " << (x) << '\n';
// #define int unsigned long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "LMH_IMAGE"

using ull = unsigned long long;
int n;
string s, t;
bool flag = false;

void dfs(int &i, int &j, ull x, ull y, ull sz)
{
    if (flag)
        return;

    if (sz == 1)
    {
        function<char(const string &, int &)> get = [&](const string &str, int &p) -> char
        {
            if (str[p] == 'B' or str[p] == 'W')
                return str[p++];
            p++;
            char c = get(str, p);
            for (int _ = 1; _ < 4; _++)
                get(str, p);
            return c;
        };

        if (get(s, i) != get(t, j))
        {
            flag = true;
            cout << "YES\n"
                 << x << ' ' << y;
        }

        return;
    }

    if (s[i] != '&' and t[j] != '&')
    {
        if (s[i] != t[j])
        {
            flag = true;
            cout << "YES\n"
                 << x << ' ' << y;
            return;
        }
        i++, j++;
        return;
    }

    ull hsz = (sz >> 1);
    if (s[i] != '&' and t[j] == '&')
    {
        j++;
        for (int _ = 0; _ < 4 and !flag; _++)
        {
            int t = i;
            dfs(t, j, x + (_ >= 2) * hsz, y + (_ % 2) * hsz, hsz);
        }
        i++;
        return;
    }

    if (s[i] == '&' and t[j] != '&')
    {
        i++;
        for (int _ = 0; _ < 4 and !flag; _++)
        {
            int t = j;
            dfs(i, t, x + (_ >= 2) * hsz, y + (_ % 2) * hsz, hsz);
        }
        j++;
        return;
    }

    i++, j++;
    for (int _ = 0; _ < 4 and !flag; _++)
        dfs(i, j, x + (_ >= 2) * hsz, y + (_ % 2) * hsz, hsz);
}

void solve()
{
    cin >> n >> s >> t;
    int i = 0, j = 0;
    dfs(i, j, 0ull, 0ull, (1ull << n));
    if (!flag)
        cout << "NO\n";
}

signed main()
{
    if (fopen(NAME ".INP", "r"))
    {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
