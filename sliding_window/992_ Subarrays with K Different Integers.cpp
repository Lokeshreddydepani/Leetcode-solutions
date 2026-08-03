class Solution {
public:
long long atMostK(vector<int>& nums, int k,unordered_map<int,int>mpp){
    int n=nums.size();
    int left=0,right=0;
    long long ans=0;
    while(right<n){
        mpp[nums[right]]++;
        while(mpp.size()>k){
            mpp[nums[left]]--;
            if(mpp[nums[left]]==0)mpp.erase(nums[left]);
            left++;
        }
        ans+=(right-left+1);
        right++;
    }
    return ans;

}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;

        return atMostK(nums, k,mpp) - atMostK(nums, k-1,mpp);
        
    }
};