class Solution {
public:
    int trap(vector<int>& ht) {
        int n = ht.size();

        int left = 0;
        int right = n - 1;

        int leftMax = 0;
        int rightMax = 0;

        int ans = 0;

        while (left < right) {

            if (ht[left] < ht[right]) {

                if (ht[left] >= leftMax)
                    leftMax = ht[left];
                else
                    ans += leftMax - ht[left];

                left++;
            }
            else {

                if (ht[right] >= rightMax)
                    rightMax = ht[right];
                else
                    ans += rightMax - ht[right];

                right--;
            }
        }

        return ans;
    }
};