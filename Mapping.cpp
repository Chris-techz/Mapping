#include "Mapping.h"
#include <iostream>

using namespace std;

tableau::tableau()
{

}

tableau::~tableau()
{

}

void tableau::acq_pts()
{
        cout << "entrez x1 : ";
        cin >> x1;
        cout << "entrez y1 : ";
        cin >> y1;
        cout << "entrez x2 : ";
        cin >> x2;
        cout << "entrez y2 : ";
        cin >> y2;
}

void tableau::tab_disp()
{
        for (int i = 9; i > 0; i--)
        {
                if ((i != y1) && (i != y2))
                {
                        cout << i << endl;
                }
                else if (i == y1)
                {
                        cout << i;
                        for (int j = 0; j < x1; j++)
                                cout << " ";
                        cout << " *" << endl;
                }
                else if (i == y2)
                {
                        cout << i;
                        for (int j = 0; j < x2; j++)
                                cout << " ";
                        cout << " *" << endl;
                }
        }

        for (int j = 0; j <= 9; j++)
        {
                cout << j << " ";
        }

        cout << endl << endl;
}
