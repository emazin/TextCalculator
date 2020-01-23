#include <iostream>

class Operation
{
public:
    Operation(double o1, double o2) :
        op1(o1), op2(o2)
    {}

    double calculate(char operation)
    {
        return op1 + op2;
    }

private:
    double op1, op2;
};

int main()
{
    std::cout << "Enter your operation: ";
    char operation;
    double operand1, operand2;
    std::cin >> operand1 >> operation >> operand2;
    Operation op(operand1, operand2);
    std::cout << "Answer: " << operand1 << operation << operand2
        << " = " << op.calculate(operation) << " \n";
}
