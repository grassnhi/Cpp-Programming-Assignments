#include<iostream>
#include<iomanip>
#include <sstream>

#include "list/DLinkedList.h"
#include "list/SLinkedList.h"
#include "list/XArrayList.h"
#include "geom/Point3D.h"
#include "stacknqueue/Stack.h"
#include "stacknqueue/Queue.h"
#include "tree/BST.h"
#include "tree/AVL.h"

void bst_demo(){
    BST<int, int*> tree;
    for(int v = 0; v < 10000; v += 1){
        tree.add(v);
    }
    cout << "BST, height: " << tree.height() << endl;
}

/*          AVL 
- Level: start at 0 
- Height: start at 1 = number of node in longest path = max level + 1
- Balanced factor = Height of left subtree - Height of right subtree
                45(-1)
        25(0)           65(-1)
    10(0)   30(0)   50(0)   85(-1)
                                96(0)
-> Balanced factor of node 25 = 1 - 1  = 0
=> AVL = BST + balanced factor {-1, 0, 1} = balanced BST -> balanced tree
- BST: all righ > root > all left and so on for subtree
- Balanced tree: balanced factor {-1, 0, 1}
- Search BST: O(n)
- Search AVL: O(logn) - min high = Hmin = LogN + 1 = log(N+1)
*/

void avl_demo(){
    AVL<int, int*> tree;
    for(int v = 0; v < 10000; v += 1){
        tree.add(v);
    }
    cout << "AVL, height: " << tree.height() << endl;
}

/*          Balanced Factor
- Left higher (LH): Left = right + 1 or left > right
- Right higher (RH): right = right + 1 or right > right
- Equal high
*/

/*      Insertion
- Insert like BST
- Detect + rebalance

                            50                      50
focus of left sub<-LH<-25(2)     75             35         75(-2) ->RH -> focus on right subtree
                LH <- 15      35   60         40        60    85 -> RH => RH of RH
                12      20                                  80  90    
            10                                                     95
=> Rebalance node 25                                => Rebanlced node 75
-> Rotation right at 25 = 15 go up + 25 down        -> Rotate left at 75 = 85 go up + 75 go down
                        50                                      50
            15                     75               35                  85
      12          25           60                       40           75     90
10            20      35                                         60     80      95

            50                                          (LH)60
        35      75(RH)                          (RH)35                 85
    30     60      85(LH)                       30      45          70
                80     90                   20       40     50
            78                                                  55
=> Rebalanced 75                                => Rebalanced 60                 
-> LH of RH -> Rotate right at 85               ->RH of LH -> Rotate left at 35
-> Then rotate left at 75                       -> Then rotate right at 60
    80                      80                              45                      45
78      85              75      85                      35      50              35          60
            90       60     78      90              35              55      30      40  50      85
                                                20                          20            55  70
*/
int main(){
    bst_demo();
    avl_demo();
}