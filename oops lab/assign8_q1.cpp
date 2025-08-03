#include <iostream>
using namespace std;
class Name {
    string first_Name;
    string middle_Name;
    string last_Name;
    string salutation;

public:
    Name(string salutation, string first_Name, string middle_Name, string last_Name) {
        this->salutation = salutation;
        this->first_Name = first_Name;
        this->middle_Name = middle_Name;
        this->last_Name = last_Name;
    }

    ~Name() {
        cout << "Destructor is called "<<endl;
    }

    void set_FirstName(string first_Name){
        this->first_Name = first_Name;
    }
    void set_MiddleName(string middle_Name){
        this->middle_Name = middle_Name;
    }
    void set_LastName(string last_Name){
        this->last_Name = last_Name;
    }
    void set_Salutation(string salutation){
        this->salutation = salutation;
    }

    string get_Salutation(){
        return salutation;
    }
    string get_FirstName(){
        return first_Name;
    }
    string get_MiddleName(){
        return middle_Name;
    }
    string get_LastName(){
        return last_Name;
    }

    string toString(){
        return salutation + " " + first_Name + " " + middle_Name + " " + last_Name;
    }
};

int main() {
    Name person("Mr.","Ajay","singh","Aulakh");

    cout<<"Full Name: "<<person.toString()<<endl;

    person.set_LastName("saini");
    person.set_FirstName("Balkaran");
    cout<<"After doing some changes:"<<endl;
    cout<<"Full Name: "<<person.toString()<<endl;

    return 0;
}