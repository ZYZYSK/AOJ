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
    ll v, k, u;
    vl d(n + 1, 0), f(n + 1, 0);
    vector<vl> G(n + 1, vl(0));
    for (ll i = 0; i < n; i++)
    {
        cin >> v >> k;
        for (ll _k = 0; _k < k; _k++)
        {
            cin >> u;
            G[v].emplace_back(u);
        }
    }
    ll cnt = 0;
    ll p, q;
    bool fflag;
    for (ll id = 1; id < n + 1; id++)
    {
        if (d[id] == 0)
        {
            stack<ll> stk;
            stk.emplace(id);
            while (!stk.empty())
            {
                fflag = true;
                p = stk.top();
                if (d[p] == 0)
                {
                    d[p] = ++cnt;
                }
                for (ll i = 0; i < G[p].size(); i++)
                {
                    if (d[G[p][i]] == 0)
                    {
                        fflag = false;
                        break;
                    }
                }
                //隣接キーの探索が完了した場合
                if (fflag)
                {
                    if (f[p] == 0)
                    {
                        f[p] = ++cnt;
                    }
                    stk.pop();
                }
                else
                {
                    for (ll i = G[p].size() - 1; i >= 0; i--)
                    {
                        q = G[p][i];
                        if (d[q] == 0)
                        {
                            stk.emplace(q);
                        }
                    }
                }
            }
        }
    }
    for (ll i = 1; i < n + 1; i++)
    {
        printf("%lld %lld %lld\n", i, d[i], f[i]);
    }
}