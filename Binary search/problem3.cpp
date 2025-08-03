//Whenever you are required to find maximum of minimum or minimum of maximum.
//You need to do it by binary search.


// #include<iostream>
// #include<vector>
// using namespace std;
// bool check(vector<int> &v,int mid,int s){
//     int n=v.size();
//     int last_placed=v[0];
//     int student=1;

//     for(int i=1;i<n;i++){
//          if((v[i]-last_placed)>=mid){
//                last_placed=v[i];
//                student++;
//                if(student==s){
//                 return true;    //students placed hojaye ache se even chache hamare baad ke spots empty reh jaye. 
//                } 
//          }
//     }

//     return false;   
// }
// int max_dist(vector<int> &v,int s){
//       int n=v.size();
//       int lo=1;
//       int hi=v[n-1]-v[0];
//       int ans=-1;
//       while(lo<=hi){
//         int mid=(lo+hi)/2;
//         if(check(v,mid,s)){  // matlab placed ho gaye saare bacche..
//             ans=mid;
//             lo=mid+1;
//         }
//         else{   //matlab placed nhi huye isiliye dist kam krna hoga..
//             hi=mid-1;
//         }
//       }
//       return ans;
// }
// int main(){
//     //(space : o(1))
//     //(time : o(nlog(v[n-1]-v[0])))
//     int n;
//     cin>>n;
//     vector<int> v(n);
//     for(int i=0;i<n;i++){
//         cin>>v[i];
//     }
//     int s;
//     cin>>s;
//     cout<<max_dist(v,s);
// }


#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> &v,int mid,int s){

    int stu_req=1,curr_sum=0;

    for(int i=0;i<v.size();i++){
        if(v[i]>mid){
            return false;  //agr box ki chocolates hi mid se jada hui, toh vo box toh hum kisi ko de hi nhi payenge.
        }

        if(curr_sum+v[i]<=mid){
            curr_sum+=v[i];
        }

        else if(curr_sum+v[i]>mid){
            stu_req++;
            curr_sum=v[i];  //ess box ko aap pechle stu ko nhi de paye isilye isi ke sath agle student se distribution krenge
            if(stu_req>s){  //agr aage koi student hi nhi hua,toh return false
                return false; 
            }
        }
    }

    return true;
}

int min_chocolates(vector<int> &v,int s){
    int n=v.size();
    int lo=v[0];
    int hi=0;
    int ans=-1;

    for(int i=0;i<n;i++){
        hi+=v[i];
    }

    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(check(v,mid,s)){  // it gives true if the chocolates has been fully given or even if some students are left.If some students are left, that means we have given a larger minimum value to each student.
            ans=mid;
            hi=mid-1; //i'll try to minimise my maximum chocolates,kyunki agr isme ho gai toh jada mein toh ho hi jayegi
        }
        else{        //ill move forward kyunki agr esme nhi hui,toh esse min mein bhi nhi hogi.
            lo=mid+1;  
        }
    }

    return ans;

}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);  //it should be sorted..
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int s;
    cin>>s;
    cout<<min_chocolates(v,s);
    return 0;
}























//brute force linear search:-

// start hum krenge difference of last and first spot that will be the maximium diff
// end krenge 0 pe,
// jo bhi diff pehla aisa mila jispe saare bacche place ho gaye return it, it will be the maximum vakue of the distance between two student...

// to find kitne bacche place huye,
// check the below check function.....


#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> &v,int mid,int stu){
     int stu_plac=1;
     int prev_spot=v[0]; //pehle student ko toh hum first spot pe hi rkhenge.
     for(int i=1;i<v.size();i++){
        if(v[i]-prev_spot>=mid){
            stu_plac++;
            prev_spot=v[i]; //kyunki abh hame yahan se dist check krna pdega.
            if(stu_plac==stu){  //agr saare ke saare students already placed ho gye,return true;
                return true; 
            }
        }
     }
     return false;
}
int max_dist(vector<int> &v,int s){
    int n=v.size();
    int lo=v[0];
    int hi=v[n-1]-v[0];
    int ans=-1;
    while(lo<=hi){
         int mid=lo+(hi-lo)/2;
         if(check(v,mid,s)){
            ans=mid;
            lo=mid+1;
         }
         else{
            hi=mid-1;
         }
    }
    return ans;
}
int main(){
    //(space : o(1))
    //(time : o(nlog(v[n-1]-v[0])))
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int s;
    cin>>s;
    cout<<max_dist(v,s);
}