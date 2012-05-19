#ifndef ADDATTRIBUTE_H
#define ADDATTRIBUTE_H

#include <QDialog>

namespace Ui {
class addAttribute;
}

class addAttribute : public QDialog
{
    Q_OBJECT
    
public:
    explicit addAttribute(QWidget *parent = 0);
    ~addAttribute();
    
private:
    Ui::addAttribute *ui;
};

#endif // ADDATTRIBUTE_H
