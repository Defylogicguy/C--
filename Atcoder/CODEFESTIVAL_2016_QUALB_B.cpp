/*************************
  Author: Defy logic guy
  20:33:32 - 12/05/2025
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
#define NAME "CODEFESTIVAL_2016_QUALB_B"

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int cur = 0, cur2 = 0;
    for (char c : s)
    {
        bool flag = false;
        if (c == 'a' and cur + 1 <= a + b)
            cur++ , flag = true;
        else if (c == 'b' and cur + 1 <= a + b and cur2 + 1 <= b)
            cur++, cur2++, flag = true;
        cout << (flag ? "Yes\n" : "No\n");
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
