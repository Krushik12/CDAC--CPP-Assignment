// Problem 2 — Sensor Log Buffer

#include<iostream>
    #include <iomanip>
    using namespace std;

    void printEnterValue(double arr[], int N, int &errors)
    {
        cout << "Valid readings :";

        for(int i=0; i < N;i++)
        {
            if(arr[i]<0)
            {
                errors++;
                continue;

            }
            cout << arr[i] << " ";


        }
        cout << endl;

    }


    void findFirstCritical(double arr[],int N){

        bool found = false;
        for(int i= 0; i< N;i++)
        {
            if(arr[i]>=45){
                cout << "First CRITICAL : Index"<< i << "->"<< arr[i] <<"'C"<< endl;
                found = true;
                break;
            }

        }
        if(!found){

            cout<<"First CRITICAL : None"<<endl;
        }


    }

    void Compute(double arr[], int N, double &min,double &max, double &average,int &normal, int &warning,int &critical,int &shutdown){

    double sum =0;
    int count = 0;
    bool firstvalid = true;
        
    for (int i=0; i < N; i++){
        if(arr[i]<0){
            continue;
        }
        if(firstvalid){

            min = arr[i];
            max = arr[i];
            firstvalid = false;

        }

        if(arr[i]<min){
            min = arr[i];

        }
        if(arr[i]>max){
            max = arr[i];
            
        }

        sum += arr[i];
        count++;

        if (arr[i] <= 29)
            {
                normal++;
            }
            else if (arr[i] <= 44)
            {
                warning++;
            }
            else if (arr[i] <= 59)
            {
                critical++;
            }
            else
            {
                shutdown++;
            }

    }

    average = sum / count;

    }





    int main(){


        int N;
        double arr[100];
        int errors = 0;

        int normal = 0;
        int warning = 0;
        int critical = 0;
        int shutdown = 0;
        double min, max, average;
        
        cout << " Enter Reading: "<< endl;
        cin >> N;
        
        for (int i = 0;i<N;i++){
            cin>>arr[i];
        }
        cout << "Readings entered : " << N << endl;


        printEnterValue(arr, N,errors);
        cout << "Skipped (errors) : " << errors << endl;

        findFirstCritical(arr,N);

        Compute(arr,N,min,max,average,normal,warning, critical,shutdown);
        cout << fixed << setprecision(2);
        cout << "Min : " << min << "'C" << endl;
        cout << "Max : " << max << "'C" << endl;
        cout << "Avg : " << average << "'C" << endl;

        cout << "Normal:" << normal
            << " Warning:" << warning
            << " Critical:" << critical
            << " Shutdown:" << shutdown << endl;

        return 0;



    }
