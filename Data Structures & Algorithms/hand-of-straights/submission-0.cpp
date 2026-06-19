class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        map<int,int>mp;
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
        }
        while(mp.size()!=0){
            int num = mp.begin()->first;
            for(int i=num;i<num+k;i++){
                if(mp.find(i)==mp.end()){
                    return false;
                }
                else{
                    mp[i]--;
                    if(mp[i]==0)mp.erase(i);
                }
            }
        }
        return true;
    }
};
