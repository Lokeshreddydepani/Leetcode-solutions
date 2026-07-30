class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>preSum(n,0);
        preSum[0]=nums[0];
        for(int i=1;i<n;i++){
            preSum[i]=preSum[i-1]+nums[i];
        }
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int ans=0;
        for(int i=0;i<n;i++){
            int remain=preSum[i]-k;
            if(mpp.count(remain))ans+=mpp[remain];
            mpp[preSum[i]]++;
        }
        return ans;
        
    }
};