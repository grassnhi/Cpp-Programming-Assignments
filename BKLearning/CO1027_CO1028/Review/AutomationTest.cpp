//fb.com/fragalis

#include <iostream>
#include <fstream>
#include <string>
#include "studyInPink3a.h"
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_COUNT = 10000; //
int c = 0;
void output() {
    fstream fileInp, fileOut;
    bool fail = 0;
    fileInp.open("testinput.txt",ios::in);
    fileOut.open("testoutput.txt",ios::in);
    for(int i = 0; i<MAX_COUNT; i++) {
        cout << "Testcase #" << i+1 << ": ";
        //point output
        string temp, pt1S, pt2S;
        int x1, x2, y1, y2, dist;
        fileInp >> temp >> temp >> temp;
        fileInp >> temp >> temp >> x1 >> y1;
        fileInp >> temp >> temp >> x2 >> y2;
        fileInp >> temp;
        Point p1(x1,y1), p2(x2,y2);
        fileOut >> temp >> temp >> temp;
        fileOut >> pt1S;
        fileOut >> pt2S;
        fileOut >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> dist;
        fileOut >> temp;
        if(pt1S != p1.toString()) {
            fail = 1;
            cout << "Point 1 toString: " << endl;
            cout << "\tYour answer: " << p1.toString() << endl;
            cout << "\tTest answer: " << pt1S << endl;
        }
        if(pt2S != p2.toString()) {
            fail = 1;
            cout << "Point 2 toString: " << endl;
            cout << "\tYour answer: " << p2.toString() << endl;
            cout << "\tTest answer: " << pt2S << endl;
        }
        if(dist != p1.distanceTo(p2)) {
            fail = 1;
            cout << "Point Distance: " << endl;
            cout << "\tYour answer: " << p1.distanceTo(p2) << endl;
            cout << "\tTest answer: " << dist << endl;
        }
        //real output
        int numOfNode;
        string name, murderName, eps, nts, pts, ueps, unts, upts, cts, ucts;
        fileInp >> temp >> temp >> temp >> numOfNode;
        fileInp >> temp >> temp >> name;
        Path path, murderPath;
        Character chVictim("Watson");
        Character chMurder("Murder");
        fileOut >> temp >> temp >> temp >> temp;
        fileOut >> temp >> temp >> eps;
        fileOut >> temp >> temp >> temp >> nts;
        fileOut >> temp >> temp >> temp >> pts;
        fileOut >> temp;
        ueps = path.toString();
        for(int j=0; j<numOfNode; j++) {
            int x,y;
            fileInp >> temp >> temp >> x >> y;
            Node n(Point(x,y),NULL);
            if(!j) {
                unts = n.toString();
            }
            path.addPoint(x,y);
            chVictim.moveToPoint(x,y);
        }
        upts = path.toString();
        if(eps != ueps) {
            fail = 1;
            cout << "Empty Path toString: " << endl;
            cout << "\tYour answer: " << ueps << endl;
            cout << "\tTest answer: " << eps << endl;
        }
        if(nts != unts) {
            fail = 1;
            cout << "Node toString: " << endl;
            cout << "\tYour answer: " << unts << endl;
            cout << "\tTest answer: " << nts << endl;
        }
        if(pts != upts) {
            fail = 1;
            cout << "Victim Path toString: " << endl;
            cout << "\tYour answer: " << upts << endl;
            cout << "\tTest answer: " << pts << endl;
        } 
        fileInp >> temp;
        fileInp >> temp >> temp >> murderName;
        for(int j=0; j<numOfNode; j++) {
            int x,y;
            fileInp >> temp >> temp >> x >> y;
            chMurder.moveToPoint(x,y);
        }
        fileInp >> temp;
        chVictim.setName(name);
        chMurder.setName(murderName);
        int maxLength, maxDistance, outDistance = -1;
        fileInp >> temp >> maxLength;
        fileInp >> temp >> maxDistance;
        fileOut >> temp >> temp >> temp;
        fileOut >> temp >> temp >> temp;
        fileOut >> temp >> temp >> temp >> cts;
        ucts = chVictim.toString();
        if(cts != ucts) {
            fail = 1;
            cout << "chVictim toString: " << endl;
            cout << "\tYour answer: " << ucts << endl;
            cout << "\tTest answer: " << cts << endl;
        }
        fileOut >> temp;     
        int cr, d, od;
        fileOut >> temp >> temp >> cr;
        fileOut >> temp >> temp;
        fileOut >> temp >> temp;
        fileOut >> temp >> d;
        fileOut >> temp >> temp >> od;
        if(cr != rescueSherlock(chMurder,chVictim,maxLength,maxDistance,outDistance)) {
            fail = 1;
            cout << "Rescue Sherlock: " << endl;
            cout << "\tYour answer: " << rescueSherlock(chMurder,chVictim,maxLength,maxDistance,outDistance) << endl;
            cout << "\tTest answer: " << cr << endl;  
        }
        //if test distance is needed, change this part to your calculating method
//        if(d != chVictim.getCurrentPosition().distanceTo(chMurder.getCurrentPosition())) {
//            fail = 1;
//            cout << "Character Distance: " << endl;
//            cout << "\tYour answer: " << chVictim.getCurrentPosition().distanceTo(chMurder.getCurrentPosition()) << endl;
//            cout << "\tTest answer: " << d << endl;     
//        }
        if(od != outDistance) {
            fail = 1;
            cout << "Out Distance: " << endl;
            cout << "\tYour answer: " << d << endl;
            cout << "\tTest answer: " << od << endl;       
        }
        if(!fail) {
            c++;
            cout << "ACCEPTED";
        }
        else break;
        cout << endl;
    }
}

int main() {
    output();
    cout << "Result: " << c << " of " << MAX_COUNT << " tests got ACCEPTED.";
	return 0;
}

