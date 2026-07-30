class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int presum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            presum+=nums[i];
            int remain=presum%k;
              remain=(remain+k)%k;//just to convert negative remainder into positive reainder
            if(mpp.count(remain))ans+=mpp[remain];
            mpp[remain]++;
        }
        return ans;
        
    }
};