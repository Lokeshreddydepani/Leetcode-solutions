class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n=statements.size();
        int ans=0;
        for(int subset=0;subset<(1<<n);subset++){//enumerate through every subset mask
            bool isValid=true;
        
            for(int i=0;i<n;i++){//go through each person

                if((subset>>i)&1){ //assume to be ith person to be good
                    for(int j=0;j<n;j++){ //now go through the what statements ith person had done
                        if( statements[i][j]==1){ //if the what ith person is said about jth person isGoog
                            if(((subset>>j)&1)==0){
                                 isValid=false;     //it proves that jth person is good
                        } 
                    }
                        if(statements[i][j]==0){
                             if(((subset>>j)&1)==1){
                                 isValid=false;     //it proves that jth person is good
                        }
                        }
                         if( statements[i][j]==2)continue;
                    }
                }
            }
           if(isValid) ans=max(ans,__builtin_popcount(subset));

        }
        return ans;
    }
};