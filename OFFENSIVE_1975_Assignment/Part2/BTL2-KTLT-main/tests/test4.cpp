#include "hcmcampaign.h"
using namespace std;

int main()
{
    cout << "----- Sample Testcase 04 -----" << endl;
    Configuration *config4 = new Configuration("tests/initial_config.txt");
    cout << config4->str() << endl;
    delete config4;
    return 0;
}
