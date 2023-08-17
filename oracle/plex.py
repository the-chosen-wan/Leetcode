def ans(p,target):
    n = len(p)
    dp = [[0 for x in range(target+1)] for y in range(n)]

    for i in range(n):
        dp[i][0] = p[i]

    
    dp[0][0] = (1-p[0])

    if target>0:
        dp[0][1] = p[0]

    for i in range(0,target+1):
        for j in range(1,n):
            dp[j][i] = (1-p[j])*dp[j-1][i]

            if(i>0):
                dp[j][i]+=p[j]*dp[j-1][i-1]
    
    return dp[n-1][target]


if __name__=="__main__":
    p = [0.3,0.3,0.6,0.2,0.7]
    n = 4
    print(ans(p,n))