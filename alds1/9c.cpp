#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
const ll INFTY = 1L << 62L;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    priority_queue<int> que;
    string ans;
    while (true)
    {
        string order;
        int value;
        cin >> order;
        if (order == "end")
        {
            break;
        }
        else if (order == "insert")
        {
            cin >> value;
            que.push(value);
        }
        else
        {
            ans += to_string(que.top());
            ans += '\n';
            que.pop();
        }
    }
    printf("%s", ans.c_str());
}