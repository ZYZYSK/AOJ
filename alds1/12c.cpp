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
vl getDistance(vector<vector<pll>> &G, ll n)
{
    vl d(n, INFTY);
    vb used(n, false);
    d[0] = 0;
    ll p;
    ll v, c;
    while (true)
    {
        p = -1;
        //最小距離の点を選ぶ
        for (ll q = 0; q < n; q++)
        {
            if (!used[q] && (p == -1 || d[q] < d[p]))
            {
                p = q;
            }
        }
        if (p == -1)
        {
            break;
        }
        // printf("d[%lld]:%lld\n", p, d[p]);
        used[p] = true;
        for (ll q = 0; q < G[p].size(); q++)
        {
            v = G[p][q].first, c = G[p][q].second;
            d[v] = min(d[v], d[p] + c);
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
    //各頂点の(隣接点,重み)
    vector<vector<pll>> G(n, vector<pll>(0));
    for (ll i = 0; i < n; i++)
    {
        cin >> u >> k;
        for (ll j = 0; j < k; j++)
        {
            cin >> v >> c;
            G[u].emplace_back(make_pair(v, c));
        }
    }
    vl d = getDistance(G, n);
    for (ll i = 0; i < n; i++)
    {
        printf("%lld %lld\n", i, d[i]);
    }
}
