#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
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
ll solver(string x, string y)
{
    vector<vl> DP(x.size() + 1, vl(y.size() + 1, 0));
    for (ll ix = 0; ix < x.size(); ix++)
    {
        for (ll iy = 0; iy < y.size(); iy++)
        {
            DP[ix + 1][iy + 1] = max(DP[ix + 1][iy], DP[ix][iy + 1]);
            if (x[ix] == y[iy])
            {
                DP[ix + 1][iy + 1] = max(DP[ix + 1][iy + 1], DP[ix][iy] + 1);
            }
        }
    }
    return DP[x.size()][y.size()];
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll q;
    cin >> q;
    vl ans(q);
    string x, y;
    for (ll i = 0; i < q; i++)
    {
        x.clear();
        y.clear();
        cin >> x >> y;
        ans[i] = solver(x, y);
    }
    print_list<vl>(ans);
}