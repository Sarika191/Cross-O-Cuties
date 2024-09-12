#include <bits/stdc++.h>
using namespace std;
void createboard(char board[3][3]){
         cout << "     " << "|" << "     " << "|" << "     " << endl;
         for(int i=0;i<3;i++){
         cout<<"  "<<board[i][0]<<"  |  "<<board[i][1]<<"  |  "<<board[i][2]<<endl;
         if(i!=2){
            cout << "-----" << "|" << "-----" << "|" << "-----" << endl;
         }
      }
         cout << "     " << "|" << "     " << "|" << "     " << endl;

   }
   int check(char board[3][3],int a){
    while(true){
      int row=(a-1)/3;
      int column=(a-1)%3;
      if(board[row][column]!=' '){
        cout<<"Invalid Move. It is occupied.Enter again"<<endl;
        cin>>a;
      }
      else{
         break;
      }
    }
    return a;
   }
bool winner(char board[3][3], char yo, char no, string player1, string player2) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == yo && board[i][1] == yo && board[i][2] == yo) {
            cout << player1 << " WON\n CONGRATULATIONS" << endl;
            return true;
            break;
        }
        if (board[i][0] == no && board[i][1] == no && board[i][2] == no) {
            cout << player2 << " WON\n CONGRATULATIONS" << endl;
            return true;
            break;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (board[0][i] == yo && board[1][i] == yo && board[2][i] == yo) {
            cout << player1 << " WON\n CONGRATULATIONS" << endl;
            return true;
            break;
        }
        if (board[0][i] == no && board[1][i] == no && board[2][i] == no) {
            cout << player2 << " WON\n CONGRATULATIONS" << endl;
            return true;
            break;
        }
    }

    if (board[0][0] == yo && board[1][1] == yo && board[2][2] == yo) {
        cout << player1 << " WON\n CONGRATULATIONS" << endl;
        return true;
    }
    if (board[0][0] == no && board[1][1] == no && board[2][2] == no) {
        cout << player2 << " WON\n CONGRATULATIONS" << endl;
        return true;
    }
    if (board[2][0] == yo && board[1][1] == yo && board[0][2] == yo) {
        cout << player1 << " WON\n CONGRATULATIONS" << endl;
        return true;
    }
    if (board[2][0] == no && board[1][1] == no && board[0][2] == no) {
        cout << player2 << " WON\n CONGRATULATIONS" << endl;
        return true;
    }
    else{
    return false;
    }
}

int main() {
    string player1, player2;
    int sign1, sign2, choice1, choice2;
    char cross = 'X', circle = 'O', yo=' ', no=' ';
    cout << endl;

    cout << "WELCOME TO TIC TAC TOE GAME" << endl;
    cout << "->Games rule: \n1.Enter your names.\n2.Enter your choosen sign.\n3.Enter 1 for cross.\n  Enter 0 for circle\n4.See the number of each block in the given figure." << endl;
    cout << "5.Enter the block number u want to fill." << endl;
    cout << endl;

    cout << "     " << "|" << "     " << "|" << "     " << endl;
    cout << "  1  " << "|" << "  2  " << "|" << "  3  " << endl;
    cout << "-----" << "|" << "-----" << "|" << "-----" << endl;
    cout << "  4  " << "|" << "  5  " << "|" << "  6  " << endl;
    cout << "-----" << "|" << "-----" << "|" << "-----" << endl;
    cout << "  7  " << "|" << "  8  " << "|" << "  9  " << endl;
    cout << "     " << "|" << "     " << "|" << "     " << endl;
    cout << endl;
    bool start=true;
    while(start){
    cout << "-------------------------------YOUR GAME BEGINS--------------------------------------------- \nNOTE- \"Data can't be changed once entered. choose wisely.\" \n " << endl;
    cout << "Enter name of 1st player:" << endl;
    cin >> player1;
    cout << "Enter name of 2nd player:" << endl;
    cin >> player2;

    while (true) {
        cout << player1 << " choose your sign:" << endl;
        cin >> sign1;
        cout << player2 << " choose your sign:" << endl;
        cin >> sign2;
        if (sign1 != sign2 && (sign1==1 || sign1==0)&& (sign2==1 || sign2==0)) {
            break;
        } else {
          cout<<endl;
            cout << "INVALID CHOICE\nEnter choice again\n1->Cross 0->Circle\nRemember choice has to be different\n(only 1 & 0)" << endl;
          cout<<endl;

        }
    }
    

    if (sign1 == 1) {
        yo = cross;
        no = circle;
    } else if (sign1 == 0) {
        yo = circle;
        no = cross;
    }

    cout << endl;
    cout << "---------------------------------START--------------------------------------" << endl;
    cout << endl;
    char board[3][3] = { { ' ', ' ', ' ' }, 
                         { ' ', ' ', ' ' }, 
                         { ' ', ' ', ' ' } }; 
     
      int a;
      int moves=0;
      while(true){
        
        cout<<player1<<" turn:"<<endl;
        
      cin>>a;
     a= check(board,a);
      switch(a){
            case 1:
                 board[0][0]=yo;
            break;
        case 2:
               board[0][1]=yo;
            break;
        case 3:
               board[0][2]=yo;

            break;
        case 4:
               board[1][0]=yo;
            
            break;
        case 5:
               board[1][1]=yo;
            
            break;
        case 6:
               board[1][2]=yo;
            
            break;
        case 7:
               board[2][0]=yo;
            
            break;
        case 8:
               board[2][1]=yo;
            
            break;
        case 9:
               board[2][2]=yo;
            
            break;
        default:
            cout<<"Invalid choice! Please enter a number between 1 and 9.";
            break;
    }
      
      createboard(board);
       moves++;
     if(moves>=9){
          cout<<"              Match Draw          \n"<<endl;
          break;
      }
      bool game=winner(board,yo,no,player1,player2);
      if(game){
        break;
      }
        cout<<player2<<" turn:"<<endl;
      cin>>a;
       moves++;
     a= check(board,a);
      switch(a){
            case 1:
                 board[0][0]=no;
            break;
        case 2:
               board[0][1]=no;
            break;
        case 3:
               board[0][2]=no;

            break;
        case 4:
               board[1][0]=no;
            
            break;
        case 5:
               board[1][1]=no;
            
            break;
        case 6:
               board[1][2]=no;
            
            break;
        case 7:
               board[2][0]=no;
            
            break;
        case 8:
               board[2][1]=no;
            
            break;
        case 9:
               board[2][2]=no;
            
            break;
        default:
            cout<<"Invalid choice! Please enter a number between 1 and 9.";
            break;
    }
      createboard(board);
     game=winner(board,yo,no,player1,player2);
      if(game){
        break;
      }
       
      }
     
      cout<<"\n __________________________________________________________________________________________\n\n            HEY\n       WANNA PLAY AGAIN                  \n     Enter '1' to restart"<<endl;
      string f;
      cin>>f;
      if(f=="1"){
        start=true;
      }
      else{
        start=false;
        cout<<"\n    ARIGATO FOR PLAYING."<<endl;
      }
     
}
    return 0;
}
