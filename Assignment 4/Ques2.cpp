#include<iostream>
using namespace std;
#include<iomanip>
#include <string>
#include<vector>


class Vehicle {
protected:
    string registrationNo;
    string ownerName;
    int yearOfManufacture;
    double kmDriven;

public:
    Vehicle(const string& reg, const string& owner,
            int year, double km);

    virtual double fuelCost(double kmToTravel) const = 0;

    virtual void describe() const;

    virtual string vehicleType() const = 0;

    virtual ~Vehicle();

    double getKmDriven() const;

    string getRegNo() const;

	string getOwnerName() const ;
};
Vehicle::Vehicle(const string& reg, const string& owner,
                 int year, double km)
    : registrationNo(reg),
      ownerName(owner),
      yearOfManufacture(year),
      kmDriven(km)
{
		cout << "[Vehicle Constructor] "
	         << registrationNo << " : "
	         << ownerName << endl;
}

Vehicle::~Vehicle()
{
	cout << "[Vehicle Destructor] "
	         << registrationNo << endl;
}

void Vehicle::describe() const
{
    cout << "Registration No: " << registrationNo <<endl;
    cout << "Owner Name: " << ownerName << endl;
    cout << "Year: " << yearOfManufacture << endl;
    cout << "KM Driven: " << kmDriven << endl;
}

double Vehicle:: getKmDriven()const{
	return kmDriven;

}

string Vehicle :: getRegNo() const{
   	return registrationNo;
   }


string Vehicle :: getOwnerName() const {
		return ownerName;
	}


class Car : public Vehicle
{
private:
    string fuelType;
    double mileageKmpl;

public:
    Car(const string& reg, const string& owner,
        int year, double km,
        const string& fuel, double mileage);

    double fuelCost(double kmToTravel) const override;

    string vehicleType() const override;

    void describe() const override;
};

Car::Car(const string& reg, const string& owner,
         int year, double km,
         const string& fuel, double mileage)
    : Vehicle(reg, owner, year, km),
      fuelType(fuel),
      mileageKmpl(mileage)
{
}
double Car::fuelCost(double kmToTravel) const
{
    double fuelPrice;

    if (fuelType == "Petrol")
        fuelPrice = 106.00;
    else
        fuelPrice = 93.00;

    return (kmToTravel / mileageKmpl) * fuelPrice;
}

string Car::vehicleType() const
{
    return "Car";
}
void Car::describe() const
{
    Vehicle::describe();

    cout << "Fuel Type: " << fuelType << endl;
    cout << "Mileage: " << mileageKmpl << " km/l" << endl;
}


class Truck : public Vehicle
{
protected:
    double payloadCapacityTons;
    double fuelEfficiencyKmpl;

public:
    Truck(const string& reg, const string& owner,
          int year, double km,
          double payload, double efficiency);

    virtual ~Truck();
    double fuelCost(double kmToTravel) const override;

    string vehicleType() const override;

    void describe() const override;
};

Truck::Truck(const string& reg, const string& owner,
             int year, double km,
             double payload, double efficiency)
    : Vehicle(reg, owner, year, km),
      payloadCapacityTons(payload),
      fuelEfficiencyKmpl(efficiency)
{
	cout << "[Truck Constructor] "
	         << registrationNo << endl;
}
double Truck::fuelCost(double kmToTravel) const
{
    double effectiveEfficiency =
        fuelEfficiencyKmpl *
        (1 - 0.05 * payloadCapacityTons);

    return (kmToTravel / effectiveEfficiency) * 93.00;
}
string Truck::vehicleType() const
{
    return "Truck";
}
void Truck::describe() const
{
    Vehicle::describe();

    cout << "Payload Capacity: "
         << payloadCapacityTons << " tons" << endl;

    cout << "Fuel Efficiency: "
         << fuelEfficiencyKmpl << " km/l" << endl;
}
Truck::~Truck()
{
    cout << "[Truck Destructor] "
         << registrationNo << endl;
}

class ElectricTruck : public Truck
{
private:
    double batteryCapacityKWh;
    double rangePerChargeKm;

public:
    ElectricTruck(const string& reg, const string& owner,
                  int year, double km,
                  double payload, double efficiency,
                  double battery, double range);
    ~ElectricTruck();
    double fuelCost(double kmToTravel) const override;

    string vehicleType() const override;

    void describe() const override;
    double batteryStatus(double tripKm) const;
};

ElectricTruck::ElectricTruck(
    const string& reg,
    const string& owner,
    int year,
    double km,
    double payload,
    double efficiency,
    double battery,
    double range)
    : Truck(reg, owner, year, km, payload, efficiency),
      batteryCapacityKWh(battery),
      rangePerChargeKm(range)
{
	 cout << "[ElectricTruck Constructor] "
	         << registrationNo << endl;
}

ElectricTruck::~ElectricTruck()
{
    cout << "[ElectricTruck Destructor] "
         << registrationNo << endl;
}
double ElectricTruck::fuelCost(double kmToTravel) const
{
    return (kmToTravel / rangePerChargeKm)
           * batteryCapacityKWh
           * 9.50;
}

string ElectricTruck::vehicleType() const
{
    return "Electric Truck";
}

void ElectricTruck::describe() const
{
    Truck::describe();

    cout << "Battery Capacity: "
         << batteryCapacityKWh << " kWh" << endl;

    cout << "Range Per Charge: "
         << rangePerChargeKm << " km" << endl;
}
double ElectricTruck::batteryStatus(double tripKm) const
{
    double remaining =
        100.0 * (1.0 - tripKm / rangePerChargeKm);

    if (remaining < 0)
    {
        remaining = 0;
    }

    return remaining;
}

class Van : public Vehicle
{
private:
    int seatingCapacity;
    double mileageKmpl;

public:
    Van(const string& reg, const string& owner,
        int year, double km,
        int seating, double mileage);

    double fuelCost(double kmToTravel) const override;

    string vehicleType() const override;

    void describe() const override;
};

Van::Van(const string& reg, const string& owner,
         int year, double km,
         int seating, double mileage)
    : Vehicle(reg, owner, year, km),
      seatingCapacity(seating),
      mileageKmpl(mileage)
{
}
double Van::fuelCost(double kmToTravel) const
{
    return (kmToTravel / mileageKmpl) * 106.00;
}
string Van::vehicleType() const
{
    return "Van";
}
void Van::describe() const
{
    Vehicle::describe();

    cout << "Seating Capacity: "
         << seatingCapacity << endl;

    cout << "Mileage: "
         << mileageKmpl << " km/l" << endl;
}

void printFleetReport(const vector<Vehicle*>& fleet,
                      double tripKm)
{
    cout << "\n===== FLEET REPORT - Trip Distance: "
         << tripKm << " km =====" << endl;

    cout << left
         << setw(12) << "Reg"
         << setw(18) << "Type"
         << setw(20) << "Owner"
         << setw(12) << "Km Driven"
         << endl;

    cout << "------------------------------------------------------------"
         << endl;



    for (Vehicle* vehicle : fleet)
    {
        cout << left
             << setw(12) << vehicle->getRegNo()
             << setw(18) << vehicle->vehicleType()
             << setw(20) << vehicle->getOwnerName()
             << setw(12) << fixed << setprecision(0)
             << vehicle->getKmDriven()
             << endl;
    }

    cout << "\n===== FUEL / CHARGE COST ESTIMATE =====" << endl;

    double minimumCost = 0;
    Vehicle* mostEfficient = nullptr;

    bool found = true;


    for (Vehicle* vehicle : fleet)
    {
        // Runtime polymorphism happens here
        double cost = vehicle->fuelCost(tripKm);

        cout << fixed << setprecision(2);

        cout << vehicle->getRegNo()
             << " (" << vehicle->vehicleType() << ")"
             << " : Rs. " << cost;



        ElectricTruck* electricTruck =
            dynamic_cast<ElectricTruck*>(vehicle);

        if (electricTruck != nullptr)
        {
            cout << " [Battery: "
                 << fixed << setprecision(0)
                 << electricTruck->batteryStatus(tripKm)
                 << "% charged]";
        }

        cout << endl;


        if (found || cost < minimumCost)
        {
            minimumCost = cost;
            mostEfficient = vehicle;
            found = false;
        }
    }


    if (mostEfficient != nullptr)
    {
        cout << "\nMost Efficient Vehicle: "
             << mostEfficient->getRegNo()
             << " (" << mostEfficient->vehicleType() << ")"
             << " - Rs. "
             << fixed << setprecision(2)
             << minimumCost
             << " for "
             << tripKm
             << " km"
             << endl;
    }
}
int main()
{


    cout << "===== PART B =====" << endl;


        {
            ElectricTruck ec(
                "V-ET001",
                "Green Logistics",
                2024,
                10000,
                5.0,
                8.0,
                500.0,
                400.0
            );


            cout << "...scope ends..." << endl;
        }


  

        cout << endl;
        cout << "===== PART C =====" << endl;


        vector<Vehicle*> fleet;


    

        fleet.push_back(
            new Car(
                "KA01AA001",
                "Ramesh Kumar",
                2022,
                45200,
                "Petrol",
                15.0
            )
        );


      

        fleet.push_back(
            new Truck(
                "MH04BB002",
                "Shyam Logistics",
                2021,
                123500,
                5.0,
                10.0
            )
        );


   

        fleet.push_back(
            new ElectricTruck(
                "GJ07CC003",
                "Green Fleet Co",
                2024,
                89000,
                3.0,
                8.0,
                500.0,
                400.0
            )
        );


      

        fleet.push_back(
            new Van(
                "DL05DD004",
                "Vijay Transport",
                2023,
                67800,
                8,
                12.0
            )
        );


 

        fleet.push_back(
            new Car(
                "TN10EE005",
                "Arun Travels",
                2020,
                78200,
                "Diesel",
                18.0
            )
        );


      double tripKm = 200.0;

        printFleetReport(fleet, tripKm);

        cout << endl;
        cout << "===== CLEANUP =====" << endl;


        for (Vehicle* vehicle : fleet)
        {
            delete vehicle;
        }


        fleet.clear();


        cout << "All vehicles deleted." << endl;

    return 0;
}
