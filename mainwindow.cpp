#include "mainwindow.h"
#include <QCoreApplication>

//global
QString value="", total ="";
int fNum,sNum;
char doit='=';

//body
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    //button start set localisation
    int x = 30,y = 65,w = 50,h = 50,dx = 65,dy = 65;

    //label parameters
    int x_l = 30,y_l = 15, w_l = 195, h_l = 50 ;

    label = new QLabel("0",this);
    label->setGeometry(QRect(x_l,y_l,w_l,h_l));


    clear_button = new QPushButton("C",this);
    clear_button->setGeometry(x_l+w_l,y_l,w,h);
    connect(clear_button, SIGNAL(released()),this, SLOT(clear()));


    add_button = new QPushButton("+",this);
    y = y_l + dy;
    add_button->setGeometry(x,y,w,h);
    connect(add_button, SIGNAL(released()),this, SLOT(add()));

    substract_button = new QPushButton("-",this);
    x += dx;
    substract_button->setGeometry(x,y,w,h);
    connect(substract_button, SIGNAL(released()),this, SLOT(substract()));

    multiply_button = new QPushButton("*",this);
    x += dx;
    multiply_button->setGeometry(x,y,w,h);
    connect(multiply_button, SIGNAL(released()),this, SLOT(multiply()));

    divide_button = new QPushButton("/",this);
    x += dx;
    divide_button->setGeometry(x,y,w,h);
    connect(divide_button, SIGNAL(released()),this, SLOT(divide()));


    one_button = new QPushButton("1",this);
    x -= 3*dx; y+= dy;
    one_button->setGeometry(x,y,w,h);
    connect(one_button, SIGNAL(released()),this, SLOT(one()));

    two_button = new QPushButton("2",this);
    x += dx;
    two_button->setGeometry(x,y,w,h);
    connect(two_button, SIGNAL(released()),this, SLOT(two()));

    three_button = new QPushButton("3",this);
    x += dx;
    three_button->setGeometry(x,y,w,h);
    connect(three_button, SIGNAL(released()),this, SLOT(three()));

    four_button = new QPushButton("4",this);
    x -= 2*dx; y+= dy;
    four_button->setGeometry(x,y,w,h);
    connect(four_button, SIGNAL(released()),this, SLOT(four()));

    five_button = new QPushButton("5",this);
    x += dx;
    five_button->setGeometry(x,y,w,h);
    connect(five_button, SIGNAL(released()),this, SLOT(five()));

    six_button = new QPushButton("6",this);
    x += dx;
    six_button->setGeometry(x,y,w,h);
    connect(six_button, SIGNAL(released()),this, SLOT(six()));

    seven_button = new QPushButton("7",this);
    x -= 2*dx; y+= dy;
    seven_button->setGeometry(x,y,w,h);
    connect(seven_button, SIGNAL(released()),this, SLOT(seven()));

    eight_button = new QPushButton("8",this);
    x += dx;
    eight_button->setGeometry(x,y,w,h);
    connect(eight_button, SIGNAL(released()),this, SLOT(eight()));

    nine_button = new QPushButton("9",this);
    x += dx;
    nine_button->setGeometry(x,y,w,h);
    connect(nine_button, SIGNAL(released()),this, SLOT(nine()));

    zero_button = new QPushButton("0",this);
    x -= 2*dx; y+= dy;
    zero_button->setGeometry(x,y,w,h);
    connect(zero_button, SIGNAL(released()),this, SLOT(zero()));

    equals_button = new QPushButton("=",this);
    equals_button->setGeometry(x+3*dx,y,w,h);
    connect(equals_button, SIGNAL(released()),this, SLOT(equals()));


}

void MainWindow::clear() {
    value="";
    label->setText(value);
    total ="";
    fNum = 0;
    sNum =0;
}

void MainWindow::equals(){
    sNum = value.toInt();
    switch (doit) {
    case '*':
        sNum = fNum * sNum;
        break;
    case '/':
        if (sNum == 0) {
            //тут как бы сообщение о делении на ноль

            break;
            sNum = 9999; //test for error
        };
        sNum = fNum / sNum;
        break;
    case '+':
        sNum = fNum + sNum;
        break;
    case '-':
        sNum = fNum - sNum;
        break;
    default:
        sNum=value.toInt();
    break;
    }
    total = QString::number(sNum);
    label->setText(total);
    value = "";
    doit='=';
    fNum=0;
    sNum=0;
}

void MainWindow::add() {
    fNum = value.toInt();
    value = "";
    label -> setText(value);
    doit ='+';
}

void MainWindow::substract(){
    fNum = value.toInt();
    value = "";
    label -> setText(value);
    doit = '-';
}

void MainWindow::multiply(){
    fNum = value.toInt();
    value = "";
    label -> setText(value);
    doit = '*';
}

void MainWindow::divide(){
    fNum = value.toInt();
    value = "";
    label -> setText(value);
    doit = '/';
}

//--------------------------
//numbers
void MainWindow::zero() {
    value+="0";
    label->setText(value);
}

void MainWindow::one(){
    value+="1";
    label->setText(value);
}

void MainWindow::two(){
    value+="2";
    label->setText(value);
}

void MainWindow::three(){
    value+="3";
    label->setText(value);
}

void MainWindow::four(){
    value+="4";
    label->setText(value);
}

void MainWindow::five(){
    value+="5";
    label->setText(value);
}

void MainWindow::six(){
    value+="6";
    label->setText(value);
}

void MainWindow::seven(){
    value+="7";
    label->setText(value);
}

void MainWindow::eight(){
    value+="8";
    label->setText(value);
}

void MainWindow::nine(){
    value+="9";
    label->setText(value);
}

MainWindow::~MainWindow()
{
}
