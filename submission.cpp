/*
    Assignment # 1
    Name: Muhammad Tayyab
    ID:   24i-0757
*/

#include <iostream>
using namespace std;

// NOTE: IF YOU DON'T ATTEMPT A QUESTION, DO NOT DELETE ITS PROTOTYPE GIVEN BELOW. LEAVE IT AS IT IS. 
// YOU ARE NOT ALLOWED TO CHANGE ANY PROTOTYPE WHATSOEVER.
// DOING ANY OF THE ABOVE WILL LEAD TO YOUR TEST CASES NOT RUNNING
// AND SO ZERO MARKS WILL BE AWARDED EVEN IF YOU ATTEMPTED OTHER QUESTIONS CORRECTLY.
// ONLY EDIT THE CODE WITHIN THE {} BRACKETS OF EACH FUNCTION.
// GOOD LUCK! (onnn scene)

/*________________________ Question 1: MorseCode ________________________*/


// Function to increase the size of result according to coming data 
char* increaseResultSize(char* result, int& size) {
    int newSize = size + 20;
    char* newRes = new char[newSize];
    for (int i = 0; i < size; i++)
        newRes[i] = result[i];
    size = newSize;
    delete[] result;  // delallocate previous result
    result = newRes;
    return result;

}

// Returns morse code code according to the index of the charcter in char array
char* getMorse(int index) {
    const char* morseTable[45] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", // A-Z
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.",  // 0-9
    ".-.-.-", "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", ".-..."
    };
    char* morse = new char[7];
    int i = 0;
    while (morseTable[index][i] != '\0')
    {
        morse[i] = morseTable[index][i];
        i++;
    }
    morse[i] = '\0';
    return morse;
}

char* convertToMorseCode(char* input) {
    int size = 50;
    char* result = new char[size];
    int resultInd = 0;

    const char characters[45] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        '.', ',', '?', '\'', '!', '/', '(', ')','&'
    };


    for (int i = 0; input[i] != '\0'; i++)
    {
        if (resultInd + 10 >= size)   // Increases the size of result
            result = increaseResultSize(result, size);

        char current = input[i];
        if (current >= 'a' && current <= 'z')
            current -= 32;

        if (current == ' ') {
            result[resultInd++] = '/';
            result[resultInd++] = ' ';
            continue;
        }

        int curInd = 0;
        while (current != characters[curInd])   // compares the current char with character array to get index 
            curInd++;


        char* morse = getMorse(curInd);  // to store morse code relative to index
        for (int j = 0; morse[j] != '\0'; j++) {
            result[resultInd++] = morse[j];
        }
        result[resultInd++] = ' ';

        //cout << curInd << "    " << morse << endl;
        delete[] morse;


    }
    result[resultInd - 1] = '\0';

    return result;
}


/*-------------------------------------------------------------------------*/


char getCharacter(char morse[]) {
    const char characters[45] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        '.', ',', '?', '\'', '!', '/', '(', ')','&'
    };
    const char* morseTable[45] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", // A-Z
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.",  // 0-9
    ".-.-.-", "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", ".-..."
    };
    for (int i = 0; i < 45; i++)
    {
        int j = 0;
        while (morseTable[i][j] != '\0' && morse[j] != '\0')
        {
            if (morseTable[i][j] != morse[j])
                break;
            j++;
        }
        if (morseTable[i][j] == '\0' && morse[j] == '\0')
        {
            return characters[i];
        }
    }
    return '\0';
}

char* convertToString(char* morse) {
    int size = 50;
    char* result = new char[size];
    int resInd = 0;

    char tempmorse[10] = "";
    int tempInd = 0;

    for (int i = 0; morse[i] != '\0'; i++) {
        if (resInd + 10 >= size){                     // To increase the size of result
            result = increaseResultSize(result, size);
        }

        // If space comes in morse code, then get the relative character
        if (morse[i] == ' ' && tempInd > 0) {
            tempmorse[tempInd] = '\0';
            result[resInd++] = getCharacter(tempmorse);
            tempInd = 0;

            // Add a space if '/' comes in morse
            if (morse[i + 1] == '/' && morse[i + 2] == ' ') {
                result[resInd++] = ' ';
                i += 2;
            }
        }
        else if (morse[i + 1] == '\0') {       // Handle last character
            tempmorse[tempInd++] = morse[i];
            tempmorse[tempInd] = '\0';
            result[resInd++] = getCharacter(tempmorse);
            tempInd = 0;
        }
        else {
            tempmorse[tempInd++] = morse[i];    //else storing morse in tempmorse
        }
    }
    result[resInd] = '\0';
    return result;
}

/*________________________ Question 2: Big Integer ________________________*/

char* additionOfBigInteger(char* Num1, char* Num2) {
    int resInd = 0, carry = 0;

    int n1_ind = 0, n2_ind = 0;

    // Calculating length of both Nums
    while (Num1[n1_ind] != '\0')
        n1_ind++;
    n1_ind--;
    while (Num2[n2_ind] != '\0')
        n2_ind++;
    n2_ind--;

    char* result = new char[n1_ind + n2_ind + 5];
    while (n1_ind >= 0 || n2_ind >= 0 || carry)
    {
        // Extracting last two digits from the string
        int dig1 = 0, dig2 = 0;
        if (n1_ind >= 0)
            dig1 = Num1[n1_ind--] - '0';
        if (n2_ind >= 0)
            dig2 = Num2[n2_ind--] - '0';
        // Calculating sum and adding cary(if any) 
        int sum = dig1 + dig2 + carry;
        result[resInd++] = sum % 10 + '0';
        carry = sum / 10;
    }
    result[resInd] = '\0';

    //reversing the result 
    for (int k = 0; k < resInd / 2; k++) {
        char temp = result[k];
        result[k] = result[resInd - k - 1];
        result[resInd - 1 - k] = temp;
    }

    int start = 0;
    while (result[start] == '0' && start < resInd - 1) {
        start++;
    }

    // Shifting the result to remove starting zeroes
    for (int k = start; k <= resInd; k++) {
        result[k - start] = result[k];
    }
    return result;
}

/*---------------------------------------------------------------------------*/
char* subtractionOfBigInteger(char* Num1, char* Num2) {

    int n1_ind = 0, n2_ind = 0;

    // Determining the length of Num1 and Num2
    while (Num1[n1_ind] != '\0')
        n1_ind++;
    n1_ind--;
    while (Num2[n2_ind] != '\0')
        n2_ind++;
    n2_ind--;
    char* result = new char[n1_ind + n2_ind + 5];
    int resInd = 0;

    // Compare the two numbers to determine which is larger
    int compare = 0;
    while (Num1[compare] == Num2[compare])
        compare++;

    // Checking if the result will be negative
    bool negative = false;
    if (n2_ind > n1_ind || (n1_ind == n2_ind && Num1[compare] < Num2[compare])) {
        negative = true;
        // Swaping Num1 and Num2 to ensure larger number is subtracted from smaller
        char* temp = Num1;
        Num1 = Num2;
        Num2 = temp;
        int tempLen = n1_ind;
        n1_ind = n2_ind;
        n2_ind = tempLen;
    }

    // Performing subtraction digit by digit from right to left
    while (n1_ind >= 0 || n2_ind >= 0) {
        int dig1 = 0, dig2 = 0;
        if (n1_ind >= 0)
            dig1 = Num1[n1_ind--] - '0';
        if (n2_ind >= 0)
            dig2 = Num2[n2_ind--] - '0';
        int differ = 0;

        // Handle borrowing
        if (dig1 < dig2) {
            differ = dig1 + 10 - dig2;
            Num1[n1_ind] -= 1;
        }
        else {
            differ = dig1 - dig2;
        }
        result[resInd++] = differ + '0';
    }
    // Add negative sign if needed
    if (negative)
        result[resInd++] = '-';

    result[resInd] = '\0';

    // Reversing the result
    for (int k = 0; k < resInd / 2; k++) {
        char temp = result[k];
        result[k] = result[resInd - k - 1];
        result[resInd - 1 - k] = temp;
    }

    int zeros = 0;
    while (result[zeros] == '0' && zeros < resInd - 1) {
        zeros++;
    }
    // Shifting the result to remove starting zeroes
    for (int k = zeros; k <= resInd; k++) {
        result[k - zeros] = result[k];
    }
    return result;
}

/*----------------------------------------------------------------------------*/
char* multiplicationOfBigInteger(char* Num1, char* Num2) {
    // Calculating lengths of Num1 and Num2
    int len1 = 0, len2 = 0;
    while (Num1[len1] != '\0')
        len1++;
    while (Num2[len2] != '\0')
        len2++;
    char* result = new char[len1 + len2 + 1];

    //initializing result string as "00000"
    for (int i = 0; i < len1 + len2; i++)
        result[i] = '0';
    result[len1 + len2] = '\0';


    for (int i = len2 - 1; i >= 0; i--) {
        int carry = 0;
        int dig2 = Num2[i] - '0';   // Extracting the last digits from Num2 one by one 

        for (int j = len1 - 1; j >= 0; j--) {
            int dig1 = Num1[j] - '0';

            int resInd = i + j + 1;  // i is decreased for each number for shifting of next multiplication

            int sum = (result[resInd] - '0') + (dig1 * dig2) + carry;
            result[resInd] = (sum % 10) + '0';
            carry = sum / 10;
        }
        result[i] += carry;    // incresaes the '0' to '1' if carry is generated 
    }

    // Remove leading zeros
    int zeros = 0;
    while (result[zeros] == '0') {
        zeros++;
    }

    for (int k = zeros; k <= len1 + len2; k++) {
        result[k - zeros] = result[k];
    }
    return result;
}


/*----------------------------------------------------------------------------*/


char* factorialOfBigInteger(char* Num1) {

    int len1 = 0;
    // Determining the length of Num1
    while (Num1[len1] != '\0')
        len1++;


    char* result = new char[len1 + 1];

    for (int i = 0; i < len1; i++)
    {
        result[i] = Num1[i];
    }
    result[len1] = '\0';

    int N = 0;
    char* NextNum = new char[len1 + 1];

    // Converting Num1 to an integer value N
    for (int i = 0; i < len1; i++)
    {
        N = N * 10 + (Num1[i] - '0');
        NextNum[i] = '0';
    }
    NextNum[len1] = '\0';


    for (int i = 1; i < N; i++)
    {
        // Reset NextNum to '0'
        for (int i = 0; i < len1; i++) {
            NextNum[i] = '0';
        }

        // Converting (N - i) to a string stored in NextNum
        int tempN = N - i, tempLength = len1 - 1;
        while (tempN > 0)
        {
            NextNum[tempLength--] = tempN % 10 + '0';
            tempN /= 10;
        }

        // Multiplying result by NextNum to compute next factorial
        char* newResult = multiplicationOfBigInteger(result, NextNum);
        delete[] result;
        result = newResult;

    }
    // cout<<N<<endl;
    delete[] NextNum;
    return result;
}

/*________________________ Question 3: Text Analysis ________________________*/

void removePunctuation(char* str) {
    int i = 0, j = 0;
    bool lastSpace = true;
    while (str[i] != '\0')
    {
        // Check if the current character is a punctuation mark
        // and the next character is alphanumeric and the character before result index was not a space

        if (((str[i] < 'A' || str[i]>'Z') && (str[i] < 'a' || str[i]>'z') && (str[i] < '0' || str[i]>'9')) &&
            ((str[i + 1] >= 'A' && str[i + 1] <= 'Z') || (str[i + 1] >= 'a' && str[i + 1] <= 'z') || (str[i + 1] >= '0' && str[i + 1] <= '9')) &&
            (j > 0 && str[j - 1] != ' '))
        {
            str[j] = ' '; // If true the add a space
            j++;
            lastSpace = true;
        }

        // If the current character is alphanumeric then add it to result index
        if ((str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= '0' && str[i] <= '9'))
        {

            str[j++] = str[i];
            lastSpace = false;
        }
        else if (str[i] == ' ' && !lastSpace) {     // Handling spaces
            str[j] = ' ';
            j++;
            lastSpace = true;
        }
        i++;
    }

    // If last character added was a space the removing it
    if (j > 0 && str[j - 1] == ' '){
        j--;
    }
    str[j] = '\0';
}

// ----------------------------------------------------------------------------------------------------------


// Increases the Size of the letters and count arrays according to coming data
void increaseSize(int*& count, char*& letters, int& size) {
    int newSize = size + 1;
    int* newCount = new int[newSize];
    char* newLetters = new char[newSize];

    for (int i = 0; i < size; i++) {
        newCount[i] = count[i];
        newLetters[i] = letters[i];
    }

    if (count) delete[] count;
    if (letters) delete[] letters;

    count = newCount;
    letters = newLetters;
    size = newSize;
}

void countLetters(char* str, int*& count, char*& letters, int& size) {
    if (!str) return;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;  // Convert to lowercase
    }

    for (int i = 0; str[i] != '\0'; i++) {
        bool unique = true;
        bool isDigit = false;
        int freq = 1;

        for (int k = 0; k < size; k++) {  // Check if the word is unique or not 
            if (str[i] == letters[k]) {
                unique = false;
                break;
            }
        }

        if (str[i] >= '0' && str[i] <= '9')    // Checking if the word is a digit
            isDigit = true;

        if (!unique || isDigit)
            continue;

        for (int j = i + 1; str[j] != '\0'; j++) {  // Checking frequency of unique character
            if (str[j] == str[i])
                freq++;
        }

        increaseSize(count, letters, size);    // Increasing size for every coming character 
        count[size - 1] = freq;
        letters[size - 1] = str[i];
    }
}



//-----------------------------------------------------------------------------------------------------------------


// Increases the count if a unique word is to be stored
void increaseWordCount(int& count, char**& words, int*& array) {
    const int maxLen = 30;
    int newCount = count + 1;
    int* newArray = new int[newCount];
    char** newWords = new char* [newCount];
    for (int i = 0; i < count; i++)
    {
        newArray[i] = array[i];

        newWords[i] = new char[maxLen];

        for (int j = 0; words[i][j] != '\0'; j++)
        {
            newWords[i][j] = words[i][j];
            if (words[i][j + 1] == '\0')
                newWords[i][j + 1] = '\0';
        }
    }
    newWords[newCount - 1] = new char[maxLen];
    for (int i = 0; i < count; i++)
    {
        delete[] words[i];
    }
    delete[] words;
    delete[] array;
    array = newArray;
    words = newWords;

    count = newCount;

}



void countWords(char* str, int*& array, char**& words, int& numberOfWords) {
    // Converting the entire string to lowercase
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32; 
        }
    }

    int j = 0;

    while (true) {
        int tempInd = 0;
        char temp[50] = ""; 

        // Extracting a word from the string
        for (; str[j] != ' ' && str[j] != '\0'; j++) {
            // Includes only valid alphabetic characters
            if (str[j] >= 'a' && str[j] <= 'z') {
                temp[tempInd++] = str[j];
            }
        }

        if (tempInd > 0) {
            temp[tempInd] = '\0'; 

            // Checking if the word already exists in `words`
            bool exist = false;
            for (int k = 0; k < numberOfWords; k++) {
                bool isSame = true;
                for (int l = 0; temp[l] != '\0' || words[k][l] != '\0'; l++) {
                    if (words[k][l] != temp[l]) {
                        isSame = false;
                        break;
                    }
                }

                if (isSame) {
                    array[k]++; //Incrementing the count for the existing word
                    exist = true;
                    break;
                }
            }

            // If the word is unique, add it to `words`
            if (!exist) {
                increaseWordCount(numberOfWords, words, array); 

                //Initializing the count for the new word
                array[numberOfWords - 1] = 1;

                //Copy the word into the `words` array
                int i = 0;
                while (temp[i] != '\0') {
                    words[numberOfWords - 1][i] = temp[i];
                    i++;
                }
                words[numberOfWords - 1][i] = '\0';
            }
        }
        if (str[j] == '\0') {
            break;
        }
        j++; // Skip the space
    }
}


/*________________________ Question 4: Recursion ________________________*/

bool primeHelper(int n, int i) {
    if (i * i > n) {
        return true;
    }
    if (n % i == 0) {
        return false;
    }
    return primeHelper(n, i + 1);
}

bool isprimeNumber(int n) {

    if (n < 2) {
        return false;
    }
    return primeHelper(n, 2);
    return false;
}

// -------------------------------------------------------------------------------------------------


int sum(int** array, int rows, int columns, int& evenSum, int& oddSum, int defCols = 0) {

    // Base case
    if (rows < 0) {
        return 0;
    }

    // If all columns of the current row have been processed, move to the previous row
    if (defCols - 1 == columns) {
        return sum(array, rows - 1, columns, evenSum, oddSum, 0);
    }
    int value = array[rows][defCols];

    // Check if the value is even or odd and update the respective sum
    if (value % 2 == 0)
        evenSum += value;
    else
        oddSum += value;

    // Recursive call for the next column in the current row
    sum(array, rows, columns, evenSum, oddSum, defCols + 1);
    return 0;
}

// -------------------------------------------------------------------------------------------------


// To print spaces
void printSpacespattern1(int spaces) {
    if (spaces == 0) {
        return;
    }
    cout << " ";
    printSpacespattern1(spaces - 1);
}

// To print Stars
void printStarsPattern1(int stars) {
    if (stars == 0) {
        cout << endl;
        return;
    }
    cout << "*";
    printStarsPattern1(stars - 1);
}


void PrintPattern1(int n, int current, int max) {
    if (current == max * 2)
        return;

    // Calculate spaces relative to middle of pattern
    int spaces = (current <= max) ? (n - current) : (current - n);


    // Printing spaces before the pattern
    printSpacespattern1(spaces);

    // Printing the pattern
    if (current <= max)
        printStarsPattern1(current * 2 - 1);
    else
        printStarsPattern1((2 * max - current) * 2 - 1);

    // Recursive call to print the next row
    PrintPattern1(n, current + 1, max);
}



// -------------------------------------------------------------------------------------------------



// To print spaces
void printSpacespattern2(int count) {
    if (count <= 0)
        return;
    cout << "  ";
    printSpacespattern2(count - 1);
}

// To print inner pattern of stars
void Printinnerpattern2(int i, int num1) {
    if (i == 0) {
        return;
    }
    if (i == num1 * 2 - 1) {
        cout << " |";
    }
    else {
        cout << " *";
    }
    Printinnerpattern2(i - 1, num1);
}


void PrintPattern2(int n, int currentRow, int max) {
    if (currentRow == max * 2) {
        return;
    }
    // Calculate spaces relative to middle of pattern
    int space_count = (currentRow <= max) ? (max - currentRow) : (currentRow - max);  


    // Printing spaces before the pattern
    printSpacespattern2(space_count);
    cout << "|";
    printSpacespattern2(space_count);

    // Printing the inner pattern
    if (currentRow <= n)
        Printinnerpattern2(currentRow * 4 - 3, currentRow);
    else
        Printinnerpattern2((n * 2 - currentRow) * 4 - 3, n * 2 - currentRow);

    // Printing spaces after the pattern
    printSpacespattern2(space_count);
    cout << " |" << endl;

    // Recursive call to print the next row
    PrintPattern2(n, currentRow + 1, max);
}






/*________________ Question 5: Maze Traversal ________________*/

bool solveMaze(int** maze, int t_row, int t_column, int rows, int cols, int thisX = 0, int thisY = 0) {


    if (thisX == t_row && thisY == t_column) {  // Path found condition
        maze[thisX][thisY] = 2;
        return true;
    }
    maze[thisX][thisY] = 2;   // Mark the visited cell with 2

    // Look for 1
    if (thisY < cols - 1 && maze[thisX][thisY + 1] == 1)
    {
        return solveMaze(maze, t_row, t_column, rows, cols, thisX, thisY + 1);   // Move Right
    }
    else if (thisY > 0 && maze[thisX][thisY - 1] == 1) {

        return solveMaze(maze, t_row, t_column, rows, cols, thisX, thisY - 1);   // Move left
    }
    else if (thisX > 0 && maze[thisX - 1][thisY] == 1) {
   
        return solveMaze(maze, t_row, t_column, rows, cols, thisX - 1, thisY);   // Move down
    }
    else if (thisX < rows - 1 && maze[thisX + 1][thisY] == 1) {
      
        return solveMaze(maze, t_row, t_column, rows, cols, thisX + 1, thisY);    // Move up
    }
    
    // If 1 is not found, mark current cell by 0 and look for 2
    maze[thisX][thisY] = 0;
    if (thisY < cols && maze[thisX][thisY + 1] == 2)
    {
        return solveMaze(maze, t_row, t_column, rows, cols, thisX, thisY + 1);   // Move Right
    }
    else if (thisY > 0 && maze[thisX][thisY - 1] == 2) {
        return solveMaze(maze, t_row, t_column, rows, cols, thisX, thisY - 1);     // Move left
    }
    else if (thisX + 1 < rows && maze[thisX + 1][thisY] == 2) {
        return solveMaze(maze, t_row, t_column, rows, cols, thisX + 1, thisY);      // Move down
    }
    else if (thisX > 0 && maze[thisX - 1][thisY] == 2) {
        return solveMaze(maze, t_row, t_column, rows, cols, thisX - 1, thisY);      // Move up
    }


    // If both 1 and 2 are not found then back track by returning false
    return false;

}

/*____________________ Question 6: SUDOKU ____________________*/

bool isValidTestNum(int** board, int x, int y, int num) {

    // cout << "Checking validity for num " << num << " at (" << y << ", " << x << ")\n";


    for (int i = 0; i < 9; i++) {  // Checking along the row
        if (board[y][i] == num) {
            return false;
        }
    }
    for (int i = 0; i < 9; i++) {   // Checking along the column
        if (board[i][x] == num) {
            return false;
        }
    }
    int subGridStartY = (y / 3) * 3;
    int subGridSEndY = subGridStartY + 3;
    int subGridStartX = (x / 3) * 3;
    int subGridSEndX = subGridStartX + 3;

            
    for (int i = subGridStartY; i < subGridSEndY; i++)   // Checking along the subGrid
    {
        for (int j = subGridStartX; j < subGridSEndX; j++)
        {
            if (board[i][j] == num) {
                return false;
            }
        }

    }

    return true;
}

bool solveSudoku(int** board, int column = 0, int row = 0, int num = 1) {


    if (column == 9) {    // means sudoku has been solved so return true
        return true;
    }

    if (row == 9) {
        return solveSudoku(board, column + 1, 0, 1);   // Moving to next column and 0th row
    }

    if (board[row][column] != 0) {                     // If cell is already filled, move downward
        return solveSudoku(board, column, row + 1, 1);
    }

    // If num exceeds 9, backtrack as no valid number was found
    if (num > 9) {           
        return false;
    }

    if (isValidTestNum(board, column, row, num)) {
        board[row][column] = num;  // If the number id valid, Place the number


        // If the solvesudoku returns true, return true 
        if (solveSudoku(board, column, row + 1, 1)) {
            return true;
        }
        // else undo the move
        board[row][column] = 0;
    }

    // Try next number
    return solveSudoku(board, column, row, num + 1);
}

