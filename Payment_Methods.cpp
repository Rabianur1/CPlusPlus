#include <iostream>
#include <string>
using namespace std;

class IOdemeYontemi{
public:
    virtual void odemeYap(double miktar)=0; 
    virtual ~IOdemeYontemi(){}               
};

class KrediKartiOdeme : public IOdemeYontemi{
private:
    string kartNo;
public:
    KrediKartiOdeme(const string& no) : kartNo(no){}

    void odemeYap(double miktar) override{
        string son4 = kartNo.substr(kartNo.length() - 4);
        cout<< miktar <<" TL kredi kartıyla ödendi. Kart No: ****" << son4 <<endl;}
};

class HavaleOdeme : public IOdemeYontemi{
private:
    string iban;
public:
    HavaleOdeme(const string& ibanNo) : iban(ibanNo){}

    void odemeYap(double miktar) override{
        string son4 = iban.substr(iban.length() - 4);
        cout<< miktar <<"TL havale ile ödendi. IBAN: ****" << son4 <<endl;}
};

class MobilOdeme : public IOdemeYontemi{
private:
    string telefonNo;
public:
    MobilOdeme(const string& tel) : telefonNo(tel){}

    void odemeYap(double miktar) override{
        string son4 = telefonNo.substr(telefonNo.length() - 4);
        cout<< miktar <<" TL mobil ödeme ile ödendi. Telefon: ****" << son4 <<endl;}
};

void odemeIslemi(IOdemeYontemi* odemeYontemi, double miktar){
    odemeYontemi->odemeYap(miktar);}

int main(){
    IOdemeYontemi* krediKarti = new KrediKartiOdeme("1234567890123456");
    IOdemeYontemi* havale = new HavaleOdeme("TR000012345678901234567890");
    IOdemeYontemi* mobil = new MobilOdeme("05551234567");

    odemeIslemi(krediKarti, 250.0);
    odemeIslemi(havale, 180.5);
    odemeIslemi(mobil, 99.99);

    delete krediKarti;
    delete havale;
    delete mobil;

    return 0;}