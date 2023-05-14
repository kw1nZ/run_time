#include <iostream>
#include <vector>
#include "run_time.hpp"

void long_job(size_t num_elements) {
    std::vector<size_t> v;
    for (size_t i = 0; i < num_elements; ++i) {
        v.push_back(i);
    }
}

void long_job_s(unsigned short s) {
    long_job(50'000'000 * s);
}

void long_job_ms(unsigned short ms) {
    long_job(5'000'000 * ms);
}

int main() {
    RunTime rt;

    rt.stop();
    long_job_s(1);
    rt.resume();

    long_job_s(1);

    long long elapsed_seconds = rt.elapsed<std::chrono::seconds>();
    std::cout << "1) " << elapsed_seconds << " seconds\n";

    long long elapsed_ms = rt.elapsed();
    std::cout << "2) " << elapsed_ms << " milliseconds\n";

    long long elapsed_microseconds = rt.elapsed<std::chrono::microseconds>();
    std::cout << "3) " << elapsed_microseconds << " microseconds\n";

    long long elapsed_nanoseconds = rt.elapsed<std::chrono::nanoseconds>();
    std::cout << "4) " << elapsed_nanoseconds << " nanoseconds\n";

    return 0;
}
