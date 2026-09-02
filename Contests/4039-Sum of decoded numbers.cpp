/*
Problem:
You are given an integer array nums.

Each nums[i] is an encoded integer representing two positive integers xi and yi. To decode nums[i], define:

widthi = nums[i] % 10.
di = floor(nums[i] / 10).
xi as the integer formed by the first widthi digits of the decimal representation of di.
yi as the integer formed by all remaining digits of the decimal representation of di.
It is guaranteed that the decimal representation of di contains more than widthi digits. Therefore, both xi and yi contain at least one digit.

The decoded value of nums[i] is xiyi.

Return the sum of the decoded values of all elements in nums, modulo 109 + 7.

The floor() function returns the integer part of the division.

Approach:
1.First we calculate the width using remainder operator and d using floor operator.
2.Then convert d to string for easy extraction of xi and yi.
3. After extracting xi yi,calculate the power using modular exponentiation and add it to the sum.

Time Complexity: O(n * log(y)) where n is the size of nums and y is the maximum value of yi.
Space Complexity:O(1)
*/

class Solution {
public:
    static const long long MOD = 1000000007;

    long long modPow(long long x, long long y) {
        long long result = 1;
        x %= MOD;

        while (y > 0) {
            if (y & 1)
                result = (result * x) % MOD;

            x = (x * x) % MOD;
            y >>= 1;
        }

        return result;
    }

    int sumDecoded(vector<long long>& nums) {
        long long sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            long long width = nums[i] % 10;
            long long d = nums[i] / 10;

            string s = to_string(d);

            long long x = stoll(s.substr(0, width));
            long long y = stoll(s.substr(width));

            sum = (sum + modPow(x, y)) % MOD;
        }

        return sum;
    }
};