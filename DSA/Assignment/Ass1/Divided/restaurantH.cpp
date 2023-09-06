#include "main.h"

restaurant* res = NULL;
table* wait = NULL;
table* printwait = NULL;
table* recent = NULL;
table* printRes = NULL;
int checkTable = -1;
void REG(int ID, string NAME, int AGE) {
	if (AGE < 16) return;
	if (AGE < 1 || AGE > 115) return;
	if (ID == -1) {
		table* t = res->recentTable;
		//get head 
		while (t->ID < t->next->ID) {
			t = t->next;
		}
		t = t->next;
		int count = 0;
		while (count < 15) {
			if (t->name == "") {
				t->name = NAME;
				t->age = AGE;
				res->recentTable = t;
				break;
			}
			t = t->next;
			count++;
		}
		if (count < 15) {
			if (recent == NULL) recent = new table(t->ID, NAME, AGE, NULL);
			else {
				table* temp = recent;
				while (temp->next != NULL) {
					temp = temp->next;
				}
				temp->next = new table(t->ID, NAME, AGE, NULL);
			}
			//add printRes
			if (printRes == NULL) printRes = new table(t->ID, NAME, AGE, NULL);
			else {
				table* temp = printRes;
				bool check = false;
				while (temp->next != NULL) {
					if (temp->age == AGE && temp->name == NAME) check = true;
					temp = temp->next;
				}
				if (temp->age == AGE && temp->name == NAME) check = true;
				if (check == false) temp->next = new table(t->ID, NAME, AGE, NULL);
			}
		}
		else {
			if (wait == NULL) {
				wait = new table(-1, NAME, AGE, NULL);
				//add
				table* temp = printRes;
				while (temp->next != NULL) {
					temp = temp->next;
				}
				temp->next = new table(-1, NAME, AGE, NULL);
			}
			else {
				table* temp = wait;
				int c = 1;
				while (temp->next != NULL) {
					if (c == 15) break;
					temp = temp->next;
					c++;
				}
				if (c != 15) {
					temp->next = new table(-1, NAME, AGE, NULL);
					//add
					temp = printRes;
					while (temp->next != NULL) {
						temp = temp->next;
					}
					temp->next = new table(-1, NAME, AGE, NULL);
				}
			}
			if (printwait == NULL) printwait = new table(-1, NAME, AGE, NULL);
			else {
				table* temp = printwait;
				int c = 1;
				while (temp->next != NULL) {
					if (c == 15) break;
					temp = temp->next;
					c++;
				}
				if (c != 15) temp->next = new table(-1, NAME, AGE, NULL);
			}
		}
	}
	else {
		table* t = res->recentTable;
		int c = 0;
		while (t->ID != ID && c < 15) {
			t = t->next;
			c++;
		}
		if (c < 15 && t->name == "") {
			t->name = NAME;
			t->age = AGE;
			res->recentTable = t;
			int count = 0;
			table* temp = recent;
			while (temp != NULL) {
				count++;
				temp = temp->next;
			}
			if (recent == NULL) recent = new table(ID, NAME, AGE, NULL);
			else {
				table* temp = recent;
				while (temp->next != NULL) {
					temp = temp->next;
				}
				temp->next = new table(ID, NAME, AGE, NULL);
			}
			//add
			if (printRes == NULL) printRes = new table(ID, NAME, AGE, NULL);
			else {
				table* temp = printRes;
				bool check = false;
				while (temp->next != NULL) {
					if (temp->age == AGE && temp->name == NAME) check = true;
					temp = temp->next;
				}
				if (temp->age == AGE && temp->name == NAME) check = true;
				if (check == false) temp->next = new table(ID, NAME, AGE, NULL);
			}
		}
		else if (c < 15) {
			int count = 0;
			while (count < 15) {
				if (t->name == "") {
					t->name = NAME;
					t->age = AGE;
					res->recentTable = t;
					break;
				}
				t = t->next;
				count++;
			}
			if (count < 15) {
				if (recent == NULL) recent = new table(t->ID, NAME, AGE, NULL);
				else {
					table* temp = recent;
					while (temp->next != NULL) {
						temp = temp->next;
					}
					temp->next = new table(t->ID, NAME, AGE, NULL);
				}
				//add
				if (printRes == NULL) printRes = new table(t->ID, NAME, AGE, NULL);
				else {
					table* temp = printRes;
					bool check = false;
					while (temp->next != NULL) {
						if (temp->age == AGE && temp->name == NAME) check = true;
						temp = temp->next;
					}
					if (temp->age == AGE && temp->name == NAME) check = true;
					if (check == false) temp->next = new table(t->ID, NAME, AGE, NULL);
				}
			}
			else {
				if (wait == NULL) {
					wait = new table(ID, NAME, AGE, NULL);
					table* temp = printRes;
					while (temp->next != NULL) {
						temp = temp->next;
					}
					temp->next = new table(-1, NAME, AGE, NULL);
				}
				else {
					table* temp = wait;
					int c = 1;
					while (temp->next != NULL) {
						if (c == 15) break;
						temp = temp->next;
						c++;
					}
					if (c != 15) {
						temp->next = new table(ID, NAME, AGE, NULL);
						//add
						temp = printRes;
						while (temp->next != NULL) {
							temp = temp->next;
						}
						temp->next = new table(t->ID, NAME, AGE, NULL);
					}
				}
				if (printwait == NULL) printwait = new table(-1, NAME, AGE, NULL);
				else {
					table* temp = printwait;
					int c = 1;
					while (temp->next != NULL) {
						if (c == 15) break;
						temp = temp->next;
						c++;
					}
					if (c != 15) temp->next = new table(-1, NAME, AGE, NULL);
				}
			}
		}
		else {
			while (t->ID < t->next->ID) {
				t = t->next;
			}
			t = t->next;
			int count = 0;
			while (count < 15) {
				if (t->ID > ID && t->name == "") {
					t->name = NAME;
					t->age = AGE;
					res->recentTable = t;
					break;
				}
				t = t->next;
				count++;
			}
			if (count == 15) {
				while (t->ID < t->next->ID) {
					t = t->next;
				}
				t = t->next;
				count = 0;
				while (count < 15) {
					if (t->name == "") {
						t->name = NAME;
						t->age = AGE;
						res->recentTable = t;
						break;
					}
					t = t->next;
					count++;
				}
			}
			if (count < 15) {
				if (recent == NULL) {
					recent = new table(t->ID, NAME, AGE, NULL);
				}
				else {
					table* temp = recent;
					while (temp->next != NULL) {
						temp = temp->next;
					}
					temp->next = new table(t->ID, NAME, AGE, NULL);
				}
				//add
				if (printRes == NULL) printRes = new table(t->ID, NAME, AGE, NULL);
				else {
					table* temp = printRes;
					bool check = false;
					while (temp->next != NULL) {
						if (temp->age == AGE && temp->name == NAME) check = true;
						temp = temp->next;
					}
					if (temp->age == AGE && temp->name == NAME) check = true;
					if (check == false) temp->next = new table(t->ID, NAME, AGE, NULL);
				}
			}
			else {
				if (wait == NULL) {
					wait = new table(ID, NAME, AGE, NULL);
					table* temp = printRes;
					while (temp->next != NULL) {
						temp = temp->next;
					}
					temp->next = new table(-1, NAME, AGE, NULL);
				}
				else {
					table* temp = wait;
					int c = 1;
					while (temp->next != NULL) {
						if (c == 15) break;
						temp = temp->next;
						c++;
					}
					if (c != 15) {
						temp->next = new table(ID, NAME, AGE, NULL);
						//add
						temp = printRes;
						while (temp->next != NULL) {
							temp = temp->next;
						}
						temp->next = new table(t->ID, NAME, AGE, NULL);
					}
				}
				if (printwait == NULL) printwait = new table(ID, NAME, AGE, NULL);
				else {
					table* temp = printwait;
					int c = 1;
					while (temp->next != NULL) {
						if (c == 15) break;
						temp = temp->next;
						c++;
					}
					if (c != 15) temp->next = new table(ID, NAME, AGE, NULL);
				}
			}
		}
	}
}
void REGM(string NAME, int AGE, int NUM) {
	if (AGE < 16) return;
	if (AGE < 1 || AGE > 115) return;
	if (checkTable != -1) return;
	int count = 0;
	int maxID = -1;
	int num = 0;
	table* t = res->recentTable;
	while (count < 15 + NUM) {
		if (t->name == "") num++;
		else num = 0;
		if (num == NUM) {
			int c;
			if (NUM == 1) c = t->ID;
			else if (t->ID - NUM < 0) c = t->ID + 15 - NUM + 1;
			else c = (t->ID + 15 - NUM + 1) % 15;
			if (c > maxID) {
				maxID = c;
			}
			num--;
		}
		count++;
		t = t->next;
	}
	if (maxID == -1) return;
	else {
		count = 0;
		while (t->ID != maxID) t = t->next;
		t->name = NAME;
		t->age = AGE;
		res->recentTable = t;
		table* last = t->next;
		for (int i = 0; i < NUM - 1; i++) {
			table* temp = last;
			last = last->next;
			delete temp;
		}
		t->next = last;
		if (recent == NULL) recent = new table(t->ID, NAME, AGE, NULL);
		else {
			table* temp = recent;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = new table(t->ID, NAME, AGE, NULL);
		}
		//add
		if (printRes == NULL) printRes = new table(t->ID, NAME, AGE, NULL);
		else {
			table* temp = printRes;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = new table(t->ID, NAME, AGE, NULL);
		}
	}
	checkTable = maxID;
}
void CLE(int ID) {
	if (ID != checkTable) {
		if (recent == NULL) return;
		table* t = res->recentTable;
		int count = 0;
		while (t->ID != ID && count < 15) {
			t = t->next;
			count++;
		}
		if (t->ID == ID && t->name == "") return;
		if (count == 15) return;
		table* temp = recent;
		if (temp->ID == ID) {
			recent = recent->next;
			delete temp;
		}
		else {
			while (temp->next->ID != ID) {
				temp = temp->next;
			}
			table* need = temp->next;
			temp->next = temp->next->next;
			delete need;
		}
		if (printRes->name == t->name && printRes->age == t->age) {
			table* temp = printRes;
			printRes = printRes->next;
			delete temp;
		}
		else {
			table* ta = printRes;
			while (ta->next->age != t->age || ta->next->name != t->name) {
				ta = ta->next;
			}
			table* temp = ta->next;
			ta->next = ta->next->next;
			delete temp;
		}
		t->name = "";
		t->age = 0;
		res->recentTable = t;
		if (wait != NULL) {
			REG(wait->ID, wait->name, wait->age);
			if (printwait->age == wait->age && printwait->name == wait->name) {
				table* t = printwait;
				printwait = printwait->next;
				delete t;
			}
			else {
				table* t = printwait;
				while (t->next->age != wait->age || t->next->name != wait->name) {
					t = t->next;
				}
				table* temp = t->next;
				t->next = t->next->next;
				delete temp;
			}
			table* temp = wait;
			wait = wait->next;
			delete temp;
		}
	}
	else {
		if (recent == NULL) return;
		table* t = res->recentTable;
		while (t->ID != ID) {
			t = t->next;
		}
		if (t->ID == ID && t->name == "") return;
		if (printRes->name == t->name && printRes->age == t->age) {
			table* temp = printRes;
			printRes = printRes->next;
			delete temp;
		}
		else {
			table* ta = printRes;
			while (ta->next->age != t->age || ta->next->name != t->name) {
				ta = ta->next;
			}
			table* temp = ta->next;
			ta->next = ta->next->next;
			delete temp;
		}
		t->name = "";
		t->age = 0;
		res->recentTable = t;
		table* last = t->next;
		int id = t->ID;
		id++;
		if (id != 15) id = id % 15;
		if (id == 0) id = 1;
		while (id != last->ID) {
			table* newTable = new table(id, "", 0, t->next);
			t->next = newTable;
			t = newTable;
			id++;
			if (id != 15) id = id % 15;
		}
		int sum;
		if (id == checkTable) sum = 15;
		else sum = (id - checkTable + 15) % 15;
		if (wait != NULL) {
			for (int i = 0; i < sum && wait != NULL; i++) {
				REG(wait->ID, wait->name, wait->age);
				if (printwait->age == wait->age && printwait->name == wait->name) {
					table* t = printwait;
					printwait = printwait->next;
					delete t;
				}
				else {
					table* t = printwait;
					while (t->next->age != wait->age || t->next->name != wait->name) {
						t = t->next;
					}
					table* temp = t->next;
					t->next = t->next->next;
					delete temp;
				}
				table* temp = wait;
				wait = wait->next;
				delete temp;
			}
		}
		table* temp = recent;
		if (temp->ID == ID) {
			recent = recent->next;
			delete temp;
		}
		else {
			while (temp->next->ID != ID) {
				temp = temp->next;
			}
			table* need = temp->next;
			temp->next = temp->next->next;
			delete need;
		}
		checkTable = -1;
	}
}
void print(table* t) {
	if (t == NULL) return;
	print(t->next);
	cout << t->name << "\n";
}
void PS(int NUM) {
	if (NUM < 1 || NUM > 30) return;
	if (recent == NULL) {
		cout << "Empty\n";
		return;
	}
	table* temp = printRes;
	int count = 0;
	while (temp != NULL) {
		temp = temp->next;
		count++;
	}
	if (NUM <= count) {
		int n = count - NUM;
		temp = printRes;
		for (int i = 0; i < n; i++) {
			temp = temp->next;
		}
		print(temp);
	}
	else if (NUM <= 30) {
		temp = printRes;
		print(temp);
	}
}
void PS() {
	if (recent == NULL) {
		cout << "Empty\n";
		return;
	}
	table* temp = printRes;
	print(temp);
}
void PQ(int NUM) {
	if (NUM < 1 || NUM > 15) return;
	if (printwait == NULL) {
		cout << "Empty\n";
		return;
	}
	table* temp = printwait;
	int count = 0;
	while (temp != NULL) {
		temp = temp->next;
		count++;
	}
	temp = printwait;
	if (NUM <= count) {
		for (int i = 0; i < NUM; i++) {
			cout << temp->name << "\n";
			temp = temp->next;
		}
	}
	else if (NUM <= 15) {
		for (int i = 0; i < count; i++) {
			cout << temp->name << "\n";
			temp = temp->next;
		}
	}
}
void PQ() {
	if (printwait == NULL) {
		cout << "Empty\n";
		return;
	}
	table* temp = printwait;
	int count = 0;
	while (temp != NULL) {
		temp = temp->next;
		count++;
	}
	temp = printwait;
	for (int i = 0; i < count; i++) {
		cout << temp->name << "\n";
		temp = temp->next;
	}
}
void PT() {
	table* temp = res->recentTable;
	if (temp->name != "") cout << temp->ID << "-" << temp->name << "\n";
	temp = temp->next;
	while (temp != res->recentTable) {
		if (temp->name != "") cout << temp->ID << "-" << temp->name << "\n";
		temp = temp->next;
	}
}
void SQ(int NUM) {
	if (wait == NULL) {
		cout << "Empty\n";
		return;
	}
	else if (wait->next == NULL) {
		cout << wait->name << "\n";
		return;
	}
	//stable sort
	table* temp = wait;
	int count = 0;
	while (temp != NULL) {
		count++;
		temp = temp->next;
	}
	if (NUM <= count) {
		table* sortTable = NULL;
		table* x = NULL;
		table* temp = wait;
		while (temp != NULL) {
			int c = 0;
			table* t = printwait;
			while (t != NULL) {
				if (t->name == temp->name && t->age == temp->age) {
					if (sortTable == NULL) x = sortTable = new table(c, temp->name, temp->age, NULL);
					else {
						x->next = new table(c, temp->name, temp->age, NULL);
						x = x->next;
					}
					break;
				}
				t = t->next;
				c++;
			}
			temp = temp->next;
		}
		x = sortTable;
		int c = NUM;
		while (x != NULL && c > 0) {
			table* max = x;
			table* t = x->next;
			while (t != NULL) {
				if (t->age > max->age || (t->age == max->age && t->ID < max->ID)) {
					max = t;
				}
				t = t->next;
			}
			int id = x->ID;
			string name = x->name;
			int age = x->age;
			x->ID = max->ID;
			x->name = max->name;
			x->age = max->age;
			max->ID = id;
			max->name = name;
			max->age = age;
			x = x->next;
			c--;
		}
		x = sortTable;
		temp = wait;
		while (x != NULL) {
			temp = wait;
			while (temp != NULL) {
				if (temp->age == x->age && temp->name == x->name) {
					x->ID = temp->ID;
					break;
				}
				temp = temp->next;
			}
			x = x->next;
		}
		while (wait != NULL) {
			table* toDelete = wait;
			wait = wait->next;
			delete toDelete;
		}
		wait = sortTable;
		temp = wait;
		while (temp != NULL) {
			cout << temp->name << "\n";
			temp = temp->next;
		}
	}
	else if (NUM <= 15) {
		table* sortTable = NULL;
		table* x = NULL;
		table* temp = wait;
		while (temp != NULL) {
			int c = 0;
			table* t = printwait;
			while (t != NULL) {
				if (t->name == temp->name && t->age == temp->age) {
					if (sortTable == NULL) x = sortTable = new table(c, temp->name, temp->age, NULL);
					else {
						x->next = new table(c, temp->name, temp->age, NULL);
						x = x->next;
					}
					break;
				}
				t = t->next;
				c++;
			}
			temp = temp->next;
		}
		x = sortTable;
		while (x != NULL) {
			table* max = x;
			table* t = x->next;
			while (t != NULL) {
				if (t->age > max->age || (t->age == max->age && t->ID < max->ID)) {
					max = t;
				}
				t = t->next;
			}
			int id = x->ID;
			string name = x->name;
			int age = x->age;
			x->ID = max->ID;
			x->name = max->name;
			x->age = max->age;
			max->ID = id;
			max->name = name;
			max->age = age;
			x = x->next;
		}
		x = sortTable;
		temp = wait;
		while (x != NULL) {
			temp = wait;
			while (temp != NULL) {
				if (temp->age == x->age && temp->name == x->name) {
					x->ID = temp->ID;
					break;
				}
				temp = temp->next;
			}
			x = x->next;
		}
		while (wait != NULL) {
			table* toDelete = wait;
			wait = wait->next;
			delete toDelete;
		}
		wait = sortTable;
		temp = wait;
		while (temp != NULL) {
			cout << temp->name << "\n";
			temp = temp->next;
		}
	}
}
void simulate(string filename, restaurant* r)
{
	res = r;
	ifstream file;
	file.open(filename);
	string line;
	while (!file.eof()) {
		getline(file, line);
		string func = "";
		string::iterator i = line.begin();
		while (i != line.end() && *i != ' ') {
			func += *i;
			i++;
		}
		if (i != line.end()) i++;
		if (func == "REG") {
			int count = 0;
			string::iterator c = i;
			while (c != line.end()) {
				if (*c == ' ') count++;
				c++;
			}
			if (count == 2) {
				int ID = 0;
				string NAME = "";
				int AGE = 0;
				while (*i != ' ') {
					ID = 10 * ID + *i - 48;
					i++;
				}
				i++;
				while (*i != ' ') {
					NAME += *i;
					i++;
				}
				i++;
				while (i != line.end()) {
					AGE = 10 * AGE + *i - 48;
					i++;
				}
				REG(ID, NAME, AGE);
			}
			else {
				string NAME = "";
				int AGE = 0;
				while (*i != ' ') {
					NAME += *i;
					i++;
				}
				i++;
				while (i != line.end()) {
					AGE = 10 * AGE + *i - 48;
					i++;
				}
				int ID = -1;
				REG(ID, NAME, AGE);
			}
		}
		else if (func == "REGM") {
			string NAME = "";
			int AGE = 0;
			int NUM = 0;
			while (*i != ' ') {
				NAME += *i;
				i++;
			}
			i++;
			while (*i != ' ') {
				AGE = 10 * AGE + *i - 48;
				i++;
			}
			i++;
			while (i != line.end()) {
				NUM = 10 * NUM + *i - 48;
				i++;
			}
			REGM(NAME, AGE, NUM);
		}
		else if (func == "CLE") {
			int ID = 0;
			while (i != line.end()) {
				ID = 10 * ID + *i - 48;
				i++;
			}
			CLE(ID);
		}
		else if (func == "PS") {
			if (i == line.end()) PS();
			else {
				int NUM = 0;
				while (i != line.end()) {
					NUM = 10 * NUM + *i - 48;
					i++;
				}
				PS(NUM);
			}
		}
		else if (func == "PQ") {
			if (i == line.end())PQ();
			else {
				int NUM = 0;
				while (i != line.end()) {
					NUM = 10 * NUM + *i - 48;
					i++;
				}
				PQ(NUM);
			}
		}
		else if (func == "SQ") {
			int NUM = 0;
			while (i != line.end()) {
				NUM = 10 * NUM + *i - 48;
				i++;
			}
			SQ(NUM);
		}
		else if (func == "PT") {
			PT();
		}
	}
	file.close();
	while (recent != NULL) {
		table* t = recent;
		recent = recent->next;
		delete t;
	}
	while (wait != NULL) {
		table* t = wait;
		wait = wait->next;
		delete t;
	}
	while (printwait != NULL){
		table* t = printwait;
		printwait = printwait->next;
		delete t;
	}
	while (printRes != NULL) {
		table* t = printRes;
		printRes = printRes->next;
		delete t;
	}
	table *current = res->recentTable->next;
	while (current != res->recentTable) {
		table* temp = current;
		current = current->next;
		delete(temp);
	}
}
