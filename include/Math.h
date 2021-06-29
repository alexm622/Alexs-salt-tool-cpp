#ifndef MATH_H
#define MATH_H

#include "string"

class Math
{
    public:
        Math();
        virtual ~Math();

        static int binaryToDecimal(int n);
        static std::string decToBinary(int n);

    protected:

    private:
};

#endif // MATH_H
