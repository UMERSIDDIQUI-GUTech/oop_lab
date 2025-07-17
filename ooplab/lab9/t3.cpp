
#include <iostream>
using namespace std;
class Time {
private:
    int hours, minutes;
public:
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes = minutes % 60;
        }
    }
    Time operator+(const Time& other) const {
        return Time(hours + other.hours, minutes + other.minutes);
    }
    Time operator-(const Time& other) const {
        int totalMinutes1 = hours * 60 + minutes;
        int totalMinutes2 = other.hours * 60 + other.minutes;
        int diff = totalMinutes1 - totalMinutes2;
        return Time(diff / 60, diff % 60);
    }
    bool operator==(const Time& other) const {
        return (hours == other.hours && minutes == other.minutes);
    }
    bool operator<(const Time& other) const {
        return (hours < other.hours || (hours == other.hours && minutes < other.minutes));
    }
    bool operator>(const Time& other) const {
        return (hours > other.hours || (hours == other.hours && minutes > other.minutes));
    }
    Time& operator++() { 
        minutes++;
        if (minutes >= 60) {
            hours++;
            minutes = 0;
        }
        return *this;
    }
    Time operator++(int) { 
        Time temp = *this;
        ++(*this);
        return temp;
    }
    Time& operator--() { 
        if (minutes == 0) {
            if (hours > 0) {
                hours--;
                minutes = 59;
            }
        } else {
            minutes--;
        }
        return *this;
    }
    Time operator--(int) { 
        Time temp = *this;
        --(*this);
        return temp;
    }
    friend ostream& operator<<(ostream& os, const Time& t) {
        os << t.hours << " hours, " << t.minutes << " minutes";
        return os;
    }
    friend istream& operator>>(istream& is, Time& t) {
        char colon;
        is >> t.hours >> colon >> t.minutes;
        if (t.minutes >= 60) {
            t.hours += t.minutes / 60;
            t.minutes = t.minutes % 60;
        }
        return is;
    }
};

int main(){
    Time t1(2, 30);
    Time t2(1, 45);
    
    Time sum = t1 + t2;
    Time diff = t1 - t2;

    cout << "Time 1: " << t1 << endl;
    cout << "Time 2: " << t2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;

    if (t1 == t2)
        cout << "Waqt barabr hai." << endl;
    else
        cout << "Waqt khrab hai." << endl;

    if (t1 < t2)
        cout << "Time 1 chota lagrha boss  time 2 se ." << endl;
    else if (t1 > t2)
        cout << "Time 1 bara lagrha boss time 2 se ." << endl;

    ++t1; 
    cout << "Time 1 brhao, Time 1: " << t1 << endl;
    t2++;
    cout << "Time 2 brhao , Time 2: " << t2 << endl;
    --t1;
    cout << "Time 1 kam karo, Time 1: " << t1 << endl;
    t2--;
    cout << "Time 2 kam karo, Time 2: " << t2 << endl;

    return 0;
}
