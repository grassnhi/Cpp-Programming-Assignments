#include "hcmcampaign.h"
using namespace std;

int main()
{

    cout << "----- Sample Testcase 02 -----" << endl;
    Vehicle tankOfLiber(20, 20, Position(1, 2), MORTAR);
    Vehicle truckOfLiber(15, 10, Position(2, 2), TRUCK);
    Infantry sniperOfLiber(10, 20, Position(1, 1), SNIPER);

    Vehicle tankOfAr(5, 20, Position(3, 2), MORTAR);
    Vehicle truckOfAr(1, 10, Position(3, 1), TRUCK);
    Infantry sniperOfAr(7, 20, Position(3, 3), SNIPER);

    Unit **unitArrayOfLiber = new Unit *[3];
    unitArrayOfLiber[0] = &tankOfLiber;
    unitArrayOfLiber[1] = &truckOfLiber;
    unitArrayOfLiber[2] = &sniperOfLiber;

    Unit **unitArrayOfAr = new Unit *[3];
    unitArrayOfAr[0] = &tankOfAr;
    unitArrayOfAr[1] = &truckOfAr;
    unitArrayOfAr[2] = &sniperOfAr;

    LiberationArmy *liberationArmy = new LiberationArmy(unitArrayOfLiber, 3, "LiberationArmy", 0);
    cout << liberationArmy->str() << endl;
    ARVN *arvn = new ARVN(unitArrayOfAr, 3, "ARVN", 0);
    cout << arvn->str() << endl;

    Army *enemyLiber = arvn;
    liberationArmy->fight(enemyLiber, false);
    Army *enemyAr = liberationArmy;
    arvn->fight(enemyAr, false);

    cout << "* After the fight" << endl;
    cout << liberationArmy->str() << endl;
    cout << arvn->str() << endl;

    delete liberationArmy;
    delete arvn;
    delete[] unitArrayOfLiber;
    delete[] unitArrayOfAr;
}
