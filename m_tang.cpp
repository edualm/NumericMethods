//
//  Método da Tangente (ou Newton)
//
//  No Copyright Claimed.
//

#include <iostream>
#include <math.h>

//
//  Function and Derivate
//

#define func1(x) x-2*log(x)-5
#define dfunc1(x) 1-(2/x)

//
//  Stop Criteria
//

#define sc 0.001f

//
//  Initial Value
//

#define iv 0.01f

int main(int argc, const char * argv[]) {
    double last_val, last_val2, fx, dfx, xn1;
    
    int iter = 0;
    
    last_val = iv;
    last_val2 = 0.00f;
    
    while (true) {
        fx = func1(last_val);
        dfx = dfunc1(last_val);
        
        xn1 = last_val - fx/dfx;
        
        last_val2 = last_val;
        last_val = xn1;
        
        iter++;
        
        std::cout << "Running Iteration " << iter << std::endl;
        
        if (fabs(last_val2 - last_val) < sc) {
            std::cout << "Final Value: " << xn1 << std::endl;
            
            return 0;
        }
    }
    
    return 1;
}
