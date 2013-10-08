//
//  Método de Picard-Peano (Non-Linear System)
//
//  No Copyright Claimed.
//

#include <iostream>

#include <math.h>

//
// Function
//

#define func1(x, y) sqrt((x*y+5*x-1)/2)
#define func2(x, y) sqrt(x+3*log(x))

//
// Stop Criteria
//

#define sc 0.00001f

//
// Initial Value
//

#define iv_x 4.0f
#define iv_y 4.0f

struct axis {
    double x;
    double y;
};

int main(int argc, const char * argv[]) {
    double fx, fy;
    
    axis last_val, last_val2;
    
    int iter = 0;
    
    last_val.x = iv_x;
    last_val.y = iv_y;
    
    last_val2.x = 0.00f;
    last_val2.y = 0.00f;
    
    while (true) {
        fx = func1(last_val.x, last_val.y);
        
        last_val2.x = last_val.x;
        last_val.x = fx;
        
        fy = func2(last_val.x, last_val.y);
        
        last_val2.y = last_val.y;
        last_val.y = fy;
        
        iter++;
        
        std::cout << "Running Iteration " << iter << std::endl;
        
        if (fabs(last_val2.x - last_val.x) < sc && fabs(last_val2.y - last_val.y) < sc) {
            std::cout << "Final Value: (" << fx << ", " << fy << ")" << std::endl;
            
            return 0;
        }
    }
    
    return 1;
}
