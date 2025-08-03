#include<iostream>
using namespace std;
int main (){
    char character;
    cout<<"Enter any alphabet:"<<endl;
    cin>>character;

    switch (character) 
    {
    case'a':
        cout<<"vowel";
        break;
    case'e':
        cout<<"vowel";
        break;
    case'i':
        cout<<"vowel";
        break;
    case'o':
        cout<<"vowel";
        break;
    case'u':
        cout<<"vowel";
        break;
    default:
        cout<<"consonant";   
    }

    int num;
    cout<<"enter a number from 1 to 7  :";
    cin>>num;

    switch (num)
    {
    case 1:
        cout<<"Monday"<<endl;
        break;
    case 2:
        cout<<"tuesday"<<endl;
        break;
    case 3:
        cout<<"wednesday"<<endl;
        break;
    case 4:
        cout<<"thursday"<<endl;
        break;
    case5:
        cout<<"friday"<<endl;
        break;
    case 6:
        cout<<"saturday"<<endl;
        break;
    default:
        cout<<"sunday"<<endl;
    }
           
    char ch;
    cout<<"enter a character :";
    cin>>ch;

    if (ch=='a') {
        cout<<"vowel"<<endl; 
    } else if (ch=='e'){
        cout<<"vowel"<<endl;
    } else if (ch=='i'){
        cout<<"vowel"<<endl;
    } else if (ch=='o'){
        cout<<"vowel"<<endl;
    } else if (ch=='u'){
        cout<<"vowel"<<endl;
    } else {
        cout<<"consonant"<<endl;
    }
                 //OR
    char ch;
    cout<<"enter a character:";
    cin>>ch;
           
    if (ch=='a'|| ch=='e' || ch=='i' || ch=='o' || ch=='u')
    {
        cout<<"vowel"<<endl;
    }  else 
    {
        cout<<"consonant"<<endl;
    }
    return 0;
}