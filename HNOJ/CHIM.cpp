/*************************
  Author: Defy logic guy
  19:31:19 - 23/08/2025
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
#define NAME "CHIM"

void solve()
{
    int q;
    cin >> q;
    string s;
    cin >> s;
    bool one = false, two = true;
    set<int> x, y;
    x.insert(0), y.insert(0);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'F')
        {
            int cnt = 0;
            while (i < s.size() and s[i] == 'F')
                cnt++, i++;
            i--;
            if (one)
            {
                set<int> nw = y;
                y.clear();
                for (auto it : nw)
                {
                    y.insert(it);
                    y.insert(it + cnt);
                    y.insert(it - cnt);
                }
            }
            else
            {
                set<int> nw = x;
                x.clear();
                for (auto it : nw)
                {
                    x.insert(it);
                    x.insert(it + cnt);
                    if (!two)
                        x.insert(it - cnt);
                }
            }
        }
        else
        {
            one = !one;
            two = false;
        }
    }

    // cout << ">>>\n";
    // for (int i = 0; i < 2 * sz; i++)
    //     cout << i << ' ' << x[i] << '\n';
    // cout << ">>>\n";
    // for (int i = 0; i < 2 * sz; i++)
    //     cout << i << ' ' << y[i] << '\n';
    // cout << ">>>\n";
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << (x.count(a) and y.count(b) ? "Yes\n" : "No\n");
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
