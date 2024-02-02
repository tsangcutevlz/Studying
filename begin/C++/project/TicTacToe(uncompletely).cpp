#include <iostream>
#include <vector>
#include <string>

using namespace std;

char c[3][3];
int R, C;
string turn = "X";
short choice;
bool check = false;
void updateBoard(int row, int col, vector<vector<string> > b, int &count, int n, int&z)
{
    if(!check){
        cout << " ";
        for (int i = 0; i < n; i++)
        {
            cout << "_______";
        }
        for (int i = 0; i < n-1; i++)
        {
            cout << "_";
        }
        check = true;
    }
    if (count == n)
    {

        cout << endl;
        int k = count;
        cout << "|";
        for (int i = 0; i < n; i++)
        {
            cout <<"       |";
        }
        cout << endl;
        
        for (int i = 0; i < n; i++)
        {
            z++;
            if (i == 0)
            {
                cout << "|";
            }
            if(z <= 10){
                cout << "   " << b[row][col - --k] << "   |";
            } else if (z > 10 && z<=100) {
                cout << "   " << b[row][col - --k] << "  |";          
            } else {
                cout << "  " << b[row][col - --k] << "  |";          
            }
            if (i == (n - 1))
            {
                cout << "\n";
            }
        }
        cout << "|";
        for (int i = 0; i < n; i++)
        {
            cout << "_______|";
        }
        count = 0;
    }
}

void createBoardElement(int n, vector<vector<string> > &b)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            b[i][j] = to_string(k++);
        }
    }
}

void displayBoard(int n, vector<vector<string> > b)
{
    int count = 0;
    int z = 0;
    cout << "       T I C -- T A C -- T O E -- G A M E      \n";
    cout << "                   FOR 2 PLAYERS               \n";
    cout << endl;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            count++;
            updateBoard(row, col, b, count, n, z);
        }
    }
    check = false;
}

int checkWin(int n, vector<vector<string> > b){


    int countX = 0;
    int countO = 0;
    int countXSub = 0;
    int countOSub = 0;
    int crossX = 0;
    int crossO = 0;
    int crossXSub = 0;
    int crossOSub = 0;
    int k = 0;
    if(n>= 5){
        k = 5;
    } else {
        k = n;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(b[i][j] == "X" || b[i][j] == "X " || b[i][j] == "X  "){
                countX++;
                if(b[i][j-1] == "O"|| b[i][j-1] == "O" || b[i][j-1] == "O " ){
                    if(b[i][j] == "X" || b[i][j] == "X " || b[i][j] == "X  "){
                        countX = 1;
                    } else {
                        countX = 0;
                    }
                } 
            } else if(b[i][j] == "O" || b[i][j] == "O " || b[i][j] == "O  "){
                countO++;
                if(b[i][j-1] == "X" || b[i][j-1] == "X " || b[i][j-1] == "X  "){ 
                    {
                        if(b[i][j] == "O" || b[i][j] == "O " || b[i][j] == "O  "){
                            countO = 1;
                        } else {
                            countO = 0;
                        }
                    }
                } 
            }
            if(b[j][i] == "X" || b[j][i] == "X " || b[j][i] == "X  "){
                countXSub++;
                if(b[j][i-1] == "O" || b[j][i-1] == "O " || b[j][i-1] == "O  "){
                    if(b[j][i] == "X" || b[j][i] == "X " || b[j][i] == "X  "){
                        countXSub = 1;
                    } else {
                        countXSub = 0;
                    }

                } 
            } else if(b[j][i] == "O" || b[j][i] == "O " || b[j][i] == "O  "){
                countOSub++;
                if(b[j][i-1] == "X" || b[j][i-1] == "X " || b[j][i-1] == "X  "){
                    if(b[j][i] == "O" || b[j][i] == "O " || b[j][i] == "O  "){
                        countOSub = 1;
                    } else {
                        countOSub = 0;
                    }
                } 
            }
        }
        if(countX == k){
            cout << "Player has X attribute is winner!!!";
            return 1;
        }
        if(countO == k){
            cout << "Player has O attribute is winner!!!";
            return 1;
        }
        if(countXSub == k){
            cout << "Player has X attribute is winner!!!";
            return 1;
        }
        if(countOSub == k){
            cout << "Player has O attribute is winner!!!";      
            return 1;
        }
        countX = 0;
        countO = 0;
        countXSub = 0;
        countOSub = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if(b[i][i] == "X" || b[i][i] == "X "|| b[i][i] == "X  "){
            crossX++;
            if(i>=1){
                if(b[i-1][i-1] == "O" ||b[i-1][i-1] == "O "|| b[i-1][i-1] == "O  "){
                    if(b[i][i] == "X" || b[i][i] == "X "|| b[i][i] == "X  "){
                        crossX = 1;
                    } else {
                        crossX = 0;
                    }
                    // crossX = 1;
                }
            }
        } else if(b[i][i] == "O" || b[i][i] == "O "|| b[i][i] == "O  "){
            crossO++;
            if(i>=1){
                if(b[i-1][i-1] == "X" ||b[i-1][i-1] == "X "|| b[i-1][i-1] == "X  "){
                    if(b[i][i] == "O" || b[i][i] == "O "|| b[i][i] == "O  "){
                        crossO = 1;
                    } else {
                        crossO = 0;
                    }
                    // crossO = 1;
                }
            }
        }
        if(b[i][n-1-i] == "X" || b[i][n-1-i] == "X " || b[i][n-1-i] == "X  "){
            crossXSub++;
            if(i >= 1){
                if(b[i-1][n-i] == "O"|| b[i-1][n-i] == "O " || b[i-1][n-i] == "O  "){
                    if(b[i][n-1-i] == "X" || b[i][n-1-i] == "X " || b[i][n-1-i] == "X  "){
                        crossXSub = 1;
                    } else {
                        crossXSub = 0;
                    }
                    // crossXSub = 1;
                }
            }
        } else if (b[i][n-1-i] == "O" || b[i][n-1-i] == "O " || b[i][n-1-i] == "O  "){
            crossOSub++;
            if(i >=1){
                if(b[i-1][n-i] == "X"|| b[i-1][n-i] == "X " || b[i-1][n-i] == "X  "){
                    if(b[i][n-1-i] == "O" || b[i][n-1-i] == "O " || b[i][n-1-i] == "O  "){
                        crossOSub = 1;
                    } else {
                        crossOSub = 0;
                    }
                    // crossOSub = 1;
                }
            }
        }
    }
    if(crossX == k|| crossXSub == k){
        cout << "Player has X attribute is winner!!!";  
        return 1;
    }
    if(crossO == k|| crossOSub == k){
        cout << "Player has O attribute is winner!!!";  
        return 1;
    }
    return 0;


}



int playerTurn(int n, vector<vector<string> > b){
    if(turn == "X"){
        cout << "\nPlayer - 1 [X] turn: ";
    } else {
        cout << "\nPlayer - 2 [O] turn: ";
    }
    
    cin >> choice;
    R = choice / n;
    C = choice % n;
    if (turn == "X" && b[R][C] != "X" && b[R][C] != "O"){
        if(choice >= 10){
            b[R][C] = "X ";
        } else {
            b[R][C] = "X";
        }
        turn = "O";
    } else if (turn == "O" && b[R][C] != "X" && b[R][C] != "O"){
        if(choice >= 10){
            b[R][C] = "O ";
        } else {
            b[R][C] = "O";
        }
        turn = "X";
    }
    if(checkWin(n, b)){
        return 0;
    }
    displayBoard(n, b);
    playerTurn(n, b);
}

int main()
{
    int n;
    cout << "nhap so luong hang, cot: ";
    cin >> n;
    vector<vector<string> > b;
    b.resize(n, vector<string>(n));
    createBoardElement(n, b);
    displayBoard(n, b);
    playerTurn(n, b);

    return 0;
}