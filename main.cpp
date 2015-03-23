#include <iostream>
#include "Fidaki.h"
#include "Config.h"
#include "Snake.h"


using namespace std;

int main()
{

    Fidaki f(1);

    while(f.nextMove()){}

    return 0;

}
