//Question 3 — Game Engine Entity System
//Part B — Namespaces

#include<iostream>
using namespace std;

namespace Physics {
    double clamp(double val, double min, double max){
        
         if(val >= min and val <= max){
            return val;
        }else if(val < min){
            return min;
        }else{
            return max;
        }
    }
    double lerp(double a, double b, double t){
        
        return a + (b-a) * t;
    }
}

namespace GameMath {
    int clamp(int val, int min, int max){
       
         if(val >= min and val <= max){
            return val;
        }else if(val < min){
            return min;
        }else{
            return max;
        }
    }
    double lerp(double a, double b, double t){
        
        return a + (b-a) * t;
    }
}
int main()
{
    double velocity = Physics::clamp(125.5, 0.0, 100.0);
    double physicsResult = Physics::lerp(10.0, 20.0, 0.5);

    cout << "Physics Clamp: " << velocity << endl;
    cout << "Physics Lerp: " << physicsResult << endl;


    int health = GameMath::clamp(150, 0, 100);
    double uiResult = GameMath::lerp(0.0, 100.0, 0.25);

    cout << "GameMath Clamp: " << health << endl;
    cout << "GameMath Lerp: " << uiResult << endl;

    {
        using namespace Physics;

        cout << "\nInside Physics block:" << endl;
        cout << "Clamp: " << clamp(150.0, 0.0, 100.0) << endl;
        cout << "Lerp: " << lerp(20.0, 40.0, 0.5) << endl;
    }

        


    return 0;
}