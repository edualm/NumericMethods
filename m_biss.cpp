//
//  Bissection Method
//
//  No Copyright Claimed.
//

#include <iostream>

#include <math.h>

#define precision(x) res * pow(10,x)

#define f(x) x - 2 * log(x) - 40

double low = 45.0f;
double high = 55.0f;

int main(int argc, const char * argv[]) {
    unsigned int iter = 0;
    
    while (true) {
        if (f(low) * f(high) < 0) {
            float x = (low + high)/2;
            
            double res = f(x);
            
            if (!floor(precision(5))) {
                std::cout << "The value of X is " << x << "." << std::endl;
                
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
