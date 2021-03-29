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
template <class T>
using pque = priority_queue<T>;
const ll INFTY = 1L << 62L;
const ll BOARD_SIZE = 8;
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
bool setable(vector<vl> &BOARD, ll r, ll c)
{
    return BOARD[r][c] == 1;
}
void setQueen(vector<vl> &BOARD, ll r, ll c)
{
    for (ll y = 0; y < BOARD_SIZE; y++)
    {
        BOARD[y][c] = 0;
    }
    for (ll x = 0; x < BOARD_SIZE; x++)
    {
        BOARD[r][x] = 0;
    }
    for (ll y = r - 1, x = c - 1; y > -1 && x > -1; y--, x--)
    {
        BOARD[y][x] = 0;
    }
    for (ll y = r - 1, x = c + 1; y > -1 && x < BOARD_SIZE; y--, x++)
    {
        BOARD[y][x] = 0;
    }
    for (ll y = r + 1, x = c + 1; y < BOARD_SIZE && x < BOARD_SIZE; y++, x++)
    {
        BOARD[y][x] = 0;
    }
    for (ll y = r + 1, x = c - 1; y < BOARD_SIZE && x > -1; y++, x--)
    {
        BOARD[y][x] = 0;
    }
    BOARD[r][c] = -1;
}
void printBoard(vector<vl> &BOARD)
{
    vs anslist(BOARD_SIZE, string(BOARD_SIZE, '.'));
    for (ll r = 0; r < BOARD_SIZE; r++)
    {
        for (ll c = 0; c < BOARD_SIZE; c++)
        {
            if (BOARD[r][c] == -1)
            {
                anslist[r][c] = 'Q';
            }
        }
    }
    print_list(anslist);
}
bool printed = false;
void dfs(vector<vl> &BOARD, ll remnant)
{
    if (remnant == 0 && !printed)
    {
        printBoard(BOARD);
        printed = true;
        return;
    }
    //すべての場合を試して見る
    for (ll y = 0; y < BOARD_SIZE; y++)
    {
        for (ll x = 0; x < BOARD_SIZE; x++)
        {
            if (setable(BOARD, y, x))
            {
                auto BOARD_new = BOARD;
                setQueen(BOARD_new, y, x);
                dfs(BOARD_new, remnant - 1);
            }
        }
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll k, r, c;
    cin >> k;
    //-1: クイーン 0: 配置不能 1:配置可能
    vector<vl> BOARD(BOARD_SIZE, vl(BOARD_SIZE, 1));
    for (ll _k = 0; _k < k; _k++)
    {
        cin >> r >> c;
        setQueen(BOARD, r, c);
    }
    ll remnant = 8 - k;
    dfs(BOARD, remnant);
}