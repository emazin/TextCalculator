#include <iostream>

class Operation
{
public:
    Operation(double o1, double o2) :
        op1(o1), op2(o2)
    {}

    double calculate(char operation)
    {
        // Perform the specific operation here:
        double result = 0;
        if (operation == '+')
            result = op1 + op2;
        else if (operation == '-')
            result = op1 - op2;
        else if (operation == '*')
            result = op1 * op2;
        else if (operation == '/')
            result = op1 / op2;
        else if (operation == '^')
            result = pow(op1, op2);
        else
            throw 0;

        return result;
    }

private:
    double op1, op2;
};

int main()
{
    while (true)
    {
        std::cout << "Enter your operation: ";
        char operation;
        double operand1, operand2;
        std::cin >> operand1 >> operation >> operand2;
        Operation op(operand1, operand2);
        std::cout << "Answer: " << operand1 << operation << operand2
            << " = " << op.calculate(operation) << " \n";
    }
 }
