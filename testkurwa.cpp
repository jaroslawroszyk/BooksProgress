#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

int main() {
    time_t now = time(0);

    // convert now to string form
    char *dt = ctime(&now);

    cout << "The local date and time is: " << dt <<"haha" << endl;

    // convert now to tm struct for UTC
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
}