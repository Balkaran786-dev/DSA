//1st approach form all possible aparenthsis and 
// select out the well formed ones. -> using the algo we did in stacks
// time o(n*2^2n)  n for checking
// space min o(2n) for internal stack rest depends how u implement it


//2nd approach  o(2^2n) time     space o(2n)
// make recursion tree u will understand.
// insights:-
//1.it should be a well formed parenthesis where for every closing bracket, there should be opening one.
//2.length=2n where n will be openeing and n will be closing one.
//3.you can add an opening bracket till no.of.open<n
//4.you can add closing when opening>closing.
//5. when opening and closing == n both, save this parenthesis.
void Parenthesis_generator(int n, int open, int close, string temp, vector<string>& vec) {
        if (open == n && close == n) {
            vec.push_back(temp);
            return;
        }

        if (open < n) {
            // Add an opening parenthesis and make a recursive call
            Parenthesis_generator(n, open + 1, close, temp + "(", vec);
        }
        
        if (close < open) {
            // Add a closing parenthesis and make a recursive call
            Parenthesis_generator(n, open, close + 1, temp + ")", vec);
        }
}
vector<string> validParenthesis(int n){
    // Write your code here.
    vector<string> vec;
        string temp = "";
        int open = 0, close = 0;

        Parenthesis_generator(n, open, close, temp, vec);
        return vec;

}