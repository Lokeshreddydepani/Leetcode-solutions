class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int preSum=0,ans=0;
        for(int i=0;i<n;i++){
            preSum+=nums[i];
            int remain=preSum-goal;
            if(mpp.find(remain)!=mpp.end()){
                ans+=mpp[remain];
            }
           // map always stores prefix sums and their frequencies.
            mpp[preSum]++;
        }
        return ans;
    }
};