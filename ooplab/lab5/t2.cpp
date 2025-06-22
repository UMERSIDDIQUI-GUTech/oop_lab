#include <iostream>
#include <string>
using namespace std;
class Printer
{
public:
 void printer()
{

cout << "Printed\n";
}
};
class Scanner
{
public:
 void scanner(){
    cout << " Scanned " << endl;
 }
};

class Copier : public Scanner, public Printer
{
public:
void copier()
{
 scanner();
 printer();
cout << "Copied\n";

}

};
int main()
{
Copier c;
c.copier();
return 0;
}