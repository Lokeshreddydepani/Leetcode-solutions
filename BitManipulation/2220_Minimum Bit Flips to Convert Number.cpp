class Solution {
public:
/* method1
while(n){
            n=n&(n-1);
            cnt++;
        }
        return cnt;*/

    int minBitFlips(int start, int goal) {
        int cnt=0;
        for(int i=31;i>=0;i--){
            int x=((goal>>i)&1),y=((start>>i)&1);
            if(x^y)cnt++;
        }
        return cnt;
    }
};