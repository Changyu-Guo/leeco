//
// Created by gcy on 2022/2/19.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


/*
 * 用 dp[i][j] 表示字符串 s 的前 i 个字符和模式 p 的前 j 个字符是否匹配
 * 在进行状态转移时，考虑模式 p 的第 j 个字符 p_j，与之对应的是 s_i
 * 如果 p_j 是小写字符，那么 s_i 必须也为相同的小写字符，状态转移方程为:
 *   dp[i][j] = dp[i - 1][j - 1]
 * 如果 p_j 是问好，那么对 s_i 没有任何要求，状态转移方程为:
 *   dp[i][j] = dp[i - 1][j - 1]
 * 如果 p_j 是星号，那么同样对 s_i 没有任何要求，但是星号可以匹配零个或任意个小写字母
 * 因此状态转移方程分为两种情况，使用星号或者不使用星号，状态转移方程为:
 *   dp[i][j] = dp[i][j - 1] | dp[i - 1][j]
 */
bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // 空模式匹配空串
    dp[0][0] = 1;

    // 非空模式匹配空串
    // 只有模式为 * 才能匹配成功
    for (int j = 1; j <= n; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = 1;
        } else {
            break;
        }
    }

    // 空模式不能匹配非空串
    // 因此不需要进行初始化

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            // 如果当前模式是 *
            if (p[j - 1] == '*') {
                // dp[i][j - 1]: 不用 *
                // dp[i - 1][j]: 用 *
                dp[i][j] = dp[i][j - 1] | dp[i - 1][j];

            // 当前模式是 '?' 或者当前模式和当前字符相同
            } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            // 如果当前模式是 ?
        }
    }
    return dp[m][n];
}

int main() {
    cout << isMatch("cb", "?a");
    return 0;
}
