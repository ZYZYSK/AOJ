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
const ll N = 3;
ll ans = INFTY;
//ゴールであるかどうかを確認する
bool checkGoal(vector<vl> &BOARD)
{
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
        {
            if (BOARD[i][j] != (i * N + j + 1) % (N * N))
            {
                return false;
            }
        }
    }
    return true;
}
//その方向に移動
void moveLeft(vector<vl> &BOARD)
{
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
        {
            if (BOARD[i][j] == 0)
            {
                swap(BOARD[i][j], BOARD[i][j - 1]);
                return;
            }
        }
    }
}
//その方向に移動
void moveRight(vector<vl> &BOARD)
{
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
        {
            if (BOARD[i][j] == 0)
            {
                swap(BOARD[i][j], BOARD[i][j + 1]);
                return;
            }
        }
    }
}
//その方向に移動
void moveUp(vector<vl> &BOARD)
{
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
        {
            if (BOARD[i][j] == 0)
            {
                swap(BOARD[i][j], BOARD[i - 1][j]);
                return;
            }
        }
    }
}
//その方向に移動
void moveDown(vector<vl> &BOARD)
{
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
        {
            if (BOARD[i][j] == 0)
            {
                swap(BOARD[i][j], BOARD[i + 1][j]);
                return;
            }
        }
    }
}
//その方向に移動できるか
bool moveAbleLeft(vector<vl> &BOARD)
{
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
        {
            if (BOARD[i][j] == 0)
            {
                return j > 0 ? true : false;
            }
        }
    }
    return false;
    return false;
}
//その方向に移動できるか
bool moveAbleRight(vector<vl> &BOARD)
{
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
        {
            if (BOARD[i][j] == 0)
            {
                return j < N - 1 ? true : false;
            }
        }
    }
    return false;
}
//その方向に移動できるか
bool moveAbleUp(vector<vl> &BOARD)
{
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
        {
            if (BOARD[i][j] == 0)
            {
                return i > 0 ? true : false;
            }
        }
    }
    return false;
}
//その方向に移動できるか
bool moveAbleDown(vector<vl> &BOARD)
{
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
        {
            if (BOARD[i][j] == 0)
            {
                return i < N - 1 ? true : false;
            }
        }
    }
    return false;
}
ll solver(vector<vl> &BOARD)
{
    //各回における盤面を登録
    set<vector<vl>> BOARDmap;
    //現在の盤面と移動回数
    queue<vector<vl>> BOARDs;
    queue<ll> ANSs;
    BOARDs.emplace(BOARD);
    ANSs.emplace(0);
    while (!BOARDs.empty())
    {
        auto board = BOARDs.front();
        auto ans = ANSs.front();
        BOARDs.pop();
        ANSs.pop();
        if (checkGoal(board))
        {
            return ans;
        }
        if (moveAbleLeft(board))
        {
            auto board_new = board;
            moveLeft(board_new);
            //すでに出現した盤面はもう検索しない
            if (!BOARDmap.count(board_new))
            {
                BOARDs.emplace(board_new);
                ANSs.emplace(ans + 1);
                BOARDmap.emplace(board_new);
            }
        }
        if (moveAbleRight(board))
        {
            auto board_new = board;
            moveRight(board_new);
            if (!BOARDmap.count(board_new))
            {
                BOARDs.emplace(board_new);
                ANSs.emplace(ans + 1);
                BOARDmap.emplace(board_new);
            }
        }
        if (moveAbleUp(board))
        {
            auto board_new = board;
            moveUp(board_new);
            if (!BOARDmap.count(board_new))
            {
                BOARDs.emplace(board_new);
                ANSs.emplace(ans + 1);
                BOARDmap.emplace(board_new);
            }
        }
        if (moveAbleDown(board))
        {
            auto board_new = board;
            moveDown(board_new);
            if (!BOARDmap.count(board_new))
            {
                BOARDs.emplace(board_new);
                ANSs.emplace(ans + 1);
                BOARDmap.emplace(board_new);
            }
        }
    }
    return -1;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<vl> BOARD(N, vl(N));
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
        {
            cin >> BOARD[i][j];
        }
    }
    cout << solver(BOARD) << endl;
}
