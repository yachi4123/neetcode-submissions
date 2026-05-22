class Solution {
public:
    int trap(vector<int>& ht) {
        int n = ht.size();
        int next = -1;
        int prev = ht[0];
        int ind = -1;
        int ans = 0;
        for(int i=1;i<n-1;i++){
            if(prev>ht[i]&&next>ht[i]&&ind>i){
                ans+=(min(prev,next)-ht[i]);
            }
            else if(prev>ht[i]){
                next = -1;
                int j = i+1;
                while(j<n){
                    if(ht[j]>=ht[i]&&ht[j]>=next){
                        next = ht[j];
                        ind = j;
                    }
                    j++;
                }
                if(next>ht[i]){
                    ans+=(min(prev,next)-ht[i]);
                }
            }
            else{
                prev = ht[i];
            }
        }
        return ans;
    }
};
