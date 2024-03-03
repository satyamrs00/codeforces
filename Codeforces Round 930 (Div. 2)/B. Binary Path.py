t = int(input())

for _ in range(t):
    n = int(input())
    l = []
    for _ in range(2):
        s = str(raw_input())
        l.append(s)
    
    dp = []
    dp.append([l[0][0], 1])
    for i in range(2):
        for j in range(n):
            if i == 0 and j == 0:
                pass
            else:
                if i-1 >= 0 and j-1 >= 0:
                    if dp[j][0] > dp[j-1][0]:
                        dp[j] = [dp[j-1][0] + l[i][j], dp[j-1][1]]
                    elif dp[j][0] < dp[j-1][0]:
                        dp[j] = [dp[j][0] + l[i][j], dp[j][1]]
                    else:
                        dp[j] = [dp[j][0] + l[i][j], dp[j][1] + dp[j-1][1]]
                elif i-1 >= 0:
                    dp[j] = [dp[j][0] + l[i][j], dp[j][1]]
                elif j-1 >= 0:
                    dp.append([dp[j-1][0] + l[i][j], dp[j-1][1]])

    print(dp[n-1][0])
    print(dp[n-1][1])

