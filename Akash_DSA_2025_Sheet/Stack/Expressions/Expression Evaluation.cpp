
// Operators are between operands.
// Example: A + B
// Needs operator precedence and parentheses to evaluate correctly.
// Usually converted to Postfix or Prefix for easier evaluation by computers.



class Solution {
public:
    int precedence(string op) {
        if (op == "^") return 3;
        else if (op == "*" || op == "/") return 2;
        else if(op == "+" || op == "-")return 1; // + or -
    }

    int floorDivide(int a, int b) {
        int q = a / b;
        int r = a % b;
        // C++ truncates toward 0.
        // We need mathematical floor.
        if (r != 0 && ((a < 0) != (b < 0))) q--;
        return q;
    }
    int calculate(int a, int b, string op) {
        if (op == "+")return a + b;
        if (op == "-") return a - b;
        if (op == "*") return a * b;
        if (op == "/")return floorDivide(a, b);
        if (op == "^") return pow(a, b);
        return 0;
    }
    void applyTop(stack<int>& values, stack<string>& ops) {

        string op = ops.top();
        ops.pop();

        int b = values.top();
        values.pop();

        int a = values.top();
        values.pop();

        values.push(calculate(a, b, op));
    }

    int evaluateInfix(vector<string>& arr) {

        stack<int> values;
        stack<string> ops;

        for (int i = 0; i < arr.size(); i++) {
            // Number
            if (arr[i] != "+" &&
                arr[i] != "-" &&
                arr[i] != "*" &&
                arr[i] != "/" &&
                arr[i] != "^") {
                values.push(stoi(arr[i]));
            }
            // Operator
            else {
                while (!ops.empty() &&
                       (precedence(ops.top()) > precedence(arr[i]) ||
                       (precedence(ops.top()) == precedence(arr[i])
                        && arr[i] != "^"))) {

                    applyTop(values, ops);
                }
                ops.push(arr[i]);
            }
        }

        // Apply remaining operators
        while (!ops.empty()) {
            applyTop(values, ops);
        }
        return values.top();
    }
};