class Solution {
public:
    int maxArea(vector<int>& ht) {
        int n = ht.size();
        int i = 0;
        int j = n-1;
        int ans = 0;
        while(i<j){
            int a = ht[i];
            int b = ht[j];
            if(a>b){
                ans = max(ans,b*(j-i));
                j--;
            }
            else if(a<b){
                ans = max(ans,a*(j-i));
                i++;
            }
            else{
                ans = max(ans,a*(j-i));
                i++;
            }
        }
        return ans;
    }
};
