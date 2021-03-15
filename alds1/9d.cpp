#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vs = vector<string>;
using ml = map<ll, ll>;
using ms = map<ll, string>;
const ll INFTY = 1L << 62L;
template <typename T>
void print_list(T array, string sep = "\n", ll begin = 0)
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
void maxHeapify(vl &A, ll i, ll N)
{
    ll l = i * 2, r = i * 2 + 1, largest;
    if (l <= N && A[l] > A[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }
    if (r <= N && A[r] > A[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(A[i], A[largest]);
        maxHeapify(A, largest, N);
    }
}
void maxHeapifyR(vl &A, ll i)
{
    while (i != 1)
    {
        swap(A[i / 2], A[i]);
        i /= 2;
    }
}
void heapSort(vl &A, int N)
{
    //buildMaxHeap
    for (int i = N / 2; i > 0; i--)
    {
        maxHeapify(A, i, N);
    }
    //sort
    ll heapSize = N;
    while (heapSize >= 2)
    {
        swap(A[1], A[heapSize]);
        --heapSize;
        maxHeapify(A, 1, heapSize);
    }
}
void maxHeapifyFromSorted(vl &A, int N)
{
    ll heapSize = 2;
    while (heapSize < N)
    {
        swap(A[1], A[heapSize]);
        maxHeapifyR(A, heapSize);
        ++heapSize;
    }
    if (heapSize < A.size())
    {
        swap(A[1], A[heapSize]);
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    string ans;
    cin >> N;
    vl A(N + 1);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i + 1];
    }
    heapSort(A, N);
    maxHeapifyFromSorted(A, N);
    print_list<vl>(A, " ", 1);
}