class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int,string>> notations(13);
        notations[0]=make_pair(1000,"M");
        notations[1]=make_pair(900,"CM");
        notations[2]=make_pair(500,"D");
        notations[3]=make_pair(400,"CD");
        notations[4]=make_pair(100,"C");
        notations[5]=make_pair(90,"XC");
        notations[6]=make_pair(50,"L");
        notations[7]=make_pair(40,"XL");
        notations[8]=make_pair(10,"X");
        notations[9]=make_pair(9,"IX");
        notations[10]=make_pair(5,"V");
        notations[11]=make_pair(4,"IV");
        notations[12]=make_pair(1,"I");
        
        string ans="";
        int i=0;
        while(num>0){
             for(int j=i;j<=12;j++){
                if(num-notations[j].first>=0){
                    ans+=notations[j].second;
                    num-=notations[j].first;
                    i=j;
                    break;
                }
             }
        }
        return ans;
    }
};