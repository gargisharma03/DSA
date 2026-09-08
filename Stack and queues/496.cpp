/*

Problem:
Next Greater Element 1:
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.



Approach:
1.First create an unoredered map structure to store the next greater elements of all the elements in nums2.Also create a result vector and a stack.
2.Loop through nums2 from right to left as we need to find next greater element to right.
3.If the stack is not empty and the value of the top element of stack is less than or equal to current nums2 element we pop the top element.
4.If stack is empty this means there is no greater element available on the right that can be the next greater element.Otherwise store the top value in the map for current value.
5.Add the current element in the stack.
6.then match the elements of nums1 in the map (as nums1 is subset all its values in map already) and add their respective next greater element to the result vector

*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;

        stack<int> st;

        unordered_map<int,int> mp;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }

            if(st.empty()){
                mp[nums2[i]]=-1;
            }

            else {
                mp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);

        }
        for (int x : nums1) {
            res.push_back(mp[x]);
        }

        return res;
    }
};