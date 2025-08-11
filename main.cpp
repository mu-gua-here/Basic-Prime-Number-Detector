//
//  main.cpp
//  Prime Number Detector
//
//  Created by mu_gua_here on 2025/6/23.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
#include <string>
#include <stdexcept>
using namespace std;
using BigInt = unsigned long long;

bool isPrime(BigInt n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    // Check odd divisors up to sqrt(n)
    // Use BigInt for the loop to avoid overflow
    BigInt limit = (BigInt)sqrt((long double)n);
    for (BigInt i = 3; i <= limit; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to safely convert string to BigInt
bool stringToBigInt(const string& str, BigInt& result) {
    if (str.empty()) return false;
    
    try {
        // Check for negative numbers
        if (str[0] == '-') return false;
        
        // Use stoull (string to unsigned long long)
        result = stoull(str);
        return true;
    } catch (const invalid_argument& e) {
        return false;
    } catch (const out_of_range& e) {
        cout << "Number is too large! Maximum supported: "
             << numeric_limits<BigInt>::max() << endl;
        return false;
    }
}

int main() {
    cout << "Welcome to the Prime Number Detector.\n";
    cout << "Supports integers up to " << numeric_limits<BigInt>::max() << endl;
    cout << "Enter 'quit' or a number < 2 to exit.\n\n";
    
    string input;
    while (true) {
        cout << "Input a number to check: ";
        
        // Read entire line to handle large numbers as strings
        if (!getline(cin, input)) {
            cout << "Input error occurred.\n";
            continue;
        }
        
        // Check for quit command
        if (input == "quit" || input == "q") {
            cout << "Program exited.\n";
            break;
        }
        
        // Check if input is empty
        if (input.empty()) {
            cout << "No input provided. Please enter a number.\n";
            continue;
        }
        
        // Convert string to BigInt
        BigInt number;
        if (!stringToBigInt(input, number)) {
            cout << "Invalid input! Please enter a valid positive integer.\n";
            continue;
        }
        
        // Check minimum value
        if (number < 2) {
            cout << "Number must be 2 or greater.\n";
            continue;
        }
        
        cout << "Checking if " << number << " is prime...\n";
        
        if (isPrime(number)) {
            cout << number << " is a prime number!\n";
        } else {
            cout << number << " is not a prime number.\n";
        }
        cout << endl;
    }
    
    return 0;
}
