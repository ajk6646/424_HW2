// This Homework was completed by Aaron Kern and worked on with Marty Mullen and Eric Valentine

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <iomanip>
#include <chrono>
#include <thread>

struct Robot 
{
    int id;
};

struct Tool 
{
    char id;
};

void executeTask(const Robot& robot1, const Tool& tool1, const Tool& tool2, const Robot& robot2) 
{
    std::cout << "Robot " << robot1.id << " is grabbing tools " << tool1.id << " and " << tool2.id << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Robot " << robot2.id << " is grabbing tools " << tool1.id << " and " << tool2.id << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Robots " << robot1.id << " and " << robot2.id << " are performing their task \n ";
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Robot " << robot1.id << " is replacing tools " << tool1.id << " and " << tool2.id << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Robot " << robot2.id << " is replacing tools " << tool1.id << " and " << tool2.id << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main() 
{
    
    Robot robots[5] = { {1}, {2}, {3}, {4}, {5} };
    Tool tools[5] = { {'A'}, {'B'}, {'C'}, {'D'}, {'E'} };

    executeTask(robots[0], tools[0], tools[1], robots[2]); 
    executeTask(robots[1], tools[1], tools[2], robots[3]); 
    executeTask(robots[4], tools[4], tools[0], robots[0]); 

    return 0;
}