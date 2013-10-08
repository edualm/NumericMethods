//
//  Método da Tangente (ou Newton) (Non-Linear System)
//
//  No Copyright Claimed.
//

#include <iostream>
#include <math.h>

//
//  Functions and Derivates
//

#define func1(x, y) 2 * pow(x, 2) - x * y - 5 * x + 1
#define dfunc1x(x, y) 4 * x - y - 5
#define dfunc1y(x, y) -x

#define func2(x, y) x + 3 * log(x) - pow(y, 2)
#define dfunc2x(x, y) (x + 3) / x
#define dfunc2y(x, y) -2 * y

//
//  Stop Criteria
//

#define sc 0.00001f

//
//  Initial Value
//

#define iv_x 4.00f
#define iv_y 4.00f

struct axis {
    double x;
    double y;
};

int main(int argc, const char * argv[]) {
    double f1, df1x, df1y, f2, df2x, df2y, xn1, yn1;
    
    axis last_val, last_val2;
    
    int iter = 0;
    
    last_val.x = iv_x;
    last_val.y = iv_y;
    
    last_val2.x = 0.00f;
    last_val2.y = 0.00f;
    
    while (true) {
        f1 = func1(last_val.x, last_val.y);
        df1x = dfunc1x(last_val.x, last_val.y);
        df1y = dfunc1y(last_val.x, last_val.y);
        
        f2 = func2(last_val.x, last_val.y);
        df2x = dfunc2x(last_val.x, last_val.y);
        df2y = dfunc2y(last_val.x, last_val.y);
        
        xn1 = last_val.x - ((f1 * df2y - f2 * df1y) / (df1x * df2y - df2x * df1y));
        yn1 = last_val.y - ((f2 * df1x - f1 * df2x) / (df1x * df2y - df2x * df1y));
        
        last_val2 = last_val;
        
        last_val.x = xn1;
        last_val.y = yn1;
        
        iter++;
        
        std::cout << last_val.x << ", " << last_val.y << " || " << last_val2.x << ", " << last_val2.y << std::endl;
        
        std::cout << "Running Iteration " << iter << std::endl;
        
        if (fabs(last_val2.x - last_val.x) < sc && fabs(last_val2.y - last_val.y) < sc) {
            std::cout << "Final Value: (" << xn1 << ", " << yn1 << ")" << std::endl;
            
            return 0;
        }
    }
    
    return 1;
}
