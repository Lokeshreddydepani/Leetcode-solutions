class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n=hours.size();
        for(int& it:hours) it= (it>8)? 1: -1;
        unordered_map<int,int>firstInd;//{presum,firsttime appearing that presum index}
        firstInd[0]=-1;
        int presum=0;
        int maxLen=0;
        for(int i=0;i<n;i++){
            presum+=hours[i];
            if(presum>0)maxLen=max(maxLen,i+1);//till here whole subArray is valid
            //u need to get longest prefix positive arr,ex: presum=5,u need to for 5-1=4 bcs it only
            //gives lonest length as compared to the 3,2,1
            int longLength=presum-1;
            if(firstInd.count(longLength))maxLen=max(maxLen,i-firstInd[longLength]);
            if(!firstInd.count(presum))firstInd[presum]=i; //store this prefixSum for time ifNotFound

        }
        return maxLen;
        
        
    }
};