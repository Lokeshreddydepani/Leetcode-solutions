class Solution {
public:
    int largestCombination(vector<int>& candidates) {
      
        int maxsize=0;
        for(int i=31;i>=0;i--){
            int size=0;
            for(int it: candidates){
                if(((it>>i)&1)){
                    size++;
                    maxsize=max(maxsize,size);
                }
            }
        }
        return maxsize;
        
    }
};