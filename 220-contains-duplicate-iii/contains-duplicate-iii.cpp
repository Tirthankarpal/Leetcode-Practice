class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& a, int id, int vd) {
        multiset<int> st;
        int i=0;
        int j=0;
        bool f=false;
        while(j<min((int)a.size(),id+1)){
            st.insert(a[j]);
            j++;
        }
        while(i<a.size()){
            auto it1=st.find(a[i]);
            st.erase(it1);
            auto it=st.lower_bound(a[i]-vd);
            if(it!=st.end()){
                if(*it<=a[i]+vd){
                    f=true;
                    break;
                }
            }
            if(j<a.size()){
                st.insert(a[j]);
                j++;
            }
            i++;
        }
        return f;
    }
};