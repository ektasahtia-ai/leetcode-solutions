class Solution(object):
    def isMatch(self, s, p):
        m, n = len(s), len(p)

        # dp[i][j] means first i chars of s
        # match first j chars of p
        dp = [[False] * (n + 1) for _ in range(m + 1)]

        dp[0][0] = True

        # Handle patterns like *, **, ***
        for j in range(1, n + 1):
            if p[j - 1] == '*':
                dp[0][j] = dp[0][j - 1]

        for i in range(1, m + 1):
            for j in range(1, n + 1):

                # Match single character
                if p[j - 1] == s[i - 1] or p[j - 1] == '?':
                    dp[i][j] = dp[i - 1][j - 1]

                # '*' can match empty or multiple chars
                elif p[j - 1] == '*':
                    dp[i][j] = dp[i][j - 1] or dp[i - 1][j]

        return dp[m][n]