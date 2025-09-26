#include "hcmcampaign.h"
using namespace std;

int main()
{

    cout << "----- Sample Testcase 01 -----" << endl;
    Configuration *config = new Configuration("tests/initial_config.txt");
    cout << config->str() << endl;
    delete config;
    return 0;
}
