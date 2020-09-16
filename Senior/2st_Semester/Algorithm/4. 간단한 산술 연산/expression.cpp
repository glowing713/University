/*
 연산자 ASCII CODE
 *: 42
 /: 47
 %: 37
 +: 43
 -: 45
 */
#include <cstdio>
#include <stack>
using namespace std;

template<typename T >inline void clear ( std::stack< T >& Stacks ) {
    while (false == Stacks.empty()) {
        Stacks.pop( );
    }
}

int calculate(int num1, int num2, char oper) {
    int result = 0;
    if (oper == '*') {
        result = num1 * num2;
    }else if (oper == '/') {
        result = num1 / num2;
    }else if (oper == '%') {
        result = num1 % num2;
    }else if (oper == '+') {
        result = num1 + num2;
    }else if (oper == '-') {
        result = num1 - num2;
    }
    
    return result;
}



int main() {
    FILE* ifs;
    FILE* ofs;
    ifs = fopen("expression.inp", "rt");
    ofs = fopen("expression.out", "wt");
    
    int cycles = 0;
    int order[50] = {0, }; // 연산자 우선순위 표시할 배열
    
    order[int('*')] = order[int('/')] = order[int('%')] = 2;    // *, /, % 는 우선순위 2
    order[int('+')] = order[int('-')] = 1;  // +, - 는 우선순위 1
    
    fscanf(ifs, "%d", &cycles);
    
    for (int cycle = 0; cycle < cycles; ++cycle) {
        stack<char> operators; // 연산자 저장 스택
        stack<int> operands;  // 피연산자 저장 스택
        int number = 0;
        char oper = 0;
        bool errorFlag = false; // 제수가 0인 경우 에러메세지 출력(n / 0 or n % 0)
        
        clear(operators);
        clear(operands);
        
        while (1) {
            fscanf(ifs, " %d %c", &number, &oper);
            // 피연산자는 피연산자 스택에 푸시
            operands.push(number);
            // 연산자는 다음과 같이 처리한다.
            if (oper == '=') break; // = 가 식의 끝임
            
            // 1. 스택이 비어있지 않으면 우선순위에 따라 처리
            while (!operators.empty() && order[int(operators.top())] >= order[int(oper)]) {
                int t_num2 = operands.top();
                operands.pop();
                int t_num1 = operands.top();
                operands.pop();
                char t_oper = operators.top();
                operators.pop();
                
                // 에러케이스를 거르는 작업
                if (t_num2 == 0 && (t_oper == '/' || t_oper == '%')) {
                    fprintf(ofs, "Error!");
                    if (cycle < cycles - 1) fprintf(ofs, "\n");
                    errorFlag = true;
                    break;
                }
                operands.push(calculate(t_num1, t_num2, t_oper));
            }
            
            // 에러케이스면 다음작업으로 돌아감
            if (errorFlag) {
                while (1) {
                    fscanf(ifs, " %d %c", &number, &oper);
                    if (oper == '=')    break;
                }
                break;
            }
            // 2. 스택이 비어있든 비어있지 않든, 새로 읽어온건 푸시
            operators.push(oper);
        }
        // 다 읽어왔으니깐 스택에 남은 연산만 처리
        while (!errorFlag && !operators.empty()) {
            int t_num2 = operands.top();
            operands.pop();
            int t_num1 = operands.top();
            operands.pop();
            char t_oper = operators.top();
            operators.pop();
            
            // 에러케이스를 거르는 작업
            if (t_num2 == 0 && (t_oper == '/' || t_oper == '%')) {
                fprintf(ofs, "Error!");
                if (cycle < cycles - 1) fprintf(ofs, "\n");
                errorFlag = true;
                break;
            }
            
            operands.push(calculate(t_num1, t_num2, t_oper));
        }
        
        
        if (!errorFlag){
            fprintf(ofs, "%d", operands.top());
            if (cycle < cycles - 1) fprintf(ofs, "\n");
            operands.pop();
        }
    }
    
    
    fclose(ifs);
    fclose(ofs);
    
    return 0;
}
