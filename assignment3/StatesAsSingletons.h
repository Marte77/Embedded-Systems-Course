//
// Created by Martinho Tavares Malhão on 27/11/2025.
//

#ifndef A1_STATESASSINGLETONS_H
#define A1_STATESASSINGLETONS_H

#include <iostream>
#include <memory>
#include <string>

class EmbeddedSystemX;
class RealTimeLoop;

// ==================== EMBEDDED SYSTEM STATE CLASSES ====================

class EmbeddedSystemXState {
protected:
    EmbeddedSystemX* context;

public:
    EmbeddedSystemXState(EmbeddedSystemX* ctx) : context(ctx) {}
    virtual ~EmbeddedSystemXState() = default;

    virtual void selfTestOk() = 0;
    virtual void initialized() = 0;
    virtual void restart() = 0;
    virtual void selfTestFailed(int errorNo) = 0;
    virtual void configure() = 0;
    virtual void configurationEnded() = 0;
    virtual void start() = 0;
    virtual void suspend() = 0;
    virtual void resume() = 0;
    virtual void exit() = 0;
    virtual void stop() = 0;
};

class PowerOnSelfTestState : public EmbeddedSystemXState {
private:
    static PowerOnSelfTestState* instance;
    PowerOnSelfTestState(EmbeddedSystemX* ctx) : EmbeddedSystemXState(ctx) {}

public:
    static PowerOnSelfTestState* getInstance(EmbeddedSystemX* ctx) {
        if (!instance) {
            instance = new PowerOnSelfTestState(ctx);
        }
        instance->context = ctx;
        return instance;
    }

    void selfTestOk() override;
    void initialized() override { std::cout << "  [PowerOnSelfTest] initialized() - Invalid event\n"; }
    void restart() override;
    void selfTestFailed(int errorNo) override;
    void configure() override { std::cout << "  [PowerOnSelfTest] configure() - Invalid event\n"; }
    void configurationEnded() override { std::cout << "  [PowerOnSelfTest] configurationEnded() - Invalid event\n"; }
    void start() override { std::cout << "  [PowerOnSelfTest] start() - Invalid event\n"; }
    void suspend() override { std::cout << "  [PowerOnSelfTest] suspend() - Invalid event\n"; }
    void resume() override { std::cout << "  [PowerOnSelfTest] resume() - Invalid event\n"; }
    void exit() override { std::cout << "  [PowerOnSelfTest] exit() - Invalid event\n"; }
    void stop() override { std::cout << "  [PowerOnSelfTest] exit() - Invalid event\n"; }
};

class InitializingState : public EmbeddedSystemXState {
private:
    static InitializingState* instance;
    InitializingState(EmbeddedSystemX* ctx) : EmbeddedSystemXState(ctx) {}

public:
    static InitializingState* getInstance(EmbeddedSystemX* ctx) {
        if (!instance) {
            instance = new InitializingState(ctx);
        }
        instance->context = ctx;
        return instance;
    }

    void selfTestOk() override { std::cout << "  [Initializing] selfTestOk() - Invalid event\n"; }
    void initialized() override;
    void restart() override;
    void selfTestFailed(int errorNo) override { std::cout << "  [Initializing] selfTestFailed() - Invalid event\n"; }
    void configure() override { std::cout << "  [Initializing] configure() - Invalid event\n"; }
    void configurationEnded() override { std::cout << "  [Initializing] configurationEnded() - Invalid event\n"; }
    void start() override { std::cout << "  [Initializing] start() - Invalid event\n"; }
    void suspend() override { std::cout << "  [Initializing] suspend() - Invalid event\n"; }
    void resume() override { std::cout << "  [Initializing] resume() - Invalid event\n"; }
    void exit() override { std::cout << "  [Initializing] exit() - Invalid event\n"; }
    void stop() override { std::cout << "  [Initializing] stop() - Invalid event\n"; }
};


class FailureState : public EmbeddedSystemXState {
private:
    static FailureState* instance;
    FailureState(EmbeddedSystemX* ctx) : EmbeddedSystemXState(ctx) {}

public:
    static FailureState* getInstance(EmbeddedSystemX* ctx) {
        if (!instance) {
            instance = new FailureState(ctx);
        }
        instance->context = ctx;
        return instance;
    }

    void selfTestOk() override { std::cout << "  [Failure] selfTestOk() - Invalid event\n"; }
    void initialized() override { std::cout << "  [Failure] initialized() - Invalid event\n"; }
    void restart() override;
    void selfTestFailed(int errorNo) override { std::cout << "  [Failure] Displaying error: " << errorNo << "\n"; }
    void configure() override { std::cout << "  [Failure] configure() - Invalid event\n"; }
    void configurationEnded() override { std::cout << "  [Failure] configurationEnded() - Invalid event\n"; }
    void start() override { std::cout << "  [Failure] start() - Invalid event\n"; }
    void suspend() override { std::cout << "  [Failure] suspend() - Invalid event\n"; }
    void resume() override { std::cout << "  [Failure] resume() - Invalid event\n"; }
    void exit() override { std::cout << "  [Failure] exit() - Invalid event\n"; }
    void stop() override { std::cout << "  [Failure] stop() - Invalid event\n"; }
};

class OperationalState : public EmbeddedSystemXState {
private:
    static OperationalState* instance;
    OperationalState(EmbeddedSystemX* ctx) : EmbeddedSystemXState(ctx) {}

public:
    static OperationalState* getInstance(EmbeddedSystemX* ctx) {
        if (!instance) {
            instance = new OperationalState(ctx);
        }
        instance->context = ctx;
        return instance;
    }

    void selfTestOk() override { std::cout << "  [Operational] selfTestOk() - Invalid event\n"; }
    void initialized() override { std::cout << "  [Operational] initialized() - Invalid event\n"; }
    void restart() override;
    void selfTestFailed(int errorNo) override { std::cout << "  [Operational] selfTestFailed() - Invalid event\n"; }
    void configure() override;
    void configurationEnded() override { std::cout << "  [Operational] configurationEnded() - Invalid event\n"; }
    void start() override { std::cout << "  [Operational] Start/run RealTimeLoop\n"; }
    void suspend() override;
    void resume() override { std::cout << "  [Operational] resume() - Invalid event\n"; }
    void exit() override;
    void stop() override { std::cout << "  [Operational] stop() - Invalid event\n"; }
};

class ConfigurationState : public EmbeddedSystemXState {
private:
    static ConfigurationState* instance;
    ConfigurationState(EmbeddedSystemX* ctx) : EmbeddedSystemXState(ctx) {}

public:
    static ConfigurationState* getInstance(EmbeddedSystemX* ctx) {
        if (!instance) {
            instance = new ConfigurationState(ctx);
        }
        instance->context = ctx;
        return instance;
    }

    void selfTestOk() override { std::cout << "  [Configuration] selfTestOk() - Invalid event\n"; }
    void initialized() override { std::cout << "  [Configuration] initialized() - Invalid event\n"; }
    void restart() override;
    void selfTestFailed(int errorNo) override { std::cout << "  [Configuration] selfTestFailed() - Invalid event\n"; }
    void configure() override { std::cout << "  [Configuration] Reading configuration info...\n"; }
    void configurationEnded() override;
    void start() override { std::cout << "  [Configuration] start() - Invalid event\n"; }
    void suspend() override { std::cout << "  [Configuration] suspend() - Invalid event\n"; }
    void resume() override { std::cout << "  [Configuration] resume() - Invalid event\n"; }
    void exit() override { std::cout << "  [Configuration] exit() - Invalid event\n"; }
    void stop() override { std::cout << "  [Configuration] stop() - Invalid event\n"; }
};

class ReadyState : public EmbeddedSystemXState {
private:
    static ReadyState* instance;
    ReadyState(EmbeddedSystemX* ctx) : EmbeddedSystemXState(ctx) {}

public:
    static ReadyState* getInstance(EmbeddedSystemX* ctx) {
        if (!instance) {
            instance = new ReadyState(ctx);
        }
        instance->context = ctx;
        return instance;
    }

    void selfTestOk() override { std::cout << "  [Ready] selfTestOk() - Invalid event\n"; }
    void initialized() override { std::cout << "  [Ready] initialized() - Invalid event\n"; }
    void restart() override;
    void selfTestFailed(int errorNo) override { std::cout << "  [Ready] selfTestFailed() - Invalid event\n"; }
    void configure() override;
    void configurationEnded() override { std::cout << "  [Ready] configurationEnded() - Invalid event\n"; }
    void start() override;
    void suspend() override { std::cout << "  [Ready] suspend() - Invalid event\n"; }
    void resume() override { std::cout << "  [Ready] resume() - Invalid event\n"; }
    void exit() override;
    void stop() override { std::cout << "  [Ready] stop() - Invalid event\n"; }
};

class SuspendedState : public EmbeddedSystemXState {
private:
    static SuspendedState* instance;
    SuspendedState(EmbeddedSystemX* ctx) : EmbeddedSystemXState(ctx) {}

public:
    static SuspendedState* getInstance(EmbeddedSystemX* ctx) {
        if (!instance) {
            instance = new SuspendedState(ctx);
        }
        instance->context = ctx;
        return instance;
    }

    void selfTestOk() override { std::cout << "  [Suspended] selfTestOk() - Invalid event\n"; }
    void initialized() override { std::cout << "  [Suspended] initialized() - Invalid event\n"; }
    void restart() override;
    void selfTestFailed(int errorNo) override { std::cout << "  [Suspended] selfTestFailed() - Invalid event\n"; }
    void configure() override { std::cout << "  [Suspended] configure() - Invalid event\n"; }
    void configurationEnded() override { std::cout << "  [Suspended] configurationEnded() - Invalid event\n"; }
    void start() override { std::cout << "  [Suspended] start() - Invalid event\n"; }
    void suspend() override { std::cout << "  [Suspended] suspend() - Invalid event\n"; }
    void resume() override;
    void exit() override;
    void stop() override;
};

class RealTimeLoopOuterState : public EmbeddedSystemXState {
private:
    static RealTimeLoopOuterState* instance;
    RealTimeLoopOuterState(EmbeddedSystemX* ctx) : EmbeddedSystemXState(ctx) {}

public:
    static RealTimeLoopOuterState* getInstance(EmbeddedSystemX* ctx) {
        if (!instance) {
            instance = new RealTimeLoopOuterState(ctx);
        }
        instance->context = ctx;
        return instance;
    }

    void selfTestOk() override { std::cout << "  [RealTimeLoopOuterState] selfTestOk() - Invalid event\n"; }
    void initialized() override { std::cout << "  [RealTimeLoopOuterState] initialized() - Invalid event\n"; }
    void restart() override;
    void selfTestFailed(int errorNo) override { std::cout << "  [RealTimeLoopOuterState] selfTestFailed() - Invalid event\n"; }
    void configure() override { std::cout << "  [RealTimeLoopOuterState] configure() - Invalid event\n"; }
    void configurationEnded() override { std::cout << "  [RealTimeLoopOuterState] configurationEnded() - Invalid event\n"; }
    void start() override { std::cout << "  [RealTimeLoopOuterState] start() - Invalid event\n"; }
    void suspend() override;
    void resume() override { std::cout << "  [RealTimeLoopOuterState] resume() - Invalid event\n"; }
    void exit() override { std::cout << "  [RealTimeLoopOuterState] exit() - Invalid event\n"; }
    void stop() override;
};

// ==================== REALTIME LOOP STATE CLASSES ====================

class RealTimeLoopState {
protected:
    RealTimeLoop* context;

public:
    RealTimeLoopState(RealTimeLoop* ctx) : context(ctx) {}
    virtual ~RealTimeLoopState() = default;

    virtual void eventX() = 0;
};

class Mode1State : public RealTimeLoopState {
private:
    static Mode1State* instance;
    Mode1State(RealTimeLoop* ctx) : RealTimeLoopState(ctx) {}

public:
    static Mode1State* getInstance(RealTimeLoop* ctx) {
        if (!instance) {
            instance = new Mode1State(ctx);
        }
        instance->context = ctx;
        return instance;
    }

    void eventX() override;
};

class Mode2State : public RealTimeLoopState {
private:
    static Mode2State* instance;
    Mode2State(RealTimeLoop* ctx) : RealTimeLoopState(ctx) {}

public:
    static Mode2State* getInstance(RealTimeLoop* ctx) {
        if (!instance) {
            instance = new Mode2State(ctx);
        }
        instance->context = ctx;
        return instance;
    }

    void eventX() override;
};

class Mode3State : public RealTimeLoopState {
private:
    static Mode3State* instance;
    Mode3State(RealTimeLoop* ctx) : RealTimeLoopState(ctx) {}

public:
    static Mode3State* getInstance(RealTimeLoop* ctx) {
        if (!instance) {
            instance = new Mode3State(ctx);
        }
        instance->context = ctx;
        return instance;
    }

    void eventX() override;
};

// ==================== REALTIME LOOP CONTEXT ====================

class RealTimeLoop {
private:
    RealTimeLoopState* currentMode;

public:
    RealTimeLoop() : currentMode(Mode1State::getInstance(this)) {}

    void changeMode(int modeNumber) {
        std::cout << "  RealTimeLoop::changeMode(" << modeNumber << ")\n";
        switch (modeNumber) {
            case 1:
                if (dynamic_cast<Mode2State*>(currentMode)) {
                    std::cout << "    Cannot transition to Mode1 using mode2\n";
                    break;
                }
                currentMode = Mode1State::getInstance(this);
                std::cout << "    Transitioned to Mode1\n";
                break;
            case 2:
                if (dynamic_cast<Mode3State*>(currentMode)) {
                    std::cout << "    Cannot transition to Mode2 using mode3\n";
                    break;
                }
                currentMode = Mode2State::getInstance(this);
                std::cout << "    Transitioned to Mode2\n";
                break;
            case 3:
                if (dynamic_cast<Mode1State*>(currentMode)) {
                    std::cout << "    Cannot transition to Mode3 using mode1\n";
                    break;
                }
                currentMode = Mode3State::getInstance(this);
                std::cout << "    Transitioned to Mode3\n";
                break;
            default:
                std::cout << "    Invalid mode\n";
        }
    }

    void eventX() {
        if (currentMode) {
            currentMode->eventX();
        }
    }

    std::string getCurrentMode() const {
        if (dynamic_cast<Mode1State*>(currentMode)) return "Mode1";
        if (dynamic_cast<Mode2State*>(currentMode)) return "Mode2";
        if (dynamic_cast<Mode3State*>(currentMode)) return "Mode3";
        return "Unknown";
    }
};

// ==================== EMBEDDED SYSTEM CONTEXT ====================

class EmbeddedSystemX {
private:
    EmbeddedSystemXState* currentState;
    RealTimeLoop* realTimeLoop;

public:
    EmbeddedSystemX()
            : currentState(PowerOnSelfTestState::getInstance(this)),
              realTimeLoop(new RealTimeLoop()) {}

    ~EmbeddedSystemX() {
        delete realTimeLoop;
    }

    void changeState(EmbeddedSystemXState* newState) {
        currentState = newState;
    }

    RealTimeLoop* getRealTimeLoop() {
        return realTimeLoop;
    }

    // Event operations
    void selfTestOk() {
        std::cout << "Event: selfTestOk()\n";
        currentState->selfTestOk();
    }

    void initialized() {
        std::cout << "Event: initialized()\n";
        currentState->initialized();
    }

    void restart() {
        std::cout << "Event: restart()\n";
        currentState->restart();
    }

    void selfTestFailed(int errorNo) {
        std::cout << "Event: selfTestFailed(ErrorNo: " << errorNo << ")\n";
        currentState->selfTestFailed(errorNo);
    }

    void configure() {
        std::cout << "Event: configure()\n";
        currentState->configure();
    }

    void configurationEnded() {
        std::cout << "Event: configurationEnded()\n";
        currentState->configurationEnded();
    }

    void start() {
        std::cout << "Event: start()\n";
        currentState->start();
    }

    void suspend() {
        std::cout << "Event: suspend()\n";
        currentState->suspend();
    }

    void resume() {
        std::cout << "Event: resume()\n";
        currentState->resume();
    }

    void exit() {
        std::cout << "Event: exit()\n";
        currentState->exit();
    }

    void stop() {
        std::cout << "Event: stop()\n";
        currentState->stop();
    }

    std::string getStateName() const {
        if (dynamic_cast<PowerOnSelfTestState*>(currentState)) return "PowerOnSelfTest";
        if (dynamic_cast<InitializingState*>(currentState)) return "Initializing";
        if (dynamic_cast<FailureState*>(currentState)) return "Failure";
        if (dynamic_cast<OperationalState*>(currentState)) return "Operational";
        if (dynamic_cast<ConfigurationState*>(currentState)) return "Configuration";
        if (dynamic_cast<ReadyState*>(currentState)) return "Ready";
        if (dynamic_cast<SuspendedState*>(currentState)) return "Suspended";
        if (dynamic_cast<RealTimeLoopOuterState*>(currentState)) return "RealTimeLoop";
        return "Unknown";
    }
};

// ==================== SINGLETON INSTANTIATIONS ====================

PowerOnSelfTestState* PowerOnSelfTestState::instance = nullptr;
InitializingState* InitializingState::instance = nullptr;
FailureState* FailureState::instance = nullptr;
OperationalState* OperationalState::instance = nullptr;
ConfigurationState* ConfigurationState::instance = nullptr;
ReadyState* ReadyState::instance = nullptr;
SuspendedState* SuspendedState::instance = nullptr;
RealTimeLoopOuterState* RealTimeLoopOuterState::instance = nullptr;

Mode1State* Mode1State::instance = nullptr;
Mode2State* Mode2State::instance = nullptr;
Mode3State* Mode3State::instance = nullptr;

// ==================== STATE IMPLEMENTATIONS ====================

void PowerOnSelfTestState::selfTestOk() {
    std::cout << "  [PowerOnSelfTest] SelfTest OK! Transitioning to Initializing...\n";
    context->changeState(InitializingState::getInstance(context));
}

void PowerOnSelfTestState::restart() {
    std::cout << "  [PowerOnSelfTest] Restarting from PowerOnSelfTest...\n";
    // Stays in same state after restart from this state
}

void PowerOnSelfTestState::selfTestFailed(int errorNo) {
    std::cout << "  [PowerOnSelfTest] SelfTest FAILED with error " << errorNo << "! Transitioning to Failure...\n";
    context->changeState(FailureState::getInstance(context));
}

void InitializingState::initialized() {
    std::cout << "  [Initializing] System initialized! Transitioning to Ready...\n";
    context->changeState(ReadyState::getInstance(context));
}

void InitializingState::restart() {
    std::cout << "  [Initializing] Restarting system back to PowerOnSelfTest...\n";
    context->changeState(PowerOnSelfTestState::getInstance(context));
}

void FailureState::restart() {
    std::cout << "  [Failure] Restarting system back to PowerOnSelfTest...\n";
    context->changeState(PowerOnSelfTestState::getInstance(context));
}

void OperationalState::configure() {
    std::cout << "  [Operational] Starting configuration...\n";
    context->changeState(ConfigurationState::getInstance(context));
}

void OperationalState::suspend() {
    std::cout << "  [Operational] Suspending system...\n";
    context->changeState(SuspendedState::getInstance(context));
}

void OperationalState::restart() {
    std::cout << "  [Operational] Restarting system back to PowerOnSelfTest...\n";
    context->changeState(PowerOnSelfTestState::getInstance(context));
}

void OperationalState::exit() {
    std::cout << "  [Operational] System exiting...\n";
}

void ConfigurationState::restart() {
    std::cout << "  [Configuration] Restarting system back to PowerOnSelfTest...\n";
    context->changeState(PowerOnSelfTestState::getInstance(context));
}

void ConfigurationState::configurationEnded() {
    std::cout << "  [Configuration] Configuration completed! Transitioning to Ready...\n";
    context->changeState(ReadyState::getInstance(context));
}

void ReadyState::restart() {
    std::cout << "  [Ready] Restarting system back to PowerOnSelfTest...\n";
    context->changeState(PowerOnSelfTestState::getInstance(context));
}

void RealTimeLoopOuterState::suspend() {
    std::cout << "  [RealTimeLoopOuterState] Suspending...\n";
    context->changeState(SuspendedState::getInstance(context));
}

void RealTimeLoopOuterState::stop() {
    std::cout << "  [RealTimeLoopOuterState] Stopping...\n";
    context->changeState(ReadyState::getInstance(context));
}

void RealTimeLoopOuterState::restart() {
    std::cout << "  [RealTimeLoopOuterState] Restarting system back to PowerOnSelfTest...\n";
    context->changeState(PowerOnSelfTestState::getInstance(context));
}


void ReadyState::start() {
    std::cout << "  [Ready] Starting RealTimeLoop...\n";
    context->changeState(RealTimeLoopOuterState::getInstance(context));
}

void ReadyState::exit() {
    std::cout << "  [Ready] Leaving RealTimeLoop...\n";
    context->changeState(PowerOnSelfTestState::getInstance(context));
}

void ReadyState::configure() {
    std::cout << "  [Ready] Configuring RealTimeLoop...\n";
    context->changeState(ConfigurationState::getInstance(context));
}

void SuspendedState::restart() {
    std::cout << "  [Suspended] Restarting system back to PowerOnSelfTest...\n";
    context->changeState(PowerOnSelfTestState::getInstance(context));
}

void SuspendedState::resume() {
    std::cout << "  [Suspended] Resuming system back to RealTimeLoop...\n";
    context->changeState(RealTimeLoopOuterState::getInstance(context));
}
void SuspendedState::stop() {
    std::cout << "  [Suspended] Stopping RTL, changing back to ready...\n";
    context->changeState(ReadyState::getInstance(context));
}
void SuspendedState::exit() {
    std::cout << "  [Suspended] Exiting...\n";
}

void Mode1State::eventX() {
    std::cout << "    [Mode1] responseM1eventX\n";
}

void Mode2State::eventX() {
    std::cout << "    [Mode2] responseM2eventX\n";
}

void Mode3State::eventX() {
    std::cout << "    [Mode3] responseM3eventX\n";
}

#endif //A1_STATESASSINGLETONS_H
