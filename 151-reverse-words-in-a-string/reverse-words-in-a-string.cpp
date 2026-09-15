class Solution {
public:
    string reverseWords(string s) {

        
        string ans = "";

        for(char c : s) {

            if(c != ' ') {
                ans += c;
            }
            else if(!ans.empty() && ans.back() != ' ') {
                ans += ' ';
            }
        }

        if(!ans.empty() && ans.back() == ' ')
            ans.pop_back();


    
        reverse(ans.begin(), ans.end());


    
        int start = 0;

        for(int i = 0; i <= ans.size(); i++) {

            if(i == ans.size() || ans[i] == ' ') {

                reverse(ans.begin() + start, ans.begin() + i);

                start = i + 1;
            }
        }

        return ans;
    }
};