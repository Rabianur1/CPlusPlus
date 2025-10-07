//Rabianur Becit  1306230084  Assignment-1  07.10.2025

#include <iostream>
#include <string> //string türünü kullanmak için
#include <iomanip> 
using namespace std;

//Öğrencinin temel bilgilerini tutan yapı(struct)
struct Student{
    string name;
    int age;
    double gpa;
};

//Kullanıcıdan n adet öğrencinin bilgilerini alan fonksiyon
//Tüm erişimler pointer üzerinden *(arr + i) şeklinde yapılır
void inputStudents(Student* arr, int n){
    for(int i = 0; i < n; i++){
        cout << "\n" << i + 1 << ". öğrenci:" << endl;

        cout << "Ad: ";
        cin.ignore();
        getline(cin, (*(arr + i)).name);

        cout << "Yaş: ";
        cin >> (*(arr + i)).age;

        cout << "GPA: ";
        cin >> (*(arr + i)).gpa;
    }
}

//Öğrencileri GPA değerine göre artan sırada sıralayan fonksiyon
//Pointer erişimleri kullanılarak sıralama yapılır
void sortByGPA(Student* arr, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if((*(arr + i)).gpa > (*(arr + j)).gpa){
                Student temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
}

//Sıralanmış öğrenci listesini ekrana yazdıran fonksiyon
void printStudents(Student* arr, int n){
    cout << left << setw(20) << "Ad" << setw(10) << "Yas" << setw(10) << "GPA" << endl;
    cout << string(40, '-') << endl;

    //Her öğrencinin bilgilerini tablo formatında yazdırır
    for(int i = 0; i < n; i++){
        cout << left << setw(20) << (*(arr + i)).name << setw(10) << (*(arr + i)).age << fixed << setprecision(2) << (*(arr + i)).gpa << endl;
    }
}

int main(){
    int n; //n öğrenci sayısını kullanıcıdan alma
    cout << "Kaç öğrenci kaydedilecek? ";
    cin >> n;
    if(n <= 0){
        cout << "Geçersiz öğrenci sayısı! Program sonlandırılıyor." << endl;
        return 0;
    }

    Student* students = new Student[n];  //Dinamik bellekten n adet Student nesnesi oluşturulur
    inputStudents(students, n);  //Öğrenci bilgilerini kullanıcıdan alma
    sortByGPA(students, n);  //Öğrencileri GPA'ye göre sıralama
    printStudents(students, n); //Sıralanmış öğrencileri ekrana yazdırma
    delete[] students;  //Dinamik bellekten ayrılan alan serbest bırakılır.

    return 0;
}  