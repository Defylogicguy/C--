/*************************
  Author: Defy logic guy
  14:38:12 - 11/02/2025
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
#define NAME "CSPHN_JUDGER"

struct node {
    bool p = false;
    int val = 0;
};

void solve()
{
    int n, m;
    cin >> n >> m;
    multiset<int, greater<int>> mset;
    vector<node> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i].p = true;
        a[i].val = 0;
        mset.insert(0);
    }

    while (m--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int i;
            cin >> i;
            if (!a[i - 1].p)
            {
                a[i - 1].p = true;
                a[i - 1].val = 0;
                mset.insert(0);
            }
        }
        else if (t == 2)
        {
            int i;
            cin >> i;
            if (a[i - 1].p)
            {
                a[i - 1].p = false;
                mset.erase(mset.find(a[i - 1].val));
            }
        }
        else if (t == 3)
        {
            int i, x;
            cin >> i >> x;
            if (a[i - 1].p)
            {
                mset.erase(mset.find(a[i - 1].val));
                a[i - 1].val += x;
                mset.insert(a[i - 1].val);
            }
        }
        else if (t == 4)
        {
            if (mset.empty())
                cout << "EMPTY\n";
            else
            {
                auto it = mset.begin();
                for (int i = 0; i < 3 and it != mset.end(); i++, it++)
                    cout << *it << ' ';
                cout << endl;
            }
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
