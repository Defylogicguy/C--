/*************************
  Author: Defy logic guy
  14:33:55 - 12/06/2025
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
#define NAME "THE EMPRESS"

void solve()
{
    auto q1 = [](int i)
    {
        cout << "? 1 " << i << endl;
        cout.flush();
        char a;
        cin >> a;
        return a;
    };

    auto q2 = [](int l, int r)
    {
        cout << "? 2 " << l << ' ' << r << endl;
        cout.flush();
        int a;
        cin >> a;
        return a;
    };

    int n;
    cin >> n;
    string s = "";
    vector<vector<int>> cnt(n + 1);
    for (int i = 0; i < n; i++)
    {
        if (!i)
        {
            s.pb(q1(1));
            cnt[0].pb(1);
        }
        else
        {
            int cur = q2(1, i + 1);
            if (cur > cnt[i - 1][0])
                s.pb(q1(i + 1));
            else
            {
                map<char, int> lst;
                for (int j = 0; j < s.size(); j++)
                    lst[s[j]] = j;
                vector<int> l;
                for (auto &[x, y] : lst)
                    l.pb(y);
                sort(all(l));
                int lo = 0, hi = l.size();
                while (hi - lo > 1)
                {
                    int mid = (lo + hi) / 2;
                    int tmp = q2(l[mid] + 1, i + 1);
                    if (tmp == cnt[i - 1][l[mid]])
                        lo = mid;
                    else
                        hi = mid;
                }
                s.pb(s[l[lo]]);
            }
            cnt[i].resize(i + 1);
            set<char> st;
            for (int j = i; j >= 0; j--)
            {
                st.insert(s[j]);
                cnt[i][j] = st.size();
            }
        }
    }
    cout << "! " << s << endl;
    cout.flush();
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
