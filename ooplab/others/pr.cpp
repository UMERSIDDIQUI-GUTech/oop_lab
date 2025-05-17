// Create a class TimedCounter with the following:
// ● Private attributes:
// ○ counter (int), maxLimit (int), resetInterval (in seconds)
// ● Public:
// ○ Constructor that sets all values; if maxLimit is less than 1, default it to 10
// ○ Method Increment() increases the counter unless it has reached maxLimit
// ○ Method ResetIfDue(int secondsElapsed) → resets counter if secondsElapsed >=
// resetInterval
// ○ Getters for counter and maxLimit, but no setter for maxLimit

// Bonus:
// Why should maxLimit be read-only after construction? What OOP principle does this follow?


#include <iostream>
#include <string>   
using namespace std;
class TimedCounter {
private:
    int counter;
    int maxLimit;
    int resetInterval;
public:
    // Constructor
    TimedCounter(int limit, int interval) {
        maxLimit = (limit < 1) ? 10 : limit; // Default to 10 if limit < 1
        resetInterval = interval;
        counter = 0;
    }

    // Increment method
    void Increment() {
        if (counter < maxLimit) {
            counter++;
        }
    }

    // ResetIfDue method
    void ResetIfDue(int secondsElapsed) {
        if (secondsElapsed >= resetInterval) {
            counter = 0;
        }
    }

    // Getters
    int getCounter() const {
        return counter;
    }

    int getMaxLimit() const {
        return maxLimit;
    }
};
int main() {
    TimedCounter tc(5, 10); // maxLimit = 5, resetInterval = 10 seconds
    tc.Increment();
    tc.Increment();
    cout << "Counter: " << tc.getCounter() << endl; // Should print 2

    tc.ResetIfDue(12); // Reset due to 12 seconds elapsed
    cout << "Counter after reset: " << tc.getCounter() << endl; // Should print 0

    return 0;
}