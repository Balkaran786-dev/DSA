#include<iostream>
using namespace std;
template <typename T>   
class Node{ //template class
    public:  //whenever we make its object,we need to define the datatype of which this template class should be of.
    T val;   //hence at compile time,it gets decided that this template class will be of which datatype .
    Node* next;

    Node(T data){
        val=data;
        next=NULL;
    }
};
int main(){
    Node<int>* node1=new Node<int>(3);
    cout<<node1->val<<endl;

    Node<char>* node2=new Node<char>('B');
    cout<<node2->val<<endl;

    Node<string>* node3=new Node<string>("hello");
    cout<<node3->val;

}