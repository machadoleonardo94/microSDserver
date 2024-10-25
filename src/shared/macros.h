//? ------------------------------------------------------------------------------------------
//*! This file contains all macros used in the project.
//? ------------------------------------------------------------------------------------------

#ifndef PROJECT_GLOBAL_MACROS
#define PROJECT_GLOBAL_MACROS

//* Hardware pinout.
#include "pinout.h"
#include "shared/interfaces.h"

//* ---------------------- Macros ----------------------

//*  --- MUX MACROS ---
#define SET_MUX_HIGH_IMPEDANCE                 \
    digitalWrite(digital_out_mux_addr0, HIGH); \
    digitalWrite(digital_out_mux_addr1, HIGH); \
    digitalWrite(digital_out_mux_addr2, HIGH); \
    digitalWrite(digital_out_mux_addr3, HIGH);

#endif
