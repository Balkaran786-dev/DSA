using namespace std;
#include<iostream>
class Fruit{
public:     //Our properties are private by default.To make it public,we use it. 
   string name;
   string color;
   Fruit(string name,string color){
      name=name;
      color=color;
   }
   // Fruit(Fruit &s){
   //    name=s.name;
   //    color=s.color;
   // }
};

int main(){
   //  Fruit apple;  //OBJECT
   //  apple.name="Apple";
   //  apple.color="Red";
   //  cout<<apple.name<<" - "<<apple.color<<endl;

   //  Fruit *mango= new Fruit();//it is giving a pointer varible to our object mango with help of "new" keyword.
   //  mango->name="Mango";
   //  mango->color="Yellow";
   //  cout<<mango->name<<" - "<<mango->color<<endl;

   //  Fruit banana;
   //  banana.color="yellow";
   //  banana.name="Banana";
   //  cout<<banana.name<<" "<<banana.color<<endl;

   //  Fruit *watermelon= new Fruit();
   //  watermelon->color="Red";
   //  watermelon->name="Watermelon";
   //  cout<<watermelon->name<<" "<<watermelon->color<<endl;

   //  Fruit *litchi = mango;
   //  cout<<litchi->color<<" "<<litchi->name;
    Fruit f("Balkaran","litchu");
    cout<<f.color;
    cout<<f.name;
    return 0;
}