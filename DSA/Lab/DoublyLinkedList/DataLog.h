class DataLog
{
private:
    list<int> logList;
    list<int>::iterator currentState;

public:
    DataLog();
    DataLog(const int &data);
    void addCurrentState(int number);
    void subtractCurrentState(int number);
    void save();
    void undo();
    void redo();

    int getCurrentStateData()
    {
        return *currentState;
    }
    
    void printLog()
    {      
        for (auto i = logList.begin(); i != logList.end(); i++) {
            if(i == currentState) cout << "Current state: ";
            cout << "[ " << *i << " ] => ";
        }
        cout << "END_LOG";
    }
};

DataLog::DataLog()
{
    /*
     * TODO:  add the first state with 0
     */
    logList.push_back(0);
    currentState = logList.begin();
}

DataLog::DataLog(const int &data)
{
    /*
     * TODO:  add the first state with data
     */
    logList.push_back(data);
    currentState = logList.begin();
}

void DataLog::addCurrentState(int number)
{
    /*
     * TODO: Increase the value of current state by number
     */
    *currentState += number;
}

void DataLog::subtractCurrentState(int number)
{
    /*
     * TODO: Decrease the value of current state by number
     */
    *currentState -= number;
}

void DataLog::save()
{
    /*
     * TODO: This function will create a new state, copy the data of the currentState
     *       and move the currentState Iterator to this new state. If there are other states behind the 
     *       currentState Iterator, we delete them all before creating a new state.
     */
    list<int>::iterator tmp = currentState;
    tmp++;
    if (tmp != logList.end())
        logList.erase(tmp, logList.end());

    logList.push_back(*currentState);

    currentState = --logList.end();
}

void DataLog::undo()
{
    /*
     * TODO: Switch to the previous state of the data
     *       If this is the oldest state in the log, nothing changes
     */
    if (currentState != logList.begin())
        currentState--;
}

void DataLog::redo()
{
    /*
     * TODO: Switch to the latter state of the data
     *       If this is the latest state in the log, nothing changes
     */
    if (currentState != --logList.end())
        currentState++;
}

////////////////////////////////////////////////////////////////////////////

class DataLog
{
private:
    list<int> logList;
    list<int>::iterator currentState;

public:
    DataLog();
    DataLog(const int &data);
    void addCurrentState(int number);
    void subtractCurrentState(int number);
    void save();
    void undo();
    void redo();

    int getCurrentStateData()
    {
        return *currentState;
    }
    
    void printLog()
    {      
        for (auto i = logList.begin(); i != logList.end(); i++) {
            if(i == currentState) cout << "Current state: ";
            cout << "[ " << *i << " ] => ";
        }
        cout << "END_LOG";
    }
};

DataLog::DataLog()
{
	logList.push_back(0);
	currentState = logList.begin();
}

DataLog::DataLog(const int &data)
{
	logList.push_back(data);
	currentState = logList.begin();
}

void DataLog::addCurrentState(int number)
{
	*currentState += number;
}

void DataLog::subtractCurrentState(int number)
{
	*currentState -= number;
}

void DataLog::save()
{
	list<int>::iterator newState = currentState;
    newState++;
    while(newState != logList.end()){
        newState = logList.erase(newState);
    }
    logList.push_back(*currentState);
    currentState++;
}

void DataLog::undo()
{
	if(currentState != logList.begin()){
        currentState = prev(currentState, 1);
    }
}

void DataLog::redo()
{
	list<int>::iterator latter = currentState;
    latter++;
    if(latter != logList.end()){
        currentState++;
    }
}