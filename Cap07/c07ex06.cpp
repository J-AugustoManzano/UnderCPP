// c07ex06.cpp

#include <iostream>
#include <print>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex mtx1, mtx2;

void thread1(void) {
    mtx1.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Espera 1 segundo
    mtx2.lock();
    std::println("Thread 1 executando...");
    mtx2.unlock();
    mtx1.unlock();
}

void thread2(void) {
    mtx2.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    mtx1.lock();
    std::println("Thread 2 executando...");
    mtx1.unlock();
    mtx2.unlock();
}

int main(void) {
    std::thread t1(thread1);
    std::thread t2(thread2);

    t1.join();
    t2.join();

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}

