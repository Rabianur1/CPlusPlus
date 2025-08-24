#include <iostream>
#include <stdexcept>
#include <exception>
using namespace std;

class InvalidOperationException : public exception{
public:
    const char* what() const noexcept override{
        return "Geçersiz bir işlem seçildi!";}
};

double divide(int a, int b){
    if(b == 0){
        throw runtime_error("Sıfıra bölme hatası!");}
    return static_cast<double>(a) / b;}

int main(){
    char devam;
    do{
        try{
            int num1, num2, secim;
            cout<<"Birinci sayıyı giriniz: ";
            cin>>num1;
            cout<<"İkinci sayıyı giriniz: ";
            cin>>num2;
            cout<<"İşlem seçiniz:\n";
            cout<<"1) Toplama\n2) Çıkarma\n3) Çarpma\n4) Bölme\n";
            cout<<"Seçiminiz: ";
            cin>>secim;

            double sonuc=0;
            switch (secim){
                case 1:
                    sonuc= num1 + num2;
                    break;
                case 2:
                    sonuc= num1 - num2;
                    break;
                case 3:
                    sonuc= num1 * num2;
                    break;
                case 4:
                    sonuc= divide(num1, num2);
                    break;
                default:
                    throw InvalidOperationException();
            }

            cout<<"Sonuç: " << sonuc <<endl;}
            
        catch(const runtime_error& e){
            cout<< e.what() <<endl;}
            
        catch(const InvalidOperationException& e){
            cout<< e.what() <<endl;}
            
        catch(...){
            cout<<"Bilinmeyen bir hata oluştu!" <<endl;}

        cout<<"Yeni işlem yapmak ister misiniz? (e/h): ";
        cin>>devam;
        cout<<endl;

    } while(devam == 'e' || devam == 'E');

    cout<<"Program sona erdi. Teşekkürler!" <<endl;
    return 0;}
