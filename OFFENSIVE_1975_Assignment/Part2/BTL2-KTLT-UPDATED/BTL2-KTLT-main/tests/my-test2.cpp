#include "hcmcampaign.h"
using namespace std;

int main()
{
    cout << "----- Triet's test 2 -----" << endl;
    HCMCampaign *campaign = new HCMCampaign("tests/my_cf2.txt");
    cout << "** Before the fight" << endl;
    cout << campaign->printResult() << endl;
    cout << "** After the fight" << endl;
    campaign->run();
    cout << campaign->printResult() << endl;
    delete campaign;
    return 0;
}
