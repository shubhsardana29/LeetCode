class Solution {
public:
    bool isPalindrome(int x) {
        long long int sum=0;
        int d=x;
        if(x<0){
            return false;
        }
        while(x!=0){
            int lastdigit=x%10;
            sum=(sum*10)+lastdigit;
            x=x/10;
        }
        if(sum==d)
       return true;
       else
       return false;

       
        

    }
};