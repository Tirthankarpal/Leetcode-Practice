class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& ii, vector<int>& ni) {
        map<int,int> mp;
        int n=ii.size();
        for(int i=0;i<n;i++){
            mp.insert({ii[i][1],ii[i][0]});
        }
        int st=ni[0];
        int e=ni[1];
        auto it=mp.lower_bound(st);
            while(it!=mp.end()&&it->second<=e){
                st=min(st,it->second);
                e=max(e,it->first);
                auto it2=it;
                it++;
                mp.erase(it2);
            }
            mp.insert({e,st});
        vector<vector<int>> ans(mp.size());
        int i=0;
        for(auto it:mp){
            ans[i]={it.second,it.first};
            i++;
        }
        return ans;
    }
};