// #include<bits/stdc++.h>
// using namespace std;
// class CWH{  //abstract datatype:An abstract class is a class that is specifically defined to lay a 
// //foundation for other classes that exhibits a common behavior 
// //or similar characteristics

//     protected:
//         string title;
//         float rating;
//     public:
//         CWH(string s, float r){
//             title =  s;
//             rating = r;
//         }
//         virtual void display()=0; //DO nothing function--> pure virtual function
//         //it makes it compulsory for us to define this function in its derived classes.
// };

// class CWHVideo: public CWH{
//     float videoLength;
//     public:
//         CWHVideo(string s, float r, float vl): CWH(s, r){
//             videoLength = vl;
//         }
//         void display(){
//             cout<<"This is an amazing video with title "<<title<<endl;
//             cout<<"Ratings: "<<rating<<" out of 5 stars"<<endl;
//             cout<<"Length of this video is: "<<videoLength<<" minutes"<<endl;
//         }
// };    
// class CWHText: public CWH
// {
//     int words;
//     public:
//         CWHText(string s, float r, int wc): CWH(s, r){
//             words = wc;
//         }
//      void display(){
//       cout<<"This is an amazing text tutorial with title "<<title<<endl;
//       cout<<"Ratings of this text tutorial: "<<rating<<" out of 5 stars"<<endl;
//       cout<<"No of words in this text tutorial is: "<<words<<" words"<<endl;
//          }
// };
// int main(){
//     string title;
//     float rating, vlen;
//     int words;

//     // for Code With Harry Video
//     title = "Django tutorial";
//     vlen = 4.56;
//     rating = 4.89;
//     CWHVideo djVideo(title, rating, vlen);

//     // for Code With Harry Text
//     title = "Django tutorial Text";
//     words = 433;
//     rating = 4.19;
//     CWHText djText(title, rating, words);

//     CWH* tuts[2];
//     tuts[0] = &djVideo;
//     tuts[1] = &djText;

//     tuts[0]->display();
//     tuts[1]->display();

//     return 0;
// }


#include <iostream>
using namespace std;
class sample
{
    public:
        sample(){
            cout<<"hello";
        }
        virtual void example() = 0;
        virtual void show()=0;
};
class Ex1 : public sample{
    public:
        void example()
        {
            cout << "ubuntu";
        }
        void show(){
            cout<<"Ex1"<<endl;
        } 
};
class Ex2 : public Ex1{
    public:
        // void example()
        // {
        //     cout << "Balkaran";
        // }
        void show(){
            cout<<"Hey";
        }
};
int main()
{
    sample *ptr[2];
    Ex1 e1;
    Ex2 e2;
    ptr[0] = &e1;
    ptr[1] = &e2;
    ptr[0]->example();
    ptr[1]->show();
   
}
