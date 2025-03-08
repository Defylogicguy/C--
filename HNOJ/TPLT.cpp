/*************************
  Author: Defy logic guy
  08:37:56 - 08/03/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "TPLT"

vector<int> up;
void makedj(int n)
{
    up.resize(n + 1);
    iota(up.begin(), up.end(), 0);
}
int find(int x) { return x == up[x] ? x : up[x] = find(up[x]); }
void uni(int x, int y) { up[find(x)] = find(y); }
bool same(int x, int y) { return find(x) == find(y); }

void solve()
{
    int n, m;
    cin >> n >> m;
    makedj(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        uni(a, b);
    }

    set<int> st;
    for (int i = 1; i <= n; i++)
        st.insert(find(i));
    cout << st.size() << endl;
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
