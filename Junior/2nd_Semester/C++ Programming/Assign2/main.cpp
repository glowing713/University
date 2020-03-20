#include "circle.h"

int main() {
    int n = 0;
    
    cout << "생성할 원의 개수를 입력하시오: ";
    cin >> n;
    
    Circle *c = new Circle[n];
    
    for(int i = 0; i < n; ++i){
        c[i].setRadius(i);
        c[i].setCenterPoint(i*1.5, i*1.5);
    }
    
    for(int i = 0; i < n; ++i){
        c[i].getRadius();
        c[i].getCenterPoint();
    }
    
    return 0;
}
