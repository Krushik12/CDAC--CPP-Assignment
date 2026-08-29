//Problem 1 — Sensor Reading Classifier

#include<iostream>
using namespace std;

int rangeS(double range){
    if(range < 0){
        return -1;
    }
    else if(range >= 0 && range <= 29){
        return 0;
    }
    else if(range >= 30 && range <= 44){
        return 1;
    }
    else if(range >= 45 && range <= 59){
        return 2;
    }
    else{
        return 3;
    }

}

void Status(int statusLable){
    switch(statusLable){

        case -1:

        cout << " Status Lable : SENSOR_ERROR"<< endl;
        cout << " Action : Sensor fault — check wiring"<< endl;
        break;

        case 0:

        cout << " Status Lable : NORMAL"<< endl;
        cout << " Action : No action required"<< endl;
        break;

        case 1:

        cout << " Status Lable : WARNING"<< endl;
        cout << " Action : Alert sent to supervisor"<< endl;
        break;

        case 2:

        cout << " Status Lable : CRITICAL"<< endl;
        cout << " Action : Cooling system triggered"<< endl;
        break;

        default:

        cout << " Status Lable : SHUTDOWNR"<< endl;
        cout << " Action : Emergency shutdown initiated"<< endl;
        break;




    }

}


int main(){

    double reading;
    cout << "Enter the Reading"<<endl;
    cin >> reading;
    double Fahrenheit = (reading * 9 / 5) + 32;
    cout << "Temperature :" << reading << "'C / " << Fahrenheit <<" F" << endl;


    int statusLables = rangeS(reading);
    Status(statusLables);

    (reading>25)?cout << "Reading : Above Average" : cout <<  "Reading : Below Average"<< endl;

    return 0;



}
