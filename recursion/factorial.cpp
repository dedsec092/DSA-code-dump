#include<iostream>
using namespace std;
int factorial(int n){
    int fact=0;
    if(n<=0){
        return 1;
    }
    fact=n*factorial(n-1);
    return fact;

}
int main(){
    int n=8;
    cout<<factorial(n);
}