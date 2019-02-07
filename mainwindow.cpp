#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_LeetTrnsltr_triggered()
{
    QMessageBox msg;
    msg.setText("<h2>Leet Translator</h2>\n© 2016 byDanchyg1337<p><font color=red>3PKS8</font> <font color=green>KFU</font> <font color=blue>College</font></p>");
    msg.exec();
}

void MainWindow::on_button_toLeet_clicked()
{
    QString l3="";
    QFile file("abc.txt");
    if(file.open(QIODevice::ReadOnly)){
        QString str="", buff="", littbuff="";
        QByteArray lineinbyte;
        str=ui->lineEdit_eng->text().toUpper();

        for(int t=0;t<str.size();t++){
            lineinbyte="";
            bool find=false;
            for(int y=0;y<26;y++){
                file.open(QIODevice::ReadOnly);
                lineinbyte=file.readLine();
                buff=lineinbyte.data();
                if(str[t]==buff.at(0)){
                    find=true;
                    short int cols=0;
                    for(int r=0;r<buff.size();r++){
                        if(buff.at(r)==';'){cols++;}
                    }
                    int var=0+rand()%cols+1;
                    short int incols=0;
                    for(int u=2;u<buff.size();u++){
                        if(incols==var-1){

                            if(buff.at(u)==';'){incols++;}
                            else{littbuff+=buff.at(u);}

                        }
                        if(buff.at(u)==';'){
                            incols++;
                        }
                    }
                    l3+=littbuff;
                    littbuff="";
                    y=27;
                }


            }
            if(find==false){
                l3+=str.at(t);
            }
            file.close();
        }
    }
    else{
        QMessageBox msg;
        msg.setText("ToLEET File is failed to open");
        msg.exec();
    }
    ui->lineEdit_leet->setText(l3);
    file.close();
}

void MainWindow::on_button_toEng_clicked()
{

    QString str,buff="",littbuff="";
    QByteArray lineinbyte;
    str=ui->lineEdit_leet->text();
    bool arrayoflitt[str.size()];
    for(int w=0;w<str.size();w++){
        arrayoflitt[w]=false;
    }
    QFile file("qwe.txt");
    if(file.open(QIODevice::ReadOnly)){
        //Явное преобразование одним символом
        for(int t=0;t<str.size();t++){
            for(int y=0;y<16;y++){
                file.open(QIODevice::ReadOnly);
                lineinbyte=file.readLine();
                buff=lineinbyte.data();
                for(int u=2;u<buff.size();u++){
                    if(str[t]==buff.at(u)){
                        str[t]=buff.at(0);y=17;arrayoflitt[t]=true;
                    }
                }
            }
            file.close();
        }
    }


    //Явное преобразование двумя и более символами
    QFile file1("rty.txt");
    if(file1.open(QIODevice::ReadOnly)){
        bool maybe=false;
        for(int f=2;f<=5;f++){
            buff="";
            if(f==5){maybe=true;f=3;}
            else if(maybe==true&&f==4){f=2;}
            else if(maybe==true&&f==3){break;exit(0);}
            for(int t=0;t<str.size();t++){
                if(arrayoflitt[t]==true){

                }
                else{
                    for(int y=0;y<40;y++){
                        file1.open(QIODevice::ReadOnly);
                        lineinbyte=file1.readLine();
                        buff=lineinbyte.data();
                        if(f==3&&y<16){}
                        else if(maybe==false&&f==3&&y>24){y=47;}
                        else if(maybe==false&&y==16&&f==2){y=47;}
                        else if(maybe==false&&y<26&&f==4){}
                        else if(maybe==false&&f==4&&y>28){y=47;}
                        else if(maybe==true&&y<30&&f==3){}
                        else if(maybe==true&&y>31&&f==3){y=47;}
                        else if(maybe==true&&y<32&&f==2){}
                        else{
                            QString way="";
                            for(int g=0;g<f;g++){
                                way+=str[t+g];
                            }
                            littbuff="";
                            for(int u=2;u<buff.size();u++){
                                if(littbuff.size()<f){
                                    littbuff+=buff.at(u);
                                }
                                else{
                                    if(way==littbuff){
                                        str[t]=buff.at(0);arrayoflitt[t]=true;
                                        for(int g=1;g<f;g++){
                                            arrayoflitt[t+g]=true;
                                            str[t+g]=' ';
                                        }
                                        for(int c=1;c<f;c++){
                                            for(int m=t+1;m<str.size()-1;m++){
                                                QCharRef d=str[m];bool cell=arrayoflitt[m];
                                                arrayoflitt[m]=arrayoflitt[m+1];
                                                arrayoflitt[m+1]=cell;
                                                str[m]=str[m+1];
                                                str[m+1]=d;
                                            }

                                        }
                                        y=47;
                                    }
                                    littbuff="";
                                }
                            }
                        }
                    }
                    file1.close();
                }
            }
        }
        ui->lineEdit_eng->setText(str);

    }
    else{
        QMessageBox msg;
        msg.setText("ToENG File is failed to open");
        msg.exec();
    }

    QFile file2("uio.txt");
    file2.open(QIODevice::ReadOnly);
    buff="";
    for(int t=0;t<str.size();t++){
        if(arrayoflitt[t]==true){

        }
        else{
            for(int y=0;y<7;y++){
                file2.open(QIODevice::ReadOnly);
                lineinbyte=file2.readLine();
                buff=lineinbyte.data();
                for(int u=2;u<buff.size();u++){
                    if(str[t]==buff.at(u)){
                        str[t]=buff.at(0);y=8;arrayoflitt[t]=true;
                    }
                }
            }
            file2.close();
        }
    }

    ui->lineEdit_eng->setText(str);
}
