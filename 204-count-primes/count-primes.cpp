class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0; 
        vector<bool> prime(n,true);
        prime[0]=false;
        prime[1]=false;
        for(int i=2;i<n;i++){
            if(!prime[i])continue;
            for(int j=2*i;j<n;j+=i){
                prime[j]=false;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(prime[i])ans++;
        }
        return ans;
    }
};