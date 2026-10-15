
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> ans;

        vector<string> mp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        string temp = "";

        solve(0, digits, temp, ans, mp);

        return ans;
    }

    void solve(int index, string &digits, string &temp,
               vector<string> &ans, vector<string> &mp) {

        if (index == digits.size()) {
            ans.push_back(temp);
            return;
        }

        int digit = digits[index] - '0';
        string letters = mp[digit];

        for (char ch : letters) {
            temp.push_back(ch);

            solve(index + 1, digits, temp, ans, mp);

            temp.pop_back();
        }
    }
};
