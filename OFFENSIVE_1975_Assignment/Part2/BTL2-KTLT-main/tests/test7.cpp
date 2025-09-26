#include "hcmcampaign.h"
using namespace std;

int main()
{
    cout << "----- Sample Testcase 06 -----" << endl;
    Unit **unitArrayOfLiber6 = new Unit *[1];
    Vehicle tankOfLiber6(20, 20, Position(1, 2), MORTAR);
    unitArrayOfLiber6[0] = &tankOfLiber6;
    LiberationArmy *liberationArmy6 = new LiberationArmy(unitArrayOfLiber6, 0, "LiberationArmy", 0);
    cout << liberationArmy6->str() << endl;
    return 0;
}
