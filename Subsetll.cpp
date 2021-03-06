/*
90. Subsets II (Medium)

Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
  
  
Solution

Intuition:

We need to use dfs+backtracking method to solve this problem. Since the title clearly states that there may be duplicate numbers in the list, we need to prune when we dfs.

Algorithm:

1. Sort the array in ascending order.
2. Define a recursive method dfs, the parameters are: current subset = "subset", current subset length = "k", return result = "res". Add the current subset to res. 
3. From k to len(nums)-1 traverse the index i. If i != k it does nums[i] == nums[i - 1], it means it nums[i] is a repeating element, so we skip it nums[i]. 
4. Will be nums[i] added to the current subset "subset". Perform a recursive search at the next level and continue to add elements to the subset. At this time, k add one. 
5. From subset deleted nums[i] backtracking.



Code in C++: 
*/


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> res;
        // sort
        sort(nums.begin(), nums.end());
        // dfs search
        vector<int> subset; 
        dfs(nums, 0, subset, res);
        return res;
    }
private:
    void dfs(vector<int>& nums, int k, vector<int>& subset, vector<vector<int>>& res) {
        // The current combination is stored in res
        res.push_back(vector<int>(subset));
        // Add an element to subset
        for (int i = k; i < nums.size(); ++i) {
            // pruning
            if (i != k && nums[i] == nums[i - 1]){
                continue;
            }
            subset.push_back(nums[i]);
            // Next level search
            dfs(nums, i + 1, subset, res);
            // backtracking
            subset.pop_back();
        }
    }
};

/*
Code in Java:
*/

class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        // sort
        Arrays.sort(nums);
        // dfs search
        Deque<Integer> subset = new ArrayDeque<>(nums.length);
        dfs(nums, 0, subset, res);
        return res;
    }
    private void dfs(int[] nums, int k, Deque<Integer> subset, List<List<Integer>> res) {
        // The current combination is stored in res
        res.add(new ArrayList<>(subset));
        // Add an element to subset
        for (int i = k; i < nums.length; ++i) {
            // pruning
            if (i != k && nums[i] == nums[i - 1]){
                continue;
            }
            subset.addLast(nums[i]);
            // Next level search
            dfs(nums, i + 1, subset, res);
            // backtracking
            subset.removeLast();
        }
    }
}

/*
Code in Python
*/

class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        # Sort
        nums.sort()
        # dfsSearch
        self.dfs(nums, 0, [], res)
        return res
        
    def dfs(self, nums, k, subset, res):
        # The current portfolio is stored in res
        res.append(subset[:])
        # Add an element to subset
        for i in range(k, len(nums)):
            # Pruning
            if (i != k and nums[i] == nums[i - 1]):
                continue
            subset.append(nums[i])
            # Next level search
            self.dfs(nums, i + 1, subset, res)
            # Backtrack
            del subset[-1]
            
/*           
Complexity Analysis

Time complexity: O(n ∗ 2n), Where n is nums the length. Generate all subsets and copy them to the output set. 
Space complexity: O(n ∗ 2n), Where n is nums the length. Storing a subset of all, a total of n elements, each element are likely to exist or not exist.

*/
