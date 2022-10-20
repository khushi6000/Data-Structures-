class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return 0;
        
        //Longest Increasing Subsequence vector
        vector<int> lis;
        lis.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i] > lis.back()) {
                lis.push_back(nums[i]);
            }
            else{
                int index = lower_bound(lis.begin(),lis.end(),nums[i]) - lis.begin();
                lis[index] = nums[i];
            }
        }
        return lis.size() > 2;
    }
};
