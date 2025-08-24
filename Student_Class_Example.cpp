#include <iostream>
#include <string>
using namespace std;

struct Lesson{
public:
    string lessonName;
    int credit;
};

class Student{
private:
    string name;
    int age;
    float gpa;

public:
    Student(string n,int a,float g){
        name=n;
        age=a;
        if(g>= 0.0 && g<= 4.0)
            gpa=g;
        else{
            cout<<"Geçersiz GPA! 0.0 - 4.0 aralığında olmalıdır.\n";
            gpa=0.0;}}


    void displayInfo(){
        cout <<"İsim: " << name <<endl;
        cout <<"Yaş: " << age <<endl;
        cout <<"GPA: " << gpa <<endl;}

    float getGPA(){
        return gpa;}


    void setGPA(float newGPA){
        if(newGPA >= 0.0 && newGPA <= 4.0){
            gpa=newGPA;
            cout<<"Yeni GPA başarıyla güncellendi: " << gpa <<endl;}
        else{
            cout<<"HATA: GPA 0.0 - 4.0 aralığında olmalıdır!" <<endl;}
    }
};

int main(){
    Lesson lesson1;
    lesson1.lessonName ="Programlama";
    lesson1.credit = 4;
    cout << "Ders Adı: " << lesson1.lessonName <<endl;
    cout << "Kredi: " << lesson1.credit <<endl;

    Student student1("Rabianur Becit", 20, 3.5);
    student1.displayInfo();

    cout << "\nMevcut GPA(getter ile): " << student1.getGPA() <<endl;

    student1.setGPA(3.8);
    student1.setGPA(5.0);

    return 0;}
