#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>                                  

int counter = 0; // shared by every thread
std::mutex m;
std::mutex m2;

void say(const char* name) { std::cout << name << " running\n"; }

// NEW: no lock, so it's a data race
void addUnsafe() {
    for (int i = 0; i < 100000; ++i)
        ++counter;
}

// NEW: lock_guard locks at construction, unlocks at end of scope
void addLockGuard() {
    for (int i = 0; i < 100000; ++i) {
        std::lock_guard<std::mutex> lk(m);
        ++counter;
    }
}

// NEW: unique_lock is the same, but you can unlock early
void addUniqueLock() {
    for (int i = 0; i < 100000; ++i) {
        std::unique_lock<std::mutex> lk(m);
        ++counter;
        lk.unlock(); // released before the end of the scope
        // anything here runs WITHOUT the lock
    }
}

// NEW: scoped_lock locks several mutexes at once, deadlock-free
void addScopedLock() {
    for (int i = 0; i < 100000; ++i) {
        std::scoped_lock lk(m, m2);
        ++counter;
    }
}

// NEW: run f on two threads at once, then print the total
void run(void (*f)(), const char* label) {
    counter = 0;
    std::thread t1(f);
    std::thread t2(f);
    t1.join();
    t2.join();
    std::cout << label << counter << "\n";
}

int main() {
    std::thread a(say, "A");
    a.join();                  // main waits here until A is done
    std::cout << "A joined\n";

    std::thread b(say, "B");
    b.detach();                // main does NOT wait, B runs on its own
    std::cout << "B detached\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // give B time to finish

    run(addUnsafe,     "unsafe:      ");   // NEW
    run(addLockGuard,  "lock_guard:  ");   // NEW
    run(addUniqueLock, "unique_lock: ");   // NEW
    run(addScopedLock, "scoped_lock: ");   // NEW
    return 0;
}