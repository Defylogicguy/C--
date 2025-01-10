#include <bits/stdc++.h>
#define int long long

using namespace std;

void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
struct node
{
    int max_sub, min_sub, max_add, min_add, res;
};

struct seg
{
    int n;
    vector<node> st;
    seg(int n) : n(n)
    {
        st.resize(4 * n + 1);
    }

    void update(int id, int l, int r, int pos, int val)
    {
        if (l > pos || r < pos || l > r)
            return;
        if (l == r)
        {
            st[id].max_sub = val - pos;
            st[id].min_sub = val - pos;
            st[id].max_add = val + pos;
            st[id].min_add = val + pos;
            st[id].res = 0;
            return;
        }

        int mid = (l + r) / 2;
        update(id * 2, l, mid, pos, val);
        update(id * 2 + 1, mid + 1, r, pos, val);
        st[id].max_sub = max(st[id * 2].max_sub, st[id * 2 + 1].max_sub);
        st[id].min_sub = min(st[id * 2].min_sub, st[id * 2 + 1].min_sub);
        st[id].max_add = max(st[id * 2].max_add, st[id * 2 + 1].max_add);
        st[id].min_add = min(st[id * 2].min_add, st[id * 2 + 1].min_add);
        st[id].res = max({st[id * 2].res, st[id * 2 + 1].res,
                          st[id * 2].max_add - st[id * 2 + 1].min_add,
                          st[id * 2 + 1].max_sub - st[id * 2].min_sub});
    }

    int getVal()
    {
        return st[1].res;
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    seg ST(n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        ST.update(1, 1, n, i, x);
    }
    cout << ST.getVal() << '\n';
    while (q--)
    {
        int p, x;
        cin >> p >> x;
        ST.update(1, 1, n, p, x);
        cout << ST.getVal() << '\n';
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}