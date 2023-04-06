vector<int> nums = {15, 2, 4, 10};
    vector<int> result = nextGreaterElement(nums);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    nums = {1, 4, 6, 9, 6};
    result = nextGreaterElement(nums);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;