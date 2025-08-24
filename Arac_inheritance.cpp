#include <iostream>
#include <string>
using namespace std;

class Arac{
public:
    Arac(){
        cout<<"Araç nesnesi oluşturuldu." <<endl;}

    void calistir(){
        cout<<"Araç çalıştırıldı." <<endl;}

    ~Arac(){
        cout<<"Araç nesnesi silindi." <<endl;}
};

class Ucabilen{
public:
    Ucabilen(){
        cout<<"Uçabilen nesnesi oluşturuldu." <<endl;}

    void uc(){
        cout<<"Araç uçuyor!" <<endl;}

    ~Ucabilen(){
        cout<<"Uçabilen nesnesi silindi." <<endl;}
};

class Yuzebilen{
public:
    Yuzebilen(){
        cout<<"Yüzebilen nesnesi oluşturuldu." <<endl;}

    void yuz(){
        cout<<"Araç suda yüzüyor!" <<endl;}

    ~Yuzebilen(){
        cout<<"Yüzebilen nesnesi silindi." <<endl;}
};

class Araba : public Arac{
private:
    string marka;
    string model;
public:
    Araba(const string& arabaMarka, const string& arabaModel) : marka(arabaMarka), model(arabaModel){
        cout<<"Araba nesnesi oluşturuldu ->"<< marka << " " << model <<endl;}

    void kornayaBas(){
        cout<<"Korna çalıyor! Biiip!" <<endl;}

    ~Araba(){
        cout<<"Araba nesnesi silindi." <<endl;}
};

class AmfibiArac : public Arac, public Ucabilen, public Yuzebilen{ 
private:
    string marka;
    string model;
public:
    AmfibiArac(const string& amfibiMarka, const string& amfibiModel) : marka(amfibiMarka), model(amfibiModel){
        cout<<"AmfibiArac nesnesi oluşturuldu ->"<< marka << " " << model <<endl;}

    void karadaGit(){
        cout<<"Araç karada ilerliyor!" <<endl;}

    ~AmfibiArac(){
        cout<<"AmfibiArac nesnesi silindi." <<endl;}
};

int main(){
    cout<<"--- Araba Sınıfı (Tekli Miras) ---" <<endl;
    Araba araba("Toyota", "Corolla"); 
    araba.calistir(); 
    araba.kornayaBas(); 
    cout<<endl;

    cout<<"--- AmfibiArac Sınıfı (Çoklu Miras) ---" <<endl; 
    AmfibiArac amfibiArac("Amphicar", "Model 770");
    amfibiArac.calistir();
    amfibiArac.uc(); 
    amfibiArac.yuz(); 
    amfibiArac.karadaGit(); 
    cout<<endl;

    return 0;}