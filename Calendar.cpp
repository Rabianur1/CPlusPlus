#include <iostream>
#include <string>
using namespace std;

struct DayNode{
    int day;              
    string title="";        
    string content="";       
    string priority="";      
    DayNode* next;  //Sonraki günü gösteren pointer
    DayNode* prev;  //Önceki günü gösteren pointer
};

//30 günlük bir takvim oluşturur ve çift yönlü bağlı listeye dönüştürür
DayNode* initCalendar(int totalDays=30){
    DayNode* head=new DayNode{1,"","","",nullptr,nullptr};  //1. günü oluşturma
    DayNode* current=head;

    for(int i=2; i<=totalDays; i++){    //2’den 30’a kadar diğer günleri oluştur ve birbirine bağla
        DayNode* newNode=new DayNode{i,"","","",nullptr,nullptr};
        if (head == nullptr){
            head = newNode;
            current = newNode;} 
        else{
            current->next = newNode;
            newNode->prev = current;
            current = newNode;}
    }

    //Listenin dairesel (circular) olması sağlanıyor
    current->next=head;
    head->prev=current;
    return head;
}

//Belirtilen gün numarasına göre düğümü bulur (1–30)
DayNode* findDay(DayNode* head,int dayNum){
        if(dayNum < 1 || dayNum > 30) 
        return nullptr;
        DayNode* current = head;
        for(int i = 1; i < dayNum; i++){
            current = current->next;}
        
        return current;
}

//Yeni bir etkinlik ekleme fonksiyonu
 void addEvent(DayNode* head){
        int dayNum;
        cout << "Etkinlik eklemek istediğiniz günü giriniz(1-30): ";
        cin >> dayNum;

        DayNode* node = findDay(head,dayNum);
        if(!node){
            cout << "Geçersiz gün numarası girdiniz!"<<endl;
            return;}

        //Eğer o güne zaten bir event eklenmişse uyarı verir
        if(node->title != ""){
            cout << "Bu gün için zaten bir event var" <<endl;
            return;}

        cout <<"Etkinlik başlığını giriniz: ";
        cin.ignore();
        getline(cin, node->title);
        cout << "Etkinlik içeriğini giriniz: ";
        getline(cin, node->content);
        cout << "Etkinlik önceliğini giriniz(Low/High): ";
        getline(cin, node->priority);

        cout <<"Etkinlik eklendi." <<endl;
}

//Mevcut bir etkinliği düzenleme fonksiyonu
void editEvent(DayNode* head){
        int dayNum;
        cout << "Düzenlemek istediğiniz günü giriniz(1-30): ";
        cin >> dayNum;

        DayNode* node = findDay(head,dayNum);
        if(!node){
            cout << "Geçersiz gün numarası girdiniz!" <<endl;
            return;}
        
        //Eğer etkinlik varsa mevcut bilgileri gösterir
        if(node->title != ""){
            cout << "Mevcut Etkinlik Bilgileri: "<<endl;
            cout << "Başlık: " << node->title <<endl;
            cout << "İçerik: " << node->content <<endl;
            cout << "Öncelik: " << node->priority <<endl;}

        //Yeni etkinlik bilgilerini alma
        cout <<"Yeni etkinlik başlığını giriniz: ";
        cin.ignore();
        getline(cin, node->title);
        cout << "Yeni etkinlik içeriğini giriniz: ";
        getline(cin, node->content);
        cout << "Yeni etkinlik önceliğini giriniz(Low/High): ";
        getline(cin, node->priority);

        cout <<"Etkinlik düzenlendi." <<endl;
}

//Etkinlikleri listeleme fonksiyonu
void listEvents(DayNode* head){
        int dayNum;
        cout << "Başlangıç gününü giriniz(1-30): ";
        cin >> dayNum;

        DayNode* node = findDay(head,dayNum);
        if(!node){
            cout << "Geçersiz gün numarası girdiniz!" <<endl;
            return;}

        char command;
        do{
            cout << "\n--- " << node->day << ". Gün ---\n";
            //Eğer etkinlik varsa mevcut bilgileri gösterir
            if(node->title != ""){
                cout << "Başlık: " << node->title <<endl;
                cout << "İçerik: " << node->content <<endl;
                cout << "Öncelik: " << node->priority <<endl;}
            else{
                cout << "Bu gün için etkinlik bulunmamaktadır."<<endl;}


            cout << "\nKomutlar: (p=önceki, n=sonraki, q=çıkış): ";  //Kullanıcıdan gezinme komutu al
            cin >> command;

            if(command == 'p') 
            node = node->prev;  //Önceki gün
            else if(command == 'n') 
            node = node->next;  //Sonraki gün

        }while (command != 'q');
        cout << "Ana menüye dönülüyor."<<endl;
}

//Etkinlik silme fonksiyonu
void deleteEvent(DayNode* head){
        int dayNum;
        cout << "Silmek istediğiniz günü giriniz(1-30): ";
        cin >> dayNum;

        DayNode* node = findDay(head,dayNum);
        if(!node){
            cout << "Geçersiz gün numarası girdiniz!"<<endl;
            return;}

        if (node->title == ""){
            cout << "Bu gün için zaten bir event bulunmamaktadır."<<endl;
            return;}

        //Etkinlik bilgilerini sıfırlama
        node->title = "";
        node->content = "";
        node->priority = "";
        cout << "Etkinlik silindi."<<endl;
}

int main(){
	DayNode* calendar=initCalendar();  //30 günlük takvimi oluştur
	int choice;

	while(true){
		cout << "\n===== CALENDAR MENU =====\n";
		cout << "1. Add event"<<endl;
		cout << "2. Edit event"<<endl;
		cout << "3. List events"<<endl;
		cout << "4. Delete event"<<endl;
		cout << "5. Exit"<<endl;
		cout << "Enter your choice: ";
		cin >>choice;

		switch(choice){
			case 1: addEvent(calendar); break;
			case 2: editEvent(calendar); break;
			case 3: listEvents(calendar); break;
			case 4: deleteEvent(calendar); break;
			case 5: cout << "Exiting...\n"; return 0;
			default: cout << "Invalid choice."<<endl;
		}
	}
}