/*************************
  Author: Defy logic guy
  10:08:26 - 04/07/2025
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
#define NAME "TRIE_ORDEREDSET"

struct node
{
    vector<int> child;
    int cnt, leaf;
    node() : child(2, -1), cnt(0), leaf(0) {}
};

const int off = (1ll << 31);
struct Trie
{
    vector<node> a;
    Trie() { a.pb(node()); }

    bool exist(int x)
    {
        x += off;
        int pos = 0;
        for (int i = 31; i >= 0; i--)
        {
            int id = (x >> i) & 1ll;
            if (a[pos].child[id] == -1)
                return false;
            pos = a[pos].child[id];
        }
        return a[pos].leaf;
    }

    void ins(int x)
    {
        if (exist(x))
            return;
        int pos = 0;
        x += off;
        a[pos].cnt++;
        for (int i = 31; i >= 0; i--)
        {
            int id = (x >> i) & 1ll;
            if (a[pos].child[id] == -1)
            {
                a[pos].child[id] = a.size();
                a.pb(node());
            }
            pos= a[pos].child[id];
            a[pos].cnt++;
        }
        a[pos].leaf = 1;
    }

    void del(int x)
    {
        if (!exist(x))
            return;
        x += off;
        int pos = 0;
        a[pos].cnt--;
        for (int i = 31; i >= 0; i--)
        {
            int id = (x >> i) & 1ll;
            pos = a[pos].child[id];
            a[pos].cnt--;
        }
        a[pos].leaf = 0;
    }

    int count(int x)
    {
        x += off;
        int pos = 0, ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            if (pos == -1)
                break;
            int id = (x >> i) & 1ll;
            if (id and a[pos].child[0] != -1)
                ans += a[a[pos].child[0]].cnt;
            pos = a[pos].child[id];
        }
        return ans;
    }

    int kth(int x)
    {
        if (x > a[0].cnt)
            return LLONG_MIN;
        int pos = 0, cnt = 0;
        for (int i = 31; i >= 0; i --)
        {
            int t = (a[pos].child[0] == -1 ? 0 : a[a[pos].child[0]].cnt);
            if (x <= t)
                pos = a[pos].child[0];
            else
            {
                x -= t;
                pos = a[pos].child[1];
                cnt |= (1ll << i);
            }
        }
        return (cnt - off);
    }
};

Trie trie;
void solve()
{
    char t;
    int x;
    cin >> t >> x;
    if (t == 'I')
        trie.ins(x);
    else if (t == 'D')
        trie.del(x);
    else if (t == 'K')
    {
        int idk = trie.kth(x);
        if (idk == LLONG_MIN)
            cout << "invalid\n";
        else
            cout << idk << '\n';
    }
    else if (t == 'C')
        cout << trie.count(x) << '\n';
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
