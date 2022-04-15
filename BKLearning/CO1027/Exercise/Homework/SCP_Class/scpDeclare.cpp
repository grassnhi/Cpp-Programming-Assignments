/*
SCP Foundation's classified archives consist of records of paranormal objects. 
The information of each object is stored using struct SCP with following requirements:

    id:                 integer, the identifier (or item number) of the object.
    objClass:           integer, the object class.
    speConProcedures:   string, specification of the object's special containment procedures.
    description:        string, description of the object.
    addendums:          string*, array of addendums describing additional information about the object.
    numAddendums:       integer, the number of addendums attached.

Declare struct SCP with mentioned requirements.

Note: 
    Libraries iostream and string have been imported, and namespace std has been used.
*/



struct SCP {
    int id;
    int objClass;
    string speConProcedures;
    string description;
    string* addendums;
    int numAddendums;
    
    struct SCP* next;
};