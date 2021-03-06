#include <random>
#include <iostream>
#include <chrono>

#include "sfc.h"
#include "jsf.h"

void gen_numbers_sfc(unsigned long num){

    sfc64 gen; //sfc rng
    gen.seed(34);
    std::uniform_real_distribution<float> dis(1.0, 100.0);

    auto start = std::chrono::high_resolution_clock::now();
    for (unsigned long n {}; n < num; ++n) {
        // Use dis to transform the random unsigned int generated by gen into a
        // double in [1, 2). Each call to dis(gen) generates a new random double
        std::cout << dis(gen) << "; ";
    }
    auto end = std::chrono::high_resolution_clock::now();

    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    std::cout << "Generated " << num << " random numbers." << std::endl;
    std::cout << "Took " << time_taken << " seconds." << std::endl;

}

void gen_numbers_jsf(unsigned long num){

    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    jsf64 gen(rd()); //jsf rng
    std::uniform_real_distribution<float> dis(1.0, 100.0);

    auto start = std::chrono::high_resolution_clock::now();
    for (unsigned long n {}; n < num; ++n) {
        // Use dis to transform the random unsigned int generated by gen into a
        // double in [1, 2). Each call to dis(gen) generates a new random double
        dis(gen);
    }
    auto end = std::chrono::high_resolution_clock::now();

    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    std::cout << "Generated " << num << " random numbers." << std::endl;
    std::cout << "Took " << time_taken << " seconds." << std::endl;

}

void gen_numbers_mt(unsigned long num){

    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<float> dis(1.0, 100.0);

    auto start = std::chrono::high_resolution_clock::now();
    for (unsigned long n {}; n < num; ++n) {
        // Use dis to transform the random unsigned int generated by gen into a
        // double in [1, 2). Each call to dis(gen) generates a new random double
        dis(gen);
    }
    auto end = std::chrono::high_resolution_clock::now();

    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    std::cout << "Generated " << num << " random numbers." << std::endl;
    std::cout << "Took " << time_taken << " seconds." << std::endl;

}

int main()
{
//     gen_numbers_mt(10000000);
     gen_numbers_sfc(10);
     gen_numbers_sfc(10);
//       gen_numbers_jsf(10000000);
}
