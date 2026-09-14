class Solution {
public:
    bool checkValidString(string s) {
        int minBalance=0;
        int maxBalance=0;

        for(char ch : s){
            if(ch== '('){
                minBalance++;
                maxBalance++;
            }
            else if(ch == ')'){
                minBalance--;
                maxBalance--;
            }
            else{
                minBalance--;
                maxBalance++;
            }
             minBalance= max(0, minBalance);

             if(maxBalance < 0){
                return false;
             }
        }

        return minBalance==0;

    }
    };
