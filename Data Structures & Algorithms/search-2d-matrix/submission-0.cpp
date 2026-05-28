class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        int row = -1;
        int s = 0;
        int e = n-1;
        while(s<=e){
            int mid = (s+e)/2;
            if(mat[mid][0]<=target && mat[mid][m-1]>=target){
                row = mid;
                break;
            }
            else if(mat[mid][m-1]<target){
                s=mid+1;
            }
            else{
                e = mid-1;
            }
        }
        if(row==-1)return false;
        int s2 = 0;
        int e2 = m-1;
        while(s2<=e2){
            int mid = (s2+e2)/2;
            if(mat[row][mid]<target){
                s2 = mid+1;
            }
            else if(mat[row][mid]>target){
                e2 = mid-1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
