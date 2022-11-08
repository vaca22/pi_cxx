#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;


#define NUM 10000000000


float fRand(float fMin, float fMax) {
    float f = (float) rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}


int main() {
    auto start = high_resolution_clock::now();
    long int s = 0;
    srand(time(NULL));

    for (long int k = 0; k < NUM; k++) {
        float x, y;
        x = fRand(-1, 1);
        y = fRand(-1, 1);
        if (x * x + y * y <= 1) {
            s++;
        }
    }
    long double p = (long double) s /  (long double)NUM*4;
    printf("area: %.20Lf\n",p);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    return 0;
}
