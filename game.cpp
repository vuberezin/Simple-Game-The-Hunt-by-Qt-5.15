#include "game.h"
#include "ui_game.h"

Game::Game(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);
}


 vector<Game::Cell> Game::buildCellButtons(size_t rows, size_t cols) {

    int p = 0;
    cells.reserve(rows * cols);
    for (size_t row = 0; row < rows; ++row) {
        for (size_t col = 0; col < cols; ++col) {
            QPushButton *btn = new QPushButton();
            btn->setStyleSheet("background-color:");
            btn->setText(" ");
            //btn->setProperty("cell", true);
            btn->setStyleSheet("font: 50px \"Verdana\";"
                               "min-height: 100px;"
                               "max-height: 100px;"
                               "min-width: 100px;"
                               "max-width: 100px;");
            ui->gridLayout->addWidget(btn,
                                     static_cast<int>(row),
                                     static_cast<int>(col),
                                     1,
                                     1);

            cells.emplace_back(btn, row, col, p++);
        }
    }

    adjustSize();
    return cells;
}


 void Game::startGame(){
     auto it = cells.begin();
     it[0].cellBtn->setEnabled(false);
     it[0].cellBtn->setStyleSheet("font: 50px \"Verdana\";"
                                  "min-height: 100px;"
                                  "max-height: 100px;"
                                  "min-width: 100px;"
                                  "max-width: 100px;"
                                  "background-color: transparent");

     it[1].cellBtn->setStyleSheet("font: 50px \"Verdana\";"
                                  "min-height: 100px;"
                                  "max-height: 100px;"
                                  "min-width: 100px;"
                                  "max-width: 100px;"
                                  "background-color: /*lightGray*/");

     it[2].cellBtn->setEnabled(false);
     it[2].cellBtn->setStyleSheet("font: 50px \"Verdana\";"
                                  "min-height: 100px;"
                                  "max-height: 100px;"
                                  "min-width: 100px;"
                                  "max-width: 100px;"
                                  "background-color: transparent");


     it[3].cellBtn->setStyleSheet("font: 50px \"Verdana\";"
                                  "min-height: 100px;"
                                  "max-height: 100px;"
                                  "min-width: 100px;"
                                  "max-width: 100px;"
                                  "background-color: /*lightGray*/");

     it[4].cellBtn->setStyleSheet("font: 50px \"Verdana\";"
                                  "min-height: 100px;"
                                  "max-height: 100px;"
                                  "min-width: 100px;"
                                  "max-width: 100px;"
                                  "background-color: /*lightGray*/");

     it[5].cellBtn->setStyleSheet("font: 50px \"Verdana\";"
                                  "min-height: 100px;"
                                  "max-height: 100px;"
                                  "min-width: 100px;"
                                  "max-width: 100px;"
                                  "background-color: /*lightGray*/");

     it[6].cellBtn->setStyleSheet("font: 50px \"Verdana\";"
                                  "min-height: 100px;"
                                  "max-height: 100px;"
                                  "min-width: 100px;"
                                  "max-width: 100px;"
                                  "background-color: /*lightGray*/");

     it[7].cellBtn->setStyleSheet("font: 50px \"Verdana\";"
                                  "min-height: 100px;"
                                  "max-height: 100px;"
                                  "min-width: 100px;"
                                  "max-width: 100px;"
                                  "color: blue;"
                                  "background-color: /*lightGray*/");

     it[8].cellBtn->setStyleSheet("font: 50px \"Verdana\";"
                                  "min-height: 100px;"
                                  "max-height: 100px;"
                                  "min-width: 100px;"
                                  "max-width: 100px;"
                                  "background-color: /*lightGray*/");

     it[9].cellBtn->setStyleSheet("font: 50px \"Verdana\";"
                                  "min-height: 100px;"
                                  "max-height: 100px;"
                                  "min-width: 100px;"
                                  "max-width: 100px;"
                                  "color: red;"
                                  "background-color: /*lightGray*/");

     it[10].cellBtn->setStyleSheet("font: 50px \"Verdana\";"
                                  "min-height: 100px;"
                                  "max-height: 100px;"
                                  "min-width: 100px;"
                                  "max-width: 100px;"
                                  "background-color: /*lightGray*/");

     it[11].cellBtn->setStyleSheet("font: 50px \"Verdana\";"
                                  "min-height: 100px;"
                                  "max-height: 100px;"
                                  "min-width: 100px;"
                                  "max-width: 100px;"
                                  "color: red;"
                                  "background-color: /*lightGray*/");

     it[12].cellBtn->setEnabled(false);
     it[12].cellBtn->setStyleSheet("font: 50px \"Verdana\";"
                                  "min-height: 100px;"
                                  "max-height: 100px;"
                                  "min-width: 100px;"
                                  "max-width: 100px;"
                                  "background-color: transparent");

     it[13].cellBtn->setStyleSheet("font: 50px \"Verdana\";"
                                  "min-height: 100px;"
                                  "max-height: 100px;"
                                  "min-width: 100px;"
                                  "max-width: 100px;"
                                  "color: red;"
                                  "background-color: /*lightGray*/");


     it[14].cellBtn->setEnabled(false);
     it[14].cellBtn->setStyleSheet("font: 50px \"Verdana\";"
                                  "min-height: 100px;"
                                  "max-height: 100px;"
                                  "min-width: 100px;"
                                  "max-width: 100px;"
                                  "background-color: transparent");

 //--------------------------------------------------------------------------------------------

      it[9].cellBtn->setText((QString)static_cast<char>(BoardMarks::X));
      //it[9].pl = 100;

      it[11].cellBtn->setText((QString)static_cast<char>(BoardMarks::X));
      //it[11].pl = 100;

      it[13].cellBtn->setText((QString)static_cast<char>(BoardMarks::X));
      //it[13].pl = 100;

      it[7].cellBtn->setText((QString)static_cast<char>(BoardMarks::O));
      //it[7].pl = 200;

 }

void Game::setConnection(){

for (Cell &cell : cells)
    connect(cell.cellBtn, &QPushButton::clicked, this, [&] { updateGame(cell); });
}

void Game::updateGame(Cell &cell)
{
    auto it = cells.begin();

    if(cell.cellBtn->text() == "X" & okX == true){
        cell.cellBtn->setText(" ");
        int i = cell.pl;
        //it[i].pl = 0;
        okX = false;
       }
    else if (cell.cellBtn->text() == " " & okX == false){
        cell.cellBtn->setText("X");
        cell.cellBtn->setStyleSheet("font: 50px \"Verdana\";"
                                    "min-height: 100px;"
                                    "max-height: 100px;"
                                    "min-width: 100px;"
                                    "max-width: 100px;"
                                    "color: red;"
                                    "background-color: " );
        int i = cell.pl;

        //it[i].pl = 100;
        okX = true;
        Game::finishGame();
    }

    if(cell.cellBtn->text() == "O" & okO == true){
        cell.cellBtn->setText(" ");
        int i = cell.pl;
        //it[i].pl = 0;
        okO = false;
       }
    else if (cell.cellBtn->text() == " " & okO == false ){
        cell.cellBtn->setText("O");
        cell.cellBtn->setStyleSheet("font: 50px \"Verdana\";"
                                    "min-height: 100px;"
                                    "max-height: 100px;"
                                    "min-width: 100px;"
                                    "max-width: 100px;"
                                    "color: blue;"
                                    "background-color: " );
        int i = cell.pl;
        //it[i].pl = 200;

        okO = true;
        Game::finishGame();
    }
    for(int i = 0; i < 14; ++i ){
     qDebug() << "Cell number = " << it[i].pl ;
    }


}

void Game::finishGame(){
    auto it = cells.begin();

        if (it[3].cellBtn->text() == "X" & it[4].cellBtn->text() == "X" & it[5].cellBtn->text() == "X"
                & it[1].cellBtn->text() == "O"){
            messageBox("Player X wins!");
        }

        else if(it[3].cellBtn->text() == "X" & it[7].cellBtn->text() == "X" & it[9].cellBtn->text() == "X"
                & it[6].cellBtn->text() == "O"){
            messageBox("Player X wins!");
        }

        else if(it[5].cellBtn->text() == "X" & it[7].cellBtn->text() == "X" & it[11].cellBtn->text() == "X"
                & it[8].cellBtn->text() == "O"){
            messageBox("Player X wins!");
        }


        else if(it[6].cellBtn->text() == "X" & it[10].cellBtn->text() == "X"
                & it[9].cellBtn->text() == "O"){
            messageBox("Player X wins!");
        }

        else if(it[8].cellBtn->text() == "X" & it[10].cellBtn->text() == "X"
                & it[11].cellBtn->text() == "O"){
            messageBox("Player X wins!");
        }

        else if(it[8].cellBtn->text() == "X" & it[10].cellBtn->text() == "X"
                & it[11].cellBtn->text() == "O"){
            messageBox("Player X wins!");
        }

        else if(it[6].cellBtn->text() == "X" & it[4].cellBtn->text() == "X"
                & it[3].cellBtn->text() == "O"){
            messageBox("Player X wins!");
        }

        else if(it[8].cellBtn->text() == "X" & it[4].cellBtn->text() == "X"
                & it[5].cellBtn->text() == "O"){
            messageBox("Player X wins!");
        }

 //--------------------------------------------------------------------------------------------

        else if(searchMaximum("X") < searchMaximum("O")){
            messageBox("Player O wins!");
        }

}

void Game::messageBox(QString str){
    QMessageBox msgBox;
    msgBox.setText(str);
    msgBox.setStyleSheet("QLabel{min-width: 200px;}");
    msgBox.exec();
}


int Game::searchMaximum(QString str){

    auto it = cells.begin();

    if(str == "O"){
    for(int i = cells.size()-1; i > 0; i--){
    if(it[i].cellBtn->text() == str){
          max = it[i].row;
        }
    }
        return max;

    } else if(str == "X"){
        for(int i = cells.size()-1; i > 0; i--){
        if(it[i].cellBtn->text() == str){
              max = it[i].row;
            }
        }

        for(int i = 0; i < cells.size(); i++){
        if(it[i].cellBtn->text() == str){
              min = it[i].row;
            }
        }

        return ( max > min) ? max : min;

    }

}

Game::~Game()
{
    delete ui;
}