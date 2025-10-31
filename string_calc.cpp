#include "string_calc.h"
#include <regex>
#include <sstream>
#include <iomanip>

bool isValidDouble(const std::string &s) {
    // Valid pattern: optional sign, digits, optional decimal + digits
    std::regex valid_pattern(R"(^[+-]?\d+(\.\d+)?$)");
    return std::regex_match(s, valid_pattern);
}

std::string addDoubleStrings(const std::string &a, const std::string &b) {
    // Convert to long double for very large / precise addition
    long double x, y;
    std::stringstream(a) >> x;
    std::stringstream(b) >> y;
    long double sum = x + y;

    // Format result to remove trailing zeros but keep at least one decimal if needed
    std::ostringstream out;
    out << std::fixed << std::setprecision(15) << sum; // high precision first
    std::string result = out.str();

    // Trim trailing zeros and decimal if unnecessary
    result.erase(result.find_last_not_of('0') + 1, std::string::npos);
    if (result.back() == '.') result.pop_back();

    return result;
}
