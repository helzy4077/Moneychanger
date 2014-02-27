#ifndef DLGGETAMOUNT_HPP
#define DLGGETAMOUNT_HPP

#include <WinsockWrapper.h>
#include <ExportWrapper.h>

#include <QDialog>

#include <cstdint>

namespace Ui {
class DlgGetAmount;
}

class DlgGetAmount : public QDialog
{
    Q_OBJECT

public:
    explicit DlgGetAmount(QWidget *parent, QString qstrAcctId, QString qstrAssetId, QString qstrReason);
    ~DlgGetAmount();

    int64_t GetAmount() { return m_lAmount; }

protected:
    bool eventFilter(QObject *obj, QEvent *event);

//  void closeEvent(QCloseEvent *event);
//  void accept();

private slots:
    void on_lineEdit_editingFinished();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    QString m_qstrAcctId;
    QString m_qstrAssetId;

    QString m_qstrReason;

    int64_t m_lAmount;
    bool    m_bValidAmount;

    Ui::DlgGetAmount *ui;
};

#endif // DLGGETAMOUNT_HPP
