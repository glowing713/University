#include "calc.h"

int main(int argc, const char * argv[]) {
    NumPad calc1;
    
    calc1.formula();    // 계산식 입력
    calc1.calculate();  // 계산 수행
    
    return 0;
}
