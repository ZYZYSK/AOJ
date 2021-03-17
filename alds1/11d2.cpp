#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vd = vector<double>;
using vs = vector<string>;
using vb = vector<bool>;
using ml = map<ll, ll>;
using md = map<ll, double>;
using ms = map<ll, string>;
using sl = set<ll>;
using sd = set<double>;
using ss = set<string>;
const ll INFTY = 1L << 62L;
template <typename T>
void print_list(T &array, string sep = "\n", ll begin = 0)
{
    string ans;
    for (ll i = begin; i < array.size(); i++)
    {
        ans += to_string(array[i]);
        if (i == array.size() - 1)
        {
            continue;
        }
        ans += sep;
    }
    printf("%s\n", ans.c_str());
}
void print_list(vs &array, string sep = "\n", ll begin = 0)
{
    string ans;

    for (ll i = begin; i < array.size(); i++)
    {
        ans += array[i];
        if (i == array.size() - 1)
        {
            continue;
        }
        ans += sep;
    }
    printf("%s\n", ans.c_str());
}
class UnionFind
{
private:
    ll n;
    vl par;
    vl size;

public:
    UnionFind(ll n);
    ~UnionFind();
    int root(ll x)
    {
        if (this->par[x] == x)
        {
            return x;
        }
        else
        {
            //xの親の親をxの親とする　
            return this->par[x] = root(this->par[x]);
        }
    }
    void merge(ll x, ll y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
        {
            return;
        }
        if (this->size[x] < this->size[y])
        {
            swap(x, y);
        }
        this->size[x] += this->size[y];
        par[y] = x;
    }
    bool same(ll x, ll y)
    {
        return this->root(x) == this->root(y);
    }
};

UnionFind::UnionFind(ll n)
{
    this->par.resize(n);
    //par[i]=iならば根
    for (ll i = 0; i < n; i++)
    {
        this->par[i] = i;
    }
    this->size.resize(n, 1);
}

UnionFind::~UnionFind()
{
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    ll s, t;
    UnionFind U(n);
    for (ll i = 0; i < m; i++)
    {
        cin >> s >> t;
        U.merge(s, t);
    }
    ll q;
    cin >> q;
    vs anslist(q);
    for (ll i = 0; i < q; i++)
    {
        cin >> s >> t;
        if (U.same(s, t))
        {
            anslist[i] = "yes";
        }
        else
        {
            anslist[i] = "no";
        }
    }
    print_list(anslist);
}