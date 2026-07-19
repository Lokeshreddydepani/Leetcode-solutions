class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>count(32,0);
        for(int i=31;i>=0;i--){
            //count no of 1's in
            int cnt=0;
            for(int num:nums){
                if(((num>>i)&1))cnt++;

            }
            count[i]=cnt;
        }
        int ans=0;
       for(int i=31;i>=0;i--){
         count[i]%=3;
         if(count[i]==1){
            ans|=(1<<i);
         }
       }
       return ans;
        
    }
};
