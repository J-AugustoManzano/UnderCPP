// c07ex07.cpp

#include <iostream>
#include <print>
#include <thread>
#include <mutex>

std::mutex mtx1, mtx2;

void thread1(void) {
    std::lock(mtx1, mtx2);  // Bloqueia ambos os mutexes de forma segura
    std::lock_guard<std::mutex> lg1(mtx1, std::adopt_lock);
    std::lock_guard<std::mutex> lg2(mtx2, std::adopt_lock);
    std::println("Thread 1 executando...");
}

void thread2(void) {
    std::lock(mtx1, mtx2);  // Bloqueia ambos os mutexes de forma segura
    std::lock_guard<std::mutex> lg1(mtx1, std::adopt_lock);
    std::lock_guard<std::mutex> lg2(mtx2, std::adopt_lock);
    std::println("Thread 2 executando...");
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

