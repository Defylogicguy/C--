/*************************
  Author: Defy logic guy
  20:56:12 - 01/02/2025
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
#define NAME "PAIR_SWAP"

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    deque<int> dq;
    int lst = min(n - 1, k);
    for (int i = 1; i <= lst; i++)
    {
        while (dq.size() and a[dq.back()] >= a[i])
            dq.pop_back();
        dq.pb(i);
    }

    for (int i = 0; i < n; i++)
    {
        if (i + 1 < n)
        {
            while (dq.size() and dq.front() < i + 1)
                dq.pop_front();

            if (dq.size())
            {
                int j = dq.front();
                if (a[j] < a[i])
                {
                    swap(a[i], a[j]);
                    break;
                }
            }
        }

        if (i + k + 1 < n)
        {
            int j = i + k + 1;
            while (dq.size() and a[dq.back()] >= a[j])
                dq.pop_back();
            dq.pb(j);
        }
    }

    for (int i : a)
        cout << i << ' ';
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
