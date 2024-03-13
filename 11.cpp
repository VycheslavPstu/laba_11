#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;


class Node {
    public:
        string data;
        Node *prev, *next;
    public:
        Node (string data){
             this -> data = data;
             this -> prev = this -> next = NULL;
        }
};


class LinkedList{
    public:
        Node *head, *tail;
    public:
        LinkedList(){
            head = tail = NULL;
        };

        ~LinkedList() {
            while (head != NULL){
                pop_front();
            }
        }

        /*1.1: Добавить элемент в начало*/
        Node *push_front(string data){
            Node *ptr = new Node(data);
            ptr -> next = head;
            if (head != NULL){
                head -> prev = ptr;
            }
            if (tail == NULL){
                tail = ptr;
                head = ptr;
                return ptr;
            }
        }

        /*1.2: Добавить элемент в конец*/        
        Node *push_back(string data){
            Node *ptr = new Node(data);
            ptr -> prev = tail;
            if (tail != NULL){
                tail -> next = ptr;
            }
            if (head == NULL){
                head = ptr;
            }
            tail = ptr;
            return ptr;
        }

        /*3.1: Удалить элемент сначала*/
        int *pop_front() {
            if (head == NULL){
                return 0;
            }
            
            Node *ptr = head -> next;
            if (ptr != NULL){
                ptr -> prev = NULL;
            }
            else{
                tail = NULL;
            }

            delete head;
            head = ptr;
            return 0;
        }
        /*3.2: Удалить элемент с конца*/
        int *pop_back() {
            if (tail == NULL){
                return 0;
            }
            
            Node *ptr = tail -> prev;
            if (ptr != NULL){
                ptr -> next = NULL;
            }
            else{
                head = NULL;
            }

            delete tail;
            tail = ptr;
            return 0;
        }

        Node *getAt(int index){
            Node *ptr = head;
            int n = 0;

            while (n != index){
                if (ptr == NULL){
                    return ptr;
                }
                ptr = ptr -> next;
                n++;
            }

            return ptr;
        }

        Node *operator [] (int index){
            return getAt(index);
        }

        /*1.3: Добавить элемент по индексу*/
        Node *insert(int index, string data) {
            Node *right = getAt(index);
            if (right == NULL){
                return push_back(data); 
            }

            Node *left = right -> prev;
            if (left == NULL){
                return push_front(data);
            } 

            Node *ptr = new Node(data);
            ptr -> prev = left;
            ptr -> next = right;
            left -> next = ptr;
            right -> prev = ptr;
            
            return ptr;
        }
        
        int *print() {
            if (size() != 0){
            for (Node *ptr = head; ptr != NULL; ptr = ptr -> next){
                cout << ptr -> data << " ";
            }
            cout << "\n";
            }
            else{
                cout << "Empty list\n";
            }
            return 0;
        }

        /*Размер списка*/
        int size() {
            int amount = 0;
            Node *ptr = head;
            while (ptr != NULL){
                amount ++;
                ptr = ptr -> next;
            }
            return amount;
        }
        
        int write(){
            ofstream out("test.txt", ios::app);
            Node *ptr = head;
            while (ptr != NULL){
                out << ptr -> data << "\n";
                ptr = ptr -> next;
            }
            out.close();
            return 0;
        }
        
        int read(){
            ifstream in("test.txt");
            string line = "";
            while(getline(in, line)) push_back(line); // Генерация списка из key элементов
            in.close();
            return 0;
        }
        /*6: Удаление из списка элемента*/
        int *erase(int index){
            Node *ptr = getAt(index);
            if (ptr == NULL) {
                return 0;
            }
            if (ptr -> prev == NULL) {
                pop_front();
                return 0;
            }
             if (ptr -> next == NULL) {
                pop_back();
                return 0;
            }

            Node *left = ptr -> prev;
            Node *right = ptr -> next;
            left -> next = right;
            right -> prev = left;

            delete ptr;
            return 0;
        }
};


int main(){
    int key, k;
    cout << "Key: ";
    cin >> key;
    cout << "K: ";
    cin >> k;
    LinkedList test; // Создание списка
    
    /*Задание со списком по вариантам*/
    srand(time(NULL));
    for (int i = 0; i <= key; i++) test.push_back(to_string(rand())); // Генерация списка из key элементов
    test.print();
    test.pop_back();
    test.print();
    for (int i = 0; i < k; i++) test.push_back(to_string(rand())); // Добавление k элементов после удаления по индекус key
    test.print();
    test.write();
    
    /*Уничтожение спиcка*/
    while (test.size() > 0) test.pop_front();
    test.print();
    
    
    /*Работа списка с файлом*/  
    test.read();
    test.print();
    
    
    /*Уничтожение спиcка*/
    while (test.size() > 0) test.pop_front();
    test.print();
    return 0;

}

/*
Записи в линейном списке содержат ключевое поле типа *char(строка символов). Сформировать двунаправленный список. 
Удалить элемент с заданным ключом. Добавить К элементов после элемента с заданным ключом.
*/
