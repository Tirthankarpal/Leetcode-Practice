class Solution {
public:
    int countPartitions(vector<int>& a) {
        int n=a.size();
        vector<int> pre=a;
        vector<int> suf=a;
        for(int i=1;i<n;i++){
            pre[i]+=pre[i-1];
        }
        for(int i=n-2;i>=0;i--){
            suf[i]+=suf[i+1];
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            if(abs(pre[i]-suf[i+1])%2==0)ans++;
        }
        return ans;
    }
};