#pragma once
#include <vector>

#include "simulation.h"

namespace corsim
{
    class IMoveStrategy {
        public:
        virtual int move(int dt, std::vector<Subject> &subj) = 0;
    };
}