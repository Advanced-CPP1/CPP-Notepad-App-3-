#include "notepad.h"
#include "ui_notepad.h"

NotePad::NotePad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NotePad)
{
    ui->setupUi(this);
    this->resize(QSize(1100, 700));
    this->setWindowIcon(QIcon(":/imgs/imgs/notepad_icon.ico"));
    for (int i = 1; i <= 100; i++) {
        ui->comboBox->addItem(QString::number(i));
    }
}

NotePad::~NotePad()
{
    delete ui;
}


void NotePad::on_fontComboBox_currentFontChanged(const QFont &f)
{
    ui->textEdit->setFont(f);
}

void NotePad::on_comboBox_activated(int index)
{
    ui->textEdit->setStyleSheet(QString(ui->textEdit->styleSheet()).append(QString("font-size: ")).append(ui->comboBox->itemText(index)).append("px;\n"));
}

void NotePad::on_color_activated(int index)
{
    ui->textEdit->setStyleSheet(QString(ui->textEdit->styleSheet()).append(QString("color: ").append(QString(ui->color->itemText(index).append(";\n")))));
    if (ui->color->itemText(index) == QString("More")) {
        QColorDialog dialog {};
        dialog.setWindowTitle(QString("Choose font-color"));
        if (dialog.exec() == QColorDialog::Accepted) {
            ui->textEdit->setStyleSheet(QString(ui->textEdit->styleSheet()).append(QString("color: ").append(QString(dialog.selectedColor().name()).append(";\n"))));
        }
    }
}

void NotePad::on_bold_button_clicked() {
    ui->textEdit->setStyleSheet(QString(ui->textEdit->styleSheet()).append(QString("font-weight: bold;\n")));
    ui->bold_button_2->setStyleSheet(QString("background-color: grey;\n"));
    ui->bold_button->hide();
    ui->bold_button_2->show();
}

void NotePad::on_bold_button_2_clicked()
{
    ui->textEdit->setStyleSheet(QString(ui->textEdit->styleSheet()).append(QString("font-weight: normal;\n")));
    ui->bold_button_2->hide();
    ui->bold_button->show();
}


void NotePad::on_underline_button_clicked()
{
    ui->textEdit->setStyleSheet(QString(ui->textEdit->styleSheet()).append(QString("text-decoration: underline;\n")));
    ui->underline_button_2->setStyleSheet(QString("background-color: grey;\n"));
    ui->underline_button->hide();
    ui->underline_button_2->show();
}


void NotePad::on_underline_button_2_clicked()
{
    ui->textEdit->setStyleSheet(QString(ui->textEdit->styleSheet()).append("text-decoration: none;\n"));
    ui->linethrough_2->setStyleSheet(QString("background-color: none;\n"));
    ui->underline_button_2->hide();
    ui->underline_button->show();
}


void NotePad::on_center_button_clicked()
{
    ui->textEdit->setAlignment(Qt::AlignCenter);
    ui->center_button_2->setStyleSheet(QString("background-color: grey;\n"));
    ui->center_button->hide();
    ui->center_button_2->show();
}


void NotePad::on_italic_button_clicked()
{
    ui->textEdit->setStyleSheet(QString(ui->textEdit->styleSheet()).append(QString("font-style: italic;\n")));
    ui->italic_button_2->setStyleSheet(QString("background-color: grey;\n"));
    ui->italic_button->hide();
    ui->italic_button_2->show();
}


void NotePad::on_center_button_2_clicked()
{
    ui->textEdit->setAlignment(Qt::AlignLeft);
    ui->center_button_2->hide();
    ui->center_button->show();
}


void NotePad::on_italic_button_2_clicked()
{
    ui->textEdit->setStyleSheet(QString(ui->textEdit->styleSheet()).append("font-style: normal;\n"));
    ui->italic_button_2->hide();
    ui->italic_button->show();
}

void NotePad::on_linethrough_clicked()
{
    ui->textEdit->setStyleSheet(QString(ui->textEdit->styleSheet()).append("text-decoration: line-through;\n"));
    ui->linethrough_2->setStyleSheet(QString("background-color: grey;\n"));
    ui->linethrough->hide();
    ui->linethrough_2->show();
}
void NotePad::on_linethrough_2_clicked()
{
    ui->textEdit->setStyleSheet(QString(ui->textEdit->styleSheet()).append("text-decoration: none;\n"));
    ui->underline_button_2->setStyleSheet(QString("background-color: none;\n"));
    ui->linethrough_2->hide();
    ui->linethrough->show();
}

void NotePad::on_paste_button_clicked()
{
    ui->textEdit->paste();
}

