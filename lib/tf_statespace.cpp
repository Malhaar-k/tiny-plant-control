#include "tf_statespace.h"
#include "stdint.h"
#include "matrix_helper.h"


namespace tfStateSpace{
    tfStateSpace_t::tfStateSpace_t(mat_s * A, mat_s * B, mat_s * C, mat_s * D){
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;

        this->X = mat_zeros(A->rows, 1); // Initial states are zero 
        this->Xdot = mat_zeros(A->rows, 1); // Initial states are zero
    }

    tfStateSpace_t::~tfStateSpace_t(){
        mat_delete(this->A);
        mat_delete(this->B);
        mat_delete(this->C);
        mat_delete(this->D);
        mat_delete(this->Xdot);
        mat_delete(this->X);

    }

    /// @brief Get the output matrix of the state space system. 
    /// @param U Input Matrix
    /// @param timeStepSize `dt` or the time step size
    /// @return `Y` Output matrix of the system
    mat_s * tfStateSpace_t::tfGetOutput(mat_s * U, float timeStepSize){
        mat_scal_mult(this->Xdot, timeStepSize); // Xdot*dt

        mat_add(this->X, this->Xdot, X); // X + Xdot*dt. Euler integration
        // If this does not work, I need to delete Xdot and create a new one at run time
        mat_s * AX = mat_mult(this->A, this->X); // AX
        mat_s * BU = mat_mult(this->B, U); // BU
        mat_add(AX, BU, this->Xdot); // XDot = AX + BU

        mat_delete(AX);
        mat_delete(BU);
        return mat_mult(this->C, this->X); // Y = CX + DU
    }
}