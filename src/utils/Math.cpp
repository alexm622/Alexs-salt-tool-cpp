#include "Math.h"

int Math::binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;

    int base = 1;

    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;

        dec_value += last_digit * base;

        base = base * 2;
    }

    return dec_value;
}

std::string Math::decToBinary(int n)
{
    // array to store binary number
    int binaryNum[3];

    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    std::string out;

    for(int in : binaryNum){
        int temp = in;
        out += std::to_string(temp);
    }

    return out;
}
