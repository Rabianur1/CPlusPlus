#include <iostream>
#include <string>
using namespace std;

struct Ogrenci{
    string isim;
    int notu;
};

int main(){
    int ogrenciSayisi;
    cout<<"Kaç öğrenci gireceksiniz? ";
    cin>>ogrenciSayisi;

    if(ogrenciSayisi <= 0){
        cout<<"Geçersiz öğrenci sayısı girdiniz!" <<endl;
        return 1;}

    Ogrenci* ogrenciler = new Ogrenci[ogrenciSayisi];

    for(int i=0; i< ogrenciSayisi; i++){
        cout << i + 1 << ". öğrencinin ismini giriniz: ";
        cin>>ogrenciler[i].isim;

        while(true){
            cout<< ogrenciler[i].isim << " adlı öğrencinin notunu giriniz(0-100): ";
            cin>>ogrenciler[i].notu;

            if(ogrenciler[i].notu >= 0 && ogrenciler[i].notu <= 100){
                break;} 
            else{
                cout<< "Geçersiz not! Lütfen 0-100 arası bir değer giriniz." <<endl;}
        }
    }

    int toplam=0;
    int enYuksekNot = ogrenciler[0].notu;
    int enDusukNot = ogrenciler[0].notu;
    string enYuksekIsim = ogrenciler[0].isim;
    string enDusukIsim = ogrenciler[0].isim;

    for(int i=0; i< ogrenciSayisi; i++){
        toplam += ogrenciler[i].notu;

        if(ogrenciler[i].notu > enYuksekNot){
            enYuksekNot = ogrenciler[i].notu;
            enYuksekIsim = ogrenciler[i].isim;}

        if(ogrenciler[i].notu < enDusukNot){
            enDusukNot = ogrenciler[i].notu;
            enDusukIsim = ogrenciler[i].isim;}
    }

    double ortalama = static_cast<double>(toplam)/ogrenciSayisi;

    cout<<"\n--- Analiz Sonuçları ---" <<endl;
    cout<<"Ortalama not: " << ortalama <<endl;
    cout<<"En yüksek not: " << enYuksekNot << " (" << enYuksekIsim << ")" <<endl;
    cout<<"En düşük not: " << enDusukNot << " (" << enDusukIsim << ")" <<endl;

    cout<<"\nOrtalama üstü öğrenciler:" <<endl;
    for(int i=0; i< ogrenciSayisi; i++){
        if(ogrenciler[i].notu > ortalama){
            cout<< ogrenciler[i].isim << " - " << ogrenciler[i].notu <<endl;}
    }

    cout<<"\nOrtalama altı öğrenciler:" <<endl;
    for(int i=0; i< ogrenciSayisi; i++){
        if(ogrenciler[i].notu < ortalama){
            cout<<ogrenciler[i].isim << " - " << ogrenciler[i].notu <<endl;}
    }

    delete[] ogrenciler;

    return 0;}