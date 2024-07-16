#include <iostream>

/**
 * @brief Prints a newline character to terminate output
 *
 */
// Base case for the recursion
void print() {
    std::cout << std::endl;  // End the line after all elements are printed
}

/**
 * @brief Prints multiple arguments separated by commas
 *
 * @param first The first argument to print
 * @param args The remaining arguments to print (optional)
 * @return template <typename T, typename... Args>
 */
// Variadic template function to handle at least one parameter
template <typename T, typename... Args>
void print(const T& first, const Args&... args) {
    std::cout << first;
    if constexpr (sizeof...(args) > 0) {
        std::cout << ", ";
        print(args...);  // Recursive call with the rest of the parameters
    } else {
        std::cout << std::endl;  // End the line after the last element
    }
}