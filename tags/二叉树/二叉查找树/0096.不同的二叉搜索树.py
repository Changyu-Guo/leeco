# -*- coding: utf - 8 -*-

def num_trees(n):
    dp = [0] * (n + 1)
    dp[0], dp[1] = 1, 1
    for i in range(2, n + 1):
        for j in range(1, n + 1):
            dp[i] += dp[j - 1] * dp[i - j]

    return dp[-1]


if __name__ == '__main__':
    res = num_trees(19)
    print(res)
