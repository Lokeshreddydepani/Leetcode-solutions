class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        //remove the bits that keep changing 101,111, only 2nd bit is smae
        //Find the common binary prefix.
        int shift=0;
        while(left!=right){
            left>>=1;//keep changing bits
            right>>=1;
            shift++;
        }
        return left<<shift;
        
    }
};