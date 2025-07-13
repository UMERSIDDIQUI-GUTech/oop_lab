#include <iostream>
#include <cstring>
using namespace std;
class Resume{
    char* name;
    char* skills;
public:
Resume(): name(nullptr), skills(nullptr){}

Resume(const char*na, const char* sk){
    name= new char[strlen(na)+1];
    strcpy(name, na);
    skills= new char[strlen(sk)+1];
    strcpy(skills, sk);
}

Resume(const Resume& aslihai) {
name = new char[strlen(aslihai.name) + 1];
strcpy(name, aslihai.name); 
skills = new char[strlen(aslihai.skills)+1];
    strcpy(skills, aslihai.skills); 

}
void abaslihai(const char* na, const char* sk){
delete[] name;
delete[] skills;

 name= new char[strlen(na)+1];
     strcpy(name, na);
 skills= new char[strlen(sk)+1];
     strcpy(skills, sk);
}
void showdekhoab(){
    cout << " Name: " << name << " " <<"  Skills: " << skills <<   endl;
}
~Resume(){
    delete[] name;
    delete[] skills;
    cout << " Kaha gaya sab " << endl;
}

};

int main(){
    Resume r1(" Umer siddiqui" , " Mathematician " );
    Resume r2=r1;
r1.showdekhoab();
r2.showdekhoab();
r1.abaslihai(" siddiqui Umer " , " Physician ") ;
r1.showdekhoab();
r2.showdekhoab();
return 0;

}