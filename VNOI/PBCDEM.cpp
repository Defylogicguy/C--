/*************************
  Author: Defy logic guy
  20:34:55 - 12/11/2025
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
#define NAME "PBCDEM"

class BigInt
{
    static const int base = 1000000000;
    static const int base_digits = 9;
    vector<int> a;
    bool neg;
    void trim()
    {
        while (a.size() and !a.back())
            a.pop_back();
        if (a.empty())
            neg = false;
    }
    static int cmp_abs(const BigInt &x, const BigInt &y)
    {
        if (x.a.size() != y.a.size())
            return x.a.size() < y.a.size() ? -1 : 1;
        for (int i = (int)x.a.size() - 1; i >= 0; --i)
            if (x.a[i] != y.a[i])
                return x.a[i] < y.a[i] ? -1 : 1;
        return 0;
    }

public:
    BigInt() : neg(false) {}
    BigInt(long long v) : neg(false) { *this = v; }
    BigInt(const string &s) : neg(false) { read(s); }
    BigInt &operator=(long long v)
    {
        neg = false;
        if (v < 0)
        {
            neg = true;
            v = -v;
        }
        a.clear();
        while (v > 0)
        {
            a.push_back(v % base);
            v /= base;
        }
        return *this;
    }
    BigInt &read(const string &s)
    {
        neg = false;
        a.clear();
        int pos = 0;
        while (pos < (int)s.size() and isspace(s[pos]))
            pos++;
        if (pos < (int)s.size() and (s[pos] == '-' || s[pos] == '+'))
        {
            if (s[pos] == '-')
                neg = true;
            pos++;
        }
        for (int i = (int)s.size() - 1; i >= pos; i -= base_digits)
        {
            int x = 0;
            int l = max(pos, i - base_digits + 1);
            for (int j = l; j <= i; j++)
                x = x * 10 + (s[j] - '0');
            a.push_back(x);
        }
        trim();
        return *this;
    }
    string toString() const
    {
        if (a.empty())
            return "0";
        string s = neg ? "-" : "";
        s += std::to_string(a.back());
        for (int i = (int)a.size() - 2; i >= 0; --i)
        {
            string t = std::to_string(a[i]);
            s += string(base_digits - (int)t.length(), '0') + t;
        }
        return s;
    }
    friend ostream &operator<<(ostream &os, const BigInt &v) { return os << v.toString(); }
    friend istream &operator>>(istream &is, BigInt &v)
    {
        string s;
        is >> s;
        v.read(s);
        return is;
    }
    friend bool operator<(const BigInt &a, const BigInt &b)
    {
        if (a.neg != b.neg)
            return a.neg;
        int cmp = cmp_abs(a, b);
        return a.neg ? cmp > 0 : cmp < 0;
    }
    friend bool operator==(const BigInt &a, const BigInt &b) { return a.neg == b.neg and a.a == b.a; }
    friend bool operator!=(const BigInt &a, const BigInt &b) { return !(a == b); }
    friend bool operator>(const BigInt &a, const BigInt &b) { return b < a; }
    friend bool operator<=(const BigInt &a, const BigInt &b) { return !(b < a); }
    friend bool operator>=(const BigInt &a, const BigInt &b) { return !(a < b); }
    friend bool operator<(const BigInt &a, long long b) { return a < BigInt(b); }
    friend bool operator>(const BigInt &a, long long b) { return a > BigInt(b); }
    friend bool operator<=(const BigInt &a, long long b) { return a <= BigInt(b); }
    friend bool operator>=(const BigInt &a, long long b) { return a >= BigInt(b); }
    friend bool operator==(const BigInt &a, long long b) { return a == BigInt(b); }
    friend bool operator!=(const BigInt &a, long long b) { return a != BigInt(b); }
    friend bool operator<(long long a, const BigInt &b) { return BigInt(a) < b; }
    friend bool operator>(long long a, const BigInt &b) { return BigInt(a) > b; }
    friend bool operator<=(long long a, const BigInt &b) { return BigInt(a) <= b; }
    friend bool operator>=(long long a, const BigInt &b) { return BigInt(a) >= b; }
    friend bool operator==(long long a, const BigInt &b) { return BigInt(a) == b; }
    friend bool operator!=(long long a, const BigInt &b) { return BigInt(a) != b; }
    friend BigInt operator-(const BigInt &v)
    {
        BigInt res = v;
        if (!res.a.empty())
            res.neg = !res.neg;
        return res;
    }
    friend BigInt operator+(const BigInt &a, const BigInt &b)
    {
        if (a.neg == b.neg)
        {
            BigInt res;
            res.neg = a.neg;
            int carry = 0;
            int n = max((int)a.a.size(), (int)b.a.size());
            res.a.resize(n);
            for (int i = 0; i < n; i++)
            {
                long long sum = carry;
                if (i < (int)a.a.size())
                    sum += a.a[i];
                if (i < (int)b.a.size())
                    sum += b.a[i];
                carry = sum >= base;
                if (carry)
                    sum -= base;
                res.a[i] = (int)sum;
            }
            if (carry)
                res.a.push_back(carry);
            return res;
        }
        return a - (-b);
    }
    friend BigInt operator-(const BigInt &a, const BigInt &b)
    {
        if (a.neg != b.neg)
            return a + (-b);
        if (a.neg)
            return (-b) - (-a);
        if (cmp_abs(a, b) >= 0)
        {
            BigInt res;
            res.neg = false;
            res.a = a.a;
            int carry = 0;
            for (int i = 0; i < (int)res.a.size(); i++)
            {
                long long diff = res.a[i] - carry - (i < (int)b.a.size() ? b.a[i] : 0);
                carry = diff < 0;
                if (carry)
                    diff += base;
                res.a[i] = (int)diff;
            }
            res.trim();
            return res;
        }
        BigInt res = b - a;
        res.neg = true;
        return res;
    }
    friend BigInt operator*(const BigInt &a, const BigInt &b)
    {
        BigInt res;
        res.neg = a.neg != b.neg;
        if (a.a.empty() || b.a.empty())
            return res;
        res.a.assign(a.a.size() + b.a.size(), 0);
        for (int i = 0; i < (int)a.a.size(); i++)
        {
            long long carry = 0;
            for (int j = 0; j < (int)b.a.size() || carry; j++)
            {
                long long cur = res.a[i + j] + carry + (long long)a.a[i] * (j < (int)b.a.size() ? b.a[j] : 0);
                res.a[i + j] = (int)(cur % base);
                carry = cur / base;
            }
        }
        res.trim();
        return res;
    }
    friend BigInt &operator+=(BigInt &a, const BigInt &b)
    {
        a = a + b;
        return a;
    }
    friend BigInt &operator-=(BigInt &a, const BigInt &b)
    {
        a = a - b;
        return a;
    }
    friend BigInt &operator*=(BigInt &a, const BigInt &b)
    {
        a = a * b;
        return a;
    }
    friend BigInt &operator/=(BigInt &a, const BigInt &b)
    {
        a = a / b;
        return a;
    }
    friend BigInt &operator%=(BigInt &a, const BigInt &b)
    {
        a = a % b;
        return a;
    }
    BigInt &operator++()
    {
        *this = *this + BigInt(1);
        return *this;
    }
    BigInt operator++(signed)
    {
        BigInt temp = *this;
        *this = *this + BigInt(1);
        return temp;
    }
    BigInt &operator--()
    {
        *this = *this - BigInt(1);
        return *this;
    }
    BigInt operator--(signed)
    {
        BigInt temp = *this;
        *this = *this - BigInt(1);
        return temp;
    }
    friend BigInt operator%(const BigInt &a, long long b) { return a % BigInt(b); }
    friend BigInt operator%(long long a, const BigInt &b) { return BigInt(a) % b; }
    friend pair<BigInt, BigInt> divmod(const BigInt &a, const BigInt &b)
    {
        if (b.a.empty())
            throw runtime_error("division by zero");
        BigInt norm_a = a;
        norm_a.neg = false;
        BigInt norm_b = b;
        norm_b.neg = false;
        if (norm_a < norm_b)
            return {BigInt(0), a};
        BigInt q;
        q.neg = a.neg != b.neg;
        q.a.assign(norm_a.a.size(), 0);
        BigInt r;
        r.neg = false;
        for (int i = (int)norm_a.a.size() - 1; i >= 0; --i)
        {
            r.a.insert(r.a.begin(), norm_a.a[i]);
            r.trim();
            int s1 = r.a.size() > norm_b.a.size() ? r.a[norm_b.a.size()] : 0;
            long long s2 = r.a.size() > norm_b.a.size() - 1 ? r.a[norm_b.a.size() - 1] : 0;
            long long d = ((long long)base * s1 + s2) / (norm_b.a.back() + 1);
            if (d >= base)
                d = base - 1;
            BigInt db = norm_b * BigInt(d);
            while (r < db)
            {
                d--;
                db = norm_b * BigInt(d);
            }
            r = r - db;
            q.a[i] = (int)d;
        }
        q.trim();
        if (q.a.empty())
            q.neg = false;
        r.trim();
        return {q, r};
    }
    friend BigInt operator/(const BigInt &a, const BigInt &b) { return divmod(a, b).first; }
    friend BigInt operator%(const BigInt &a, const BigInt &b) { return divmod(a, b).second; }
    friend BigInt pow(BigInt a, long long e)
    {
        if (e < 0)
            throw runtime_error("negative exponent");
        BigInt res(1);
        while (e)
        {
            if (e & 1)
                res = res * a;
            a = a * a;
            e >>= 1;
        }
        return res;
    }
    friend BigInt operator^(const BigInt &a, long long e) { return pow(a, e); }
    friend BigInt operator^(const BigInt &a, const BigInt &b)
    {
        long long e = 0;
        for (int i = (int)b.a.size() - 1; i >= 0; --i)
        {
            e = e * base + b.a[i];
            if (e < 0)
                throw runtime_error("exponent too large");
        }
        return pow(a, e);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<BigInt> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = n; j >= i; j--)
            dp[j] += dp[j - i];
    cout << dp[n] - 1;
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
