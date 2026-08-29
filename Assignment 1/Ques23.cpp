//Problem 2.3 — Hardware Register Access


#include <iostream>
using namespace std;

int main()
{
    int statusReg = 0b10110001;
    int controlReg = 0b00000000;
    int dataReg = 0b11001010;

    
    // regPtr1 : Pointer to const int
    // The value cannot be changed through this pointer.
    // But the pointer itself can point somewhere else.
    

    const int* regPtr1 = &statusReg;

    cout << "--- regPtr1 : const int* ---" << endl;
    cout << "Status Register : " << *regPtr1 << endl;

    // *regPtr1 = 10;
    // ERROR: Cannot modify statusReg through regPtr1
    // because regPtr1 is a pointer to const int.

    // regPtr1 = &dataReg;
    // This is actually VALID.
    // A const int* means the VALUE is constant through the pointer,
    // but the pointer itself can be changed.
    regPtr1 = &dataReg;

    cout << "After repointing : " << *regPtr1 << endl;


    // =====================================================
    // regPtr2 : Constant pointer to int
    // Pointer cannot be changed, but the value can be changed.
    // =====================================================

    int* const regPtr2 = &controlReg;

    cout << "\n--- regPtr2 : int* const ---" << endl;
    cout << "Control Register Before : " << *regPtr2 << endl;

    *regPtr2 = 255;

    cout << "Control Register After : " << *regPtr2 << endl;

    // regPtr2 = &dataReg;
    // ERROR: Cannot change the address stored in regPtr2
    // because regPtr2 is a constant pointer.


    // =====================================================
    // regPtr3 : Constant pointer to const int
    // Neither the value nor the pointer can be changed.
    // =====================================================

    const int* const regPtr3 = &statusReg;

    cout << "\n--- regPtr3 : const int* const ---" << endl;
    cout << "Status Register : " << *regPtr3 << endl;

    // *regPtr3 = 100;
    // ERROR: Cannot modify the value through regPtr3
    // because it points to const int.

    // regPtr3 = &dataReg;
    // ERROR: Cannot change the address stored in regPtr3
    // because the pointer itself is const.

    return 0;
}
