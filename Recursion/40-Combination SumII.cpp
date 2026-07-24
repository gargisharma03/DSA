/*
LeetCode 40 – Combination Sum II

Approach:

The first step is to sort the input array so that duplicate values become adjacent. This makes it easy to detect and skip duplicate branches.

Next, we use DFS and Backtracking to build all possible combinations. Each recursive call represents a node in the decision tree where we decide which candidate to include next. Since every element can be used only once, after selecting an element at index i, the recursive call starts from i + 1, ensuring that the same index is never reused.

To avoid generating duplicate combinations, we skip duplicate values only at the same recursion level. If the current value is the same as the previous value and we are still exploring the same recursion level, we skip it because starting another branch with the same value would generate identical combinations.
However, duplicate values are allowed across different recursion levels, which is why combinations such as [1,1,6] are valid when the input contains two 1s.

Thus, the algorithm:

1. Sorts the array.
2. Uses DFS and Backtracking to explore all valid combinations.
3. Starts the next recursive call from i + 1 so that each index is used at most once.
4. Skips duplicate values only among sibling nodes (same recursion level) to ensure that every combination in the result is unique.
*/
#include <climits>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(int index, int remaining, vector<int>& candidates) {

        if (remaining == 0) {
            res.push_back(path);
            return;
        }

        if (remaining < 0)
            return;

        for (int i = index; i < candidates.size(); i++) {
            if(i>index && candidates[i]==candidates[i-1]){
                continue;
            }

            path.push_back(candidates[i]);

            dfs(i+1, remaining - candidates[i], candidates);

            path.pop_back();
        }
    }
public:

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(0, target, candidates);
        return res;
    }
};