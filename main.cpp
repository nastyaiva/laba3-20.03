#include <iostream>
#include <cstring>
using namespace std;

class Car {
protected:
    string model;
    int maxSpeed;

public:
    Car(const string& model, int maxSpeed) : model(model), maxSpeed(maxSpeed) {}

    virtual void printInfo() {
        cout << "Model: " << model <<endl;
        cout << "Max Speed: " << maxSpeed << " km/h" <<endl;
    }
};

class Truck : public Car {
private:
    double cargoCapacity;

public:
    Truck(const string& model, int maxSpeed, double cargoCapacity) : Car(model, maxSpeed), cargoCapacity(cargoCapacity) {}

    void printInfo() override {
        Car::printInfo();
        cout << "Cargo Capacity: " << cargoCapacity << " tons" << endl;
    }
};

int main() {
    Car car("Toyota", 200);
    Truck truck("Volvo", 150, 5.0);

    // Статический полиморфизм
    car.printInfo();
    cout <<endl;
    truck.printInfo();

    cout << "\n\n";

    // Динамический полиморфизм
    Car* carPtr = &car;
    carPtr->printInfo();
    cout << endl;

    Car* truckPtr = &truck;
    truckPtr->printInfo();

    return 0;
}

