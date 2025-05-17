#include <iostream>
#include <string>
using namespace std;
class TimedCounter{
    private:
int counter;
int maxlimit;
int resetunterval;
public:
TimedCounter(int maxlim, int c , int ri){
    counter=c;
    resetunterval=ri;
    if(maxlimit>1){
        maxlimit=10;
    }
    else{
        maxlimit=maxlim;
    }
}
    void increment(){
        if(counter < maxlimit){
            counter++;
        }   
    }
    void Resetifdue(int secondselapsed){
        if(secondselapsed >= resetunterval){
            counter =0;
        }
    }
    int getCounter(){
       return  counter;
    }
    int getmaxLim(){
        return maxlimit;
    }
};
int main(){
    TimedCounter t1(10 , 0,12);
    cout << t1.getCounter() << endl;
    cout << t1.getmaxLim()<< endl;
    t1.increment();
    t1.Resetifdue(19);
    cout << t1.getCounter() << endl;

}

//to maintain consistent behaviour
//encapsulation and constructor logic