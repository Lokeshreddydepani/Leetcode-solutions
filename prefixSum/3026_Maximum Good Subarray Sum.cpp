class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long ans=LLONG_MIN;
        long long presum=0;
        unordered_map<long long,long long>mpp;//{nums[i] : min prefixval before this nums[i]}
        //mpp[nums[0]]=0;
        for(int i=0;i<n;i++){
            presum+=nums[i];
            long long prevprefix=presum-nums[i];
           
            long long maxSum=LLONG_MIN;
            int need1=nums[i]-k;
            if(mpp.count(need1)){
                maxSum = max(maxSum, presum - mpp[need1]);  
            }
            int need2=nums[i]+k;
            if(mpp.count(need2)){
                maxSum = max(maxSum, presum - mpp[need2]);
            }
           if (mpp.count(nums[i]))
                mpp[nums[i]] = min(mpp[nums[i]], prevprefix);
            else
                mpp[nums[i]] = prevprefix;
            ans=max(ans,maxSum);

        }
        return (ans==LLONG_MIN)?0 :ans;
    }
};