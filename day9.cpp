#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

// BigInteger represented as little-endian decimal digits
class BigInt {
private:
    std::vector<unsigned short> digits; // little-endian: digits[0] is least significant

public:
    BigInt(unsigned long long val) {
        if (val == 0) digits.push_back(0);
        while (val > 0) {
            digits.push_back(static_cast<unsigned short>(val % 10));
            val /= 10;
        }
    }

    BigInt operator*(unsigned int multiplier) const {
        BigInt result(0);
        result.digits.clear();

        unsigned long long carry = 0;
        for (unsigned short digit : digits) {
            unsigned long long prod = static_cast<unsigned long long>(digit) * multiplier + carry;
            result.digits.push_back(static_cast<unsigned short>(prod % 10));
            carry = prod / 10;
        }
        while (carry > 0) {
            result.digits.push_back(static_cast<unsigned short>(carry % 10));
            carry /= 10;
        }
        return result;
    }

    std::string toString() const {
        std::string s;
        s.reserve(digits.size());
        for (auto it = digits.rbegin(); it != digits.rend(); ++it)
            s.push_back(static_cast<char>('0' + *it));
        return s;
    }
};

// Computes n! using arbitrary-precision arithmetic.
// Returns the result as a decimal string.
std::string factorial(unsigned int n) {
    BigInt result(1);
    for (unsigned int i = 2; i <= n; ++i) {
        result = result * i;
    }
    return result.toString();
}

bool readNonNegativeInt(unsigned int& out) {
    std::string line;
    if (!std::getline(std::cin, line)) return false;

    // Trim whitespace
    line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());

    if (line.empty()) return false;

    size_t pos = 0;
    try {
        unsigned long long val = std::stoull(line, &pos);
        if (pos != line.size()) return false;                 // trailing garbage
        if (val > std::numeric_limits<unsigned int>::max()) return false;
        out = static_cast<unsigned int>(val);
        return true;
    } catch (const std::exception&) {
        return false;
    }
}

int main() {
    constexpr unsigned int kMaxSupported = 10000; // ~35500+ digits; raise if needed

    std::cout << "Enter a non-negative integer (0 - " << kMaxSupported << "): ";

    unsigned int n;
    if (!readNonNegativeInt(n)) {
        std::cerr << "Error: invalid input. Expected a non-negative integer.\n";
        return EXIT_FAILURE;
    }
    if (n > kMaxSupported) {
        std::cerr << "Error: input too large. Maximum supported is " << kMaxSupported << ".\n";
        return EXIT_FAILURE;
    }

    std::cout << n << "! = " << factorial(n) << '\n';
    return EXIT_SUCCESS;
}
