#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vd = vector<double>;
using vs = vector<string>;
using ml = map<ll, ll>;
using ms = map<ll, string>;
const ll INFTY = 1L << 62L;
template <typename T>
void print_list(T &array, string sep = "\n", ll begin = 0)
{
    string ans;
    if (typeid(array[0]) == typeid(string))
    {
        for (ll i = begin; i < array.size(); i++)
        {
            ans += array[i];
            if (i == array.size() - 1)
            {
                continue;
            }
            ans += sep;
        }
    }
    else if (typeid(array[0]) == typeid(char))
    {
        for (ll i = begin; i < array.size(); i++)
        {
            ans.push_back(array[i]);
            if (i == array.size() - 1)
            {
                continue;
            }
            ans += sep;
        }
    }
    else
    {
        for (ll i = begin; i < array.size(); i++)
        {
            ans += to_string(array[i]);
            if (i == array.size() - 1)
            {
                continue;
            }
            ans += sep;
        }
    }
    printf("%s\n", ans.c_str());
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll u, k, v;
    vector<vl> G(n + 1, vl(0));
    for (ll i = 0; i < n; i++)
    {
        cin >> u >> k;
        for (ll _k = 0; _k < k; _k++)
        {
            cin >> v;
            G[u].push_back(v);
        }
    }
    vl d(n + 1, -1);
    queue<ll> que;
    ll p, q;
    que.push(1);
    d[1] = 0;
    while (!que.empty())
    {
        p = que.front();
        que.pop();
        for (ll i = 0; i < G[p].size(); i++)
        {
            q = G[p][i];
            if (d[q] == -1)
            {
                que.push(q);
                d[q] = d[p] + 1;
            }
        }
    }
    for (ll i = 1; i < n + 1; i++)
    {
        printf("%lld %lld\n", i, d[i]);
    }
}