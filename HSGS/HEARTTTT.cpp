/*************************
  Author: Defy logic guy
  23:56:38 - 25/06/2025
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
#define NAME "HEARTTTT"
struct Seg
{
    int cnt, len;
    bool f;
};

const int N = 1000005;
Seg st[4 * N];
string s;

void build(int p, int l, int r)
{
    st[p].len = r - l + 1;
    if (l == r)
    {
        st[p].cnt = (s[l - 1] == '<');
        return;
    }
    int m = (l + r) >> 1;
    build(p << 1, l, m);
    build(p << 1 | 1, m + 1, r);
    st[p].cnt = st[p << 1].cnt + st[p << 1 | 1].cnt;
}

void apply(int p)
{
    st[p].cnt = st[p].len - st[p].cnt;
    st[p].f ^= 1;
}

void push(int p)
{
    if (st[p].f)
    {
        apply(p << 1);
        apply(p << 1 | 1);
        st[p].f = 0;
    }
}

void update(int p, int l, int r, int i, int j)
{
    if (i > r || j < l)
        return;
    if (i <= l && r <= j)
    {
        apply(p);
        return;
    }
    push(p);
    int m = (l + r) >> 1;
    update(p << 1, l, m, i, j);
    update(p << 1 | 1, m + 1, r, i, j);
    st[p].cnt = st[p << 1].cnt + st[p << 1 | 1].cnt;
}

int queryCnt(int p, int l, int r, int i, int j)
{
    if (i > r || j < l)
        return 0;
    if (i <= l && r <= j)
        return st[p].cnt;
    push(p);
    int m = (l + r) >> 1;
    return queryCnt(p << 1, l, m, i, j) + queryCnt(p << 1 | 1, m + 1, r, i, j);
}   
void solve()
{
    int n, q;
    cin >> n >> q;
    cin >> s;
    build(1, 1, n);
    while (q--)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
            update(1, 1, n, l, r);
        else
        {
            int c1 = queryCnt(1, 1, n, l, r);
            int len = r - l + 1;
            int c3 = len - c1;
            cout << min(c1, c3) << '\n';
        }
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
