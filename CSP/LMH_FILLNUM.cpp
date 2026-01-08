/*************************
  Author: Defy logic guy
  14:31:47 - 11/10/2025
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
#define NAME "LMH_FILLNUM"

int n, m, k;
pair<int, int> f(int idx)
{
    if (idx == 0)
        return {1LL, 0LL};
    if (idx == 1)
        return {10LL % k, 1LL % k};
    if (idx % 2 == 0)
    {
        auto t = f(idx / 2);
        int one = t.first, two = t.second;
        return {(one * one) % k, (two * (1 + one)) % k};
    }
    else
    {
        auto t = f(idx - 1);
        return {(t.first * 10LL) % k, (t.second * 10LL + 1) % k};
    }
}

struct node
{
    int l, r, d;
    bool operator<(const node &other) const { return l < other.l; }
};

void solve()
{
    cin >> n >> m >> k;

    set<node> st;
    st.insert({1, n, 0});

    auto upd = [&](int l, int r, int c)
    {
        auto it = st.lower_bound({l, 0, 0});
        if (it != st.begin())
        {
            auto t = it;
            t--;
            if (t->r >= l)
                it = t;
        }
        vector<node> v;
        while (it != st.end() && it->l <= r)
        {
            int idx = it->l, R = it->r, d = it->d;
            auto cur = it;
            ++it;
            st.erase(cur);
            if (idx < l)
                v.pb({idx, l - 1, d});
            if (R > r)
                v.pb({r + 1, R, d});
        }
        v.pb({l, r, c});
        for (auto &i : v)
        {
            auto nw = st.insert(i).first;
            if (nw != st.begin())
            {
                auto t = nw;
                --t;
                if (t->d == nw->d && t->r + 1 == nw->l)
                {
                    node m = {t->l, nw->r, nw->d};
                    st.erase(t);
                    st.erase(nw);
                    nw = st.insert(m).first;
                }
            }
            auto nxt = nw;
            ++nxt;
            if (nxt != st.end() && nxt->d == nw->d && nw->r + 1 == nxt->l)
            {
                node m = {nw->l, nxt->r, nw->d};
                st.erase(nw);
                st.erase(nxt);
                st.insert(m);
            }
        }
    };

    for (int i = 0; i < m; ++i)
    {
        int l, r, c;
        cin >> l >> r >> c;
        upd(l, r, c);
    }

    int ans = 0;
    for (auto i : st)
    {
        int len = i.r - i.l + 1;
        auto t = f(len);
        ans = (ans * t.first + i.d * t.second) % k;
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
