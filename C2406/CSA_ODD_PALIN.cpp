/*************************
  Author: Defy logic guy
  22:19:12 - 22/02/2025
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
#define NAME "CSA_ODD_PALIN"

vector<int> func(const vector<char> &a, int sz)
{
    vector<int> freq(26, 0);
    vector<int> _max;
    if (sz <= 0 || a.size() < sz)
        return _max;

    int cur = 0;
    int left = 0;

    for (int i = 0; i < a.size(); i++)
    {
        int c = a[i] - 'a';
        freq[c]++;
        if (freq[c] > cur)
            cur = freq[c];

        while (i - left + 1 > sz)
        {
            int d = a[left] - 'a';
            freq[d]--;
            left++;
            if (d == c)
            {
                if (freq[d] + 1 == cur)
                {
                    cur = 0;
                    for (int j = 0; j < 26; j++)
                        if (freq[j] > cur)
                            cur = freq[j];
                }
            }
            else if (freq[d] + 1 == cur)
            {
                cur = 0;
                for (int j = 0; j < 26; j++)
                    if (freq[j] > cur)
                        cur = freq[j];
            }
        }

        if (i - left + 1 == sz)
            _max.pb(cur);
    }

    return _max;
}

bool f(int mid, int k, const vector<char> &even, const vector<char> &odd)
{
    int m = (mid + 1) / 2;
    int n = mid / 2;

    bool one = false;
    if (even.size() >= m && odd.size() >= n)
    {
        vector<int> maxeven = func(even, m);
        vector<int> maxodd = func(odd, n);
        int len = min(maxeven.size(), maxodd.size());
        for (int i = 0; i < len; i++)
            if (maxeven[i] + maxodd[i] >= mid - k)
            {
                one = true;
                break;
            }
    }

    bool two = false;
    if (odd.size() >= m && even.size() >= n)
    {
        vector<int> maxodd = func(odd, m);
        vector<int> maxeven = func(even, n);
        int len = min(maxodd.size(), maxeven.size());
        for (int i = 0; i < len; i++)
            if (maxodd[i] + maxeven[i] >= mid - k)
            {
                two = true;
                break;
            }
    }

    return one || two;
}

void solve()
{
    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<char> even, odd;
    for (int i = 0; i < n; i++)
        if (i % 2 == 0)
            even.pb(s[i]);
        else
            odd.pb(s[i]);

    int mid = 1, r = n, ans = 0;
    while (mid <= r)
    {
        int mid = (mid + r) / 2;
        if (f(mid, k, even, odd))
        {
            ans = mid;
            mid = mid + 1;
        }
        else
            r = mid - 1;
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