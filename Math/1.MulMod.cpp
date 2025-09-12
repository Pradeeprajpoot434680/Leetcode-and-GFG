#include <iostream>
using namespace std;

long long mulMod(long long a, long long b, long long c) {
    long long result = 0;  // Result of multiplication under modulo c
    a = a % c;  // Reduce a modulo c to avoid overflow during multiplication

    while (b > 0) {
        // If the current bit of b is set (i.e., b is odd)
        if (b % 2 == 1) {
            result = (result + a) % c;  // Add current a to result
        }
        
        // Double a and halve b for the next iteration
        a = (2 * a) % c;  // a = a * 2 % c
        b = b / 2;  // Halve b (binary exponentiation step)
    }

    return result;
}

int main() {
    long long a, b, c;
    cout << "Enter values for a, b, and c: ";
    cin >> a >> b >> c;

    long long result = mulMod(a, b, c);
    cout << "Result of (" << a << " * " << b << ") % " << c << " = " << result << endl;

    return 0;
}