//
// Created by Yahel Tubul on 03/05/2026.
//
#include "LocationEstimator.h"

LocationEstimator::LocationEstimator(double gain) {
    Kal_gain = gain;
    estimatX = 0;
    estimatY = 0;
    estimatZ = 0;
}