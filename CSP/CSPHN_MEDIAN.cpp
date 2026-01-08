/*************************
  Author: Defy logic guy
  15:22:33 - 08/02/2025
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
#define NAME "CSPHN_MEDIAN"

void solve()
{
    int n;
    cin >> n;

    heap<int> _max;
    heap<int, vector<int>, greater<int>> _min;

    while (n--)
    {
        string s;
        cin >> s;
        if (s == "push")
        {
            int x;
            cin >> x;
            if (_max.empty() or x <= _max.top())
                _max.push(x);
            else
                _min.push(x);

            if (_max.size() > _min.size() + 1)
            {
                _min.push(_max.top());
                _max.pop();
            }
            else if (_min.size() > _max.size())
            {
                _max.push(_min.top());
                _min.pop();
            }
        }
        else if (s == "median")
        {
            if (_max.size() == _min.size())
                cout << _max.top() << ' ' << _min.top() << endl;
            else
                cout << _max.top() << endl;
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
