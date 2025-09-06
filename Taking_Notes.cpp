#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    vector<string>notes;
    int choice;

    while (true){
        cout<<"\n--- NOT ALMA UYGULAMASI ---\n";
        cout<<"1. Not ekle\n2. Notları göster\n3. Not sil\n4. Çıkış\nSeçiminizi giriniz: ";
        cin>>choice;
        cin.ignore(); 

        if (choice == 1){
            string note;
            cout<<"Not giriniz: ";
            getline(cin, note);
            notes.push_back(note);
            cout<<"Not eklendi!\n";}
            
        else if(choice == 2){
            if(notes.empty()){
                cout<<"Henüz not bulunmamaktadır.\n";} 
            else{
                cout<<"\n--- NOTLAR ---\n";
                for(size_t i=0; i < notes.size(); ++i){
                    cout<< i + 1 << ". " << notes[i] <<endl;}
            }
        }
            
        else if(choice == 3){
            if(notes.empty()){
                cout<<"Silinecek not yok.\n";} 
            else{
                cout<<"\n--- NOTLAR ---\n";
                for(size_t i=0; i < notes.size(); ++i){
                    cout<< i + 1 << ". " << notes[i] <<endl;}
                
                int index;
                cout<<"Silmek istediğiniz notun numarasını giriniz: ";
                cin >> index;
                cin.ignore();
                if(index > 0 && index <= notes.size()){
                    notes.erase(notes.begin() + index - 1);
                    cout<<"Not silindi!\n";} 
                else{
                    cout<<"Geçersiz numara!\n";}
            }
        }
            
        else if(choice == 4){
            cout<<"Programdan çıkılıyor...\n";
            break;}
            
        else{
            cout<< "Geçersiz seçim!\n";}
    }
    return 0;}