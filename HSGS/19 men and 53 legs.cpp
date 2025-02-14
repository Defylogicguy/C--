/*************************
  Author: Defy logic guy
  14:32:20 - 13/02/2025
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
#define NAME "19 men and 53 legs"

vector<int> a, tree, lazy;
void init(int idx, int l, int r)
{
    if (l == r)
    {
        tree[idx] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    init(2 * idx, l, mid);
    init(2 * idx + 1, mid + 1, r);
    tree[idx] = max(tree[2 * idx], tree[2 * idx + 1]);
}


void solve()
{
    int n;
    cin >> n;
    a.resize(n), tree.resize(4 * n), lazy.resize(4 * n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    a.insert(a.end(), all(a));

    int m;
    cin >> m;
    while (m--)
    {
        string s;
        getline(cin, s);
        istringstream iss(s);
        vector<int> v;
        while (iss >> s)
            v.pb(stoll(s));
        if (v.size() == 3)
        {
            update()
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
