#include <iostream>
using namespace std;

class Box{
private:
    double width;

public:
    Box(double w) : width(w){}
   friend void printWidth(const Box& b);
};

void printWidth(const Box& b){
    cout<<"Box width: " << b.width <<endl;}

class Math{
public:
    inline int square(int x){
        return x*x;}
};

class Counter{
private:
    static int count; 

public:
    Counter(){
        count++;}

    static void showCount(){
        cout<<"Number of Counter objects: " << count <<endl;}
};

int Counter::count=0;

int main(){
    cout<<"--- Friend Function Example ---" <<endl;
    Box b1(10.5);
    printWidth(b1);
    cout<<endl;

    cout<<"--- Inline Function Example ---" <<endl;
    Math m;
    int num=7;
    cout<<"Square of " << num << " is: " << m.square(num) <<endl;
    cout<<endl;

    cout<<"--- Static Member Example ---" <<endl;
    Counter c1;
    Counter c2;
    Counter c3;
    Counter::showCount();

    return 0;}