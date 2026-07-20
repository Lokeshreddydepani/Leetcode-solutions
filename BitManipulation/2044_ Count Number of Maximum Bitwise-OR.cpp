class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int maxOr=INT_MIN;
        int cnt=0;
        for(int mask=0;mask<(1<<n);mask++){
            int subOr=0;
            for(int i=0;i<n;i++){
                if(((mask>>i)&1))subOr|=nums[i];
            }
            if(subOr>maxOr){
                maxOr=subOr;
                cnt=1;//again start counting having orval from this
            }else if(subOr==maxOr)cnt++;
        }
        return cnt;
    }
};