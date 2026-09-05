//============================================================================
// Name        : Ques3.cpp
// Author      : Krushik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

class DataProcessor {

public:
// Pure virtual functions — all subclasses MUST implement these
virtual void loadData( const string& source) = 0 ;
virtual void processData() = 0 ;
virtual void exportResult ( const string& destination) = 0 ;
virtual string processorType() const = 0 ;
virtual int recordCount () const = 0 ;
// Non-pure virtual — base provides a default report format
virtual void printSummary () const ;
virtual ~ DataProcessor () = default;
};

void DataProcessor:: printSummary() const{
	cout << "Processor Type: "<<processorType()<<endl;
	cout << "Record Count : "<<recordCount()<<endl;

}

class CSVProcessor : public DataProcessor {
private:
    vector<string> records;

public:

    void loadData(const string& source) override {
        records.push_back("john,25");
        records.push_back("alice,30");
        records.push_back("bob,22");
        records.push_back("david,35");
        records.push_back("emma,28");
    }

    void processData() override {

        for (string& record : records) {

            for (char& ch : record) {
                ch = toupper(ch);
            }
        }
    }

    void exportResult(const string& destination) override {

        cout << "[CSV EXPORT -> " << destination << "]" << endl;

        for (const string& record : records) {
            cout << record << endl;
        }
    }

    string processorType() const override {
        return "CSV Processor";
    }

    int recordCount() const override {
        return static_cast<int>(records.size());
    }
};


class SensorStreamProcessor : public DataProcessor {
private:
    vector<double> readings;

    double mean;
    double minimum;
    double maximum;

public:
    void loadData(const string& source) override {

        readings.push_back(23.4);
        readings.push_back(21.8);
        readings.push_back(25.1);
        readings.push_back(22.6);
        readings.push_back(24.3);
        readings.push_back(26.0);
        readings.push_back(20.9);
        readings.push_back(23.7);
    }

    void processData() override {

        double total = 0;

        for (double value : readings) {
            total += value;
        }

        mean = total / readings.size();

        minimum = *min_element(readings.begin(), readings.end());

        maximum = *max_element(readings.begin(), readings.end());
    }

    void exportResult(const string& destination) override {

        cout << "[SENSOR EXPORT -> " << destination << "]" << endl;

        cout << "Mean: " << mean << endl;
        cout << "Min: " << minimum << endl;
        cout << "Max: " << maximum << endl;
    }

    string processorType() const override {
        return "Sensor Stream Processor";
    }

    int recordCount() const override {
        return static_cast<int>(readings.size());
    }

	double getMean(){
		return mean;
	}
};



int main() {

	// DataProcessor dp;
	// DataProcessor cannot be instantiated because it is an abstract class.
	// It contains pure virtual functions.

	vector<DataProcessor*> pipeline;
	pipeline.push_back(new CSVProcessor());
	pipeline.push_back(new SensorStreamProcessor ());
	for(auto* p : pipeline)
	{ 	p->loadData("source_data");
		p->processData();
		p->printSummary();
		p-> exportResult("output_dir");
		cout <<"---"<< endl;
	}


	//Bonus:
	// dynamic_cast is safe because it checks the actual runtime type.
	// static_cast would be unsafe here because it does not perform a runtime type check.
	//Casting a SensorStreamProcessor* to CSVProcessor* using static_cast could produce an invalid pointer and cause undefined behavior when used.

	for(auto* p : pipeline) {
	if(auto* csv =dynamic_cast<CSVProcessor*>(p))
		{
		cout <<"Found CSV Processor with "<< csv->recordCount() <<" records."<< endl;
		}
	else if(auto* sensor = dynamic_cast <SensorStreamProcessor*>(p))
		{
		cout << "Found Sensor Processor — Mean: " << sensor->getMean() << endl;
		}
	}


	 for (auto* p : pipeline) {
	        delete p;
	    }
	return 0;
}
