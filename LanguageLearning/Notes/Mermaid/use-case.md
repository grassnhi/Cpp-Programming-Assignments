```mermaid

graph TD;
    Student -->(Log in/out);
    Student -->(Upload Document);
    Student -->(Select Printer);
    Student -->  (Configure Printing);
    Student --> (Purchase Pages);
    Student -->  (View Printing History);
    Student -->  (View Printing Summary);

    SPSO -->  (Manage Printers);
    SPSO -->  (Configure System);
    SPSO -->  (Monitor Printing);
    SPSO -->  (Generate Reports);
    SPSO -->  (Manage Users);

    Printer -->  (Print Document);
    Printer -->  (Report Status);

    HCMUT_SSO -->  (Authenticate User);
    BKPay -->  (Process Payment);

```
