class Solution {
public:
    static const int n=1e6+5;
    static int fac[n];
    int binexp(int a,int b,int m){
        int result=1;
        while(b>0){
            if(b&1){
                result=(result*1LL*a)%m;
            }
            a=(a*1LL*a)%m;
            b=b>>1;
        }
        return result;
    }
    typedef long long ll;
    int countPermutations(vector<int>& c) {
        int mn=c[0]+1;
        map<int,int> mp;
        for(int i=1;i<c.size();i++){
            mn=min(mn,c[i]);
            mp[c[i]]++;
        }
        if(mn<=c[0])return 0;
        else{
            fac[0]=1;
            for(int i=1;i<n;i++){
                fac[i]=(1LL*i*fac[i-1])%(1000000007);
            }
            int ans=fac[c.size()-1];
            int denom=1;
            // for(auto it:mp){
            //     denom=(denom*1LL*fac[it.second])%(1000000007);
            // }
            // ans=(ans*1LL*binexp(denom,1000000005,1000000007))%1000000007;
            return ans;
        }
    }
};
int Solution::fac[Solution::n];