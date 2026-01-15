class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> mp;
        for(int i=0;i<max((int)s.size()-9,0);i++){
            mp[s.substr(i,10)]++;
        }
        vector<string> ans;
        for(auto it:mp){
            if(it.second>1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};