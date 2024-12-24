#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <regex>
#include <stdexcept>

using namespace std;

class ScientificCalculator {
private:
    double memory; // Memory to store values
    double ans;    // Last result

public:
    // Constructor to initialize memory and last result to 0
    ScientificCalculator() : memory(0), ans(0) {}

    // Function to evaluate a mathematical expression
    double evaluateExpression(string expression) {
        expression = replaceConstants(expression);  // Replace constants (like pi) with actual values
        expression = handleFunctions(expression);   // Handle mathematical functions like sin, cos, etc.

        stack<double> operands;  // Stack to hold numbers
        stack<char> operators;   // Stack to hold operators

        // Function to determine operator precedence
        auto precedence = [](char op) {
            if (op == '+' || op == '-') return 1;
            if (op == '*' || op == '/') return 2;
            if (op == '^') return 3;
            return 0;
        };

        // Function to apply an operator to the operands stack
        auto applyOperator = [&operands](char op) {
            double b = operands.top(); operands.pop();  // Pop the second operand
            double a = operands.top(); operands.pop();  // Pop the first operand
            switch (op) {
                case '+': operands.push(a + b); break;
                case '-': operands.push(a - b); break;
                case '*': operands.push(a * b); break;
                case '/': 
                    if (b != 0) operands.push(a / b);  // Handle division by zero
                    else throw runtime_error("Math ERROR: Division by zero");
                    break;
                case '^': operands.push(pow(a, b)); break; // Power operation
            }
        };

        // Loop through each character in the expression
        for (size_t i = 0; i < expression.length(); i++) {
            char c = expression[i];

            if (isspace(c)) continue;  // Skip spaces

            if (isdigit(c) || c == '.') {  // If the character is a number or decimal point
                string num;
                // Collect the entire number (including decimals)
                while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                    num += expression[i++];
                }
                i--; // Adjust the index back
                operands.push(stod(num));  // Convert string to double and push to operand stack
            }
            else if (c == '(') {
                operators.push(c);  // Push '(' to operators stack
            }
            else if (c == ')') {
                // Process operators inside parentheses
                while (!operators.empty() && operators.top() != '(') {
                    applyOperator(operators.top());
                    operators.pop();
                }
                operators.pop(); // Remove '(' from stack
            }
            else {
                // Process operators (apply operators with higher precedence first)
                while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                    applyOperator(operators.top());
                    operators.pop();
                }
                operators.push(c);  // Push current operator to stack
            }
        }

        // Apply remaining operators
        while (!operators.empty()) {
            applyOperator(operators.top());
            operators.pop();
        }

        ans = operands.top();  // Store the final result
        return operands.top();  // Return the result
    }

    // Function to handle mathematical functions (like sin, cos, sqrt)
    string handleFunctions(string expression) {
        regex funcRegex("(sin|cos|tan|log|ln|sqrt)\\((\\d+(\\.\\d*)?)\\)");
        smatch match;

        // Loop through the expression and apply functions
        while (regex_search(expression, match, funcRegex)) {
            string func = match[1];  // Extract function (sin, cos, etc.)
            double value = stod(match[2]);  // Extract the number inside the function
            double result;

            // Apply the correct mathematical function
            if (func == "sin") result = sin(value * M_PI / 180.0);  // Convert degrees to radians
            else if (func == "cos") result = cos(value * M_PI / 180.0);
            else if (func == "tan") result = tan(value * M_PI / 180.0);
            else if (func == "log") result = log10(value);  // Logarithm base 10
            else if (func == "ln") result = log(value);     // Natural logarithm (base e)
            else if (func == "sqrt") {
                if (value < 0) throw runtime_error("Math ERROR: Negative square root");
                result = sqrt(value);  // Square root
            }

            // Replace the function in the expression with the result
            expression.replace(match.position(), match.length(), to_string(result));
        }

        return expression;
    }

    // Replace constants like 'pi' or 'Ans' in the expression
    string replaceConstants(string expression) {
        regex piRegex("(pi|π)");
        expression = regex_replace(expression, piRegex, to_string(M_PI));  // Replace 'pi' with the actual value

        regex ansRegex("Ans");
        expression = regex_replace(expression, ansRegex, to_string(ans));  // Replace 'Ans' with the last result

        return expression;
    }

    // Store a value in memory
    void storeInMemory(double value) {
        memory = value;
        cout << "Stored in memory" << endl;
    }

    // Recall the stored value from memory
    void recallMemory() const {
        cout << "Memory value: " << memory << endl;
    }

    // Clear the stored value in memory
    void clearMemory() {
        memory = 0;
        cout << "Memory cleared" << endl;
    }
};

int main() {
    ScientificCalculator calc;
    string choice;

    // Display options to the user
    while (true) {
        cout << "\nOptions:\n1: Evaluate Expression\n2: Store in Memory\n3: Recall Memory\n4: Clear Memory\n5: Off\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == "5") {
            cout << "CASIO" << endl;  // Exit the program
            break;
        }

        try {
            if (choice == "1") {
                string expression;
                cout << "Enter the mathematical expression: ";
                cin.ignore(); // Clear input buffer
                getline(cin, expression);  // Get the full expression from the user
                try {
                    double result = calc.evaluateExpression(expression);
                    cout << "Answer: " << result << endl;  // Display the result
                } catch (const exception &e) {
                    cout << "Error: " << e.what() << endl;  // Handle errors
                }
            } else if (choice == "2") {
                double value;
                cout << "Enter the value to store in memory: ";
                cin >> value;
                calc.storeInMemory(value);  // Store the value in memory
            } else if (choice == "3") {
                calc.recallMemory();  // Recall the value from memory
            } else if (choice == "4") {
                calc.clearMemory();  // Clear the memory
            } else {
                cout << "Invalid choice. Please try again." << endl;  // Handle invalid choice
            }
        } catch (const exception &e) {
            cout << "Error: " << e.what() << endl;  // Handle any errors that occur
        }
    }

    return 0;
}
