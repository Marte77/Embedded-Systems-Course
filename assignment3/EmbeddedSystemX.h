//
// Created by Martinho Tavares Malhão on 25/11/2025.
//

#ifndef A1_EMBEDDEDSYSTEMX_H
#define A1_EMBEDDEDSYSTEMX_H
#include <string>
#include <map>
#include <chrono> // std::chrono::microseconds
#include <thread> // std::this_thread::sleep_for
#include <iostream>
#include <exception>
enum OuterState {
    PowerOnSelfTest,
    Initializing,
    Failure,
    Operational,
};
enum OperationalState {
    UNINITIALIZED,
    Ready,
    Configuration,
    RealTimeLoop,
    Suspended
};
class EmbeddedSystemX;
enum RealTimeLoopState {
    Mode1, Mode2, Mode3
};
class OperationalObject {
    OperationalState state = UNINITIALIZED;
    EmbeddedSystemX *embeddedSystemX;
    RealTimeLoopState realTimeLoopState;
public:
    std::string operationalStateToString() {
        switch (state) {
            case UNINITIALIZED: return "UNINITIALIZED";
            case Ready: return "Ready";
            case Configuration: return "Configuration";
            case RealTimeLoop: return "RealTimeLoop";
            case Suspended: return "Suspended";
            default: return "Unknown";
        }
    }
    void setOperationalState(OperationalState s) {
        std::cout << "Operational State changed from " << operationalStateToString();
        state = s;
        std::cout << " to " << operationalStateToString() << std::endl;
    }
    std::string loopStateToString() {
        switch (realTimeLoopState) {
            case Mode1: return "Mode1";
            case Mode2: return "Mode2";
            case Mode3: return "Mode3";
            default: return "Unknown";
        }
    }
    void setLoopState(RealTimeLoopState s) {
        std::cout << "RealTimeLoopState State changed from " << loopStateToString();
        realTimeLoopState = s;
        std::cout << " to " << loopStateToString() << std::endl;
    }
    OperationalObject(EmbeddedSystemX *e) {
        embeddedSystemX = e;
    }

    void ready() {
        setOperationalState(Ready);
        configure();
    }

    void configurationEnded() {
        setOperationalState(Ready);
        run();
    }
    void suspended() {
        setOperationalState(Suspended);
        std::this_thread::sleep_for(std::chrono::seconds{1});
        std::cout << "ended suspension" << std::endl;
        resume();
    }
    void resume() {
        std::cout << "Resuming" << std::endl;
        run(false);
    }
    void run(bool firstRun);
    void configure();
    void stop();
};

class EmbeddedSystemX {
    OuterState outerState;
    OperationalObject *operational;
    std::string name;
    int counter = -1;
public:
    EmbeddedSystemX() {
        outerState = PowerOnSelfTest;
        name = "Emb";
        operational = new OperationalObject(this);
    }

    void setOuterState(OuterState s) {
        std::cout << "Outer State changed from " << outerStateToString();
        outerState = s;
        std::cout << " to " << outerStateToString() << std::endl;
    }


    void systemSelftest() {
        counter++;
        if (counter % 2 == 0) {
            SelfTestFailed(counter);
        } else {
            SelftestOk();
        }
    }

    void SelftestOk() {
        setOuterState(Initializing);
        Initalized();
    }

    void Initalized() {
        operational->ready();
    }

    void Restart() {
        setOuterState(PowerOnSelfTest);
        systemSelftest();
    }

    void ConfigurationEnded() {

    }

    void Exit() {
        std::cout << "Exit called" << std::endl;
        throw std::logic_error("counter is >10 Ending program now");
    }

    void SelfTestFailed(int errorNumber) {
        setOuterState(Failure);
        if (errorNumber > 10) { Exit(); }
        Restart();
    }
    void ConfigX() {
        std::cout << "ConfigX called" << std::endl;
    }
    void chMode(int mode) {
        std::cout << "chMode called with mode " << mode << std::endl;
    }
    void eventX() {
        std::cout << "EventX called" << std::endl;
    }
    void eventY() {

    }

    void run() {
        systemSelftest();
    }

    std::string outerStateToString() {
        switch (outerState) {
            case PowerOnSelfTest: return "PowerOnSelfTest";
            case Initializing: return "Initializing";
            case Failure: return "Failure";
            case Operational: return "Operational";
            default: return "Unknown";
        }
    }

};

void OperationalObject::stop() {
    setOperationalState(Ready);
    embeddedSystemX->Restart();
}
void OperationalObject::configure() {
    setOperationalState(Configuration);
    std::cout << "read configuration and operate on it" << std::endl;
    embeddedSystemX->ConfigX();
}
void OperationalObject::run(bool firstRun = true) {
    setOperationalState(RealTimeLoop);
    if (firstRun) {
        std::this_thread::sleep_for(std::chrono::seconds{2});
        std::cout << "operational object has to suspend for some reason" << std::endl;
        suspended();
    } else {
        //std::this_thread::sleep_for(std::chrono::seconds{5});
        int i = 0;
        while (i < 6) {
            i++
            std::cout << "Run Iteration = " << i << std::endl;
            embeddedSystemX->chMode(1);
            setLoopState(Mode1);
            embeddedSystemX->eventX();

            embeddedSystemX->chMode(2);
            setLoopState(Mode2);
            embeddedSystemX->eventX();

            embeddedSystemX->chMode(3);
            setLoopState(Mode3);
            embeddedSystemX->eventX();
        }
        std::cout << "operational object will now end" << std::endl;
        stop();
    }
}
#endif //A1_EMBEDDEDSYSTEMX_H
