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
#define NAME "SIMILAR"

struct State
{
    int len, link;
    map<int, int> next;
};

void extend(int c, vector<State> &states, int &size, int &last)
{
    int p = last;
    int curr = size++;
    states.emplace_back();
    states[curr].len = states[p].len + 1;
    while (p != -1 && !states[p].next.count(c))
    {
        states[p].next[c] = curr;
        p = states[p].link;
    }
    if (p == -1)
    {
        states[curr].link = 0;
    }
    else
    {
        int q = states[p].next[c];
        if (states[p].len + 1 == states[q].len)
        {
            states[curr].link = q;
        }
        else
        {
            int clone = size++;
            states.emplace_back();
            states[clone].len = states[p].len + 1;
            states[clone].next = states[q].next;
            states[clone].link = states[q].link;
            while (p != -1 && states[p].next[c] == q)
            {
                states[p].next[c] = clone;
                p = states[p].link;
            }
            states[q].link = clone;
            states[curr].link = clone;
        }
    }
    last = curr;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }

    vector<int> diff(n - 1);
    for (int i = 0; i < n - 1; ++i)
    {
        diff[i] = a[i + 1] - a[i];
    }

    vector<State> states;
    states.emplace_back();
    states[0].len = 0;
    states[0].link = -1;
    int size = 1, last = 0;

    for (int c : diff)
    {
        extend(c, states, size, last);
    }

    int max_len = 0;
    for (int i = 1; i < size; ++i)
    {
        max_len = max(max_len, states[i].len);
    }

    cout << (max_len ? max_len + 1 : 0) << endl;
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
    {
        solve();
    }
    return 0;
}