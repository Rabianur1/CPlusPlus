#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    srand(time(0));
    int number, guess, attempts = 0, maxAttempts;
    int level;

    cout << "1-100 arasında bir sayıyı tahmin etme oyununa hoşgeldiniz!\n";
    cout << "Zorluk seviyesini seçiniz:\n";
    cout << "1. Kolay (15 hakkınız var)\n";
    cout << "2. Orta (10 hakkınız var)\n";
    cout << "3. Zor (5 hakkınız var)\n";
    cout << "Seçiminizi giriniz: ";
    cin >> level;

    if(level == 1) maxAttempts=20;
    else if(level == 2) maxAttempts=10;
    else if(level == 3) maxAttempts=5;
    else{
        cout<<"Geçersiz seçim. Oyun sonlandırılıyor.\n";
        return 0;}

    number = rand() % 100 + 1; 
    cout<<"\n1-100 arasında bir sayı tuttum. " << maxAttempts << " hakkınız var!\n";

    while(attempts < maxAttempts){
        cout<<"Tahmininizi giriniz: ";
        cin >> guess;
        attempts++;

        if(guess > number)
            cout<<"Daha küçük bir sayı dene.\n";
        else if(guess < number)
            cout<<"Daha büyük bir sayı dene.\n";
        else{
            cout<<"Tebrikler! " << attempts << ". denemede doğru bildiniz.\n";
            break;}

        if(attempts == maxAttempts){
            cout<<"Maalesef hakkınız bitti. Doğru sayı: " << number <<endl;}
    }
 return 0;}