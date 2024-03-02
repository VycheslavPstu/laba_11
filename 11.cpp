#include <vector>
#include <cstdio>
#include <fstream>
#include <string>
using namespace std;


struct list{
    vector<string> i;
};


list create_list(vector<string> vec){
    list k;
    k.i = vec;
    return k;
}


void print_list(list k){
    if (k.i.size() > 0){
        for (int i = 0; i < k.i.size(); i++){
            printf("%s ", k.i[i].c_str());
        }
        printf("\n");
    }
    else{
        printf("Empty list\n");
    }
}


list delete_element(list k, int id){
    k.i.erase(k.i.begin()+id);
    return k;
}


list add_element(list k, string element){
    k.i.push_back(element);
    return k;
}


void write_list(list k){
    ofstream out("list.txt", ios::app);
    for (int i = 0; i < k.i.size(); i++){
        out << k.i[i] << "\n";
    }
    out.close();
}


list delete_list(list k){
    k.i = {};
    return k;
}


list restore_list(list k){
    ifstream in("list.txt");
    string line;
    while (getline(in, line)){
        k.i.push_back(line);
    }
    in.close();
    return k;
}


int main(){
    list s = create_list({"bebr0", "bebr1", "bebr2", "bebr3", "bebr4", "bebr5"});
    print_list(s);
    s = delete_element(s, 1);
    print_list(s);
    s = add_element(s, "bebr6");
    print_list(s);
    write_list(s);
    printf("List was successfully written in list.txt\n");
    s = delete_list(s);
    print_list(s);
    s = restore_list(s);
    print_list(s);
    s = delete_list(s);
    print_list(s);
    return 0;
}
