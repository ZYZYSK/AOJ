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
vl group;
void setGroup(vector<vl> &G, ll s, ll n, int id)
{
    queue<ll> que;
    vector<bool> v(n + 1, false);
    que.push(s);
    v[s] = true;
    group[s] = id;
    ll p, q;
    while (!que.empty())
    {
        p = que.front();
        que.pop();
        for (ll i = 0; i < G[p].size(); i++)
        {
            q = G[p][i];
            if (!v[q])
            {
                v[q] = true;
                group[q] = id;
                que.push(q);
            }
        }
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    group.resize(n, -1);
    ll s, t;
    vector<vl> G(n, vl(0));
    for (ll i = 0; i < m; i++)
    {
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    ll q;
    cin >> q;
    vs anslist(q);
    for (ll i = 0; i < q; i++)
    {
        cin >> s >> t;
        if (group[s] == -1)
        {
            setGroup(G, s, n, s);
        }
        if (group[t] == -1)
        {
            setGroup(G, t, n, t);
        }
        if (group[s] == group[t])
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