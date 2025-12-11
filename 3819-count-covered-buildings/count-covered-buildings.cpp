class Solution {
public:
    typedef long long ll;
    int countCoveredBuildings(int k, vector<vector<int>>& b) {
        map<int,set<int>> r;
        map<int,set<int>> c;
        int n=b.size();
        for(int i=0;i<n;i++){
            c[b[i][0]].insert(b[i][1]);
            r[b[i][1]].insert(b[i][0]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int ro=b[i][0];
            int co=b[i][1];
            auto it1=r[co].lower_bound(ro+1);
            auto it2=r[co].lower_bound(ro);
            auto it3=c[ro].lower_bound(co+1);
            auto it4=c[ro].lower_bound(co);
            if(it1!=r[co].end()&&it2!=r[co].begin()&&it3!=c[ro].end()&&it4!=c[ro].begin())ans++;
        }
        return ans;
    }
};