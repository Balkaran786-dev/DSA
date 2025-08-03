//1.
#include<iostream>
using namespace std;
class Complex{
public:
     int real;
     int img;

     Complex(int x,int y){
        real=x;
        img=y;
     }

//while writing operator overloading function,firstly 
//write,returntype. then jo bhi operator overload karna 
//hai vo likho then argument mein hamara jo operator
//ke baad vala variable hoga vo pass hoga..    
     Complex operator+(Complex &c){
        Complex ans(0,0); //ans is a object of class complex.hence needs to be initialised due to parameterised constructor.
        ans.real = real+c.real;
        ans.img = img+c.img;
        return ans;
     }
};

int main(){
    Complex c1(1,2);
    Complex c2(2,4);
    Complex c3=c1+c2;  //just because c3 is of complex datatype,isliye jab hum return karenge ans
                       //toh vo bhi complex datatype ka hona chahiye.
    cout<<c3.real<<" i"<<c3.img<<endl;
    return 0;
}

// //2.
// #include<iostream>
// using namespace std;
// //cancatenation through operator overloading.
// class Nameandgrade{
// public:
//     string student1;
//     string student2;
     
//     Nameandgrade(string x,string y){
//         student1=x;
//         student2=y;
//     }

//     Nameandgrade operator+(Nameandgrade &g){
//         Nameandgrade result("","");
//         result.student1=student1+g.student1;
//         result.student2=student2+g.student2;
//         return result;
//     }

// };
// int main(){
//      Nameandgrade s("Balkaran ","Karandeep ");
//      Nameandgrade g("A","B");
//      Nameandgrade sandg =s+g;
//      cout<<sandg.student1<<" - "<<sandg.student2;
//     return 0;
// }

//practice of same code
// #include<iostream>
// using namespace std;
// class complex{
// public:
//     int real;
//     int img;

//     complex(int x,int y){
//         real=x;
//         img=y;
//     }
    
//     //operator overloading function
//     complex operator+ (complex &c){
//         complex ans(0,0);
//         ans.real=real+c.real;  
//         ans.img=img+c.img;
//         return ans;
//     }
// };

// int main(){
//     complex c1(1,2);
//     complex c2(2,3);
//     complex c3=c1+c2;
//     cout<<c3.real<<" i"<<c3.img<<endl;
// }


//2.
#include<iostream>
using namespace std;
class con{
public:
   string name_or_grade1;
   string name_or_grade2;

   con(string s1,string s2){
    name_or_grade1=s1;
    name_or_grade2=s2;
   }

   con operator+ (con &c){
    con result("","");
    result.name_or_grade1=name_or_grade1+c.name_or_grade1;
    result.name_or_grade2=name_or_grade2+c.name_or_grade2;
    return result;
   }
};
int main(){
    con c1("Balkaran","Aashna");
    con c2("A","B");
    con res=c1+c2;
    cout<<res.name_or_grade1<<" "<<res.name_or_grade2<<endl;

}


