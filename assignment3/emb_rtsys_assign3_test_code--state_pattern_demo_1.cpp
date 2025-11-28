// Code from some internet examples for training of intuition.
// Code demonstrates a state pattern's characteristic structure
// of the functionality and interplay of functions and objects.
// (Intars, 28 nov 2025)
// ---------------------
#include <iostream>

class Machine
{
    class State_of_machine *pointer_to_current_state;

public:
    Machine();  // default constructor
    void set_current_state(State_of_machine  *some_provided_state)
    {   pointer_to_current_state = some_provided_state;    }
    void ON_upon_request();  // declaration of function that will switch machine into state ON
    void OFF_upon_request(); // declaration of function that will switch off the machine
};

class State_of_machine
{
public:
    virtual void ON_upon_request(Machine *given_machine)
    {   std::cout << " state machine is already in a state ON\n";    }

    virtual void OFF_upon_request(Machine *given_machine)
    {   std::cout << " state machine is already in a state OFF\n";   }
};



// specifications of a function void ON()  and  void OFF()
void Machine::ON_upon_request()
{   pointer_to_current_state->ON_upon_request(this);     }
void Machine::OFF_upon_request()
{   pointer_to_current_state->OFF_upon_request(this);    }


class Specific_state_ON:public State_of_machine
{
public:
    Specific_state_ON() {   std::cout << "\n ON state's record constructed in memory|  "; }
    ~Specific_state_ON()    { std::cout << " ON state's record removed\n";  }
    void OFF_upon_request(Machine *given_machine);

};
class Specific_state_OFF:public State_of_machine
{
public:
    Specific_state_OFF() { std::cout << "\n OFF state's record constructed in memory|  ";    }
    ~Specific_state_OFF() { std::cout << " OFF state's record removed\n";    }
    void ON_upon_request(Machine *given_machine)
    {   std::cout << "| switching from OFF state to state ON |";
        given_machine->set_current_state(new Specific_state_ON());
        delete this;
    }
};
void Specific_state_ON::OFF_upon_request(Machine *given_machine)
{   std::cout << "| switching from ON state to state OFF |";
    given_machine->set_current_state(new Specific_state_OFF());
    delete this;
}


// specification of default constructor
Machine::Machine()
{   pointer_to_current_state = new Specific_state_OFF();
    std::cout << std::endl;
}



int main()
{
    void(Machine:: *pointer_to_machine_obj[])() =
    {        Machine::OFF_upon_request, Machine::ON_upon_request    };

    Machine finite_state_machine;
    int user_input_numeric;
    while(1)
    {   std::cout << "Enter on keyboard either 0 or 1:  ";
        std::cin >> user_input_numeric;
        (finite_state_machine.*pointer_to_machine_obj[user_input_numeric])();
    }
}
