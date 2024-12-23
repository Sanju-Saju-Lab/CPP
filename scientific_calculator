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
    ScientificCalculator() : memory(0), ans(0) {}

    double evaluateExpression(string expression) {
        expression = replaceConstants(expression);
        expression = handleFunctions(expression);

        stack<double> operands;
        stack<char> operators;

        auto precedence = [](char op) {
            if (op == '+' || op == '-') return 1;
            if (op == '*' || op == '/') return 2;
            if (op == '^') return 3;
            return 0;
        };

        auto applyOperator = [&operands](char op) {
            double b = operands.top(); operands.pop();
            double a = operands.top(); operands.pop();
            switch (op) {
                case '+': operands.push(a + b); break;
                case '-': operands.push(a - b); break;
                case '*': operands.push(a * b); break;
                case '/': 
                    if (b != 0) operands.push(a / b);
                    else throw runtime_error("Math ERROR: Division by zero");
                    break;
                case '^': operands.push(pow(a, b)); break;
            }
        };

        for (size_t i = 0; i < expression.length(); i++) {
            char c = expression[i];

            if (isspace(c)) continue;

            if (isdigit(c) || c == '.') {
                string num;
                while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                    num += expression[i++];
                }
                i--;
                operands.push(stod(num));
            }
            else if (c == '(') {
                operators.push(c);
            }
            else if (c == ')') {
                while (!operators.empty() && operators.top() != '(') {
                    applyOperator(operators.top());
                    operators.pop();
                }
                operators.pop(); // Remove '('
            }
            else {
                while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                    applyOperator(operators.top());
                    operators.pop();
                }
                operators.push(c);
            }
        }

        while (!operators.empty()) {
            applyOperator(operators.top());
            operators.pop();
        }

        ans = operands.top();
        return operands.top();
    }

    string handleFunctions(string expression) {
        regex funcRegex("(sin|cos|tan|log|ln|sqrt)\\((\\d+(\\.\\d*)?)\\)");
        smatch match;

        while (regex_search(expression, match, funcRegex)) {
            string func = match[1];
            double value = stod(match[2]);
            double result;

            if (func == "sin") result = sin(value * M_PI / 180.0);
            else if (func == "cos") result = cos(value * M_PI / 180.0);
            else if (func == "tan") result = tan(value * M_PI / 180.0);
            else if (func == "log") result = log10(value);
            else if (func == "ln") result = log(value);
            else if (func == "sqrt") {
                if (value < 0) throw runtime_error("Math ERROR: Negative square root");
                result = sqrt(value);
            }

            expression.replace(match.position(), match.length(), to_string(result));
        }

        return expression;
    }

    string replaceConstants(string expression) {
        regex piRegex("(pi|π)");
        expression = regex_replace(expression, piRegex, to_string(M_PI));

        regex ansRegex("Ans");
        expression = regex_replace(expression, ansRegex, to_string(ans));

        return expression;
    }

    void storeInMemory(double value) {
        memory = value;
        cout << "Stored in memory" << endl;
    }

    void recallMemory() const {
        cout << "Memory value: " << memory << endl;
    }

    void clearMemory() {
        memory = 0;
        cout << "Memory cleared" << endl;
    }
};

int main() {
    ScientificCalculator calc;
    string choice;

    while (true) {
        cout << "\nOptions:\n1: Evaluate Expression\n2: Store in Memory\n3: Recall Memory\n4: Clear Memory\n5: Off\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == "5") {
            cout << "CASIO" << endl;
            break;
        }

        try {
            if (choice == "1") {
                string expression;
                cout << "Enter the mathematical expression: ";
                cin.ignore(); // Clear input buffer
                getline(cin, expression);
                try {
                    double result = calc.evaluateExpression(expression);
                    cout << "Answer: " << result << endl;
                } catch (const exception &e) {
                    cout << "Error: " << e.what() << endl;
                }
            } else if (choice == "2") {
                double value;
                cout << "Enter the value to store in memory: ";
                cin >> value;
                calc.storeInMemory(value);
            } else if (choice == "3") {
                calc.recallMemory();
            } else if (choice == "4") {
                calc.clearMemory();
            } else {
                cout << "Invalid choice. Please try again." << endl;
            }
        } catch (const exception &e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
