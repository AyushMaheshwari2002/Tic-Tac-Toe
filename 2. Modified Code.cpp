// Modified Code of Tic Tac Toe Game


#include <bits/stdc++.h>
#include <time.h>
#include<cstring>
#include<conio.h>

using namespace std;

char board[9] = {' ' , ' ' , ' '  , ' ' , ' ' , ' ' , ' ' , ' ' , ' '};

void show_board()
{
    cout << "--------------------"<< endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << board[0] << "  |   " << board[1] << "  |   " << board[2] << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "--------------------"<< endl;
    
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << board[3] << "  |   " << board[4] << "  |   " << board[5] << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "--------------------"<< endl;
    
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << board[6] << "  |   " << board[7] << "  |   " << board[8] << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "--------------------"<< endl;
}

void get_X_player_choice()
{
    while(true)
    {
        cout << "Select Your Position (1 - 9) : ";
        
        int choice;
        cin >> choice;
        choice--;                  //b'coz position starts from 0 in board array
        
        if(choice < 0 || choice > 8)
        {
            cout << "Please Select Your Choice from (1 - 9)" << endl;
        }
        
        else if(board[choice] != ' ')
        {
            cout << "Please Select an Empty Postion !!!" << endl;
        }
        
        else
        {
            board[choice] = 'X';
            break;
        }
    }
}

void get_O_player_choice()
{
    while(true)
    {
        cout << "Select Your Position (1 - 9) : ";
        
        int choice;
        cin >> choice;
        choice--;                //b'coz position starts from 0 in board array
        
        if(choice < 0 || choice > 8)
        {
            cout << "Please Select Your Choice from (1 - 9)." << endl;
        }
        
        else if(board[choice] != ' ')
        {
            cout << "Please Select an Empty Postion !!!" << endl;
        }
        
        else
        {
            board[choice] = 'O';
            break;
        }
    }
}

void get_Computer_choice()
{
    srand(time(0));                   //change random no. by using your laptop time
    int choice;
    do
    {
        choice = rand() % 10;        // this will generate a random no. b/w 0-9
    }while(board[choice] != ' ');       //if random no's place is occupied then loop stops
    
    board[choice] = 'O';            // computer character is always 'O'
}

int count_board(char symbol)
{
    int total = 0;
    for(int i = 0; i < 9; i++)
    {
        if(board[i] == symbol)
        {
            total++;
        }
    }
    
    return total;
}

char check_winner()
{
    // check winner in rows
    if(board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
    {
        return board[0];
    }
    if(board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
    {
        return board[3];
    }
    if(board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
    {
        return board[6];
    }
    
    // check winner in columns
    if(board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
    {
        return board[0];
    }
    if(board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
    {
        return board[1];
    }
    if(board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
    {
        return board[2];
    }
    
    // check winner diagonally
    if(board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
    {
        return board[0];
    }
    if(board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
    {
        return board[2];
    }
    
    if(count_board('X') + count_board('O') < 9)
    {
        return 'C';           // C stands for continue the game
    }
    else
    {
        return 'D';          // D for Draw
    }
    
}

void computer_vs_player()
{
    string player_name;
    cout << "Enter Your Name : ";
    cin >> player_name;
    
    while(true)
    {
        system("cls");
        show_board();
        if(count_board('X') == count_board('O'))
        {
            cout << player_name << "'s Turn." << endl;
            get_X_player_choice();
        }
        else
        {
            get_Computer_choice();
        }
        
        char winner = check_winner();
        if(winner == 'X')
        {
            system("cls");
            show_board();
            cout << player_name << " Won the Game." << endl;
            break;
        }
        
        else if(winner == 'O')
        {
            system("cls");
            show_board();
            cout << "Computer Won the Game." << endl;
            break;
        }
        
        else if(winner == 'D')
        {
            system("cls");
            show_board();
            cout << "Game is Draw." << endl;
            break;
        }
    }
}

void player_vs_player()
{
    string X_player_name, O_player_name;
    cout << "Enter X Player Name : ";
    cin >> X_player_name;
    
    cout << "Enter O Player Name : ";
    cin >> O_player_name;
    
    while(true)
    {
        system("cls");
        show_board();
        if(count_board('X') == count_board('O'))
        {
            cout << X_player_name << "'s Turn." << endl;
            get_X_player_choice();
        }
        else
        {
            cout << O_player_name << "'s Turn." << endl;
            get_O_player_choice();
        }
        
        char winner = check_winner();
        if(winner == 'X')
        {
            system("cls");
            show_board();
            cout << X_player_name << " Won the Game." << endl;
            break;
        }
        
        else if(winner == 'O')
        {
            system("cls");
            show_board();
            cout << O_player_name << " Won the Game." << endl;
            break;
        }
        
        else if(winner == 'D')
        {
            system("cls");
            cout << "Game is Draw." << endl;
            break;
        }
    }
}

int main()
{
    int chances;
    cout << "Enter how many chances you want to play : ";
    cin >> chances;

    while(chances--)
    {   
        int mode;
        memset(board,' ',sizeof(board));

        cout<<"\nPress Enter to Proceed!!\n";
        getch();
        system("cls");

        cout << "CHANCES LEFT : ";
        cout << chances;

        cout << "\n\n1. Computer vs Player." << endl;
        cout << "2. Player vs Player." << endl;
        cout << "\nSelect Game Mode : ";
        cin >> mode;
        
        switch(mode)
        {
            case 1 :
                computer_vs_player();
                break;
                
            case 2 :
                player_vs_player();
                break;
                
            default :
                cout << "Please Select Valid Game Mode." << endl;
                break;
        }
    }

    return 0;
}



