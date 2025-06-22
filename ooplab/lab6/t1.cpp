#include <iostream>
#include <string>
using namespace std;
class PaymentGateway {  
public:
    virtual bool pay(double amount) = 0; 
    virtual ~PaymentGateway()= default; 
};
class stripeGateway : public PaymentGateway{
public:
bool pay(double amount) override{
    if(amount > 1000){
  cout << " Payment of $" << amount << " using stripe : failed "  << endl;   
   return false;
    }
    else{
        cout << " Payment of $" << amount << " using stripe : Success "  << endl;
    }
    return true;
}
};

class PaypalGateway : public PaymentGateway{
public:
bool pay(double amount) override{
    if(amount < 10){
      cout << " Payment of $" << amount << " using paypal : Failed "  << endl;
    return false;
    }
    else{
         cout << " Payment of $" << amount << " using paypal : Success "  << endl;
    }
    return true;
}
};
class CryptoGateway : public PaymentGateway{
public:
bool pay(double amount) override{
  cout << " Payment of $" << amount << " using crypto : Success "  << endl;
    return true;
}
};
    int main()
{
    PaymentGateway* paygate;

    paygate = new stripeGateway();
    paygate->pay(500); 
    paygate->pay(1000);

    paygate = new PaypalGateway();
    paygate->pay(9);
    paygate->pay(11); 

    paygate= new CryptoGateway();
    paygate->pay(5000);

    delete paygate;

    return 0;
}
