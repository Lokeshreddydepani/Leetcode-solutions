class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        long long totalRem= (accumulate(nums.begin(),nums.end(),0LL))%p;
        if(totalRem==0)return 0;
        unordered_map<int,int>mpp;//{curremainder,index}
        mpp[0]=-1;
        long long presum=0;
        int minLen=n;
        for(int i=0;i<n;i++){
            presum+=nums[i];
           int currRem=(presum)%p;
           //totalRem=subarrRemainder  totalRem=(currprefix-previousPrefix)%p, 
           //totalRem=currRem-previosRem, to find, previousRem=(currRem-totalRem)
           int target=(currRem-totalRem+p)%p;
           if(mpp.count(target)){
            minLen=min(minLen,i-mpp[target]);
           }
            mpp[currRem]=i;
           
        }
        return (minLen==n)?-1:minLen;
        
    }
};