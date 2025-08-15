#include <iostream>
using namespace std;

class SecretBox {
private:
    int secretCode = 1234;

public:
    // Friend function declaration
    friend void revealSecret(SecretBox box);
};

// Friend function definition (OUTSITE THE CLASS)
void revealSecret(SecretBox box) {
    // Can access private member directly!
    cout << "Secret code is: " << box.secretCode << endl;
}

int main() {
    SecretBox box;
    revealSecret(box); // Output: Secret code is: 1234
}