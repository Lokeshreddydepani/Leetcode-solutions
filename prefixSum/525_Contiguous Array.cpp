class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        for(int & it:nums) if(it==0) it=-1;
        unordered_map<int,int>mpp;//{presum,ind}
        mpp[0]=-1;//0 is encountered at index -1
       // vector<int>presum;
       // presum[0]=nums[0];
       int presum=0, maxLen=0;
        for(int i=0;i<n;i++){
           presum +=nums[i];
            if(mpp.count(presum)){
              maxLen=max(maxLen,i-mpp[presum]);
            }else{
            mpp[presum]=i;
            }

        }
        return maxLen;
        


        
    }
};