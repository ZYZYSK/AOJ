//////////////////////////////////////////////////
//クラスカル法
//////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vd = vector<double>;
using vs = vector<string>;
using vb = vector<bool>;
using mll = map<ll, ll>;
using mld = map<ll, double>;
using mls = map<ll, string>;
using mlb = map<ll, bool>;
using sl = set<ll>;
using sd = set<double>;
using ss = set<string>;
using pll = pair<ll, ll>;
using pls = pair<ll, string>;
using pld = pair<ll, double>;
using plb = pair<ll, bool>;
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
    ll root(ll x)
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
    ll getSize(ll x)
    {
        return this->size[this->root(x)];
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
//辺abとそのコスト
class Edge
{
public:
    ll a, b, cost;
    bool operator<(const Edge &o) const
    {
        return this->cost < o.cost;
    }
    Edge(ll i, ll j, ll cost)
    {
        this->a = i;
        this->b = j;
        this->cost = cost;
    }
};
//グラフ
class Graph
{
private:
    //頂点数
    int size;
    //辺集合
    vector<Edge> es;

public:
    //クラスカル法
    ll kruskal()
    {
        UnionFind U(size);
        ll cost = 0;
        //コストが小さい順にソート
        sort(this->es.begin(), this->es.end());
        for (auto &e : this->es)
        {
            if (!U.same(e.a, e.b))
            {
                cost += e.cost;
                U.merge(e.a, e.b);
            }
        }
        return cost;
    }
    //コンストラクタ
    Graph(ll size)
    {
        this->size = size;
    }
    //辺を追加
    void addEdge(ll i, ll j, ll cost)
    {
        this->es.emplace_back(Edge(i, j, cost));
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll cost;
    Graph G(n);
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> cost;
            if (cost != -1)
            {
                G.addEdge(i, j, cost);
            }
        }
    }
    cout << G.kruskal() << endl;
}
