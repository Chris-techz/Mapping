#ifndef MAPPING_H
#define MAPPING_H

class tableau
{
private:

        int x1;
        int x2;
        int y1;
        int y2;
        int nb_pts;

public:

        tableau();
        ~tableau();
        void tab_disp();
        void acq_pts();
};

#endif // MAPPING_H
