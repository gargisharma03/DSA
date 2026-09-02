/*
Problem:
You are given an integer array nums.

An integer x is special if all occurrences of x in nums appear in a single contiguous block.

Return the number of distinct special integers in nums.

Approach:
1.Used array to count occurrences.
2.Looped through array to check if the number is different from the previous and incremented the count for that number.
3.Then again looped through the blocks array to check if count is 1 then the number of blocks is incremented.
TC:O(N) SC:O(1)

*/

class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int count=0;
        int blocks[101]={};

        for(int i=0;i<nums.size();i++){
            if(i==0|| nums[i]!=nums[i-1]){
                blocks[nums[i]]++;
            }
        }

        for(int x=1;x<=100;x++){
            if(blocks[x]==1){
                count++;
            }
        }

        return count;
        
    }
};