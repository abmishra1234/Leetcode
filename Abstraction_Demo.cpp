using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<list>
#include<forward_list>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstring>
#include<climits>

#define FORREF
#ifndef FORREF

// Data Abstraction
class Employee {
private:
    string mName;
    int mId;

public:
    Employee(string _name, int _id) 
        : mName(_name), mId(_id) { }
    string getName() {
        return mName;
    }
    void setName(string _name) {
        mName = _name;
    }
    int getId() {
        return mId;
    }
    void setId(int _id) {
        mId = _id;
    }
};

// Functional / Process Abstraction
class DemoFuncAbs {
private:
    //
    // Power On
    bool power_on;
    int acce_val;
    const int max_acce_val = 150;
    // internal methods 
    void create_Spark(bool eng_state) {
        if(eng_state) cout << "Getting Engine Off..." << endl;
        else cout << "Getting Engine On..." << endl;
    }
    void acc_inc() {
        cout << "Car is Acceleratd" << endl;
        if (acce_val < max_acce_val) acce_val = min(acce_val+5,max_acce_val);
    }
    void acc_dec() {
        cout << "Car is De-acceleratd" << endl;
        if (acce_val > 0) acce_val = max(0, acce_val - 5);
    }

public:
    DemoFuncAbs() : power_on(false), acce_val(0) {}

    // methods
    /*
        if it is off than return false
        it it is on after this method than
        return true;
    */
    bool ignition() {
        create_Spark(power_on);
        return !power_on;
    }

    // dir might be pressed (true) or released(false)
    int accelerate(bool dir) {
        if (dir) acc_inc();
        else acc_dec();
        return acce_val;
    }
};


int main(void)
{
    Employee emp("abinash", 88888);
    cout << "name = " << emp.getName() << endl;
    cout << "id = " << emp.getId() << endl;

    // Demo Ignition and Acceleration
    DemoFuncAbs dfa;
    bool engine_state = dfa.ignition();
    cout << (engine_state) ? cout << "\nEngine On\n" : cout << "\nEngine is Off\n" << endl;
    dfa.accelerate(true);

    return 0;
}

#endif // FORREF