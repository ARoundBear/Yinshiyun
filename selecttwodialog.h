#ifndef SELECTTWODIALOG_H
#define SELECTTWODIALOG_H

#include <QDialog>

namespace Ui {
class SelectTwoDialog;
}

class SelectTwoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectTwoDialog(QWidget *parent = nullptr);
    ~SelectTwoDialog();
    QVector<int> GetQCameras();
    void SetQCameras(QVector<int> QTemps);
    bool ResetCameras();
signals:
    void ChooseCameras();
private:
    Ui::SelectTwoDialog *ui;
    QVector<int> QCameras;
};

#endif // SELECTTWODIALOG_H
