#include "hcmcampaign.h"
using namespace std;

int main() {
        cout << "----- Testcase COMPLEX -----" << endl;
    HCMCampaign* campaign = new HCMCampaign("tests/ct_test2.txt");
    cout << "* Before the fight" << endl;
    cout << campaign->printResult() << endl;
    campaign->run();
    cout << "* After the fight" << endl;
    cout << campaign->printResult() << endl;
    delete campaign;
    return 0;
}
