/*************************
  Author: Defy logic guy
  14:28:40 - 26/04/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "NOISEQ"

void solve()
{
    int n, r;
    cin >> n >> r;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(all(a));
    vector<pair<int, int>> b = a;
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        int x = a[i].first;
        for (int j = (i == 0 ? x - r : max(x - r, b[i - 1].first + 1)); j <= x + r; j++)
            if (st.find(j) == st.end())
            {
                st.insert(j);
                b[i].first = j;
                break;
            }
    }
    sort(all(b), [](pair<int, int> a, pair<int, int> b)
         { return a.second < b.second; });
    cout << st.size() << endl;
    for (int i = 0; i < n; i++)
        cout << b[i].first << ' ';
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
