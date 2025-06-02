/*************************
  Author: Defy logic guy
  15:46:41 - 02/06/2025
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
#define endl '\n'
#define NAME "CONTEST10_PLANET"

void solve()
{
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();

    vector<int> p;
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (st.size() && s[st.top()] > s[i])
        {
            p.pb(st.top());
            st.pop();
        }
        st.push(i);
    }

    while (st.size())
    {
        p.pb(st.top());
        st.pop();
    }

    int l = 1, r = n;
    int m = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int f = mid * (2 * n - mid + 1) / 2;
        if (f >= k)
        {
            m = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    int f1 = (m - 1) * (2 * n - (m - 1) + 1) / 2;
    int of = k - f1;

    vector<char> del(n, 0);
    for (int i = 0; i < m - 1; i++)
        del[p[i]] = 1;

    int cnt = 0;
    char ans;
    for (int i = 0; i < n; i++)
        if (!del[i])
        {
            cnt++;
            if (cnt == of)
            {
                ans = s[i];
                break;
            }
        }

    cout << ans << "\n";
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
    cin >> tt;

    while (tt--)
        solve();
    return 0;
}
