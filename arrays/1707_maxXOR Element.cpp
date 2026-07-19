class TrieNode {
    public:
    TrieNode* children[2];
     TrieNode (){
        children[0]=nullptr;
        children[1]=nullptr;
     }

};
class Trie {
    public:
    TrieNode* root;
    Trie (){
        root=new TrieNode();
    }
    void insert(int num){
        TrieNode *curr=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(curr->children[bit]==nullptr){
                curr->children[bit]=new TrieNode();
            }
            curr=curr->children[bit];
        }
    }

    int getMaxXor(int num){
        TrieNode *curr=root;
        int ans=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            int wanted=bit^1;
            if(curr->children[wanted]!=nullptr){
                ans|=(1<<i);
                curr=curr->children[wanted];

            }else{
                curr=curr->children[bit];
            }
        }
         return ans;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        sort(nums.begin(),nums.end());
        int originalInd=0;
        for(auto& it:queries){
            it.push_back(originalInd);
            originalInd++;
        }
        sort(queries.begin(),queries.end(),[](auto&a,auto&b){
            return a[1]<b[1];
        });
        vector<int>ans(queries.size());
        //construct trie only till the maxSize of m in all(x,m)
        int j=0;
        for(auto & it:queries){

            int x=it[0], m=it[1];
            
            while(j<nums.size() && nums[j]<=m){
                trie.insert(nums[j]);
                j++;
            }
            if(j==0)ans[it[2]]=-1;
            else ans[it[2]]=trie.getMaxXor(x);

        }
        return ans;
        
    }
};