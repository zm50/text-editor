#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QDebug>
#include <QColorDialog>
#include <QDir>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class View; }
QT_END_NAMESPACE

class View : public QMainWindow
{
    Q_OBJECT

public:
    View(QWidget *parent = nullptr);
    ~View();

private slots:

    void on_boldBtn_clicked();

    void on_italicBtn_clicked();

    void on_spinFontSize_valueChanged(int arg1);

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_colorBtn_clicked();

    void on_openBtn_clicked();

    void on_saveBtn_clicked();

    void on_fontComboBox_currentFontChanged(const QFont &f);

    void on_underlineBtn_clicked();

private:
    Ui::View *ui;
};
#endif // VIEW_H
