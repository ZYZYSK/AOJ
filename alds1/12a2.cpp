//////////////////////////////////////////////////
//プリム法
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
class Prim
{
private:
    //隣接行列
    vector<vl> G;
    //コスト
    ll cost;
    //頂点数
    ll size;
    //すでに確定した頂点からの最小コスト
    vl mincost;
    //既に確定したかどうか
    vb used;

public:
    //コンストラクタ
    Prim(vector<vl> &G)
    {
        this->G = G;
        this->size = G.size();
        mincost.assign(this->size, INFTY);
        used.assign(this->size, false);
        this->cost = 0;
        //頂点0から開始
        this->mincost[0] = 0;
    }
    //最小全域木のコストを求める
    ll getCost()
    {
        while (true)
        {
            ll v = -1;
            for (ll u = 0; u < this->size; u++)
            {
                //最小コストで行ける頂点vを探す
                if (!this->used[u] && (v == -1 || mincost[u] < mincost[v]))
                {
                    v = u;
                }
            }
            //最小全域木ができたので終了
            if (v == -1)
            {
                break;
            }
            this->used[v] = true;
            this->cost += this->mincost[v];
            //確定した頂点から行ける頂点について,最小コストを更新
            for (ll u = 0; u < this->size; u++)
            {
                if (G[v][u] != -1)
                {
                    this->mincost[u] = min(mincost[u], G[v][u]);
                }
            }
        }
        return this->cost;
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<vl> G(n, vl(n));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> G[i][j];
        }
    }
    Prim P(G);
    cout << P.getCost() << endl;
}
