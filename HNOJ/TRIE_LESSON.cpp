/*************************
  Author: Defy logic guy
  15:33:22 - 07/07/2025
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
#define NAME "TRIE_LESSON"

struct Trie
{
    struct node
    {
        int child[2];
        int cnt;
        node() : child{-1, -1}, cnt(0) {}
    };

    vector<node> a;
    Trie() { a.pb(node()); }
    void ins(int x)
    {
        int pos = 0;
        for (int i = 20; i >= 0; i--)
        {
            int id = (x >> i) & 1;
            if (a[pos].child[id] == -1)
                a[pos].child[id] = a.size(), a.pb(node());
            pos = a[pos].child[id];
            a[pos].cnt++;
        }
    }
    int get(int x)
    {
        int pos = 0, ans = 0;
        for (int i = 20; i >= 0; i--)
        {
            int id = (x >> i) & 1;
            if (a[pos].child[id] != -1 and a[a[pos].child[id]].cnt == (1 << i))
            {
                ans |= (1 << i);
                pos = a[pos].child[id ^ 1];
            }
            else
                pos = a[pos].child[id];
            if (pos == -1)
                break;
        }
        return ans;
    }
};

void solve()
{
    Trie trie;
    int n, q;
    cin >> n >> q;
    while (n--)
    {
        int x;
        cin >> x;
        trie.ins(x);
    }

    int z = 0;
    while (q--)
    {
        int x;
        cin >> x;
        z ^= x;
        cout << trie.get(z) << endl;
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
    cout.tie(nullptr);

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();
    return 0;
}
