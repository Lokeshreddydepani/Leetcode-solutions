class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int>prefixXor(n,0);
        prefixXor[0]=arr[0];
        for(int i=1;i<n;i++){
            prefixXor[i]=prefixXor[i-1]^arr[i];
        }
        vector<int>ans(queries.size());
        //xor(l,r)=xor(r)^xor(l-1)
        int ind=0;
        for(vector<int>& it:queries){
            int left=it[0],right=it[1];
            if(left==0){
                ans[ind]=prefixXor[right];
            }else{
            ans[ind]=prefixXor[right]^prefixXor[left-1];
            }
            ind++;
        }
        return ans;
    }
};