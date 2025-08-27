//Take a vector.
//take two variables front and back initialising with -1;
//when you put first ele in the vector,increase both variable by 1.
//when you put ele again in the vector,only increse the back.
//when you dequeue,you only increase the front by one.Don't need to remove any element.
//when you want to display all the elements in the queue, do it from front to back.

//advantage of this type of implementation: can manage its insertion and deletion on its own whereas in linked list,we need to manage insertion and deletion on our own.
#include<iostream>
#include<vector>
using namespace std;

class queue{
     vector<int> v;
     int curr_size;
     int front;
     int back;

     public:
     queue(){
      curr_size=0;
      front=back=-1;
     }

     void enqueue(int data){
        if(v.size()==0){
            v.push_back(data);
            front++;
            back++;
            curr_size++;
            return;
        }
        v.push_back(data);
        back++;
        curr_size++;
        return;
     }
   
     void dequeue(){
        if(back==-1){
            //queue is empty
            return;
        }
        front++;
        curr_size--;
        return;
     }
     bool Is_empty(){
        return back==-1;
     }
     int size(){
        return curr_size;
     }
     int get_front(){
        return v[front];
     }
     void display(){
        while(front<=back){
           cout<<v[front]<<" ";
           front++;
        }
     }
};


int main(){
    queue qu;
    qu.enqueue(1);
    qu.enqueue(2);
    qu.enqueue(3);
    cout<<qu.get_front()<<endl;
    qu.dequeue();
    cout<<qu.get_front()<<endl;
    qu.enqueue(4);
    qu.enqueue(5);
    qu.display();
    return 0;
}