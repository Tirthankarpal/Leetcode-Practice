class Solution {
public:
    typedef long long ll;
    vector<ll> siz;
    vector<ll> par;
    void uni(ll a,ll b){
        a=find(a);
        b=find(b);
        if(a==b)return;
        if(siz[a]>siz[b]){
            par[b]=a;
            siz[a]+=siz[b];
        }
        else{
            par[a]=b;
            siz[b]+=siz[a];
        }
    }
    ll find(ll a){
        if(par[a]==a)return a;
        return par[a]=find(par[a]);
    }
    int largestComponentSize(vector<int>& nums) {
        int n=nums.size();
        siz.resize(n,1);
        par.resize(n);
        for(int i=0;i<n;i++) par[i]=i;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            int x=nums[i];
            for(int j=2;j*j<=x;j++){
                if(x%j==0){
                    if(mp.count(j))uni(i,mp[j]);
                    else mp[j]=i;
                    while(x%j==0) x/=j;
                }
            }
            if(x>1){
                if(mp.count(x)) uni(i,mp[x]);
                else mp[x]=i;
            }
        }
        ll res=0;
        for(int i=0;i<n;i++){
            res=max(res,siz[find(i)]);
        }
        return res;
    }
};