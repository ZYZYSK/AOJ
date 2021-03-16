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
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vl R(n), C(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> R[i] >> C[i];
    }
    vector<vl> DP(n + 1, vl(n + 1, 0));
    ll j;
    for (ll d = 1; d < n; d++)
    {
        for (ll i = 0; i < n - d; i++)
        {
            j = i + d;
            DP[i][j] = INFTY;
            for (ll k = i; k < j; k++)
            {
                DP[i][j] = min(DP[i][j], DP[i][k] + DP[k + 1][j] + R[i] * C[k] * C[j]);
            }
        }
    }
    cout << DP[0][n - 1] << endl;
}