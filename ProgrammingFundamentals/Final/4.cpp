#include<iostream>

using namespace std;

class ImmutableString {
    char* str;
public:
	ImmutableString() {
        
	}

	ImmutableString (const char* s) {

	}
	
	~ImmutableString() {

	}
	
	int str_find(const ImmutableString& other) {
        return 0;
	}

	int str_compare(const ImmutableString& other) {
        return 0;
	}

	int getSize() {
        return 0;
	}

	char charAt(int idx) {
        return 0;
	}

	// Already implemented, do not change
	friend ostream& operator<< (ostream& out, const ImmutableString& s) {
		out << s.str;
		return out;
	}
};

int main(){
    const char* tmp1 = "abcd";
    const char* tmp2 = "bc";
    const char* tmp3 = "az";

    ImmutableString s1(tmp1);
    ImmutableString s2(tmp2);
    ImmutableString s3(tmp3);

    cout << "check charAt: " << s1.charAt(0) << '\n';
    s1.charAt(4);
    cout << "check str_find: " <<  s1.str_find(s2) << '\n';
    cout << "check str_compare: " << s1.str_compare(s3);
    return 0;
}