
#ifndef 	__DEBUG__
#define 	__DEBUG__

#include "io.h"

// TODO: add flags

#define MCO_PIN  (PC4)

// Exposes different clocks to the MCO pin (PC4)
// Pin should be push-pull multiplexed output
void enable_mco_output();


#endif // __DEBUG__
