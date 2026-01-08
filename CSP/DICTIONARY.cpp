/*************************
  Author: Defy logic guy
  23:17:38 - 10/11/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
ostream &operator<<(ostream &os, const string &s)
{
    os.write(s.data(), s.size());
    return os;
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <typename T>
auto operator<<(ostream &os, const T &c) -> typename enable_if<!is_same<T, string>::value, decltype(c.begin(), c.end(), os)>::type
{
    for (auto it = c.begin(); it != c.end(); ++it)
        os << (it == c.begin() ? "{" : ", ") << *it;
    return os << "}";
}
#define dbg(x) cerr << #x << " = " << (x) << '\n';
#define int long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "DICTIONARY"

vector<string> s;

bool cmp(int a, int b)
{
    if (a == -1)
        return false;
    if (b == -1)
        return true;
    return s[a].size() != s[b].size() ? s[a].size() > s[b].size() : s[a] < s[b];
}

struct Trie
{
    struct node
    {
        vector<int> child;
        int idx;
        node() : child(26, -1), idx(-1) {}
    };
    vector<node> a;
    Trie() { a.pb(node()); }

    void insert(const string &t, int idx)
    {
        int pos = 0;
        for (char c : t)
        {
            int id = c - 'a';
            if (a[pos].child[id] == -1)
            {
                a[pos].child[id] = a.size();
                a.pb(node());
            }
            pos = a[pos].child[id];
        }
        if (a[pos].idx == -1 || cmp(idx, a[pos].idx))
            a[pos].idx = idx;
    }

    int ans = -1;
    void dfs(int u, char lst, vector<int> cnt)
    {
        if (a[u].idx != -1 && (ans == -1 || cmp(a[u].idx, ans)))
            ans = a[u].idx;
        for (char i = lst; i <= 'z'; i++)
        {
            int id = i - 'a';
            if (a[u].child[id] != -1 && cnt[id] > 0)
            {
                cnt[id]--;
                dfs(a[u].child[id], i, cnt);
                cnt[id]++;
            }
        }
    }
} trie;

void solve()
{
    int n;
    cin >> n;
    s.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        string t = s[i];
        sort(all(t));
        trie.insert(t, i);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        string t;
        cin >> t;
        vector<int> cnt(26, 0);
        for (char c : t)
            cnt[c - 'a']++;
        trie.ans = -1;
        trie.dfs(0, 'a', cnt);
        if (trie.ans == -1)
            cout << "IMPOSSIBLE\n";
        else
            cout << s[trie.ans] << '\n';
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
