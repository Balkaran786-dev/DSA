#include<iostream>
using namespace std;
void Shift(int s, int d){
    cout<<s<<" -> "<<d<<endl;
}
void Hanoi5(int n, int from_rod, int to_rod,int aux_rod1, int aux_rod2, int aux_rod3){
    if (n == 0)return;
    if (n == 1) {
        Shift(from_rod,to_rod);
        return;
    }
    Hanoi5(n - 2, from_rod, aux_rod1, aux_rod2, aux_rod3, to_rod);
    Shift(from_rod, aux_rod3);
    Shift(from_rod, aux_rod2);
    Shift(from_rod, to_rod);
    Shift(aux_rod2, to_rod);
    Shift(aux_rod3, to_rod);
    Hanoi5(n - 2, aux_rod1, to_rod, from_rod, aux_rod2, aux_rod3);
}
int main(){
    Hanoi5(5,1, 2, 3, 4, 5);
}