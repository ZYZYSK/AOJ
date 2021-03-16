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
ll solver(ll n)
{
    if (n == 0 || n == 1)
        return 1;
    vl a(n + 1);
    a[0] = 1, a[1] = 1;
    for (ll i = 2; i < n + 1; i++)
    {
        a[i] = a[i - 2] + a[i - 1];
    }
    return a[n];
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    cout << solver(n) << endl;
}