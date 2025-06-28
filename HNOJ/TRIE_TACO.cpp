/*************************
  Author: Defy logic guy
  08:54:41 - 28/06/2025
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
#define NAME "TRIE_TACO"

struct Node
{
    vector<int> child;
    int cnt, exist;
    Node() : child(26, -1), cnt(0), exist(0) {}
};

struct Trie
{
    vector<Node> t;
    Trie()
    {
        t.emplace_back();
    }

    void insert(const string &s)
    {
        int u = 0;
        for (char ch : s)
        {
            int c = ch - 'a';
            if (t[u].child[c] == -1)
            {
                t[u].child[c] = t.size();
                t.emplace_back();
            }
            u = t[u].child[c];
            t[u].exist++;
        }
        t[u].cnt++;
    }

    int type1(const string &s)
    {
        int u = 0;
        int ans = 0;
        for (char ch : s)
        {
            int c = ch - 'a';
            if (t[u].child[c] == -1)
                break;
            u = t[u].child[c];
            ans += t[u].cnt;
        }
        return ans;
    }

    int type2(const string &s)
    {
        int u = 0;
        for (char ch : s)
        {
            int c = ch - 'a';
            if (t[u].child[c] == -1)
                return 0;
            u = t[u].child[c];
        }
        return t[u].exist;
    }
};

Trie trie;
void solve()
{
    int t;
    string s;
    cin >> t >> s;
    if (t == 0)
        trie.insert(s);
    else if (t == 1)
        cout << trie.type1(s) << '\n';
    else
        cout << trie.type2(s) << '\n';
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
    cin >> tt;

    while (tt--)
        solve();
    return 0;
}
