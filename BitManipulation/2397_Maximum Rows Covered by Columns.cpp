class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int rowSize=matrix.size(),colSize=matrix[0].size();
        vector<int>rowMasks;
        for(int i=0;i<rowSize;i++){
            int mask=0;
            for(int j=0;j<colSize;j++){
                if(matrix[i][j]==1)mask|=(1<<j);
            }
            rowMasks.push_back(mask);

        }
        //go through the bit mask of each subseet having exactly numSeclect columns
        int ans=0;
        for (int colMask = 0; colMask < (1 << colSize); colMask++){
            if (__builtin_popcount(colMask) != numSelect)
                   continue;//skip like 111,000 like invalid

            int n=rowMasks.size(), coveredrows=0;
            for(int i=0;i<n;i++){
                
                if((colMask&rowMasks[i])==rowMasks[i]){
                    coveredrows++;
                }
            }
            ans=max(ans,coveredrows);
        }
        return ans;
    }
};