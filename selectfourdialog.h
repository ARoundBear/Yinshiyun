#ifndef SELECTFOURDIALOG_H
#define SELECTFOURDIALOG_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class SelectFourDialog;
}

class SelectFourDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectFourDialog(QWidget *parent = nullptr);
    ~SelectFourDialog();
    QVector<int> GetQCameras();
    void SetQCameras(QVector<int> QTemps);
    bool ResetCameras();
signals:
    void ChooseCameras();
private:
    Ui::SelectFourDialog *ui;
    QVector<int> QCameras;
};

#endif // SELECTFOURDIALOG_H
