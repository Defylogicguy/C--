/*************************
  Author: Defy logic guy
  14:30:22 - 04/07/2025
*************************/
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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
#define NAME "TRIE_SETXORMIN"

struct Trie
{
    static const int maxn = 2e5;
    struct node
    {
        int child[2], cnt, end;
        node()
        {
            child[0] = child[1] = -1;
            cnt = end = 0;
        }
    };
    node a[maxn * 30];
    int sz;
    Trie()
    {
        sz = 0;
        a[0] = node();
    }

    bool exist(int x)
    {
        int pos = 0;
        for (int i = 30; i >= 0; i--)
        {
            int b = (x >> i) & 1LL;
            if (a[pos].child[b] == -1)
                return false;
            pos = a[pos].child[b];
        }
        return a[pos].end > 0;
    }

    void ins(int x)
    {
        if (exist(x))
            return;
        int pos = 0;
        a[pos].cnt++;
        for (int i = 30; i >= 0; i--)
        {
            int b = (x >> i) & 1LL;
            if (a[pos].child[b] == -1)
            {
                a[pos].child[b] = ++sz;
                a[sz] = node();
            }
            pos = a[pos].child[b];
            a[pos].cnt++;
        }
        a[pos].end++;
    }

    void del(int x)
    {
        if (!exist(x))
            return;
        int pos = 0;
        a[pos].cnt--;
        for (int i = 30; i >= 0; i--)
        {
            int b = (x >> i) & 1LL;
            pos = a[pos].child[b];
            a[pos].cnt--;
        }
        a[pos].end--;
    }

    int get(int x)
    {
        int pos = 0;
        int res = 0;
        if (a[0].cnt == 0)
            return 0;
        for (int i = 30; i >= 0; i--)
        {
            int b = (x >> i) & 1LL;
            if (a[pos].child[b] != -1 && a[a[pos].child[b]].cnt > 0)
                pos = a[pos].child[b];
            else
            {
                res |= (1LL << i);
                pos = a[pos].child[b ^ 1ll];
            }
        }
        return res;
    }
};

Trie trie;
void solve()
{
    int t, x;
    cin >> t >> x;
    if (t == 0)
        trie.ins(x);
    else if (t == 1)
        trie.del(x);
    else
        cout << trie.get(x) << '\n';
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