//Problem 2.5 — Drone Navigation Utilities

#include <iostream>
#include <cmath>
#include <iomanip>
#define M_PI 3.14159265358979323846

using namespace std;


inline double distanceBetween(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}


inline double toRadians(double degrees)
{
    return degrees * (M_PI / 180.0);
}


inline double clamp(double value, double minVal, double maxVal)
{
    if (value < minVal)
    {
        return minVal;
    }
    else if (value > maxVal)
    {
        return maxVal;
    }

    return value;
}


inline bool isInSafeZone(double x, double y,
                         double cx, double cy, double radius)
{
    double distance = distanceBetween(x, y, cx, cy);

    return distance <= radius;
}

int main()
{
   
    double homeX = 0.0;
    double homeY = 0.0;

    double radius = 50.0;

   
    double x1 = 30.0;
    double y1 = 40.0;

    double x2 = 40.0;
    double y2 = 30.0;

    double x3 = 60.0;
    double y3 = 20.0;

    cout << fixed << setprecision(2);

    cout << "--- Drone Navigation ---" << endl;
    cout << "Home : (" << homeX << ", " << homeY << ")" << endl;
    cout << "Safe Zone Radius : " << radius << endl;

    
    double distance1 = distanceBetween(homeX, homeY, x1, y1);

    cout << "\nWaypoint 1 : (" << x1 << ", " << y1 << ")" << endl;
    cout << "Distance from Home : " << distance1 << endl;
    cout<<"SafeZone : " << isInSafeZone(x1, y1, homeX, homeY, radius) << endl;
    

    
    double distance2 = distanceBetween(homeX, homeY, x2, y2);

    cout << "\nWaypoint 2 : (" << x2 << ", " << y2 << ")" << endl;
    cout << "Distance from Home : " << distance2 << endl;
    cout<<"SafeZone : " << isInSafeZone(x2, y2, homeX, homeY, radius) << endl;
    

    
    double distance3 = distanceBetween(homeX, homeY, x3, y3);

    cout << "\nWaypoint 3 : (" << x3 << ", " << y3 << ")" << endl;
    cout << "Distance from Home : " << distance3 << endl;
    cout<<"SafeZone : " << isInSafeZone(x3, y3, homeX, homeY, radius) << endl;
    

    return 0;
}
