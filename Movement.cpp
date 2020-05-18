#include "Movement.h"

namespace corsim
{
    int Default::move(int dt, std::vector<Subject> &subj) 
    {
        int countInf = 0;

        for (Subject& s : subj)
        {
            s.set_x(s.x() + s.dx() * dt);
            s.set_y(s.y() + s.dy() * dt);

            if(s.infected()) 
            {
                countInf++;
            }
        }

        return countInf;
    }

    int Lockdown::move(int dt, std::vector<Subject> &subj) 
    {
        for (int i = 0; i < (subj.size() * 0.75); i++)
        {
            subj.at(i).setLock(true);
        }

        int countInf = 0;

        for (Subject& s : subj)
        {
            if (!s.getLock())
            {
                s.set_x(s.x() + s.dx() * dt);
                s.set_y(s.y() + s.dy() * dt);
            }
            if(s.infected()) 
            {
                countInf++;
            }
        }

        return countInf;
    }

        int BThree::move(int dt, std::vector<Subject> &subj) 
    {
        int countInf = 0;

        for (Subject& s : subj)
        {
            s.set_x(s.x() + s.dx() * dt);
            s.set_y(s.y() + s.dy() * dt);

            if(s.infected()) 
            {
                countInf++;
                
                s.addInfectionDay();
            }

            // two weeks
            if (s.daysInfected() > 14)
            {
                s.giveMedicine();
            }
        }

        return countInf;
    }
}