#include "addattribute.h"
#include "ui_addattribute.h"

addAttribute::addAttribute(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addAttribute)
{
    ui->setupUi(this);
}

addAttribute::~addAttribute()
{
    delete ui;
}
