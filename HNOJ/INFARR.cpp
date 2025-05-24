/*************************
  Author: Defy logic guy
  22:52:26 - 19/05/2025
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
#define NAME "INFARR"

const int inf = 2e18;
int n;

int lcm(int a, int b)
{
    int l = a / __gcd(a, b);
    if (l >= inf / b)
        return inf;
    return l * b;
}

vector<int> masks, idx;

int check(int mid)
{
    int cnt = 0;
    for (int i = 1; i < (1 << n); i++)
    {
        if (idx[i] % 2 == 0)
            cnt -= mid / masks[i];
        else
            cnt += mid / masks[i];
    }
    return  mid - cnt;
}

void solve()
{
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
        
    masks.resize(1 << n);
    idx.resize(1 << n);

    for (int i = 0; i < (1 << n); i++)
    {
        masks[i] = 1;
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                masks[i] = lcm(masks[i], a[j]);
        idx[i] = __builtin_popcount(i);
    }

    int l = 0, r = 1e18, ans = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (check(mid) >= k)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << endl;
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
