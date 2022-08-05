#include "s21_smart_calc_cpp.h"
#include "ui_s21_smart_calc_cpp.h"
//#include "../qcustomplot.h"

s21_smart_calc_cpp::s21_smart_calc_cpp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::s21_smart_calc_cpp)
{
    ui->setupUi(this);
    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));

//    int xy_1 = ui->spin_xy_1->text().toInt();
//    int xy_2 = ui->spin_xy_1->text().toInt();
//    int result_1 = ui->spin_result_1->text().toInt();
//    int result_2 = ui->spin_result_2->text().toInt();

//    h = 0.1;
//    xBegin = result_2;
//    xEnd = result_1 + h;

//    ui->widget->xAxis->setRange(xy_2, xy_1);
//    ui->widget->yAxis->setRange(xy_2, xy_1);

//    X = xBegin;
//    N = (xEnd - xBegin)/h + 2;

//    for (X = xBegin; X <= xEnd; X+=h) {
//        x.push_back(X);
//        y.push_back(sin(X));
//    }
//    ui->widget->addGraph();
//    ui->widget->graph(0)->addData(x, y);
//    ui->widget->replot();
}

s21_smart_calc_cpp::~s21_smart_calc_cpp() {
    delete ui;
}

void s21_smart_calc_cpp::digits_numbers() {
    QPushButton *button = (QPushButton *)sender();

    ui->lineEdit->setText(ui->lineEdit->text() + button->text());
}

void s21_smart_calc_cpp::digits_operations() {
    QPushButton *button = (QPushButton *)sender();
    ui->lineEdit->setText(button->text());
}

void s21_smart_calc_cpp::on_pushButton_tch_clicked() {
    ui->lineEdit->setText(ui->lineEdit->text() + ".");
}

void s21_smart_calc_cpp::on_pushButton_plus_clicked() {
    ui->lineEdit->setText(ui->lineEdit->text() + "+");
}

void s21_smart_calc_cpp::on_pushButton_sub_clicked() {
    ui->lineEdit->setText(ui->lineEdit->text() + "-");
}

void s21_smart_calc_cpp::on_pushButton_mult_clicked() {
    ui->lineEdit->setText(ui->lineEdit->text() + "*");
}

void s21_smart_calc_cpp::on_pushButton_div_clicked() {
    ui->lineEdit->setText(ui->lineEdit->text() + "/");
}

void s21_smart_calc_cpp::on_pushButton_mod_clicked() {
    ui->lineEdit->setText(ui->lineEdit->text() + "mod");
}

void s21_smart_calc_cpp::on_pushButton_R_clicked() {
    ui->lineEdit->setText(ui->lineEdit->text() + ")");
}

void s21_smart_calc_cpp::on_pushButton_L_clicked() {
    ui->lineEdit->setText(ui->lineEdit->text() + "(");
}

void s21_smart_calc_cpp::on_pushButton_x_clicked() {
    ui->lineEdit->setText(ui->lineEdit->text() + "x");
}

void s21_smart_calc_cpp::on_pushButton_sin_clicked() {
    // if (ui->pushButton_result->isChecked()) {ui->lineEdit->setText("0");}
    ui->lineEdit->setText(ui->lineEdit->text() + "sin(");
}

void s21_smart_calc_cpp::on_pushButton_asin_clicked() {
    ui->lineEdit->setText(ui->lineEdit->text() + "asin(");
}

void s21_smart_calc_cpp::on_pushButton_ln_clicked() {
    ui->lineEdit->setText(ui->lineEdit->text() + "ln(");
}

void s21_smart_calc_cpp::on_pushButton_pow_clicked() {
    ui->lineEdit->setText(ui->lineEdit->text() + "^");
}

void s21_smart_calc_cpp::on_pushButton_sqrt_clicked() {
    ui->lineEdit->setText(ui->lineEdit->text() + "sqrt(");
}

void s21_smart_calc_cpp::on_pushButton_cos_clicked() {
    ui->lineEdit->setText(ui->lineEdit->text() + "cos(");
}

void s21_smart_calc_cpp::on_pushButton_log_clicked() {
    ui->lineEdit->setText(ui->lineEdit->text() + "log(");
}

void s21_smart_calc_cpp::on_pushButton_acos_clicked() {
    ui->lineEdit->setText(ui->lineEdit->text() + "acos(");
}

void s21_smart_calc_cpp::on_pushButton_tan_clicked() {
    ui->lineEdit->setText(ui->lineEdit->text() + "tan(");
}

void s21_smart_calc_cpp::on_pushButton_atan_clicked() {
    ui->lineEdit->setText(ui->lineEdit->text() + "atan(");
}

void s21_smart_calc_cpp::on_pushButton_result_clicked() {
    double x = 0;
    QPushButton *button = (QPushButton *)sender();
    button->setChecked(true);
    QString send = ui->lineEdit->text();
    QByteArray ba = send.toLocal8Bit();
    char* buf = ba.data();

    if (ui->lineEdit_2->text() != "") {
        x = (ui->lineEdit_2->text().toDouble());
    }

    QString toStr = QString::number(input_parsing(buf, x), 'g', 15);
    ui->lineEdit->setText(toStr);
}

void s21_smart_calc_cpp::on_pushButton_sin_2_clicked() {
    ui->lineEdit->setText("");
}


void s21_smart_calc_cpp::on_pushButton_tan_2_clicked() {
    QString send = ui->lineEdit->text();
    QByteArray ba = send.toLocal8Bit();
    char* buf = ba.data();
    ui->widget->clearGraphs();
    x.clear();
    y.clear();
    result_1 = 0;
    result_2 = 0;
    xBegin = 0;
    xEnd = 0;
    h = 0.1;

    X = ui->lineEdit_2->text().toDouble();

    xy_1 = ui->spin_xy_1->text().toDouble();
    xy_2 = ui->spin_xy_2->text().toDouble();
    result_1 = ui->spin_result_1->text().toInt();
    result_2 = ui->spin_result_2->text().toInt();

    xBegin = result_2;
    xEnd = result_1 + h;

    ui->widget->xAxis->setRange(xy_2, xy_1);
    ui->widget->yAxis->setRange(xy_2, xy_1);
    N = (xEnd - xBegin)/h + 2;

    for (X = xBegin; X <= xEnd; X+=h) {
        x.push_back(X);
        y.push_back(input_parsing(buf, X));
    }

    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);
    ui->widget->replot();
}

void s21_smart_calc_cpp::on_pushButton_result_credit_clicked() {
    int sum_credit = 0;  // сумма кредита
    int procent_credit = 0;  // процентная ставка
    int time_credit = 0;  // количество месяцев
    int result_credit = 0;  //платеж по кредиту в месяц
    int result_procent = 0;  // сумма переплаты за прoценты

    sum_credit = ui->line_credit_sum->text().toInt();
    procent_credit = ui->line_credit_procent->text().toInt();
    time_credit = ui->line_credit_data->text().toInt();

    QString q_result_credit = "";
    QString q_result_procent = "";
    if (ui->line_credit_sum->text() != "" && ui->line_credit_procent->text() != "" && ui->line_credit_data->text() != "") {
        result_procent = (((sum_credit/100)*procent_credit)/12)*time_credit;
        result_credit = (sum_credit/time_credit)+(result_procent/time_credit);
        q_result_credit = QString::number(result_credit);
        q_result_procent = QString::number(result_procent);
        ui->line_res_procent->setText(q_result_procent);
        ui->line_res_mes->setText(q_result_credit);
    }
}


void s21_smart_calc_cpp::on_pushButton_result_depozit_clicked() {
    int sum_dep = 0;  // сумма депозита
    int procent_dep= 0;  // проценты по вкладу
    int time_dep = 0;  // срок вклада
    int result_dep = 0;
    int result_procent_dep = 0;

    sum_dep = ui->line_sum_dep->text().toInt();
    procent_dep = ui->line_procent_dep->text().toInt();
    time_dep = ui->line_time_dep->text().toInt();

    QString q_result_dep = "";
    QString q_result_procent_dep = "";

    result_procent_dep = (((sum_dep/100)*procent_dep)/12)*time_dep;
    result_dep = result_procent_dep + sum_dep;

    q_result_procent_dep = QString::number(result_procent_dep);
    q_result_dep = QString::number(result_dep);

    ui->line_res_procent_dep->setText(q_result_procent_dep);
    ui->line_res_sum_dep->setText(q_result_dep);
}




