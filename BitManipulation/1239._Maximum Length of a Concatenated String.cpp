class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        //remove duplicate /invalid strings 
        vector<pair<int,int>>valid;
        for(string it:arr){
            int mask=0,validLen=0;bool ok=true;
            for(int i=0;i<it.size();i++){
                int ind=it[i]-'a';
                if((mask>>ind)&1){   //rejects nvalid strings like aba bcs 2 as present
                    ok=false; 
                }
                mask|=(1<<ind);
                validLen++;
            }
           if(ok) valid.push_back({mask,validLen});

        }
        int m=valid.size(),maxLen=0;
        for(int subset=0;subset<(1<<m);subset++){
            int currsubset = 0;
            int currLen = 0;
            bool ok = true;
            //m is size of each subset
            for(int i=0;i<m;i++){//go through each subset mask
                if((subset>>i)&1){
                    if((valid[i].first & currsubset)==0){//go through the substiring mask which u created in first
                        //there is no commom character b/w them
                        currsubset|=valid[i].first;
                        currLen+=valid[i].second;
                    }else{
                        ok=false;
                        break;
                    }
                }
            }
            maxLen=max(maxLen,currLen);
        }
       return maxLen;
    }
};