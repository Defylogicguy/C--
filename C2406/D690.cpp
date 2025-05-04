/*************************
  Author: Defy logic guy
  00:10:13 - 04/05/2025
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
#define NAME "D690"

void solve()
{
    int n;
    cin >> n;
    vector<int> ps;
    vector<bool> p(55555, true);
    p[0] = p[1] = false;
    for (int i = 2; i * i <= n; ++i)
        if (p[i])
        {
            ps.pb(i);
            for (int j = i * i; j <= n; j += i)
                p[j] = false;
        }
    shuffle(all(ps), default_random_engine(time(0)));
    bool flag = false;
    vector<int> res;
    auto isComp = [&](int x) -> bool
    {
        if (x <= 55555)
            return p[x];
        for (int i = 2; i * i <= x; i++)
            if (x % i == 0)
                return false;
        return x > 1;
    };
    for (int i = 0; i < ps.size() and !flag; i++)
        for (int j = i + 1; j < ps.size() and !flag; j++)
            for (int k = j + 1; k < ps.size() and !flag; k++)
                for (int l = k + 1; l < ps.size() and !flag; l++)
                    for (int m = l + 1; m < ps.size() and !flag; m++)
                    {
                        int sum = ps[i] + ps[j] + ps[k] + ps[l] + ps[m];
                        if (isComp(sum))
                        {
                            flag = true;
                            res = {ps[i], ps[j], ps[k], ps[l], ps[m]};
                            flag = true;
                        }
                    }

    for (int x : ps)
    {
        if (res.size() == n)
            break;
        if (find(all(res), x) != res.end())
            continue;
        flag = true;
        for (int a = 0; a < 5 and flag; a++)
            for (int b = a + 1; b < 5 and flag; b++)
                for (int c = b + 1; c < 5 and flag; c++)
                    for (int d = c + 1; d < 5 and flag; d++)
                        {
                            int sum= x + res[a] + res[b] + res[c] + res[d];
                            if (!isComp(sum))
                                flag = false;
                        }
        if (flag)
            res.pb(x);
    }
    for (int i : res)
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
