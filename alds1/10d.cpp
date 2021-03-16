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

void solver(vd &p, vector<vd> &q, vector<vd> &DP, ll n)
{
    ll j;
    for (ll d = 1; d < n + 1; d++)
    {
        for (ll i = 0; i < n - d + 1; i++)
        {
            j = i + d;
            DP[i][j] = static_cast<double>(INFTY);
            //q[0][1]=q[1][1]+q[0][0]+p[1]
            //q[1][2]=q[2][2]+q[1][1]+p[2]
            //...
            //q[0][2]=q[2][2]+q[0][1]+p[2]
            q[i][j] = q[j][j] + q[i][j - 1] + p[j];
            //p[k+1]を根としたとき，ダミーキーd[i]以上，d[j]以下の値となる要素全体の期待値の最小値を求める
            for (ll k = i; k < j; k++)
            {
                DP[i][j] = min(DP[i][j], DP[i][k] + DP[k + 1][j] + q[i][k] + q[k + 1][j]);
            }
        }
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vd p(n + 1);
    //q[i][j]: ダミーキーd[i]以上，d[j]以下の値となる要素の確率の合計
    vector<vd> q(n + 1, vd(n + 1));
    //dp[i][j]: ダミーキーd[i]以上，d[j]以下の値となる要素全体の最小の期待値
    vector<vd> DP(n + 1, vd(n + 1));
    for (ll i = 1; i < n + 1; i++)
    {
        cin >> p[i];
    }
    for (ll i = 0; i < n + 1; i++)
    {
        cin >> q[i][i];
    }
    solver(p, q, DP, n);
    cout << DP[0][n] + 1 << endl;
}
