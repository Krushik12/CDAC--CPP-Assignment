//Problem 4 — Startup Configuration via CLI

#include <iostream>
using namespace std;

void Result(int warn, int critical, int readings)
{
    

    int normal = 0;
    int warning = 0;
    int criticalCount = 0;
    int shutdown = 0;

    for (int i = 0; i < readings; i++)
    {
        int temperature = rand() % 70;

        if (temperature < warn)
        {
            normal++;
        }
        else if (temperature < critical)
        {
            warning++;
        }
        else if (temperature < 60)
        {
            criticalCount++;
        }
          else
        {
            shutdown++;
        }
    }

    cout << "Results : Normal:" << normal
         << " Warning:" << warning
         << " Critical:" << criticalCount
         << " Shutdown:" << shutdown << endl;
}

int main(int argc, char* argv[])
{
    
    if (argc != 4)
    {
        cout << "Usage : ./sensor_monitor <warn_threshold> "
             << "<critical_threshold> <num_readings>" << endl;

        cout << "Error : Missing arguments." << endl;

        return 1;
    }

    
    int warn = stoi(argv[1]);
    int critical = stoi(argv[2]);
    int num_readings = stoi(argv[3]);

   
    if (warn >= critical)
    {
        cout << "Error : Warn threshold must be less than "
             << "critical threshold." << endl;

        return 1;
    }

    if (num_readings < 1 || num_readings > 500)
    {
        cout << "Error : Number of readings must be between 1 and 500."
             << endl;

        return 1;
    }

    cout << "Config : Warn=" << warn
         << "'C Critical=" << critical
         << "'C Readings=" << num_readings << endl;

         Result(warn,critical,num_readings);



}
