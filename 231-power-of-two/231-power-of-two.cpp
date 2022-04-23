class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n<=0){
            return 0;
        }
        int count=0;
        while(n!=0){
            //check last bit
            if (n & 1){
                count++;
            }
            // after checking bit, just remove it from n
            n=n>>1;
        }
        
        // 2 ki power wale no. has only 1 set bit
        if (count==1){
            return true;
        }
        else{
            return false;
        }
        
    }
};