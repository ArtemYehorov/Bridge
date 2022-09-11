#include<iostream>
using namespace std;
#pragma region OFF_ON
class Off_On {
public:
    virtual ~Off_On() {}
    virtual string OperationOff_On() const = 0;
};

class ConcreteOff_OnTV : public Off_On {
public:
    string OperationOff_On() const override {
        return "ConcreteOff_OnTV: TV operation.\n";
    }
};

class ConcreteOff_OnPhone : public Off_On {
public:
    string OperationOff_On() const override {
        return "OperationOff_On: Phone operation.\n";
    }
};
#pragma endregion

#pragma region Abstraction
class Abstraction {
protected:
    Off_On* Off_On_;

public:
    Abstraction(Off_On* off_on) : Off_On_(off_on) {
    }

    virtual ~Abstraction() {
    }

    virtual string Operation() const
    {
       return "Abstraction: Base operation with:\n" +
       this->Off_On_->OperationOff_On();
    }
};

class ExtendedAbstraction : public Abstraction {
public:
    ExtendedAbstraction(Off_On* off_on) : Abstraction(off_on) {
    }
    string Operation() const override
    {
       return "ExtendedAbstraction: Extended operation with:\n" +
       this->Off_On_->OperationOff_On();
    }
};

#pragma endregion

void ClientCode(const Abstraction& abstraction) 
{
    cout << abstraction.Operation();
}

int main() {
    Off_On* off_on = new ConcreteOff_OnTV;
    Abstraction* abstraction = new Abstraction(off_on);

    ClientCode(*abstraction);

    cout << endl;

    delete off_on;
    delete abstraction;


    off_on = new ConcreteOff_OnPhone;
    abstraction = new ExtendedAbstraction(off_on);

    ClientCode(*abstraction);

    delete off_on;
    delete abstraction;

    return 0;
}
