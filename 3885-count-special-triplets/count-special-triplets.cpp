class Solution {
public:
    typedef long long ll;
    ll mod=1000000007;
    int specialTriplets(vector<int>& a) {
        unordered_map<ll,ll> mpk;
        unordered_map<ll,ll> mpj;
        ll ans=0;
        for(int i=a.size()-1;i>=0;i--){
            if(a[i]%2==0){
                ans+=(mpj[a[i]/2])%mod;
                ans%=mod;
            }
            mpj[a[i]]+=mpk[2*a[i]];
            mpk[a[i]]++;
        }
        return ans;
    }
};