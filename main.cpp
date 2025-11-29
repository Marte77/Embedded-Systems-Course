// Learn with Examples, 2020, MIT license
#include <systemc> // include the systemC header file
using namespace sc_core; // use namespace
#include "nonassignment_exs/simple_process_ex.h"
#include "ex1lec4slides/top.h"
#include "assignmentcode/31/ModuleSingle.h"
#include "assignmentcode/32/ModuleDouble.h"
#include "assignmentcode/33/ModuleTCP.h"
#include "assignmentcode/33/TopTCP.h"
#include "assignmentcode/34/AvalonSTTop.h"
#include "assignmentcode/35/Top35.h"
#include "assignment3/StatesAsSingletons.h"

/*void hello1() { // a normal c++ function
    std::cout << "Hello world using approach 1" << std::endl;
}

struct HelloWorld : sc_module { // define a systemC module
    SC_CTOR(HelloWorld) {// constructor function, to be explained later
        SC_METHOD(hello2); // register a member function to the kernel
    }
    void hello2(void) { // a function for systemC simulation kernel, void inside () can be omitted
        std::cout << "Hello world using approach 2" << std::endl;
    }
};

int sc_main(int, char*[]) { // entry point
    hello1(); // approach #1: manually invoke a normal function
    HelloWorld helloworld("helloworld"); // approach #2, instantiate a systemC module
    sc_start(); // let systemC simulation kernel to invoke helloworld.hello2();
    return 0;
}
*/
int sc_main(int, char*[]) {
    //simple_process_ex ex("ex1");
    //sc_start();
    //Top top("top");
    //sc_start();
    if (true) {
        EmbeddedSystemX system;
        std::cout << "Initial State: " << system.getStateName() << "\n\n";

        // Test sequence following the state diagram
        std::cout << "--- Testing Power-On SelfTest ---\n";
        system.selfTestOk();
        std::cout << "Current State: " << system.getStateName() << "\n\n";

        std::cout << "--- Testing Initialization ---\n";
        system.initialized();
        std::cout << "Current State: " << system.getStateName() << "\n\n";

        std::cout << "--- Testing Configuration from Ready ---\n";
        system.configure();
        std::cout << "Current State: " << system.getStateName() << "\n\n";

        std::cout << "--- Testing Configuration End ---\n";
        system.configurationEnded();
        std::cout << "Current State: " << system.getStateName() << "\n\n";

        std::cout << "--- Testing Start/Run (Ready to Operational) ---\n";
        system.start();
        std::cout << "Current State: " << system.getStateName() << "\n\n";

        std::cout << "--- Testing RealTimeLoop Mode Changes ---\n";
        RealTimeLoop* rtl = system.getRealTimeLoop();
        std::cout << "Current Mode: " << rtl->getCurrentMode() << "\n";
        rtl->changeMode(2);
        std::cout << "Current Mode: " << rtl->getCurrentMode() << "\n";
        rtl->eventX();
        rtl->changeMode(3);
        std::cout << "Current Mode: " << rtl->getCurrentMode() << "\n";
        rtl->eventX();
        rtl->changeMode(1);
        std::cout << "Current Mode: " << rtl->getCurrentMode() << "\n";
        rtl->eventX();
        std::cout << "\n";

        std::cout << "--- Testing Suspend (Operational to Suspended) ---\n";
        system.suspend();
        std::cout << "Current State: " << system.getStateName() << "\n\n";

        std::cout << "--- Testing Resume (Suspended back to Operational) ---\n";
        system.resume();
        std::cout << "Current State: " << system.getStateName() << "\n\n";

        std::cout << "--- Testing Configure from Operational ---\n";
        system.configure();
        std::cout << "Current State: " << system.getStateName() << "\n\n";

        std::cout << "--- Testing Restart from Configuration ---\n";
        system.restart();
        std::cout << "Current State: " << system.getStateName() << "\n\n";

        std::cout << "--- Testing SelfTest Failure ---\n";
        system.selfTestFailed(42);
        std::cout << "Current State: " << system.getStateName() << "\n\n";

        std::cout << "--- Testing Restart from Failure ---\n";
        system.restart();
        std::cout << "Current State: " << system.getStateName() << "\n\n";

        return 0;
    }
    else {
        int exercise = 31;
        switch (exercise) {
            case 31: {
                ModuleSingle m = ModuleSingle("Module_Single");
                sc_start(200, SC_MS);
                break;
            }
            case 32: {
                ModuleDouble m = ModuleDouble("Module_Double");
                sc_start(200, SC_MS);
                break;
            }
            case 33: {
                TopTCP top = TopTCP("Top");
                sc_start(200, SC_MS);
                break;
            }
            case 34: {
                AvalonSTTop top = AvalonSTTop("STTop");
                sc_start(500, SC_NS);
                break;
            }
            case 35: {
                Top35 top = Top35("Top35");
                sc_start(500, SC_NS);
                break;
            }
            default: {
                std::cout << "No exercise available for " << exercise << std::endl;
            }
        }
        return 0;
    }
}