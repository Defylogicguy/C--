/*************************
  Author: Defy logic guy
  09:16:38 - 11/01/2025
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
#define NAME "SHV_PERM"

bool check(vector<int> a, int k)
{
    int cnt = 0;
    for (int i = 0; i < a.size(); i++)
        for (int j = i + 1; j < a.size(); j++)
            if (a[i] > a[j])
                cnt++;
    return cnt == k;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    iota(all(a), 1);
    int cnt = 0;
    do
        cnt += check(a, k);
    while (next_permutation(all(a)));
    cout << cnt << endl;
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
