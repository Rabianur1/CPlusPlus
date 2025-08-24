#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Student{
private:
    int studentID;
    string fullName;
    string universityName;

public:
    Student(){
        studentID=0;
        fullName="Undefined";
        universityName="Undefined";
        cout<<"Default Constructor called." <<endl;}

    Student(string name){
        studentID=0;
        fullName=name;
        universityName="Istanbul University-Cerrahpasa";
        cout<<"Parameterized Constructor (with full name) called." <<endl;}

    Student(int id, string name, string university){
        studentID=id;
        fullName=name;
        universityName=university;
        cout<<"Parameterized Constructor (with all variables) called." <<endl;}

    ~Student(){
        cout<<"Deconstructor called for student: " << fullName <<endl;}

    void display(){
        cout<<"Student ID: " << studentID << ", Full Name: " << fullName << ", University: " << universityName <<endl;}
};

class Circle{
private:
    int x; 
    int y;
    double radius; 
    const double PI=3.14159;

public:
    Circle(){
        x=0;
        y=0;
        radius=10.0;}

    Circle(int newX, int newY, double newRadius){
        x=newX;
        y=newY;
        setRadius(newRadius);}

    void setRadius(double r){
        if (r > 0.0){
            radius=r;} 
        else{
            radius=10.0;}}

    int getX(){
        return x;}

    int getY(){
        return y;}

    double getRadius(){
        return radius;}

    double getArea(){
        return PI * pow(radius, 2);}

    void displayCircle(){
        cout <<"radius " << radius << " at point x=" << x <<" "<<"y=" << y <<endl;}

    void move(int horiz, int vert){
        x += horiz;
        y += vert;}
};

int main(){
    cout<<"--- Student Class Demonstration ---"<<endl;
    Student s1;
    s1.display();
    cout<<endl;

    Student s2("Rabianur Becit");
    s2.display();
    cout<<endl;

    Student s3(12345, "Harry Potter", "Hogwarts University");
    s3.display();
    cout<<endl;

    cout<<"--- Circle Class Demonstration ---" <<endl;
    Circle c1;
    c1.displayCircle();

    Circle c2(5, -5, 15.5);
    c2.displayCircle();

    cout<<"Setting radius to an invalid value(0.0):" <<endl;
    c2.setRadius(0.0);
    c2.displayCircle();

    cout<<"Area of the circle: " << c2.getArea() <<endl;

    cout<<"Moving circle by (2, 3):" <<endl;
    c2.move(2, 3);
    c2.displayCircle();

    return 0;}