class Solution {
public:
    bool isPalindrome(string s) {
        int j = s.length()-1;
        int i = 0;
        while(i<=j){
            if(((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9'))&&
            ((s[j]>='a'&&s[j]<='z')||(s[j]>='A'&&s[j]<='Z')||(s[j]>='0'&&s[j]<='9'))){
                if(tolower(s[i])!=tolower(s[j])){
                    return false;
                }
                else{
                    i++;
                    j--;
                }
            }
            else if(!((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9'))){
                i++;
            }
            else{
                j--;
            }
        }
        return true;
    }
};
