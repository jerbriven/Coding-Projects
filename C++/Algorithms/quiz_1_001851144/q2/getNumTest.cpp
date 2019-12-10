#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
// how many times the loops are run, the higher this number
// is, the longer it takes, but the more accurate it gets. 
// max is 4294967295 (using uint32_t)
#define LOOP_REPS 111167295
using namespace std;

int getNumberEqual(const int x[], int n, int desiredValue) {
int count = 0;
if (n <= 0)
    return 0;
else {
    if (x[n - 1] == desiredValue)
    count = 1;
    return getNumberEqual(x, n - 1, desiredValue) + count;
} // end else
} // end getNumberEqual

int main(int argc, char *argv[]) {
    cout.setf(ios_base::fixed); // shows decimals in the output
    cout << "loop_reps: (uint32_t used)  " << LOOP_REPS << endl;
    // reference loop
    clock_t rl_start = clock();
    // loop index is volatile so that the empty loop isn't optimized away
    for(volatile uint32_t rl_index = 0; rl_index < LOOP_REPS; ++rl_index) {
        // empty loop - just to calculate how much time an empty loop needs
    }
    clock_t rl_end = clock();
    double rl_time = difftime(rl_end, rl_start) / CLOCKS_PER_SEC;
    // output the time the reference loop took
    cout << "reference empty loop:   " << rl_time << endl;
    // flops loop
    volatile float a = 1.5;
    volatile float b = 1.6;
    clock_t fl_start = clock();

    int m1[] = {4, 9, 9};
    int m2[] = {1, 3, 5, 8, 20, 12};
    int m3[] = {1, 3, 5, 9, 20, 25, 30, 30, 29, 30, 1, 30};
    for(volatile uint32_t fl_index = 0; fl_index < LOOP_REPS; ++fl_index) {
        getNumberEqual(m1, 3, 1);
        //cout << fl_index << endl;
    }
    
    clock_t fl_end = clock();
    double fl_time = difftime(fl_end, fl_start) / CLOCKS_PER_SEC;
    unsigned long flops = LOOP_REPS / ((fl_time - rl_time) / 2);
    cout << "flops time (clocks per second)  :   " << fl_time << endl;
    cout << "FLOPS:     " << flops << endl;

    fl_start = clock();

    for(volatile uint32_t fl_index = 0; fl_index < LOOP_REPS; ++fl_index) {
        getNumberEqual(m2, 6, 1);
        //cout << fl_index << endl;
    }

    fl_end = clock();
    fl_time = difftime(fl_end, fl_start) / CLOCKS_PER_SEC;
    flops = LOOP_REPS / ((fl_time - rl_time) / 2);
    cout << "flops time (clocks per second)  :   " << fl_time << endl;
    cout << "FLOPS:     " << flops << endl;

    fl_start = clock();

    for(volatile uint32_t fl_index = 0; fl_index < LOOP_REPS; ++fl_index) {
        getNumberEqual(m3, 12, 1);
        //cout << fl_index << endl;
    }

    fl_end = clock();
    fl_time = difftime(fl_end, fl_start) / CLOCKS_PER_SEC;
    flops = LOOP_REPS / ((fl_time - rl_time) / 2);
    cout << "flops time (clocks per second)  :   " << fl_time << endl;
    cout << "FLOPS:     " << flops << endl;
}