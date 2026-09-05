//============================================================================
// Name        : Ques1.cpp
// Author      : Krushik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include<string>
#include<utility>
#include <algorithm>
#include<iomanip>
#include <stdexcept>


class LedgerEntry{
private:
	string description;
	double* amounts;
	int days;
	static int totalEntries ;

public:
	// Constructor
	LedgerEntry(const string& desc,int days) : description(desc),days(days){

		amounts = new double[days];
		for (int i=0;i< days;i++){

			amounts[i]=0.0;

			}

		totalEntries++;

		cout << "[LedgerEntry Created]"<<description<<"( "<<days<<" days )"<<endl;

	}
	// Copy Constructor
		LedgerEntry(const LedgerEntry& other) : description(other.description),days(other.days){


			amounts = new double[days];
			for (int i=0;i< days;i++){

				amounts[i]= other.amounts[i];
				}

			totalEntries++;

			cout << "[Copy Constructor]"<<description<<endl;

		}



	//Copy Assignment

		LedgerEntry& operator=(const LedgerEntry& other){

			if(this != &other){
				delete[] amounts;

				description = other.description;
				days = other.days;

				amounts = new double[days];

				for (int i=0;i< days;i++){

					amounts[i]= other.amounts[i];

				}
			}
			cout <<"[Copy Assignment]"<< endl;
			return *this;
		}

		//move assignment constructor
	LedgerEntry(LedgerEntry&& other) noexcept: description(std::move(other.description)),
			amounts(other.amounts),days(other.days)
	{
			other.amounts = nullptr;
			other.days =0;
			other.description = "";

			totalEntries++;

			cout << "[Move Constructor] Ownership transferred from: "<< description << endl;


	}

	//move assignment operator
	LedgerEntry& operator=(LedgerEntry&& other) noexcept
	{
	    if (this != &other) {

	        delete[] amounts;

	        description = std::move(other.description);
	        amounts = other.amounts;
	        days = other.days;

	        other.amounts = nullptr;
	        other.days = 0;
	        other.description = "";
	    }

	    cout << "[Move Assignment] Ownership transferred"<<description<< endl;

	    return *this;
	}

	~LedgerEntry(){

			delete[] amounts;
			totalEntries--;
			cout<<"[Destructor] "<<description<<" Destroyed"<<endl;
		}

	LedgerEntry operator+(const LedgerEntry& other)const{

		int resultDays = min(days, other.days);

		LedgerEntry result(
				description + " + "+ other.description,
				resultDays
		);

		for(int i=0; i< resultDays;i++){

			result[i]= amounts[i]+other.amounts[i];
		}

		return result;


	}

	double getTotal() const{

		double total =0;
		for(int i=0; i< days;i++){

			total += amounts[i];
		}
		return total;
	}


	bool operator ==( const LedgerEntry& other)const
		{
		return getTotal()==other.getTotal();

		}

	bool operator > ( const LedgerEntry& other)const
		{
		return getTotal()>other.getTotal();

		}

	double& operator[](int index){
		if (index < 0 || index >= days)
		    {
		        throw out_of_range("Index out of range");
		    }
		return amounts[index];
	}

	const double& operator[](int index) const{
		if (index < 0 || index >= days)
		    {
		        throw out_of_range("Index out of range");
		    }

		return amounts[index];
	}

	bool isEmpty() const{

		return amounts == nullptr;
	}

	friend ostream& operator <<(ostream& out, const LedgerEntry& entry);



	friend istream& operator >>(istream& in, LedgerEntry& entry);



	static int getTotalEntries(){
		return totalEntries;
	}
};

ostream& operator <<(ostream& out, const LedgerEntry& entry){
	out <<	entry.description << ": [";

	for (int i = 0; i < entry.days;i++){

		out<<fixed<< setprecision(2) <<entry.amounts[i];

		if(i < entry.days-1){
			out<<" , ";
		}

	}

	out << "] Total : "<<fixed<< setprecision(2)<<entry.getTotal();

	return out;
}

istream& operator >>(istream& in, LedgerEntry& entry){
	{
		for(int i=0; i< entry.days;i++){

			in >> entry.amounts[i];
		}

	return in;
	}

}


int LedgerEntry::totalEntries = 0;


int main()
{
    // Objective 1
    LedgerEntry jan("January Sales", 5);

    jan[0] = 1200.50; jan[1] = 3400.00;
    jan[2] = 800.75; jan[3] = 2100.00;
    jan[4] = 650.25;


    LedgerEntry feb("February Sales", 5);

    feb[0] = 900.00; feb[1] = 2200.50; feb[2] = 1750.00;
    feb[3] = 3000.00; feb[4] = 475.50;


    cout << endl;

    cout << jan << endl;
    cout << feb << endl;


    // Objective 2
    LedgerEntry combined = jan + feb;

    cout << "Combined: "
         << combined
         << endl;


    cout << endl;
    // Objective 3
    cout << "Jan == Feb : " << (jan == feb ? "Yes" : "No")<< endl;
    cout << "Jan > Feb : "<< (jan > feb ? "Yes" : "No")<< endl;


    cout << endl;
    // Objective 4
    LedgerEntry moved = std::move(jan);

    cout << "After move, jan.amounts is null: "<< (jan.isEmpty() ? "YES" : "NO")<< endl;

    cout << "Moved entry: "<< moved<< endl;

    cout << endl;

    // Objective 5
    LedgerEntry q1("Q1 Total", 5);

    q1 = move(feb);

    cout << "Q1 (moved from feb): " << q1 << endl;


    // Objective 6

    cout << endl;
    cout << "Live LedgerEntry objects: " << LedgerEntry::getTotalEntries()<< endl;


    return 0;
}
