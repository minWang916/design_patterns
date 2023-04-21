#include <iostream>
using namespace std;

// Forward declaration of the Context class
class Computer;

// The State class
class PowerState {
public:
    virtual ~PowerState() {}
    virtual void PressPowerButton(Computer* context) = 0;
};

// Concrete State classes
class OnState : public PowerState {
public:
    void PressPowerButton(Computer* context) override;
};

class OffState : public PowerState {
public:
    void PressPowerButton(Computer* context) override;
};

// The Context class
class Computer {
private:
    PowerState* state_;

public:
    Computer() {
        // Set the initial state of the computer to OffState
        state_ = new OffState();
    }

    void SetState(PowerState* state) {
        state_ = state;
    }

    void PressPowerButton() {
        state_->PressPowerButton(this);
    }
};

void OnState::PressPowerButton(Computer* context) {
    // Change the state of the computer to OffState
    cout << "Shutting down the computer...\n";
    context->SetState(new OffState());
    delete this;
}

void OffState::PressPowerButton(Computer* context) {
    // Change the state of the computer to OnState
    cout << "Starting up the computer...\n";
    context->SetState(new OnState());
    delete this;
}

int main() {
    Computer computer;

    // Turn on the computer
    computer.PressPowerButton();

    // Turn off the computer
    computer.PressPowerButton();

    return 0;
}