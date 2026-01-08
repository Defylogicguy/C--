/*************************
 Author: Defy logic guy
22:06:04 - 03/07/2025
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
#define NAME "LMH_PENTIME"

struct node
{
    int a, b, idx;
    node(int a = -1, int b = -1, int idx = -1) : a(a), b(b), idx(idx) {}
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<node> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].a;
    for (int i = 0; i < n; i++)
        cin >> a[i].b, a[i].idx = i;
    sort(all(a), [](const node &a, const node &b)
         { return a.a * b.b > a.b * b.a; });
    vector<int> pos(n);
    for (int i = 0; i < n; i++)
        pos[a[i].idx] = i;
    auto f = [](const vector<node> &a) -> int
    {
        int ans = 0, cur = 0;
        for (int i = 0; i < a.size(); i++)
            cur += a[i].b, ans += cur * a[i].a;
        return ans;
    };
    int base = f(a);
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (pos[x] < pos[y])
            cout << base << '\n';
        else
        {
            int px = pos[x], py = pos[y];
            node z(a[px].a + a[py].a, a[px].b + a[py].b);
            vector<node> nw;
            nw.reserve(n - 1);
            for (int i = 0; i < n; i++)
            {
                if (a[i].idx == x or a[i].idx == y)
                    continue;
                nw.pb(a[i]);
            }
            auto it = lower_bound(all(nw), z, [](const node &a, const node &b)
                                  { return a.a * b.b > a.b * b.a; });
            nw.insert(it, z);
            cout << f(nw) - a[px].a * a[py].b << '\n';
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