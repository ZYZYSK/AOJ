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
class fenwick_tree
{
private:
    ll n = n;
    vl bit;

public:
    fenwick_tree(ll n);
    ~fenwick_tree();
    void add(ll pos, ll value);
    ll sum(ll pos);
};

fenwick_tree::fenwick_tree(ll n)
{
    this->n = n;
    bit.resize(n + 1, 0);
}

fenwick_tree::~fenwick_tree()
{
}
void fenwick_tree::add(ll pos, ll value)
{
    while (pos <= this->n)
    {
        this->bit[pos] += value;
        pos += (pos & -pos);
    }
}
ll fenwick_tree::sum(ll pos)
{
    ll ans = 0;
    while (pos > 0)
    {
        ans += this->bit[pos];
        pos -= (pos & -pos);
    }
    return ans;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vl A(n);
    ml M;
    for (ll i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    //数列の順序を保ったまま数を小さくする
    vl B = A;
    sort(A.begin(), A.end());
    for (ll i = 0; i < n; i++)
    {
        M[A[i]] = i + 1;
    }
    for (ll i = 0; i < n; i++)
    {
        A[i] = M[B[i]];
    }
    //転倒数を求める
    ll ans = 0;
    fenwick_tree t(n);
    for (ll i = 0; i < n; i++)
    {
        ans += (i - t.sum(A[i]));
        t.add(A[i], 1);
    }
    cout << ans << endl;
}