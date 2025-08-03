#include<iostream>
#include<vector>
using namespace std;
class queue{
     vector<int> v;
     int cs;
     int front;
     int rear;
     public:
     queue(int n){
      this->v.resize(n);
      this->cs=0;
      this->front=0;
      this->rear=n-1;
     }
     void enqueue(int data){
        if(Is_full()){
            return;
        }
        this->rear=(this->rear+1)%this->v.size();
        this->v[this->rear]=data;
        this->cs++;
     }
     void dequeue(){
        if(Is_empty())return;
        this->front=(this->front+1)%this->v.size();
        this->cs--;
     }
     bool Is_empty(){
        return this->cs==0;
     }
     bool Is_full(){
        return this->cs==this->v.size();
     }
     void display(){
        if(Is_empty())return;
        int frt=this->front;
        int rr=this->rear;
        while(frt!=rr){
           cout<<v[frt]<<" ";
           frt=(frt+1)%this->v.size();
        }
        cout<<v[frt]; //kyunki jab dono frt and rr equal ho jayenge toh ek last vala element print krne ko rh jayega
        cout<<endl;
     }
};
int main(){
    queue q(5);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);

	q.display();

	q.dequeue();
    q.dequeue();

	q.display();
	q.enqueue(8);
	q.enqueue(21);
	q.enqueue(5);
	q.display();

    return 0;
}