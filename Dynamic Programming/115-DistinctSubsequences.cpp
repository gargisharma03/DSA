/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

 

Approach:
Used space optimized 1D Dynamic Programming approach.

1.Created a 1D array of size t.length()+1 and initialized to 0.
2.Set first element to 1(base case) as empty string is a subsequence of any string.
3.Used two nested loops to iterate through characters of s and t(in reverse order to take values from previous iteration).
4.If characters match,added value from prev index of t to the current index of t.
5.Otherwise,leave dp[j] untouched
6.Returned dp[n] as the total no. of distinct subsequences.
*/

using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();

        
        vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= m; i++) {
            
            for (int j = n; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[n];
    }
};