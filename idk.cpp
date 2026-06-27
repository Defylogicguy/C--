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
    for (auto it = c.begin(); it != c.end(); it++)
        os << (it == c.begin() ? "{" : ", ") << *it;
    return os << "}";
}
#define dbg(x) cerr << #x << " = " << (x) << '\n';
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "line2"

class Vec
{
public:
    struct Pt
    {
        double x, y;
        Pt(double x = 0, double y = 0) : x(x), y(y) {}
        bool operator==(const Pt &other) const { return x == other.x && y == other.y; }
    };
    Pt st, end;
    double len = 0.0;
    Vec(double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0) : st(x1, y1), end(x2, y2) { len = hypot(x2 - x1, y2 - y1); }
    Vec(const Pt &s, const Pt &e) : st(s), end(e) { len = hypot(e.x - s.x, e.y - s.y); }
    Pt direction() const { return Pt(end.x - st.x, end.y - st.y); }
    static double dot(const Vec &a, const Vec &b)
    {
        Pt da = a.direction();
        Pt db = b.direction();
        return da.x * db.x + da.y * db.y;
    }
    static double cross(const Vec &a, const Vec &b)
    {
        Pt da = a.direction();
        Pt db = b.direction();
        return da.x * db.y - da.y * db.x;
    }
    static double angleBetween(const Vec &a, const Vec &b)
    {
        if (a.st == b.st or a.st == b.end or a.end == b.st or a.end == b.end)
        {
            double d = dot(a, b);
            double cosAngle = d / (a.len * b.len);
            cosAngle = min(1.0, max(-1.0, cosAngle));
            return acos(cosAngle);
        }
        cerr << "No common point between vectors\n";
        exit(1);
    }
    Vec operator+(const Vec &other) const { return Vec(st.x + other.st.x, st.y + other.st.y, end.x + other.end.x, end.y + other.end.y); }
    Vec operator-(const Vec &other) const { return Vec(st.x - other.st.x, st.y - other.st.y, end.x - other.end.x, end.y - other.end.y); }
    bool operator==(const Vec &other) const { return st == other.st && end == other.end; }
};

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int t = c;
    c = a - d, d = b + t;
    cout << d - b << ' ' << a - c << ' ' << c * b - a * d;
}

signed main()
{
    if (fopen(NAME ".IN", "r"))
    {
        freopen(NAME ".IN", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
