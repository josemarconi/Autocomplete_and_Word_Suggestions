#include "leitura.hpp"
#include <time.h>   

int main() 
{
    double timespent = 0.0;

    clock_t begin = clock();

    std::ofstream arquivo("dataset/output.data", std::ios::out);
    
    arquivo.close();

    Principal();

    clock_t end = clock();

    timespent += (double)(end - begin) / CLOCKS_PER_SEC;

    cout << endl << timespent << endl;

    return 0;
}