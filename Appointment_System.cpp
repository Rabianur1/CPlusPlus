#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Tek yönlü bağlı liste için düğüm yapısı
struct Appointment{
    string patientName;      
    double time;          
    int duration;            
    Appointment* next; 
};

//Ondalık saat formatını dakikaya çevirir.
int saateDakikaCevir(double saat){
    int saatKismi = (int)saat;                
    int dakikaKismi = (int)((saat - saatKismi) * 100);
    return saatKismi *60 + dakikaKismi;}

//Dakika cinsinden değeri ondalıklı saate çevirir.
double dakikayiSaateCevir(int dakika){
    int saatKismi = dakika/60;               
    int dakikaKismi = dakika%60;             
    return saatKismi + (dakikaKismi/100.0);}

//Listedeki tüm randevuları ekrana yazdırır.
void printAll(Appointment* head){
    if(head == nullptr){                      
        cout << "Henüz kayıtlı randevu bulunmamaktadır."<<endl;;
        return;}

    cout << "\n--- RANDEVU LİSTESİ ---\n";
    Appointment* current = head;                    
    while(current != nullptr){
        cout << fixed << setprecision(2);      
        cout << "Hasta: " << current->patientName
             << " | Saat: " << current->time
             << " | Süre: " << current->duration << " dk\n";
        current=current->next;}
}

//Belirtilen saatten sonraki randevuları gösterir.
void printFromTime(Appointment* head, double time){
    if(head== nullptr){
        cout << "Listede randevu bulunmuyor."<<endl;
        return;}

    cout << "\n" << time << " saatinden sonraki randevular:\n";
    Appointment* temp = head;
    while(temp != nullptr){
        if(temp->time >= time){              
            cout << "Hasta: " << temp->patientName
                 << " | Saat: " << temp->time
                 << " | Süre: " << temp->duration << " dk"<<endl;}

        temp = temp->next;}
}

//Yeni eklenecek randevu mevcut bir randevu ile çakışıyor mu kontrol eder.
bool cakismaVarMi(Appointment*head, double time, int duration){
    int newHead = saateDakikaCevir(time);           //Yeni randevunun başlangıcı
    int newEnd = newHead + duration;             //Yeni randevunun bitişi

    Appointment* temp =head;
    while(temp != nullptr){
        int mevcutBas = saateDakikaCevir(temp->time);
        int mevcutBitis = mevcutBas + temp->duration;

        //Çakışma kontrolü: aralıklar üst üste biniyor mu
        if(!(newEnd <= mevcutBas || newHead >= mevcutBitis)){
            return true;}  //çakışma var

        temp = temp->next;}
    return false;  //çakışma yok
}

//Yeni randevu ekleme
void insertAppointment(Appointment*&head, string name, double time, int duration){
    if(time < 9.00 || time > 17.00){
        cout << "Randevular sadece 09.00 - 17.00 arasında olabilir."<<endl;
        return;}

    //Çakışma kontrolü
    if(cakismaVarMi(head,time,duration)){
        cout << "Bu saat aralığında başka bir randevu bulunmaktadır."<<endl;
        return;}

    //Yeni düğüm oluşturma
    Appointment* newNode= new Appointment;
    newNode->patientName =name;
    newNode->time = time;
    newNode->duration = duration;
    newNode->next = nullptr;

    //Liste boşsa doğrudan başa ekleme
    if(head == nullptr || head->time > time){
        newNode->next = head;
        head = newNode;
        return;}

    //Uygun yere (saat sırasına göre) ekleme
    Appointment* current = head;
    while(current->next != nullptr && current->next->time <time){
        current = current->next;}

    newNode->next = current->next;
    current->next = newNode;
}

//Belirtilen saatteki randevuyu listeden silme
void deleteAppointment(Appointment*&head, double time){
    if(head == nullptr){
        cout << "Liste zaten boş."<<endl;
        return;}

    //İlk düğüm silinecekse
    if(head->time == time){
        Appointment* temp =head;
        head = head->next;
        delete temp;
        cout << "Randevu silindi."<<endl;
        return;}

    Appointment* current = head;
    while(current->next != nullptr && current->next->time != time){
        current = current->next;}

    if(current->next == nullptr){
        cout << "Bu saatte bir randevu bulunamadı."<<endl;
        return;}

    Appointment* temp =current->next;
    current->next = temp->next->next;
    delete temp;
    cout << "Randevu silindi."<<endl;
}

//Gün boyunca toplam dolu zamanı hesaplama
int totalBusyMinutes(Appointment* head){
    int total = 0;
    Appointment* current = head;
    while(current != nullptr){
        total += current->duration;
        current = current->next;}

    return total;}

//Belirtilen saatten sonraki ilk boş zamanı önerir
double suggestNextAvailable(Appointment* head, double startTime){
    int currentEnd = saateDakikaCevir(startTime);
    int last = 17 * 60; // 17:00 son saat

    if(head == nullptr) 
    return startTime;  //Hiç randevu yoksa hemen uygundur

    Appointment* current = head;
    while(current != nullptr){
        int begin = saateDakikaCevir(current->time);
        int end = begin + current->time;

        //Aralarda 15 dakikalık boşluk varsa öner
        if(currentEnd < begin){
            if(currentEnd + 15 <= begin)
                return dakikayiSaateCevir(currentEnd);
            else
                currentEnd = end;} 

        else if(currentEnd < end){
            currentEnd = end;}

        current =current->next;
    }

    if(currentEnd<last)
        return dakikayiSaateCevir(currentEnd);
    else
        return -1; //Gün sonuna kadar boşluk yok
}

int main(){
    Appointment*head = nullptr;  //Liste başını tutar
    int choice;

    do{
        cout << "\n========== RANDEVU PLANLAMA ==========\n";
        cout << "1. Tüm randevuları listele"<<endl;
        cout << "2. Belirli bir saatten sonraki randevuları göster"<<endl;
        cout << "3. Yeni randevu ekle"<<endl;
        cout << "4. Randevu sil"<<endl;
        cout << "5. Toplam dolu süreyi hesapla"<<endl;
        cout << "6. İlk uygun zamanı öner"<<endl;
        cout << "0. Çıkış"<<endl;
        cout << "Seçiminiz: ";
        cin >>choice;

        if(choice == 1){
            printAll(head);}

        else if(choice == 2){
            double time;
            cout << "Saat giriniz: ";
            cin >> time;
            printFromTime(head,time);}

        else if(choice == 3){
            string name;
            double time;
            int duration;
            cout << "Hasta adı: ";
            cin >> ws;          
            getline(cin,name);  
            cout << "Saat: ";
            cin >> time;
            cout << "Süre: ";
            cin >> duration;
            insertAppointment(head,name,time,duration);}

        else if(choice == 4){
            double time;
            cout << "Silinecek randevu saatini giriniz: ";
            cin >> time;
            deleteAppointment(head,time);}

        else if(choice == 5){
            cout << "Toplam dolu süre: " << totalBusyMinutes(head) << " dakika"<<endl;}

        else if(choice == 6){
            double time;
            cout << "Başlangıç saati: ";
            cin >>time;
            double uygun = suggestNextAvailable(head,time);
            if (uygun == -1)
                cout << "Bugün için boş zaman kalmadı."<<endl;
            else
                cout << "İlk uygun zaman: " << fixed << setprecision(2) << uygun << "\n";}

    } while(choice!= 0);

    cout << "Program sonlandırıldı."<<endl;
    return 0;}