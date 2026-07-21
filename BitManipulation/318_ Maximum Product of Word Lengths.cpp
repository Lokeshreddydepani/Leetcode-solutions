class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<pair<int,int>>arr;
        for(string it:words){
            int currMask=0,currLen=0;
            for(int i=0;i<it.size();i++){
                int ind=it[i]-'a';
                currMask|=(1<<ind);
                currLen++;
            }
            arr.push_back({currMask,currLen});
        }
        int n=arr.size();
       int ans=0;
       for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((arr[i].first & arr[j].first)==0){
                ans=max(ans,arr[i].second*arr[j].second);

            }

        }
       }
       return ans;
        
    }
};