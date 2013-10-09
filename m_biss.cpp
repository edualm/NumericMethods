//
//  Bissection Method
//
//  No Copyright Claimed.
//

#include <iostream>
#include <iomanip>

#include <math.h>

//
//  Precision Macro (Do Not Change!)
//

#define precision(x) res * pow(10,x)

#define prec 6

//
//  Function
//

#define f(x) cos(x) + exp(2 - x)

double low = 3.0f;
double high = 2.0f;

int main(int argc, const char * argv[]) {
    unsigned int iter = 0;
    
    while (true) {
        if (f(low) * f(high) < 0) {
            float x = (low + high)/2;
            
            double res = f(x);
            
            if (!floor(precision(prec))) {
                std::cout << "The value of X is " << std::setprecision(prec + 2) << x << "." << std::endl;
                
                break;
            }
            
            iter++;
            
            std::cout << "Running iteration " << iter << "..." << std::endl;
            
            if (res > 0)
                high = x;
            else
                low = x;
        } else {
            std::cout << "Error!";
            
            return 1;
        }
    }
    
    return 0;
}
