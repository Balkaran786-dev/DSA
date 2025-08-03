class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n=words.size();
        int i=0;
        while(i<n){
            int linelength=words[i].size();
            int j=i+1;
            //checking kitne words humara aa skte hain ek line mein without exceeding the maxWidth
            while(j<n && linelength+words[j].size()+(j-i)<=maxWidth){
                linelength+=words[j].size();
                j++;
            }
 
            int numWords=j-i;  // itne total words hai, kyunki j humara uss word pe hoga jisse include nhi krna
            int numSpaces=maxWidth-linelength;  //itni spaces bach gyi 
            
            string line;
            if(numWords==1 || j==n){  //means either we have one word, or we are on last line
                line=words[i];
                for(int k=i+1;k<j;k++){
                    line+=' '+words[k];
                }
                line +=string(maxWidth-line.size(),' ');
            }
            else{
                int spacesBtwWords=numSpaces/(numWords-1);
                int extraSpaces=numSpaces % (numWords-1);
                line=words[i];
                for(int k=i+1;k<j;k++){
                    line+=string(spacesBtwWords,' ');
                    if(extraSpaces>0){
                        line+=' ';   //ek se jada extra space nhi aayegi, its a fundamental thing,for exm four words are there, so Extrapsaces can be just 0-2 only, agr 3 hoti voh toh sbme brbr hi aa jati, so 0-2 hi hongi, aand ek ek left se dete jayege extra;
                        extraSpaces--;
                    }
                    line+=words[k];
                }
            }
            ans.push_back(line);
            i=j;
        }
        return ans;
    }
};