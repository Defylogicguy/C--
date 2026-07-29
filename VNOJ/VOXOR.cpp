/*************************
  Author: Defy logic guy
  08:51:20 - 30/06/2026
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
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "VOXOR"

struct Trie
{
    struct node
    {
        vector<int> c;
        int cnt;
        node() : c(2, -1), cnt(0) {}
    };
    int xr;
    vector<node> a;
    Trie() : xr(0) { a.pb(node()); }
    void insert(int x)
    {
        int pos = 0;
        for (int i = 30; i >= 0; i--)
        {
            int b = (x >> i) & 1ll;
            if (a[pos].c[b] == -1)
                a[pos].c[b] = a.size(), a.pb(node());
            pos = a[pos].c[b];
            a[pos].cnt++;
        }
    }
    int kth(int k)
    {
        int pos = 0, ans = 0;
        for (int i = 30; i >= 0; i--)
        {
            if (pos == -1)
                break;
            int xb = (xr >> i) & 1ll;
            int t = 0;
            if (a[pos].c[!xb] != -1)
                t = a[a[pos].c[!xb]].cnt;
            if (t >= k)
            {
                ans |= (1ll << i);
                pos = a[pos].c[!xb];
            }
            else
            {
                k -= t;
                pos = a[pos].c[(!xb ^ 1)];
            }
        }
        return ans;
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Trie trie;
    for (int i = 0; i < n; i++)
        trie.insert(a[i]);
    while (q--)
    {
        string s;
        int x;
        cin >> s >> x;
        if (s[0] == 'X')
            trie.xr ^= x;
        else
            cout << trie.kth(x) << '\n';
    }
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
