/*************************
  Author: Defy logic guy
  10:18:03 - 28/06/2025
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
#define NAME "TRIE_KTH"

struct Node
{
    vector<int> child, idx;
    Node() : child(26, -1) {}
};

struct Trie
{
    vector<Node> a;
    Trie() { a.pb(Node()); }

    void insert(const string &s, int idx)
    {
        int pos = 0;
        for (char c : s)
        {
            int id = c - 'a';
            if (a[pos].child[id] == -1)
            {
                a[pos].child[id] = a.size();
                a.pb(Node());
            }
            pos = a[pos].child[id];
        }
        a[pos].idx.pb(idx);
    }

    void dfs(int id, vector<int> &res)
    {
        if (!a[id].idx.empty())
            res.insert(res.end(), all(a[id].idx));
        for (int i = 0; i < 26; i++)
            if (a[id].child[i] != -1)
                dfs(a[id].child[i], res);
    }
};

void solve()
{
    int n;
    cin >> n;

    vector<string> s(n);
    Trie trie;

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        trie.insert(s[i], i + 1);
    }

    vector<int> res;
    trie.dfs(0, res);

    for (int idx : res)
        cout << idx << endl;
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
