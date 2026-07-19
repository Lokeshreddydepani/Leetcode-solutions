class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         int n=nums.size();
        set<vector<int>>st;
        for(int mask=0;mask<(1<<n);mask++){
            vector<int>subset;
            for(int i=0;i<nums.size();i++){
                if(((mask>>i)&1))subset.push_back(nums[i]);
            }
            if(!st.count(subset))st.insert(subset);
        }     
    vector<vector<int>>ans;
        for(auto & it:st){
            ans.push_back(it);
        }
       return ans;
    }
};