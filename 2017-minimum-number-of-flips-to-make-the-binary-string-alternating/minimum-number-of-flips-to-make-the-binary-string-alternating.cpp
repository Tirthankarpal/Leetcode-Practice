class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        s+=s;
        int fp1=0;
        int res=0;
        int c1=0,c2=0;
        for(int i=0;i<n;i++){ //1010
            if(i%2==0){
                if(s[i]!='1')fp1++;
            }
            else{
                if(s[i]!='0')fp1++;
            }
        }
        c1=fp1;
        int j=n;
        while(j<s.size()){
            if((j-n)%2==1){
                if(s[j-n]=='1')fp1--;
            }
            else{
                if(s[j-n]=='0')fp1--;
            }
            if(j%2==1){
                if(s[j-n]=='1')fp1++;
            }
            else{
                if(s[j-n]=='0')fp1++;
            }
            c1=max(0,min(c1,fp1));
            j++;
        }
        fp1=0;
        j=n;
        for(int i=0;i<n;i++){ //0101
            if(i%2==1){
                if(s[i]!='1')fp1++;
            }
            else{
                if(s[i]!='0')fp1++;
            }
        }
        c2=fp1;
        while(j<s.size()){
            if((j-n)%2==0){
                if(s[j-n]=='1')fp1--;
            }
            else{
                if(s[j-n]=='0')fp1--;
            }
            if(j%2==0){
                if(s[j-n]=='1')fp1++;
            }
            else{
                if(s[j-n]=='0')fp1++;
            }
            c2=max(0,min(c2,fp1));
            j++;
        }
        return min(c1,c2);
    }
};