#include <bits/stdc++.h> 
using namespace std; 
#define NO_OF_CHARS 256 
void badCharHeuristic(const string& str, int size, vector<int>& badchar) { 
    for (int i = 0; i < NO_OF_CHARS; i++) 
        badchar[i] = -1; 
    for (int i = 0; i < size; i++) 
        badchar[(int)str[i]] = i; 
} 
void search(string text, string pattern) { 
    int m = pattern.size(); 
    int n = text.size(); 
    vector<int> badchar(NO_OF_CHARS); 
    badCharHeuristic(pattern, m, badchar); 
    int shift = 0; 
    while (shift <= (n - m)) { 
        int j = m - 1; 
        while (j >= 0 && pattern[j] == text[shift + j]) 
            j--; 
        if (j < 0) { 
            cout << "Pattern occurs at shift = " << shift << endl; 
            shift += (shift + m < n) ? m - badchar[text[shift + m]] : 1; 
        } else { 
            shift += max(1, j - badchar[text[shift + j]]); 
        } 
    } 
} 
int main() { 
    string text = "ABAAABCD"; 
    string pattern = "ABC"; 
    search(text, pattern); 
    return 0; 
} 