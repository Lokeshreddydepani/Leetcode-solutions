class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        //mpp[0]=1;
        int ans=0;
        int idx;
        for(int i=0;i<n;i++){
           if(nums[i]==k)idx=i;
        }
        int balance=0;
        for(int i=idx; i<n ;i++){
               if(nums[i] > k)
                    balance++;
                else if(nums[i] < k)
                    balance--;
               mpp[balance]++;
        }
        //traverse left side
        balance=0;
           for(int i=idx;i>=0;i--){
           
           if(nums[i]>k)balance++;
           else if(nums[i]<k)balance--;
           //case1:L+R =0,L=-R
           if(mpp.count(-balance))ans+=mpp[-balance];
           //case2:L+R=1,L=1-R
           if(mpp.count(1-balance))ans+=mpp[1-balance];
            

           }
           return ans;
        

        
    }
};