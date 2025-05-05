bool LiberationArmy::findSmallest(int target, vector<Unit*>& selectedUnits) {
    vector<Unit*> allUnits;
    for (UnitNode* temp = unitList->getHead(); temp; temp = temp->next) {
        allUnits.push_back(temp->unit);
    }

    sort(allUnits.begin(), allUnits.end(), [](Unit* a, Unit* b) {
        return a->getAttackScore() < b->getAttackScore();
    });

    vector<Unit*> bestGroup, currentGroup;
    int bestScore = INT_MAX;
    findCombination(allUnits, 0, target, 0, currentGroup, bestGroup, bestScore);

    if (!bestGroup.empty()) {
        selectedUnits = bestGroup;
        return true;
    }
    return false;
}
