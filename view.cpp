#include "view.h"
#include "ui_view.h"
#include <QTextCodec>
#include <QFontComboBox>

View::View(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
{
    setFixedWidth(1080);
    setFixedHeight(1080);
    ui->setupUi(this);
    ui->spinFontSize->setMinimum(5);
    ui->spinFontSize->setMaximum(50);
    ui->spinFontSize->setValue(15);
}

View::~View()
{
    delete ui;
}


void View::on_boldBtn_clicked()
{
    QTextCharFormat fmt;
    fmt.setFontWeight(ui->plainTextEdit->currentCharFormat().fontWeight() == 50?100:50);
    ui->plainTextEdit->mergeCurrentCharFormat(fmt);
}


void View::on_italicBtn_clicked()
{
    QTextCharFormat fmt;
    fmt.setFontItalic(!ui->plainTextEdit->currentCharFormat().fontItalic());
    ui->plainTextEdit->mergeCurrentCharFormat(fmt);
}


void View::on_underlineBtn_clicked()
{
    QTextCharFormat fmt;
    fmt.setFontUnderline(!ui->plainTextEdit->currentCharFormat().fontUnderline());
    ui->plainTextEdit->mergeCurrentCharFormat(fmt);
}


void View::on_spinFontSize_valueChanged(int arg1)
{
    QTextCharFormat fmt;
    fmt.setFontPointSize(arg1);
    ui->plainTextEdit->mergeCurrentCharFormat(fmt);
}


void View::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(arg1);
    ui->plainTextEdit->mergeCurrentCharFormat(fmt);
}


void View::on_colorBtn_clicked()
{
    QPalette pal = ui->plainTextEdit->palette();
    QColor iniColor = pal.color(QPalette::Text);
    QColor color = QColorDialog::getColor(iniColor,this,"选择颜色");
    if(!color.isValid())
        return;

    //pal.setColor(QPalette::Text,color);
    QTextCharFormat fmt;
    fmt.setForeground(color);   //设置字体颜色
    ui->plainTextEdit->mergeCurrentCharFormat(fmt);

    //ui->plainTextEdit->setPalette(pal);
}

void View::on_openBtn_clicked()
{
    QString curPath = QDir::currentPath();
//    QString filter = "文本文件(*.txt)";
    QString fileName = QFileDialog::getOpenFileName(this,"打开文本文件",curPath);
    if(fileName.isEmpty())
        return;

    setWindowTitle(fileName);

    QFile file(fileName);
    if(file.open(QIODevice::ReadWrite)){
        QByteArray data = file.readAll();
        ui->plainTextEdit->setPlainText(data);
        file.close();
    }
}


void View::on_saveBtn_clicked()
{
    QString curPath = QDir::currentPath();
    // QString filter = "文本文件(*.txt)";
    QString fileName = QFileDialog::getSaveFileName(this,"另存为",curPath);
    if(fileName.isEmpty())
        return;

    QFile file(fileName);
    if(file.open(QIODevice::WriteOnly)){
        QString content = ui->plainTextEdit->toPlainText();
        QByteArray strBytes = content.toUtf8();
        file.write(strBytes,strBytes.length());
    }
}


void View::on_fontComboBox_currentFontChanged(const QFont &f)
{
    QTextCharFormat fmt;
    fmt.setFont(f);
    ui->plainTextEdit->mergeCurrentCharFormat(fmt);
}

