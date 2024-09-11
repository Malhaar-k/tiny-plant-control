#ifndef _TF_STATESPACE_H_
#define _TF_STATESPACE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "matrix_helper.h"

namespace tfStateSpace{
    
    class tfStateSpace_t{
        private:
            mat_s * Xdot; // dx/dt
            mat_s * X; // state vector


        public: 
            // State matrices
            mat_s * A; 
            mat_s * B;
            mat_s * C;
            mat_s * D;
    
        public: 
            tfStateSpace_t(mat_s * A, mat_s * B, mat_s * C, mat_s * D);
            ~tfStateSpace_t();
            mat_s * tfGetOutput(mat_s * input, float timeStepSize);
    };

}

#ifdef __cplusplus
}
#endif

#endif