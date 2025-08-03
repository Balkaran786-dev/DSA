// #include<bits/stdc++.h>
// using namespace std;
// template <class T>
// class Harry
// {
// public:
//     T data;
//     Harry(T a)
//     {
//         data = a;
//     }
//     void display();
// };
// template <class T>  //we can write the methods of template class outside the class like this.
// void Harry<T>::display(){
//     cout<<data<<endl;
// }
// int main()
// {
//     Harry<float> h(5.7);
//     cout << h.data << endl;
//     h.display();
//     return 0;
// }


//overloading of template functions

#include <iostream>
using namespace std;
 
void func(int a){
    cout<<"I am first func() "<<a<<endl;
}
 
template<class T>
void func(T a){
    cout<<"I am templatised func() "<<a<<endl;
}
template<class T>
void func1(T a){
    cout<<"I am templatised func() "<<a<<endl;
}

int main()
{
    func(4);  //Exact match takes the highest priority
    func1(5); //if exact match does not present,then usko template mein ghuste hain.
    
    return 0;
}
