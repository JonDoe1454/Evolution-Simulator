#include "RandomInt.h"

int RandomInt::GetRandomInt(int minNum, int maxNum){
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution dist(minNum, maxNum);
    return dist(mt);
}
