class Solution {
public:
    bool isValid(string word) {
        int n=word.size();
        if(n<3) return false;
        transform(word.begin(),word.end(),word.begin(),::toupper);
        bool t=false,k=false;
        for(int i=0;i<n;i++){
            bool num=false;
            if(word[i]>='0'&&word[i]<='9') num=true;
            if((!(word[i]>='A'&&word[i]<='Z'))&&(!num)) return false;
            if(!num&&(word[i]=='A'||word[i]=='E'||word[i]=='I'||word[i]=='O'||word[i]=='U')) t=true;
            if(!num&&(word[i]!='A'&&word[i]!='E'&&word[i]!='I'&&word[i]!='O'&&word[i]!='U')) k=true;
        }
        if(t&&k) return true;
        else return false;
    }
};