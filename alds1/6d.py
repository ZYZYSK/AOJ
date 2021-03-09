def solve(n, A):
    VMAX = 10000

    ans = 0
    s = min(A)
    V = [False] * n
    B = sorted(A)
    T = {B[i]: i for i in range(n)}

    for i in range(n):
        if V[i]:
            continue
        cur = i
        S = 0
        m = VMAX
        an = 0
        while not V[cur]:
            V[cur] = True
            an += 1
            v = A[cur]
            m = min(m, v)
            S += v
            cur = T[v]
        ans += min(S + (an - 2) * m, m + S + (an + 1) * s)
    return ans

def main():
    n = int(input())
    A = [int(x) for x in input().split()]
    print(solve(n, A))

main()