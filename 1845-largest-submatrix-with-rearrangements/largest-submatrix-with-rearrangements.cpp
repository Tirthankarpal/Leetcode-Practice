class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& m) {
        for(int i=0;i<m[0].size();i++){
            for(int j=m.size()-2;j>=0;j--){
                if(m[j][i]>0)m[j][i]+=m[j+1][i];
            }
        }
        for(int i=0;i<m.size();i++){
            sort(m[i].begin(),m[i].end());
        }
        int ans=0;
        for(int i=0;i<m.size();i++){
            int len=1;
            for(int j=m[0].size()-1;j>=0;j--){
                ans=max(ans,m[i][j]*len);
                len++;
            }
        }
        return ans;
    }
};