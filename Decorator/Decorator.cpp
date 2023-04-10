#include<iostream>
using namespace std;
class Component {
  public:
    virtual string Operation() const = 0;
};

class ConcreteComponent : public Component {
  public:
    string Operation() const override {
      return "Base Operation";
    }
};

class Decorator : public Component {
  protected:
    Component* component_;
  public:
    Decorator(Component* component) : component_(component) {
    }

    string Operation() const override {
      return this->component_->Operation();
    }
};

class ConcreteDecoratorA : public Decorator {
  public:
    ConcreteDecoratorA(Component* component) : Decorator(component) {
    }

    string Operation() const override {
      return "Operation A(" + Decorator::Operation() + ")";
    }
};

class ConcreteDecoratorB : public Decorator {
  public:
    ConcreteDecoratorB(Component* component) : Decorator(component) {
    }

    string Operation() const override {
      return "Operation B(" + Decorator::Operation() + ")";
    }
};

class ConcreteDecoratorC : public Decorator {
  public:
    ConcreteDecoratorC(Component* component) : Decorator(component) {
    }

    string Operation() const override {
      return "Operation C(" + Decorator::Operation() + ")";
    }
};

class ConcreteDecoratorD : public Decorator {
  public:
    ConcreteDecoratorD(Component* component) : Decorator(component) {
    }

    string Operation() const override {
      return "Operation D(" + Decorator::Operation() + ")";
    }
};

void ClientCode(Component* component) {
    cout << "RESULT: " << component->Operation();
}

int main() {
  Component* simple = new ConcreteComponent;
  cout << "Client: I've got a simple component:\n";
  ClientCode(simple);
  cout << "\n\n";

  Component* decorator1 = new ConcreteDecoratorA(simple);
  Component* decorator2 = new ConcreteDecoratorB(decorator1);
  cout << "Client: Now I've got a decorated component with order B - A - base:\n";
  ClientCode(decorator2);
  cout << "\n";

  cout << "\n";
  Component* decorator_1 = new ConcreteDecoratorD(simple);
  Component* decorator_2 = new ConcreteDecoratorA(decorator_1);
  Component* decorator_3 = new ConcreteDecoratorC(decorator_2);
  Component* decorator_4 = new ConcreteDecoratorB(decorator_3);
  cout << "Client: Now I've got a decorated component with order B - C - A - D - base:\n";
  ClientCode(decorator_4);
  cout << "\n";
}