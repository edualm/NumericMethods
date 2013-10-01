//
//  Método de Picard-Peano
//
//  No Copyright Claimed.
//

#include <iostream>

#include <math.h>

//
// Function
//

#define func1(x) exp((x-5)/2)

//
// Stop Criteria
//

#define sc 0.001f

//
// Initial Value
//

#define iv 0.1f

int main(int argc, const char * argv[]) {
    double last_val, last_val2, fx;
    
    int iter = 0;
    
    last_val = sc;
    last_val2 = 0.00f;
    
    while (true) {
        fx = func1(last_val);
        
        last_val2 = last_val;
        last_val = fx;
        
        iter++;
        
        std::cout << "Running Iteration " << iter << std::endl;
        
        if (fabs(last_val2 - last_val) < sc) {
            std::cout << "Final Value: " << fx << std::endl;
            
            return 0;
        }
    }
    
    return 1;
}
