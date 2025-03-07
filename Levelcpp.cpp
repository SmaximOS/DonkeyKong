#include"Level.h"
#include "general.h"

    
    

    // Destructor to free allocated memory
    Level::~Level(){
        delete[] ladders;
    }

    // Setters and Getters for the board
    void Level:: setBoardValue(int row, int col, char value) {
        if (row >= 0 && row < 8 && col >= 0 && col < GameConfig::WIDTH - 2)
            board[row][col] = value;
    }

    char Level:: getBoardValue(int row, int col) const {
        if (row >= 0 && row < 8 && col >= 0 && col < GameConfig::WIDTH - 2)
            return board[row][col];
        return -1; // Return -1 if out of bounds
    }

    // Setters and Getters for ladders
    void Level:: addLadder(Ladder ladder)
    {
        numLadders++;
        if (numLadders == 1)
            ladders = (Ladder*)malloc(sizeof(Ladder));
        else
            ladders = (Ladder*)realloc(ladders, sizeof(Ladder) * numLadders);

        ladders[numLadders-1] = ladder;
    }

    Ladder Level:: getLadder(int index) const {
        if (index >= 0 && index < numLadders)
            return ladders[index];
        return Ladder(Point(), 0); // Return a default ladder if out of bounds
    }

    int Level:: getNumLadders() const {
        return numLadders;
    }
    char(*Level::getBoardPointer())[GameConfig::WIDTH - 2] {
        return board;
        }

    // Method to print the board
    void Level::printBoard() const
    {
        int y = GameConfig::FLOOR1;
        for (int i = 0; i < GameConfig::NUMFLOORS; i++)
        {
            int x = GameConfig::MIN_X +1; // Start inside the border
            for (int j = 0; j < GameConfig::WIDTH -2; j++) // Full width now
            {
                gotoxy(x, y);
                switch (board[i][j])
                {
                case 1:
                    cout << '=';
                    break;
                case 2:
                    cout << '>';
                    break;
                case 3:
                    cout << '<';
                    break;
                case 0:
                    cout << ' ';
                    break;
                }
                x++;
            }
            gotoxy(x, y);
            switch (board[i][GameConfig::WIDTH-3])
            {
            case 1:
                cout << '=';
                break;
            case 2:
                cout << '>';
                break;
            case 3:
                cout << '<';
                break;
            case 0:
                cout << ' ';
                break;
            }
            y -= GameConfig::FLOORDIFF;
        }
        printLadders();
    }
    void Level::printLadders()const
    {

        for (int i = 0;i < numLadders;i++)
        {

            ladders[i].draw();
        }
    }
    void Level::initializeBoard()
    {
        int i;

        //Floor 1
        for (i = 0;i <=30 ;i++)
            board[0][i] = 1;

        board[0][30] = 2;//Right Slope

        for (i = 71;i < GameConfig::WIDTH-2;i++)
            board[0][i] = 1;
        board[0][71] = 3;

        //Floor2
        for (i = 0;i <= 15;i++)
            board[1][i] = 1;
        board[1][15]= 2;

        for (i = 27;i <= 74;i++)
            board[1][i] = 1;
        board[1][74] = 2;

        for (i = 78;i < GameConfig::WIDTH - 2;i++)
            board[1][i] = 1;

        //Floor3
        for (i = 4;i <= 19;i++)
            board[2][i] = 1;
        board[2][19] = 2;

        for (i = 22;i <=50;i++)
            board[2][i] = 1;
        board[2][50] = 2;

        for (i = 67;i <= 80;i++)
            board[2][i] = 1;
        for (i = 85;i < GameConfig::WIDTH - 2;i++)
            board[2][i] = 1;

        //Floor4
        for (i = 12;i <= 31;i++)
            board[3][i] = 1;
        board[3][31] = 2;

        for (i = 34;i <= 43;i++)
            board[3][i] = 1;
        board[3][43] = 2;

        for (i = 55;i <=100;i++)
            board[3][i] = 1;
        board[3][55] = 3;

        //Floor5
        for (i = 33;i <= 70;i++)
            board[4][i] = 1;
        board[4][33] = 3;

        //Floor6
        for(i = 0;i <= 16;i++)
            board[5][i] = 1;
        for (i = 26;i <=66;i++)
              board[5][i] = 1;
        board[5][26] = 3;
        for (i = 83;i <GameConfig::WIDTH-2;i++)
              board[5][i] = 1;
        board[5][83] = 3;

        //Floor7
        for (i = 4;i <= 19;i++)
            board[6][i] = 1;
        for (i = 22;i <= 34;i++)
            board[6][i] = 1;
        board[6][34] = 2;
        for (i = 47;i <= 60;i++)
            board[6][i] = 1;
        for (i = 63;i <= 73;i++)
            board[6][i] = 1;
        board[6][73] = 2;
        for (i = 82;i <= 98;i++)
            board[6][i] = 1;

        //Floor8
        for (i = 0;i <=30;i++)
            board[7][i] = 1;
        for (i = 50 ;i <= 57;i++)
            board[7][i] = 1;

        //Ladders

        addLadder(Ladder(Point(GameConfig::MIN_X + 10, GameConfig::FLOOR1 - 1), 5));
        addLadder(Ladder(Point(GameConfig::MIN_X + 30, GameConfig::FLOOR1 - 1), 2));
        addLadder(Ladder(Point(GameConfig::MIN_X + 73, GameConfig::FLOOR1 - 1), 2));
        addLadder(Ladder(Point(GameConfig::MIN_X + 92, GameConfig::FLOOR2 - 1), 2));
        addLadder(Ladder(Point(GameConfig::MIN_X + 60, GameConfig::FLOOR4 - 1), 2));
        addLadder(Ladder(Point(GameConfig::MIN_X + 28, GameConfig::FLOOR6 - 1), 2));
        addLadder(Ladder(Point(GameConfig::MIN_X + 97, GameConfig::FLOOR2 - 1), 5));
        addLadder(Ladder(Point(GameConfig::MIN_X + 55, GameConfig::FLOOR6 - 1), 1));
        addLadder(Ladder(Point(GameConfig::MIN_X + 37, GameConfig::FLOOR4 - 1), 1));
    }


