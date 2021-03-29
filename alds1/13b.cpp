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
            if (BOARD[i][j] != (i * 3 + j + 1) % (N * N))
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
void solver(vector<vl> &BOARD, ll ans_tmp)
{
    //無限防止
    if (ans_tmp > 15)
    {
        return;
    }
    //ゴールしたら最短手数を更新
    if (checkGoal(BOARD))
    {
        ans = min(ans, ans_tmp);
        return;
    }
    if (moveAbleLeft(BOARD))
    {
        auto BOARD_new = BOARD;
        moveLeft(BOARD_new);
        solver(BOARD_new, ans_tmp + 1);
    }
    if (moveAbleRight(BOARD))
    {
        auto BOARD_new = BOARD;
        moveRight(BOARD_new);
        solver(BOARD_new, ans_tmp + 1);
    }
    if (moveAbleUp(BOARD))
    {
        auto BOARD_new = BOARD;
        moveUp(BOARD_new);
        solver(BOARD_new, ans_tmp + 1);
    }
    if (moveAbleDown(BOARD))
    {
        auto BOARD_new = BOARD;
        moveDown(BOARD_new);
        solver(BOARD_new, ans_tmp + 1);
    }
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
    solver(BOARD, 0);
    cout << ans << endl;
}