class Solution {
public:
    void solve(vector<int>& nums, int index, vector<int>& curr,
               vector<vector<int>>& ans) {
        ans.push_back(curr);

        
        for (int i = index; i < nums.size(); i++) {
            curr.push_back(nums[i]);

            solve(nums, i + 1, curr, ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        solve(nums, 0, curr, ans);

        return ans;
    }
};
