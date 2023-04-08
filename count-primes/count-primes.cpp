class Solution {
public:
    int countPrimes(int n) {
    int count=0;
    // saare no. ko initially prime no. maan kar array mai store kar liya
    vector<bool>prime(n+1,true);

    // 0 or 1 ko non prime bana diya
    prime[0]=prime[1]=false;

    for(int i=2;i<n;i++){
        if(prime[i]==true){
            count++;
        }

        // table wise non-prime mark kardo
        for (int j = 2*i; j < n; j=j+i)
        {
            prime[j]= false;
        }
    }
    return count;
}
    
};