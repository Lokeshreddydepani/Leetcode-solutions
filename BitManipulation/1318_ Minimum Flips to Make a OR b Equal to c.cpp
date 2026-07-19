class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips=0;
        for(int i=31;i>=0;i--){
            int Abit=((a>>i)&1),Bbit=((b>>i)&1),Cbit=((c>>i)&1);
            if(Cbit==0){
                flips+=Abit+ Bbit;
            }else{
                //c=1
               // only one case failing a=0,b=0,c=1
               if(Abit==0 && Bbit==0)flips++;
            }
        }
        return flips;
    }
};