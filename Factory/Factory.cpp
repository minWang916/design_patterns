#include<iostream>
using namespace std;
class Product {
    public:
        virtual string Operation() const = 0;
};

class ConcreteProduct1 : public Product {
    public:
        string Operation() const override {
            return "Product1's actions";
        }
};

class ConcreteProduct2 : public Product {
    public:
        string Operation() const override {
            return "Product2's actions";
        }
};

class Creator {
    public:
        virtual Product* FactoryMethod() const = 0;

        string SomeOperation() const {
            Product* product = this->FactoryMethod();
            string result = "Creator: The same creator's code but can work with " + product->Operation() + "\n";
            return result;
        }
};

class ConcreteCreator1 : public Creator {
    public:
        Product* FactoryMethod() const override {
            return new ConcreteProduct1();  
        }
};

class ConcreteCreator2 : public Creator {
    public:
        Product* FactoryMethod() const override {
            return new ConcreteProduct2();
        }
};


void ClientCode(const Creator& creator) {
    cout<<creator.SomeOperation();
}

int main() {
  cout << "App: Launched with the ConcreteCreator1.\n";
  Creator* creator = new ConcreteCreator1();
  ClientCode(*creator);
  cout << endl;
  cout << "App: Launched with the ConcreteCreator2.\n";
  Creator* creator2 = new ConcreteCreator2();
  ClientCode(*creator2);
}