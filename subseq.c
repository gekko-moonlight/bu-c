#include "subseq.h"

int subseq(const char s1[], const char s2[])
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int **dp = malloc(sizeof(int*) * (len1+1));
    for (int i = 0; i < (len1+1); ++i) {
        dp[i] = malloc(sizeof(int) * (len2+1));
        bzero(dp[i], sizeof(int) * (len2+1));
    }
    int max_len = 0;

    for (int i = 0; i < len1; ++i) {
        for (int j = 0; j < len2; ++j) {
            dp[i+1][j+1] = (s1[i] == s2[j]) ? (dp[i][j] + 1) : 0;
            max_len = (max_len > dp[i+1][j+1]) ? max_len : dp[i+1][j+1];
        }
    }

    for (int i = 0; i < len1; ++i)
        free(dp[i]);
    free(dp);

    return max_len;
}
