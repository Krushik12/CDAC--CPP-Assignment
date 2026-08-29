#include<iostream>
#include <iomanip>
using namespace std;

void readTemp(double temp[][3]){
      for (int floor = 0; floor < 3; floor++)
    {
        for (int room = 0; room < 3; room++)
        {
            cout << "Enter temperature for Floor "<< floor + 1<< ", Room "<< room + 1 << ": ";

            cin >> temp[floor][room];
             
        }
       
    }

}

void DisplayTemp(double temp[][3]){
    cout << setw(15) << "Room1" << setw(10) << "Room2" << setw(10) << "Room3" << endl;

    for (int floor = 0; floor < 3; floor++)
    {
        cout << "Floor " << floor + 1 << " :";

        for (int room = 0; room < 3; room++)
        {
            cout << fixed << setprecision(1)<< temp[floor][room];
        }
        cout << endl;
    }
}

void HottestRoom(double temp[][3]){

    double hottest = temp[0][0];
    int hottestFloor = 0;
    int hottestRoom = 0;


    for (int floor = 0; floor < 3; floor++)
    {
        

        for (int room = 0; room < 3; room++)
        {
            if(temp[floor][room] > hottest){
                hottest = temp[floor][room];
                hottestFloor = floor;
                hottestRoom = room;
            }
        }
       
    }
        cout << "\nHottest Room  : Floor " << hottestFloor+1
               << ", Room " << hottestRoom+1 << "  ->  " << fixed 
               << setprecision(1) << hottest << "'C" << endl;
}

void HottestFloor(double temp[][3])
{
    double highestAverage = 0;
    int hottestFloor = 0;

    for (int floor = 0; floor < 3; floor++)
    {
        double sum = 0;

        for (int room = 0; room < 3; room++)
        {
            sum += temp[floor][room];
        }

        double average = sum / 3;

        if (average > highestAverage)
        {
            highestAverage = average;
            hottestFloor = floor;
        }
    }

    cout << "Hottest Floor : Floor " << hottestFloor + 1<< "  (avg " << fixed << setprecision(2)<< highestAverage << "'C)" << endl;
}
void countWarning(double temp[][3])
{
    int count = 0;

    for (int floor = 0; floor < 3; floor++)
    {
        for (int room = 0; room < 3; room++)
        {
            if (temp[floor][room] >= 30)
            {
                count++;
            }
        }
    }

    cout << "Rooms at WARNING or above : " << count << endl;
}


int main(){
    
    double temp[3][3];
 

    readTemp(temp);
    DisplayTemp(temp);
    HottestRoom(temp);
    HottestFloor(temp);
    countWarning(temp);
    

    return 0;

        
    


}