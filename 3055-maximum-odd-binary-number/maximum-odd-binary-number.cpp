class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int countOnes=0;
        int countZeros=0;
        for(char i:s){
            if(i=='1'){
                countOnes++;
            }
            else{
                countZeros++;
            }
        }
        return string(countOnes - 1, '1') + string(countZeros, '0') + '1';
    }
};