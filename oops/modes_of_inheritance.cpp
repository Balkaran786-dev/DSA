#include<iostream>
using namespace std;  
class Parent{        //access specifiers,if it not mentioned,by  default it remains private.
public:
   int x;//accessible anywhere from the code.

protected:
   int y;//accessible only in parent class & derived class.

private:
   int z;//only accessible in own class
};

class child1: public Parent{   //modes of inheritance.
   //x will be public
   //y will be protected
   //z will be inaccessible
}
class child1: protected Parent{
   //x will be protected
   //y will be protected
   //z will be inaccessible
}
class child1: private Parent{
   //x will be private
   //y will be private
   //z will be inaccessible
}
int main(){
    Parent P1;
    P1.x;  
    return 0;
}

// #include<iostream>
// using namespace std;
// class parent{
// public:
//     int x;
// protected:
//     int y;
// private:
//     int z;
// };

// class child1: public parent{
//    /*x - public
//      y - protected
//      z - inaccessible*/
// };
// class child2: private parent{
//    /*x - private
//      y - private
//      z - inaccessible*/
// };
// class child1: protected parent{
//    /*x - protected
//      y - protected
//      z - inaccessible*/
// };
// int main(){
//    parent p1;
//    p1.x=7;
// }

#include<iostream>
using namespace std;
class parent{
   protected:
   int a;
};
class child:protected parent{
   protected:
    int b;
    void sum(){
      return b+a;
    }
};
class grandchild:protected child{
    protected:
    int c;
    void sum(){
      return c+b+a;
    }
};
int main(){
   return 0;
}