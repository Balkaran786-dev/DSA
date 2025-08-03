#include<bits/stdc++.h>
using namespace std;
class Queue{
	int rear, front;
	int size;
	int *arr;
public:
	Queue(int s){
	 front = rear = -1;
	 size = s;
	 arr = new int[s];
	}
	void Enqueue(int value);
	int dequeue();
	void displayQueue();
};
void Queue::Enqueue(int value){
	if ((front == 0 && rear == size-1) || ((rear+1) == front)){
		cout<<"\n overflow";
		return;
	}
	else if (front == -1){  //when queue is empty
		front=rear=0;
		arr[rear]=value;
	}
	else if (rear == size-1 && front != 0){  //when rear is at the end but we have space at the beginning
		rear = 0;
		arr[rear] = value;
	}
	else{               
		rear++;
		arr[rear] = value;
	}
}
int Queue::dequeue(){
	if (front == -1){
		cout<<"\nQueue is Empty";
		return INT_MIN;
	}

	int data = arr[front];
	arr[front] = -1;
	if (front == rear){
		front = -1;
		rear = -1;
	}
	else if (front == size-1)
		front = 0;
	else
		front++;

	return data;
}

// Function displaying the elements
// of Circular Queue
void Queue::displayQueue()
{
	if (front == -1)
	{
		cout<<"\nQueue is Empty";
		return;
	}
	cout<<"\nElements in Circular Queue are: ";
	if (rear >= front){
		for (int i = front; i <= rear; i++)
			printf("%d ",arr[i]);
	}
	else{
		for (int i = front; i < size; i++)
			cout<<arr[i]<<" ";

		for (int i = 0; i <= rear; i++)
			cout<<arr[i]<<" ";
	}
}
int main(){
	Queue q(5);
	q.Enqueue(1);
	q.Enqueue(2);
	q.Enqueue(3);
	q.Enqueue(4);

	q.displayQueue();

	 cout<<"The deleted value is:- "<<q.dequeue()<<endl;
	 cout<<"The deleted value is:- "<<q.dequeue()<<endl;

	q.displayQueue();
	q.Enqueue(8);
	q.Enqueue(21);
	q.Enqueue(5);
	q.displayQueue();

	q.Enqueue(20);
	return 0;
}
