// This Homework was completed by Aaron Kern and worked on with Marty Mullen and Eric Valentine

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <iomanip>
#include <chrono>
#include <thread>

class Sensor
{
public:
    virtual ~Sensor() {}
    virtual void gatherData() const = 0;
    virtual void processData() const = 0;
};

class AerospaceControlSystem
{
private:
    std::vector<Sensor*> sensors;

public:
    void addSensor(Sensor* sensor)
    {
        sensors.push_back(sensor);
    }
    void monitorAndAdjust()
    {
        for (Sensor* sensor : sensors)
        {
            sensor->gatherData();
            sensor->processData();
            std::cout << "Adjusting controls based on sensor data \n";
        }
    }
};

class AoASensor : public Sensor
{
public:
    void gatherData() const override
    {
        std::cout << "Gathering data from angle of attack sensor \n";
    }
    void processData() const override
    {
        std::cout << "Processing data from angle of attack sensor \n";
    }
};

class AltitudeSensor : public Sensor
{
public:
    void gatherData() const override
    {
        std::cout << "Gathering data from altitude sensor \n";
    }
    void processData() const override
    {
        std::cout << "Processing data from altitude sensor \n";
    }
};

class TemperatureSensor : public Sensor
{
public:
    void gatherData() const override
    {
        std::cout << "Gathering data from temperature sensor \n";
    }
    void processData() const override
    {
        std::cout << "Processing data from temperature sensor \n";
    }
};




int main()
{
    AerospaceControlSystem ctrlSys;

    ctrlSys.addSensor(new AoASensor());
    ctrlSys.addSensor(new AltitudeSensor());
    ctrlSys.addSensor(new TemperatureSensor());

    ctrlSys.monitorAndAdjust();

    return 0;
}

