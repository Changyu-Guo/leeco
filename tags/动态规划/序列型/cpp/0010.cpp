//
// Created by gcy on 2022/2/19.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 * dp[i][j] 表示 s 的前 i 个字符与 p 中的前 j 个字符是否能够匹配
 * 在进行状态转移时，我们考虑 p 的第 j 个字符的匹配情况
 * 1. 如果 p 的第 j 个字符是一个小写字母，那么必须在 s 中匹配一个相同的小写字母，则状态转移方程为:
 *   dp[j][i] = dp[i - 1][j - 1]
 * 2. 如果 p 的第 j 个字符是 *，那么表示我们可以对 p 的 j - 1 个字符匹配任意次数，可以分为使用和不使用模式两种情况:
 *   dp[i][j] = dp[i][j - 2] || dp[i - 1][j]
 * 3. 在任意情况下，只要 p[j] 是 .，那么 p[j] 一定能匹配 s 中的字符
 */
bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // base case
    // 1. 空模式匹配空串
    dp[0][0] = 1;
    // 2. 空模式不能匹配非空串
    // 3. 非空模式可能匹配空串
    for (int j = 1; j <= n; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                    dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i][j - 2];
                }
            }
        }
    }
    return dp[m][n];
}

int main() {
    cout << isMatch("aab", "c*a*b");
    return 0;
}