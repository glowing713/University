#include "point.h"

int main(){
    Point *p = new Point[3];
    
    p[0].setPos(2.3, 5.5, 3.2);
    p[1].setPos(7.43, 3.4, 6.4);
    p[2].setPos(8.5, 2.3, 73.2);
    
    for(int i = 0; i < 3; i++){
        p[i].getPos();
    }
    
    return 0;
}
