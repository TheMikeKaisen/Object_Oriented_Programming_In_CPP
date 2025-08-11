#include<iostream>
using namespace std;

class Complex{
    private:
    int real, imag;

    public:
    Complex(double real = 0.0, double imag = 0.0) {
        // this is a pointer, thus we have to write it like this -> real to point to the current object
        this->real = real; 
        this->imag = imag;
    } 

    //OPERATOR OVERLOADING
    // marking function as const ensures you cannot modify current object's member variables.
    // marking parameter as const ensures you cannot modify member variables of object in the parameter.
    Complex operator+(const Complex &otherObj) const {
        Complex result;
        result.real = real + otherObj.real;
        result.imag = imag + otherObj.imag;
        return result;
    }

    void display(){
        cout << this->real << " + " << this->imag << "i " << endl;
    }


};

int main() {

    Complex c1(100.00, 30.0);
    Complex c2(340.00, 24.0);

    Complex c3 = c1 + c2;

    cout << "c1= "; c1.display();
    cout << "c2= "; c2.display();
    cout << "c2= "; c3.display(); 
    return 0;
}