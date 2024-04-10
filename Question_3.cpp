// This Homework was completed by Aaron Kern and worked on with Marty Mullen and Eric Valentine

#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <chrono>
#include <atomic>
#include <condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;
queue<int> ATC_queue;
queue<int> landing_queue;
atomic<bool> awake(true);

void approachingPlanes()
{
    mtx.lock();
    ATC_queue.push(1);
    ATC_queue.push(2);
    ATC_queue.push(3);
    ATC_queue.push(4);
    ATC_queue.push(5);
    ATC_queue.push(6);
    ATC_queue.push(7);
    ATC_queue.push(8);
    ATC_queue.push(9);
    ATC_queue.push(10);
    mtx.unlock();

    cout << "Aircraft 1 is approaching" << endl;
    cout << "Aircraft 2 is approaching" << endl;
    cout << "Aircraft 3 is approaching" << endl;
    cout << "Aircraft 4 is approaching" << endl;
    cout << "Aircraft 5 is approaching" << endl;
    cout << "Aircraft 6 is approaching" << endl;
    cout << "Aircraft 7 is approaching" << endl;
    cout << "Aircraft 8 is approaching" << endl;
    cout << "Aircraft 9 is approaching" << endl;
    cout << "Aircraft 10 is approaching" << endl;
}

void landingPlanes()
{
    vector<int> diverted;

    while (true)
    {
        mtx.lock();
        while (!ATC_queue.empty() && landing_queue.size() < 3) {
            int planeToLand = ATC_queue.front();
            ATC_queue.pop();
            landing_queue.push(planeToLand);
            cout << "Aircraft " << planeToLand << " queued for landing" << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }

        if (landing_queue.size() >= 3) {
            while (!ATC_queue.empty()) {
                int planeToDivert = ATC_queue.front();
                ATC_queue.pop();
                diverted.push_back(planeToDivert);
                cout << "Aircraft " << planeToDivert << " is diverted to another airport" << endl;
            }
        }
        mtx.unlock();
    }
}

void landingProcess()
{
    while (true)
    {
        mtx.lock();
        if (!landing_queue.empty())
        {
            int planeToLand = landing_queue.front();
            landing_queue.pop();
            mtx.unlock();
            cout << "Aircraft " << planeToLand << " is landing" << endl;
        }
        else
        {
            mtx.unlock();
        }

        this_thread::sleep_for(chrono::seconds(1));
    }
}

void printATCAwake() {
    while (true) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return !awake; });

        cout << "Air Traffic Controller is awake." << endl;
        awake = true;

        lock.unlock();
    }
}

void checkATCSleep()
{
    this_thread::sleep_for(chrono::seconds(1));
    while (true)
    {
        mtx.lock();
        bool allPlanesLanded = ATC_queue.empty() && landing_queue.empty();
        mtx.unlock();

        if (allPlanesLanded)
        {
            cout << "The Air Traffic Controller is asleep" << endl;
            awake = false;
            break;
        }
        this_thread::sleep_for(chrono::seconds(1));
    }
}

int main()
{
    thread t1(printATCAwake);
    thread t2(approachingPlanes);
    thread t3(landingPlanes);
    thread t4(landingProcess);
    thread t5(checkATCSleep);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    return 0;
}