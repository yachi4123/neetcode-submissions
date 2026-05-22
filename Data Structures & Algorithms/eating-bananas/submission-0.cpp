#define ll long long
class Solution {
public:

    bool isGood(int k, vector<int>& piles, int h){
        ll t = 0;
        int n = piles.size();
        for(int i=0;i<n;i++){
            if(piles[i]%k==0) t+=piles[i]/k;
            else t+= (piles[i]/k)+1;
        }
        if(t<=h)return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        ll e = 1000000000;
        ll s = 1;
        int ans = 0;
        while(s<=e){
            int mid = s+(e-s)/2;
            bool check = isGood(mid,piles,h);
            if(check){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};
