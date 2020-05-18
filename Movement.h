#pragma once

#include "IMoveStrategy.h"

namespace corsim
{
    class Default : public IMoveStrategy
    {
        public:
        int move(int dt, std::vector<Subject> &subj);
    };

    class Lockdown : public IMoveStrategy
    {
        public:
        int move(int dt, std::vector<Subject> &subj);
    };

    // Used for assignment B.3
    class BThree : public IMoveStrategy
    {
        public:
        int move(int dt, std::vector<Subject> &subj);
    };
}