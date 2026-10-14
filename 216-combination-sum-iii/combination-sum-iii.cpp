
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void solve(int start, int k, int n) {
        if (curr.size() == k) {
            if (n == 0) {
                ans.push_back(curr);
            }
            return;
        }
        for (int i = start; i <= 9; i++) {
            if (i > n) break;

            curr.push_back(i);

            solve(i + 1, k, n - i);

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        solve(1, k, n);
        return ans;
    }
};

