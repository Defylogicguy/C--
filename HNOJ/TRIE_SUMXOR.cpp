/*************************
  Author: Defy logic guy
  23:24:08 - 06/07/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "TRIE_SUMXOR"

struct Trie
{
    struct node
    {
        int child[2];
        node() : child{-1, -1} {}
    };

    vector<node> a;
    Trie() { a.pb(node()); }
    void ins(int x)
    {
        int pos = 0;
        for (int i = 30; i >= 0; i--)
        {
            int b = (x >> i) & 1ll;
            if (a[pos].child[b] == -1)
                a[pos].child[b] = a.size(), a.pb(node());
            pos = a[pos].child[b];
        }
    }
    int get(int x)
    {
        int pos = 0, ans = 0;
        for (int i = 30; i >= 0; i--)
        {
            int b = (x >> i) & 1ll;
            if (a[pos].child[b ^ 1] != -1)
            {
                ans |= 1ll << i;
                pos = a[pos].child[b ^ 1];
            }
            else
                pos = a[pos].child[b];
        }
        return ans;
    }
};

void solve()
{
    Trie trie;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> pf(n + 1, 0);
    partial_sum(all(a), pf.begin() + 1, [](const int &a, const int &b)
                { return a ^ b; });
    trie.ins(0);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, trie.get(pf[i]));
        trie.ins(pf[i]);
    }
    cout << ans;
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
