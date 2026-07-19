class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x=0;
        for(int num:nums)x^=num;
        //now separete into 2 two groups using rightmost setbit
      //int diff=x &(-x);
      unsigned int mask = static_cast<unsigned int>(x) &
                    (~static_cast<unsigned int>(x) + 1);
                    //copied from chatgpt this line
          int x1=0,x2=0;
        for(int num:nums){
          
            if(num& mask){
                x1^=num;
            }else{
                x2^=num;
            }
        }
        return {x1,x2};
        
    }
};