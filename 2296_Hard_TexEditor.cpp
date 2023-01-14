// 2296. Design a Text Editor
// https://leetcode.com/problems/design-a-text-editor/description/

using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<list>
#include<forward_list>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstring>

//#define FORREF
#ifndef FORREF
/*
    Problem understanding:
    Design a text editor eith cursor.
    - Add text to where the cursor is
        -- meaning you might have to trace the cursor, or in some scenario
           you will have to manage the cursor position
    - Delete text from where the cursor is (simulating the backtrace key )
      -- ok, let's see how deleting will impact your cursor position and text state??
    - Move the cursor either left or right
      -- Cursor moving is bound to the min and max range?? Think on it
    @Note:
    When deleting text, only characters to the left of the cursor will be deleted. 
    The cursor will also remain within the actual text and cannot be moved beyond it. 
    More formally, 
    we have that 0 <= cursor.position <= currentText.length always holds.

    @Constraint : At most 2 * 104 calls in total will be made to addText, 
                  deleteText, cursorLeft and cursorRight.

    Implement the TextEditor class:
    1. TextEditor() Initializes the object with empty text.
    2. void addText(string text) Appends text to where the cursor is. 
       The cursor ends to the right of text.
       
       @Constraint text consists of lowercase English letters.
       @Constraint: 1 <= text.length, k <= 40

    3. int deleteText(int k) Deletes k characters to the left of the cursor. 
       Returns the number of characters actually deleted.
       @Constraint: 1 <= text.length, k <= 40

    4. string cursorLeft(int k) Moves the cursor to the left k times. 
       Returns the last min(10, len) characters to the left of the cursor, 
       where len is the number of characters to the left of the cursor.

    5. string cursorRight(int k) Moves the cursor to the right k times. 
       Returns the last min(10, len) characters to the left of the cursor, 
       where len is the number of characters to the left of the cursor. 


    Let's try to understand the problem with example??




*/

class TextEditor {
public:
    TextEditor() {

    }

    void addText(string text) {

    }

    int deleteText(int k) {

    }

    string cursorLeft(int k) {

    }

    string cursorRight(int k) {

    }
};

int main(void)
{

    return 0;
}

#endif // FORREF
