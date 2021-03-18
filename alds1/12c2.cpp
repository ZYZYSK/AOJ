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
template <class T>
using pque = priority_queue<T>;
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
vl getDistance(vector<vector<pll>> &G, ll n)
{
    vl d(n, INFTY);
    vb used(n, false);
    d[0] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> QUE;
    QUE.emplace(make_pair(d[0], 0));
    ll p;
    ll v, c;
    while (!QUE.empty())
    {
        //最小距離の点を選ぶ
        p = QUE.top().second;
        //最小距離の点を確定
        QUE.pop();
        used[p] = true;
        //最小距離の点からたどりつけるすべての点を探し，距離を更新
        for (ll q = 0; q < G[p].size(); q++)
        {
            c = G[p][q].first, v = G[p][q].second;
            if (d[p] + c < d[v])
            {
                d[v] = d[p] + c;
                QUE.emplace(make_pair(d[v], v));
            }
        }
    }
    return d;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll u, k, v, c;
    //各頂点の(重み，隣接点)
    vector<vector<pll>> G(n, vector<pll>(0));
    for (ll i = 0; i < n; i++)
    {
        cin >> u >> k;
        for (ll j = 0; j < k; j++)
        {
            cin >> v >> c;
            G[u].emplace_back(make_pair(c, v));
        }
    }
    vl d = getDistance(G, n);
    for (ll i = 0; i < n; i++)
    {
        printf("%lld %lld\n", i, d[i]);
    }
}
