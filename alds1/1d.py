def maxSub(r,n):
    x0=r[0]
    x1=r[1]-r[0]
    for i in range(1,n):
        x1=max(r[i]-x0,x1)
        x0=min(r[i],x0)
    return x1

# def maxSub(r,n):
#     dp=[[-3000000000 for j in range(0,n)]for i in range(0,n)]
#     for j in range(1,n):
#         for i in range(0,n-j,j):
#             dp[i][i+j]=max(dp[i][i+j-1],dp[i+1][i+j],r[i+j]-r[i])
#     return dp[0][n-1]
n=int(input())
r=[int(input()) for i in range(n)]
print(maxSub(r,n))