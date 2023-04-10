#include<iostream>
using namespace std;
class Singleton
{
    private:
        static Singleton* singleton_instance;
        string value;
        Singleton(string value){
            this->value = value;
        }
    public: 
        static Singleton *GetInstance(string value){
            if(singleton_instance == nullptr){
                singleton_instance = new Singleton(value);
            }
            return singleton_instance;;
        }
   
        void Singleton_actions()
        {
            cout<<"Singleton is doing something with data "<<value<<" \n";
        }
        string getValue() const {
            return value;
        }
};

Singleton* Singleton::singleton_instance = nullptr;

int main()
{
    cout <<"If you see the same value, then singleton was reused (yay!\n" <<
            "If you see different values, then 2 singletons were created (booo!!)\n\n" <<
            "RESULT:\n";   

    Singleton* a = Singleton::GetInstance("FOO");
    a->Singleton_actions();
    Singleton* b = Singleton::GetInstance("BAR");
    b->Singleton_actions();
}