#include "pch.h"
#include <gtest/gtest.h>
#include "../Project1/submission.cpp"


////////////////////////////////////////////////TESTCASES/////////////////////////////////////////////////////



///////////////////////////Pointers///////////////////////////////


/*------------------------- Question1 ---------------------------*/

TEST(MorseCodeTest, SingleLetter) {
    char input[] = "h";
    char expected[] = "....";
    char* result = convertToMorseCode(input);
    EXPECT_STREQ(result, expected);
    delete[] result;
}

TEST(MorseCodeTest, SimpleWord) {
    char input[] = "Crazy";
    char expected[] = "-.-. .-. .- --.. -.--";
    char* result = convertToMorseCode(input);
    EXPECT_STREQ(result, expected);
    delete[] result;
}

TEST(MorseCodeTest, Sentence) {
    char input[] = "OOP is easier than PF NGL";
    char expected[] = "--- --- .--. / .. ... / . .- ... .. . .-. / - .... .- -. / .--. ..-. / -. --. .-..";
    char* stringToMorse = convertToMorseCode(input);
    EXPECT_STREQ(stringToMorse, expected);

    char output[] = "oop is easier than pf ngl";
    char* morseToString = convertToString(stringToMorse);
    EXPECT_STREQ(morseToString, output);

    delete[] stringToMorse;
    delete[] morseToString;

}

TEST(MorseCodeTest, MorseSentence) {
    char morse[] = "--- -. . / .- -. -.. / - .... . / ... .- -- . / - .... .. -. --.";
    char expected[] = "one and the same thing";
    char* result = convertToString(morse);
    EXPECT_STREQ(result, expected);
    delete[] result;
}


/*----------------------Question2---------------------------*/

TEST(BigIntegerTest, Addition) {
    char num1[] = "99999999";
    char num2[] = "1";
    char expected[] = "100000000";
    char* result = additionOfBigInteger(num1, num2);
    EXPECT_STREQ(result, expected);
    delete[] result;
}

TEST(BigIntegerTest, AdditionLeadingZeros) {
    char num1[] = "0000123";
    char num2[] = "00000456";
    char expected[] = "579";
    char* result = additionOfBigInteger(num1, num2);
    EXPECT_STREQ(result, expected);
    delete[] result;
}

TEST(BigIntegerTest, SubtractionNegativeResult) {
    char num1[] = "123";
    char num2[] = "456";
    char expected[] = "-333";
    char* result = subtractionOfBigInteger(num1, num2);
    EXPECT_STREQ(result, expected);
    delete[] result;
}

TEST(BigIntegerTest, MultiplicationLargeNumbers) {
    char num1[] = "12345678901234567890";
    char num2[] = "2";
    char expected[] = "24691357802469135780";
    char* result = multiplicationOfBigInteger(num1, num2);
    EXPECT_STREQ(result, expected);
    delete[] result;
}


TEST(BigIntegerTest, FactorialLarge) {
    char num1[] = "20";
    char expected[] = "2432902008176640000";
    char* result = factorialOfBigInteger(num1);
    EXPECT_STREQ(result, expected);
    delete[] result;
}


/*--------------------------Question3------------------------ - */

TEST(TextAnalysisTest, RemovePunctuationBasic) {
    char input[] = "!!!Donkey Work, is Certainly!!! Unacceptable!?";
    char expected[] = "Donkey Work is Certainly Unacceptable";
    removePunctuation(input);
    EXPECT_STREQ(input, expected);
}

TEST(TextAnalysisTest, RemovePunctuationMultipleSpaces) {
    char input[] = "Sir; (Shehryar) just :cannot wait to see all of you smiling...when you look at them sessional-1 && sessional-2 exams frfr!!! :)";
    char expected[] = "Sir Shehryar just cannot wait to see all of you smiling when you look at them sessional 1 sessional 2 exams frfr";
    removePunctuation(input);
    EXPECT_STREQ(input, expected);
}

TEST(TextAnalysisTest, RemovePunctuationOnlyPunctuation) {
    char input[] = "!!!@@@###$$$%%%";
    char expected[] = "";
    removePunctuation(input);
    EXPECT_STREQ(input, expected);
}

TEST(TextAnalysisTest, CountLetters) {
    char input[] = "[Get the TAs of sections C and D chocolates for 5 {bonus} points no cap frfr (this could be cap)!!";
    int* count = nullptr;
    char* letters = nullptr;
    int size = 0;
    removePunctuation(input);
    countLetters(input, count, letters, size);

    char expectedLetters[] = "get hasofcindlrbup"; // Unique characters in order of appearance
    int expectedCount[] = { 1,5,7,19,3,5,7,9,4,7,3,5,3,2,3,2,2,3 };

    ASSERT_EQ(size, 18);
    for (int i = 0; i < size; i++) {
        EXPECT_EQ(count[i], expectedCount[i]);
        EXPECT_EQ(letters[i], expectedLetters[i]);
    }

    delete[] count;
    delete[] letters;
}

TEST(TextAnalysisTest, CountWordsBasic) {
    char input[] = "FAST ka ragra is real Is it or is iT not?";
    int* count = nullptr;
    char** words = nullptr;
    int numberOfWords = 0;
    countWords(input, count, words, numberOfWords);

    char* expectedWords[] = { "fast", "ka", "ragra", "is", "real", "it", "or", "not" };
    int expectedCount[] = { 1, 1, 1, 3, 1, 2, 1, 1 };

    ASSERT_EQ(numberOfWords, 8);
    for (int i = 0; i < numberOfWords; i++) {
        EXPECT_STREQ(words[i], expectedWords[i]);
        EXPECT_EQ(count[i], expectedCount[i]);
        delete[] words[i];
    }

    delete[] count;
    delete[] words;
}


///////////////////////Recursive Functions///////////////////////

/*----------------------- Question 4 ----------------------------*/


TEST(PrimeTest, SmallPrimes) {
    EXPECT_TRUE(isprimeNumber(2));
    EXPECT_TRUE(isprimeNumber(3));
    EXPECT_TRUE(isprimeNumber(5));
    EXPECT_TRUE(isprimeNumber(7));
    EXPECT_TRUE(isprimeNumber(11));
}

TEST(PrimeTest, SmallNonPrimes) {
    EXPECT_FALSE(isprimeNumber(1));
    EXPECT_FALSE(isprimeNumber(4));
    EXPECT_FALSE(isprimeNumber(6));
    EXPECT_FALSE(isprimeNumber(8));
    EXPECT_FALSE(isprimeNumber(9));
    EXPECT_FALSE(isprimeNumber(10));
}

TEST(PrimeTest, LargePrimes) {
    EXPECT_TRUE(isprimeNumber(7919));
    EXPECT_TRUE(isprimeNumber(104729));
}

TEST(PrimeTest, LargeNonPrimes) {
    EXPECT_FALSE(isprimeNumber(100000));
    EXPECT_FALSE(isprimeNumber(99991 * 99989));
}

TEST(PrimeTest, EdgeCases) {
    EXPECT_FALSE(isprimeNumber(0));
    EXPECT_FALSE(isprimeNumber(-1));
    EXPECT_FALSE(isprimeNumber(-17));
    EXPECT_TRUE(isprimeNumber(2));
}


TEST(SumTest, BasicMatrix) {
    int rows = 2, columns = 2;
    int** array = new int* [rows];
    int data[2][2] = { {1, 2}, {3, 4} };
    for (int i = 0; i < rows; i++) {
        array[i] = new int[columns];
        for (int j = 0; j < columns; j++) {
            array[i][j] = data[i][j];
        }
    }

    int evenSum = 0, oddSum = 0;
    sum(array, rows - 1, columns - 1, evenSum, oddSum);
    EXPECT_EQ(evenSum, 6);
    EXPECT_EQ(oddSum, 4);

    for (int i = 0; i < rows; i++) delete[] array[i];
    delete[] array;
}

TEST(SumTest, AllEvenNumbers) {
    int rows = 3, columns = 3;
    int** array = new int* [rows];
    int data[3][3] = { {2, 4, 6}, {8, 10, 12}, {14, 16, 18} };
    for (int i = 0; i < rows; i++) {
        array[i] = new int[columns];
        for (int j = 0; j < columns; j++) {
            array[i][j] = data[i][j];
        }
    }

    int evenSum = 0, oddSum = 0;
    sum(array, rows - 1, columns - 1, evenSum, oddSum);
    EXPECT_EQ(evenSum, 90);
    EXPECT_EQ(oddSum, 0);

    for (int i = 0; i < rows; i++) delete[] array[i];
    delete[] array;
}

TEST(SumTest, AllOddNumbers) {
    int rows = 2, columns = 3;
    int** array = new int* [rows];
    int data[2][3] = { {1, 3, 5}, {7, 9, 11} };
    for (int i = 0; i < rows; i++) {
        array[i] = new int[columns];
        for (int j = 0; j < columns; j++) {
            array[i][j] = data[i][j];
        }
    }

    int evenSum = 0, oddSum = 0;
    sum(array, rows - 1, columns - 1, evenSum, oddSum);
    EXPECT_EQ(evenSum, 0);
    EXPECT_EQ(oddSum, 36);

    for (int i = 0; i < rows; i++) delete[] array[i];
    delete[] array;
}

TEST(SumTest, MatrixWithNegatives) {
    int rows = 2, columns = 2;
    int** array = new int* [rows];
    int data[2][2] = { {-2, -3}, {4, 5} };
    for (int i = 0; i < rows; i++) {
        array[i] = new int[columns];
        for (int j = 0; j < columns; j++) {
            array[i][j] = data[i][j];
        }
    }

    int evenSum = 0, oddSum = 0;
    sum(array, rows - 1, columns - 1, evenSum, oddSum);
    EXPECT_EQ(evenSum, 2);
    EXPECT_EQ(oddSum, 2);

    for (int i = 0; i < rows; i++) delete[] array[i];
    delete[] array;
}

TEST(SumTest, EmptyMatrix) {
    int** array = nullptr;
    int evenSum = 0, oddSum = 0;
    sum(array, -1, -1, evenSum, oddSum);
    EXPECT_EQ(evenSum, 0);
    EXPECT_EQ(oddSum, 0);
}

//PATTERNS:

std::string captureOutput(int n, int current, int max) {
    std::streambuf* old_buf = std::cout.rdbuf();
    std::ostringstream ss;
    std::cout.rdbuf(ss.rdbuf());

    PrintPattern1(n, current, max);

    std::cout.rdbuf(old_buf);

    return ss.str();
}

TEST(PatternTest1, BasicPattern) {
    std::string output = captureOutput(5, 1, 5);

    std::string expected_output =
        "    *\n"
        "   ***\n"
        "  *****\n"
        " *******\n"
        "*********\n"
        " *******\n"
        "  *****\n"
        "   ***\n"
        "    *\n";

    EXPECT_EQ(output, expected_output);
}

TEST(PatternTest1, SmallPattern) {
    std::string output = captureOutput(3, 1, 3);

    std::string expected_output =
        "  *\n"
        " ***\n"
        "*****\n"
        " ***\n"
        "  *\n";

    EXPECT_EQ(output, expected_output);
}

TEST(PatternTest1, LargePattern) {
    std::string output = captureOutput(10, 1, 10);

    std::string expected_output =
        "         *\n"
        "        ***\n"
        "       *****\n"
        "      *******\n"
        "     *********\n"
        "    ***********\n"
        "   *************\n"
        "  ***************\n"
        " *****************\n"
        "*******************\n"
        " *****************\n"
        "  ***************\n"
        "   *************\n"
        "    ***********\n"
        "     *********\n"
        "      *******\n"
        "       *****\n"
        "        ***\n"
        "         *\n";

    EXPECT_EQ(output, expected_output);
}

std::string captureOutput2(int n, int current, int max) {
    std::streambuf* old_buf = std::cout.rdbuf();
    std::ostringstream ss;
    std::cout.rdbuf(ss.rdbuf());

    PrintPattern2(n, current, max);

    std::cout.rdbuf(old_buf);

    return ss.str();
}

TEST(PatternTest2, BasicPattern) {
    std::string output = captureOutput2(5, 1, 5);

    std::string expected_output =
        "        |         |         |\n"
        "      |       * * | * *       |\n"
        "    |     * * * * | * * * *     |\n"
        "  |   * * * * * * | * * * * * *   |\n"
        "| * * * * * * * * | * * * * * * * * |\n"
        "  |   * * * * * * | * * * * * *   |\n"
        "    |     * * * * | * * * *     |\n"
        "      |       * * | * *       |\n"
        "        |         |         |\n";

    EXPECT_EQ(output, expected_output);
}

TEST(PatternTest2, SmallPattern) {
    std::string output = captureOutput2(4, 1, 4);

    std::string expected_output =
        "      |       |       |\n"
        "    |     * * | * *     |\n"
        "  |   * * * * | * * * *   |\n"
        "| * * * * * * | * * * * * * |\n"
        "  |   * * * * | * * * *   |\n"
        "    |     * * | * *     |\n"
        "      |       |       |\n";

    EXPECT_EQ(output, expected_output);
}

/*____________________ Question 5 ____________________*/

void deleteMaze(int** maze, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] maze[i];
    }
    delete[] maze;
}

//void displayMaze(int** maze, int n, int m) {
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            std::cout << maze[i][j] << " ";
//        }
//        std::cout << std::endl; 
//    }
//}

void traversePath(int** maze, int n, int m, int x, int y) { //Donot eidt this
    int cx = 0, cy = 0;

    bool** visited = new bool* [n];
    for (int i = 0; i < n; i++) {
        visited[i] = new bool[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = false;
        }
    }

    visited[cx][cy] = true;

    while (cx != x || cy != y) {
        bool moved = false;

        // Move down
        if (cx + 1 < n && maze[cx + 1][cy] == 2 && !visited[cx + 1][cy]) {
            cx += 1;
            visited[cx][cy] = true;
            moved = true;
        }
        // Move right
        else if (cy + 1 < m && maze[cx][cy + 1] == 2 && !visited[cx][cy + 1]) {
            cy += 1;
            visited[cx][cy] = true;
            moved = true;
        }
        // Move up
        else if (cx - 1 >= 0 && maze[cx - 1][cy] == 2 && !visited[cx - 1][cy]) {
            cx -= 1;
            visited[cx][cy] = true;
            moved = true;
        }
        // Move left
        else if (cy - 1 >= 0 && maze[cx][cy - 1] == 2 && !visited[cx][cy - 1]) {
            cy -= 1;
            visited[cx][cy] = true;
            moved = true;
        }

        if (!moved) {
            for (int i = 0; i < n; i++) {
                delete[] visited[i];
            }
            delete[] visited;
            //displayMaze(maze, n, m);
            FAIL() << "Invalid path during traversal!"; // Fail the test if path is invalid
        }
    }

    for (int i = 0; i < n; i++) {
        delete[] visited[i];
    }
    delete[] visited;
}


TEST(MazeTest, TestMaze1) {
    int maze1[6][6] = {
        {1, 1, 0, 1, 1, 1},
        {0, 1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0, 1},
        {1, 1, 0, 0, 0, 1},
        {1, 0, 0, 1, 1, 1},
        {1, 1, 1, 1, 0, 1}
    };
    int n = 6, m = 6;
    int x = 2, y = 3; // destination

    int** maze = new int* [n];
    for (int i = 0; i < n; ++i) {
        maze[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            maze[i][j] = maze1[i][j];
        }
    }

    ASSERT_TRUE(solveMaze(maze, x, y, n, m)) << "Path not found!";

    traversePath(maze, n, m, x, y);

    ASSERT_EQ(maze[x][y], 2) << "Destination not reached!";

    deleteMaze(maze, n);
}

TEST(MazeTest, mulipath) {
    int maze1[6][6] = {
        {1, 1, 0, 1, 1, 1},
        {0, 1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0, 1},
        {1, 1, 1, 1, 0, 1},
        {1, 0, 0, 1, 1, 1},
        {1, 1, 1, 1, 0, 1}
    };
    int n = 6, m = 6;
    int x = 2, y = 3; // destination

    int** maze = new int* [n];
    for (int i = 0; i < n; ++i) {
        maze[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            maze[i][j] = maze1[i][j];
        }
    }

    ASSERT_TRUE(solveMaze(maze, x, y, n, m)) << "Path not found!";

    traversePath(maze, n, m, x, y);

    ASSERT_EQ(maze[x][y], 2) << "Destination not reached!";

    deleteMaze(maze, n);
}

TEST(MazeTest, TestMaze2) {
    int maze2[5][5] = {
        {1, 1, 0, 0, 1},
        {1, 1, 0, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 1, 1, 0},
        {1, 0, 1, 1, 1}
    };
    int n = 5, m = 5;
    int x = 4, y = 4; // destination

    int** maze = new int* [n];
    for (int i = 0; i < n; ++i) {
        maze[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            maze[i][j] = maze2[i][j];
        }
    }

    ASSERT_TRUE(solveMaze(maze, x, y, n, m)) << "Path not found!";

    traversePath(maze, n, m, x, y);

    ASSERT_EQ(maze[x][y], 2) << "Destination not reached!";

    deleteMaze(maze, n);
}

TEST(MazeTest, TestMaze3) {
    int maze3[4][5] = {
        {1, 0, 1, 1, 1},
        {1, 0, 0, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 1}
    };
    int n = 4, m = 5;
    int x = 3, y = 4; // destination

    int** maze = new int* [n];
    for (int i = 0; i < n; ++i) {
        maze[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            maze[i][j] = maze3[i][j];
        }
    }

    ASSERT_TRUE(solveMaze(maze, x, y, n, m)) << "Path not found!";

    traversePath(maze, n, m, x, y);

    ASSERT_EQ(maze[x][y], 2) << "Destination not reached!";

    deleteMaze(maze, n);
}

TEST(MazeTest, TestMaze4) {
    int maze4[3][6] = {
        {1, 1, 0, 1, 1, 1},
        {0, 1, 0, 1, 0, 1},
        {1, 1, 1, 1, 0, 1}
    };
    int n = 3, m = 6;
    int x = 2, y = 5; // destination

    int** maze = new int* [n];
    for (int i = 0; i < n; ++i) {
        maze[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            maze[i][j] = maze4[i][j];
        }
    }

    ASSERT_TRUE(solveMaze(maze, x, y, n, m)) << "Path not found!";

    traversePath(maze, n, m, x, y);

    ASSERT_EQ(maze[x][y], 2) << "Destination not reached!";

    deleteMaze(maze, n);
}

TEST(MazeTest, TestMaze5) {
    int maze5[2][3] = {
        {1, 1, 1},
        {0, 0, 1}
    };
    int n = 2, m = 3;
    int x = 1, y = 2; // destination

    int** maze = new int* [n];
    for (int i = 0; i < n; ++i) {
        maze[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            maze[i][j] = maze5[i][j];
        }
    }

    ASSERT_TRUE(solveMaze(maze, x, y, n, m)) << "Path not found!";

    traversePath(maze, n, m, x, y);

    ASSERT_EQ(maze[x][y], 2) << "Destination not reached!";

    deleteMaze(maze, n);
}

TEST(MazeTest, TestMaze6) {
    int maze6[3][5] = {
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 1}
    };
    int n = 3, m = 5;

    int** maze = new int* [n];
    for (int i = 0; i < n; ++i) {
        maze[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            maze[i][j] = maze6[i][j];
        }
    }

    ASSERT_FALSE(solveMaze(maze, 2, 4, n, m)) << "Path should not be found!";

    deleteMaze(maze, n);
}

/*____________________ Question 6 ____________________*/


int** createDynamicBoard(int board[9][9]) {
    int** dynamicBoard = new int* [9];
    for (int i = 0; i < 9; i++) {
        dynamicBoard[i] = new int[9];
        for (int j = 0; j < 9; j++) {
            dynamicBoard[i][j] = board[i][j];
        }
    }
    return dynamicBoard;
}

void deleteBoard(int** board) {
    for (int i = 0; i < 9; i++) {
        delete[] board[i];
    }
    delete[] board;
}

bool isValidSudoku(int** board) {
    bool row[9][10] = {}, col[9][10] = {}, block[9][10] = {};
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int num = board[i][j];
            if (num < 1 || num > 9) return false;
            int blockIdx = (i / 3) * 3 + (j / 3);
            if (row[i][num] || col[j][num] || block[blockIdx][num])
                return false;
            row[i][num] = col[j][num] = block[blockIdx][num] = true;
        }
    }
    return true;
}

TEST(SudokuTest, test1) {
    int board[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    int** dynamicBoard = createDynamicBoard(board);
    int originalBoard[9][9];
    memcpy(originalBoard, board, sizeof(board));

    ASSERT_TRUE(solveSudoku(dynamicBoard));
    ASSERT_TRUE(isValidSudoku(dynamicBoard));

    // Ensure original values are unchanged
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (originalBoard[i][j] != 0) {
                ASSERT_EQ(dynamicBoard[i][j], originalBoard[i][j])
                    << "Original value at (" << i << ", " << j << ") was altered.";
            }
        }
    }

    deleteBoard(dynamicBoard);
}

TEST(SudokuTest, test2) {
    int board[9][9] = {
        {8, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 3, 6, 0, 0, 0, 0, 0},
        {0, 7, 0, 0, 9, 0, 2, 0, 0},
        {0, 5, 0, 0, 0, 7, 0, 0, 0},
        {0, 0, 0, 0, 4, 5, 7, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 3, 0},
        {0, 0, 1, 0, 0, 0, 0, 6, 8},
        {0, 0, 8, 5, 0, 0, 0, 1, 0},
        {0, 9, 0, 0, 0, 0, 4, 0, 0}
    };

    int** dynamicBoard = createDynamicBoard(board);
    int originalBoard[9][9];
    memcpy(originalBoard, board, sizeof(board));

    ASSERT_TRUE(solveSudoku(dynamicBoard));
    ASSERT_TRUE(isValidSudoku(dynamicBoard));

    // Ensure original values are unchanged
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (originalBoard[i][j] != 0) {
                ASSERT_EQ(dynamicBoard[i][j], originalBoard[i][j])
                    << "Original value at (" << i << ", " << j << ") was altered.";
            }
        }
    }

    deleteBoard(dynamicBoard);
}

TEST(SudokuTest, test3) {
    int board[9][9] = {
        {0, 0, 0, 0, 0, 0, 0, 5, 7},
        {0, 0, 0, 0, 0, 6, 0, 0, 0},
        {1, 0, 0, 7, 0, 0, 0, 9, 6},
        {6, 0, 0, 0, 0, 0, 4, 0, 0},
        {0, 0, 0, 0, 2, 0, 0, 0, 0},
        {0, 4, 3, 0, 0, 0, 0, 0, 0},
        {0, 0, 8, 0, 1, 0, 0, 0, 9},
        {0, 9, 0, 2, 0, 7, 8, 0, 0},
        {0, 0, 5, 0, 8, 4, 0, 7, 0}
    };

    int** dynamicBoard = createDynamicBoard(board);
    int originalBoard[9][9];
    memcpy(originalBoard, board, sizeof(board));

    ASSERT_TRUE(solveSudoku(dynamicBoard));
    ASSERT_TRUE(isValidSudoku(dynamicBoard));

    // Ensure original values are unchanged
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (originalBoard[i][j] != 0) {
                ASSERT_EQ(dynamicBoard[i][j], originalBoard[i][j])
                    << "Original value at (" << i << ", " << j << ") was altered.";
            }
        }
    }

    deleteBoard(dynamicBoard);
}

TEST(SudokuTest, test4) {
    int board[9][9] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    int** dynamicBoard = createDynamicBoard(board);
    int originalBoard[9][9];

    ASSERT_TRUE(solveSudoku(dynamicBoard));
    ASSERT_TRUE(isValidSudoku(dynamicBoard));

    deleteBoard(dynamicBoard);
}

TEST(SudokuTest, UnsolvableSudoku) {
    int unsolvableBoard[9][9] = {
        {5, 1, 6, 8, 4, 9, 7, 3, 2},
        {3, 0, 7, 6, 0, 5, 0, 0, 0},
        {8, 0, 9, 7, 0, 0, 0, 6, 5},
        {1, 3, 5, 0, 6, 0, 9, 0, 7},
        {4, 7, 2, 5, 9, 1, 0, 0, 6},
        {9, 6, 8, 3, 7, 0, 5, 0, 0},
        {2, 5, 3, 1, 8, 6, 0, 7, 4},
        {6, 8, 4, 2, 0, 7, 0, 5, 0},
        {7, 9, 1, 0, 5, 0, 6, 0, 0}
    };

    int** dynamicBoard = createDynamicBoard(unsolvableBoard);
    ASSERT_FALSE(solveSudoku(dynamicBoard));
    deleteBoard(dynamicBoard);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}