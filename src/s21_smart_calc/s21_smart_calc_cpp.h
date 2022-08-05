#ifndef S21_SMART_CALC_CPP_H
#define S21_SMART_CALC_CPP_H

#include <QMainWindow>
#include "../qcustomplot.h"
#include <QVector>
#include <QTimer>
#include <QtMath>

#ifdef __cplusplus
extern "C"{
#endif
    #include "../s21_smart_calc.h"
#ifdef __cplusplus
}
#endif

QT_BEGIN_NAMESPACE
namespace Ui { class s21_smart_calc_cpp; }
QT_END_NAMESPACE

class s21_smart_calc_cpp : public QMainWindow
{
    Q_OBJECT

public:
    s21_smart_calc_cpp(QWidget *parent = nullptr);
    ~s21_smart_calc_cpp();

private:
    Ui::s21_smart_calc_cpp *ui;
    double xBegin, xEnd, h, X, xy_1, xy_2, result_1, result_2;
    int N;
    QVector<double> x, y;


private slots:
    void digits_numbers();
    void digits_operations();
    void on_pushButton_tch_clicked();
    void on_pushButton_plus_clicked();
    void on_pushButton_sub_clicked();
    void on_pushButton_mult_clicked();
    void on_pushButton_div_clicked();
    void on_pushButton_mod_clicked();
    void on_pushButton_R_clicked();
    void on_pushButton_L_clicked();
    void on_pushButton_x_clicked();
    void on_pushButton_sin_clicked();
    void on_pushButton_asin_clicked();
    void on_pushButton_ln_clicked();
    void on_pushButton_pow_clicked();
    void on_pushButton_sqrt_clicked();
    void on_pushButton_cos_clicked();
    void on_pushButton_log_clicked();
    void on_pushButton_acos_clicked();
    void on_pushButton_tan_clicked();
    void on_pushButton_atan_clicked();
    void on_pushButton_result_clicked();

    void on_pushButton_sin_2_clicked();
    void on_pushButton_tan_2_clicked();
    void on_pushButton_result_credit_clicked();
    void on_pushButton_result_depozit_clicked();
};
#endif // S21_SMART_CALC_CPP_H
