    /*************************
     Author: Defy logic guy
    14:20:24 - 29/11/2025
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
    #define NAME "LMH_ACTIVITY"

    struct node
    {
        int l, r, id;
        node(int l = 0, int r = 0, int id = 0) : l(l), r(r), id(id) {}
    };

    void solve()
    {
        int n;
        cin >> n;
        vector<node> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i].l >> a[i].r, a[i].id = i;
        sort(all(a), [](const node &a, const node &b)
            { return a.r == b.r ? a.l < b.l : a.r < b.r; });
        vector<int> res;
        int lst = -1;
        for (node it : a)
            if (it.l >= lst)
            {
                lst = it.r;
                res.pb(it.id);
            }
        cout << res.size() << '\n';
        for (int i : res)
            cout << i + 1 << '\n';
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
