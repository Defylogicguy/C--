/*************************
  Author: Defy logic guy
  23:36:11 - 12/09/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <typename T>
auto operator<<(ostream &os, const T &c) -> decltype(c.begin(), c.end(), os)
{
    for (auto it = c.begin(); it != c.end(); ++it)
        os << (it == c.begin() ? "{" : ", ") << *it;
    return os << "}";
}
#define dbg(x) cerr << #x << " = " << (x) << '\n';
#define int long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "448C"

int dfs(int l, int r, int h, const vector<int> &a)
{
    bool flag = true;
    for (int i = l; i <= r; i++)
        if (a[i] > h)
        {
            flag = false;
            break;
        }
    if (flag)
        return 0ll;
    int mn = *min_element(a.begin() + l, a.begin() + r + 1);
    int one = mn - h;
    int i = l;
    while (i <= r)
    {
        if (a[i] == mn)
        {
            i++;
            continue;
        }
        int j = i;
        while ( j<= r and a[j] > mn)
            j++;
        one += dfs(i, j - 1, mn, a);
        i = j;
    }
    return min(one, r - l + 1);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << dfs(0, n - 1, 0, a);
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
    cout.tie(nullptr);

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
