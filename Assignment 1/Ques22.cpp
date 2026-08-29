//Problem 2.2 — Signal Processing Pipeline

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void displaySignal(double *signal, int n)
{
    double *ptr = signal;

    for (int i = 0; i < n; i++)
    {
        cout << *ptr << " ";
        ptr++;
    }

    cout << endl;
}
double computeRMS(double *signal, int n)
{
    double sum = 0.0;

    double *ptr = signal;

    for (int i = 0; i < n; i++)
    {
        sum += (*ptr) * (*ptr);
        ptr++;
    }

    return sqrt(sum / n);
}

void normalise(double *signal, int n)
{
    double maxValue = 0.0;

    double *ptr = signal;

    
    for (int i = 0; i < n; i++)
    {
        if (abs(*ptr) > maxValue)
        {
            maxValue = abs(*ptr);
        }

        ptr++;
    }


    ptr = signal;

    for (int i = 0; i < n; i++)
    {
        *ptr = *ptr / maxValue;
        ptr++;
    }
}
int countZeroCrossings(double *signal, int n)
{
    int count = 0;

    double *ptr = signal;

    for (int i = 0; i < n - 1; i++)
    {
        if ((*ptr < 0 && *(ptr + 1) > 0) ||
            (*ptr > 0 && *(ptr + 1) < 0))
        {
            count++;
        }

        ptr++;
    }

    return count;
}
void applyGain(double *signal, int n, double gainFactor)
{
    double *ptr = signal;

    for (int i = 0; i < n; i++)
    {
        *ptr = *ptr * gainFactor;
        ptr++;
    }
}

int main()
{
    double signal[] = {0.5, -1.2, 0.8, -0.3, 1.0, -0.9, 0.1};

    int n = 7;

    

    cout << "Original Signal : ";
    displaySignal(signal, n);

    
    double rms = computeRMS(signal, n);
    cout << "RMS : " << rms << endl;

    int crossings = countZeroCrossings(signal, n);
    cout << "Zero Crossings : " << crossings << endl;
    
    normalise(signal, n);
    cout << "After Normalise : ";
    displaySignal(signal, n);

    
    double gainFactor = 2.0;
    applyGain(signal, n, gainFactor);

    cout << "After Gain (" << gainFactor << ") : ";
    displaySignal(signal, n);
}
