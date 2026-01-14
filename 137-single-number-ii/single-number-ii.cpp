class Solution {
public:
    int singleNumber(vector<int>& a) {
        vector<int> cnt(34,0);
        for(int i=0;i<a.size();i++){
            long long num=a[i];
            if(num<0){
                cnt[33]++;
                num=-num;
            }
            for(int j=0;j<33;j++){
                if((num&((long long)1<<j))>0)cnt[j]++;
                cnt[j]%=3;
            }
            cnt[33]%=3;
        }
        long long val=0;
        for(int i=0;i<33;i++){
            val+=((long long)cnt[i]<<i);
        }
        if(cnt[33]>0)return -val;
        else return val;
    }
};