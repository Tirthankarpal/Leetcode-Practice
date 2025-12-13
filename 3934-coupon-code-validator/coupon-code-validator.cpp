class Solution {
public:
    vector<string> validateCoupons(vector<string>& c, vector<string>& b, vector<bool>& is) {
        vector<string> ans;
        multiset<pair<string,string>> s;
        for(int i=0;i<c.size();i++){
            bool f1=c[i].size()>0;
            bool f2=((b[i]=="electronics")||(b[i]=="grocery")||(b[i]=="pharmacy")||(b[i]=="restaurant"));
            bool f3=is[i];
            for(int j=0;j<c[i].size();j++){
                if(!(('a'<=c[i][j]&&'z'>=c[i][j])||('A'<=c[i][j]&&'Z'>=c[i][j])||('0'<=c[i][j]&&'9'>=c[i][j])||(c[i][j]=='_')))f1=false;
            }
            if(f1&&f2&&f3)s.insert({b[i],c[i]});
        }
        for(auto it=s.begin();it!=s.end();it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};