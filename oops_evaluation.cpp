// #include <bits/stdc++.h>
// #include <fstream>

// using namespace std;

// int main(){

//     string fileName;
//     cout<<"enter the file name in which you wnat to add the the text:- \n";
//     cin>>fileName;

//     ofstream Out(fileName);
    
//     cout << "Enter your text :" << endl;

//     int lineCount = 0, WordCount = 0, CharCount = 0;
//     bool flag=true;
//     while (flag) {
//         string line;
//         cout<<"Enter the line you want to insert:-\n";
//         cin.ignore();
//         getline(cin,line);

//         Out<<line<<endl;
//         lineCount++;
//         CharCount += line.size();
        
        
//         for(int i=0;i<line.size();i++){
//             if(line[i]==' ') WordCount++;
//         }
        
//         WordCount++;
//         string ans;
//         cout<<"Do you want to insert more lines? \n";
//         cin>>ans;
//         if(ans=="No") flag=false;
//         else flag=true;
//     }

//     Out.close();
//     cout << "Number of lines: " << lineCount << endl;
//     cout << "Number of words: " << WordCount << endl;
//     cout << "Number of characters: " << CharCount << endl;

//     return 0;
// }


#include <iostream> 
using namespace std;
template <typename T>
class Calculator{
public:
    
    T Add(T a, T b) {
        return a + b;
    }

    T Subtract(T a, T b) {
        return a - b;
    }

    T Divide(T a, T b) {
        if(b==0){
            cout<<"Invalid\n";
            return INT16_MIN;
        }
        return a / b;
    }

    T Multiply(T a, T b) {
        return a * b;
    }

    T modulo(T a,T b){
        return a%b;
    }

    void display_operations(){
        cout<<"1. Add\n";
        cout<<"2. Subtract\n";
        cout<<"3. Multiply\n";
        cout<<"4. Divide\n";
        cout<<"5. Modulo\n";
        cout<<"6. Exit if you don't want to go ahead\n";
    }
};

int main(){

    Calculator<int> cal; 
    int operation;
    double x, y;

    while(true){
        cal.display_operations();
        cout<<"Enter your choice: ";
        cin>>operation;
        
        if (operation== 6) {
            cout << "Exiting the calulator. Goodbye!\n";
            break;
        }

        cout<<"Enter numbers: ";
        cin>>x>>y;

            switch(operation){
                case 1:
                    cout<<"Result: "<<cal.Add(x, y)<<"\n";
                    break;
                case 2:
                    cout<<"Result: "<<cal.Subtract(x, y)<<"\n";
                    break;
                case 3:
                    cout<<"Result: "<<cal.Multiply(x, y)<<"\n";
                    break;
                case 4:
                    cout<<"Result: "<<cal.Divide(x, y)<<"\n";
                    break;
                case 5:
                    cout<<"Result: "<<cal.modulo(x, y)<<"\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        
    }

    return 0;
}
