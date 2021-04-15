#include <iostream>
#include <ctime>
#include <sys/time.h>
#include <unistd.h>

using namespace std;
unsigned int snooze(unsigned int secs)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    unsigned int t0 = (unsigned int)tv.tv_sec;
    sleep(secs);
    gettimeofday(&tv, NULL);
    unsigned int t1 = (unsigned int)tv.tv_sec;
    cout << "Slept for " << t0 << " of " << t1 << " secs." << endl;
}