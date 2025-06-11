/*************************
  Author: Defy logic guy
  19:03:22 - 03/06/2025
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
#define NAME "ABC326F"

int n, x, y;
int n1 = 0, n2 = 0;
vector<int> a, b, ans;
int m1 = -1, m2 = -1, m3 = -1, m4 = -1;
map<int, int> one, two;

void b1(int i, int sum, int msk)
{
    if (i > n1 / 2)
    {
        one[sum] = msk;
        return;
    }
    b1(i + 1, sum - a[i - 1], msk);
    b1(i + 1, sum + a[i - 1], msk | (1LL << i));
}

void b2(int i, int sum, int msk)
{
    if (m1 != -1)
        return;
    if (i > n1)
    {
        if (!one.count(y - sum))
            return;
        m1 = one[y - sum];
        m2 = msk;
        return;
    }
    b2(i + 1, sum - a[i - 1], msk);
    b2(i + 1, sum + a[i - 1], msk | (1LL << i));
}

void b3(int i, int sum, int msk)
{
    if (i > n2 / 2)
    {
        two[sum] = msk;
        return;
    }
    b3(i + 1, sum - b[i - 1], msk);
    b3(i + 1, sum + b[i - 1], msk | (1LL << i));
}

void b4(int i, int sum, int msk)
{
    if (m3 != -1)
        return;
    if (i > n2)
    {
        if (!two.count(x - sum))
            return;
        m3 = two[x - sum];
        m4 = msk;
        return;
    }
    b4(i + 1, sum - b[i - 1], msk);
    b4(i + 1, sum + b[i - 1], msk | (1LL << i));
}

void solve()
{
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++)
    {
        int val;
        cin >> val;
        if (i & 1)
            a.pb(val);
        else
            b.pb(val);
    }

    n1 = a.size();
    n2 = b.size();
    ans.assign(n + 1, 0);

    b1(1, 0, 0);
    b2(n1 / 2 + 1, 0, 0);
    b3(1, 0, 0);
    b4(n2 / 2 + 1, 0, 0);

    if (m1 == -1 or m3 == -1)
    {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";

    int i1 = 0, i2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
        {
            i1++;
            if ((m1 >> i1) & 1 or (m2 >> i1) & 1)
                ans[i] = 1;
        }
        else
        {
            i2++;
            if ((m3 >> i2) & 1 or (m4 >> i2) & 1)
                ans[i] = 1;
        }
    }

    int d = 0;
    for (int i = 1; i <= n; i++)
    {
        int t;
        if (i & 1)
            t = (ans[i] ? 1 : 3);
        else
            t = (ans[i] ? 0 : 2);
        cout << ((t == (d + 1) % 4) ? 'L' : 'R');
        d = t;
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