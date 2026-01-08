/*************************
  Author: Defy logic guy
  14:11:04 - 12/06/2025
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
#define NAME "THE HIGH PRIESTESS"

void solve()
{
    auto query = [](int x) -> int
    {
        cout << "- " << x << endl;
        cout.flush();
        int a;
        cin >> a;
        return a;
    };

    int cnt;
    cin >> cnt;
    int prv = 0, n = 0;
    while (n)
    {
        n++;
        int idk = query(n + 1);
        n += (1 << (idk - cnt + 1)) - 1;
        prv = (1 << (idk - cnt + 1)) - 1;
        cnt -= 1;
    }
    cout << "! " << n << endl;
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
    cin >> tt;

    while (tt--)
        solve();
    return 0;
}
