/********************************************************************************
** Form generated from reading UI file 'paperwalletdialog.ui'
**
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAPERWALLETDIALOG_H
#define UI_PAPERWALLETDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include "verticallabel.h"

QT_BEGIN_NAMESPACE

class Ui_PaperWalletDialog
{
public:
    QLabel *privateKeyQRCode;
    QLabel *addressQRCode;
    QPushButton *getNewAddress;
    QLabel *paperTemplate;
    VerticalLabel *addressText;
    VerticalLabel *privateKeyText;
    QPushButton *printButton;
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QComboBox *walletCount;
    QTextEdit *publicKey;
    QLabel *label_2;

    void setupUi(QDialog *PaperWalletDialog)
    {
        if (PaperWalletDialog->objectName().isEmpty())
            PaperWalletDialog->setObjectName(QString::fromUtf8("PaperWalletDialog"));
        PaperWalletDialog->resize(716, 450);
        privateKeyQRCode = new QLabel(PaperWalletDialog);
        privateKeyQRCode->setObjectName(QString::fromUtf8("privateKeyQRCode"));
        privateKeyQRCode->setGeometry(QRect(524, 159, 149, 149));
        privateKeyQRCode->setScaledContents(true);
        addressQRCode = new QLabel(PaperWalletDialog);
        addressQRCode->setObjectName(QString::fromUtf8("addressQRCode"));
        addressQRCode->setGeometry(QRect(47, 86, 120, 120));
        addressQRCode->setScaledContents(true);
        getNewAddress = new QPushButton(PaperWalletDialog);
        getNewAddress->setObjectName(QString::fromUtf8("getNewAddress"));
        getNewAddress->setGeometry(QRect(20, 415, 151, 26));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/add"), QSize(), QIcon::Normal, QIcon::Off);
        getNewAddress->setIcon(icon);
        paperTemplate = new QLabel(PaperWalletDialog);
        paperTemplate->setObjectName(QString::fromUtf8("paperTemplate"));
        paperTemplate->setGeometry(QRect(20, 10, 675, 362));
        paperTemplate->setText(QString::fromUtf8(""));
        paperTemplate->setPixmap(QPixmap(QString::fromUtf8(":/images/paper_wallet")));
        addressText = new VerticalLabel(PaperWalletDialog);
        addressText->setObjectName(QString::fromUtf8("addressText"));
        addressText->setGeometry(QRect(212, 20, 31, 341));
        QFont font;
        font.setFamily(QString::fromUtf8("Monospace"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(75);
        addressText->setFont(font);
        addressText->setAlignment(Qt::AlignCenter);
        addressText->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        privateKeyText = new VerticalLabel(PaperWalletDialog);
        privateKeyText->setObjectName(QString::fromUtf8("privateKeyText"));
        privateKeyText->setGeometry(QRect(500, 10, 31, 361));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Monospace"));
        font1.setPointSize(8);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        privateKeyText->setFont(font1);
        privateKeyText->setScaledContents(true);
        privateKeyText->setAlignment(Qt::AlignCenter);
        privateKeyText->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        printButton = new QPushButton(PaperWalletDialog);
        printButton->setObjectName(QString::fromUtf8("printButton"));
        printButton->setGeometry(QRect(420, 415, 111, 26));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/receiving_addresses"), QSize(), QIcon::Normal, QIcon::Off);
        printButton->setIcon(icon1);
        buttonBox = new QDialogButtonBox(PaperWalletDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(610, 415, 81, 26));
        buttonBox->setStandardButtons(QDialogButtonBox::NoButton);
        buttonBox->setCenterButtons(true);
        label = new QLabel(PaperWalletDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 415, 91, 26));
        walletCount = new QComboBox(PaperWalletDialog);
        walletCount->setObjectName(QString::fromUtf8("walletCount"));
        walletCount->setGeometry(QRect(290, 415, 74, 26));
        walletCount->setEditable(false);
        publicKey = new QTextEdit(PaperWalletDialog);
        publicKey->setObjectName(QString::fromUtf8("publicKey"));
        publicKey->setGeometry(QRect(100, 378, 600, 30));
        publicKey->setUndoRedoEnabled(false);
        publicKey->setReadOnly(true);
        publicKey->setAcceptRichText(false);
        label_2 = new QLabel(PaperWalletDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 380, 91, 26));
        getNewAddress->raise();
        paperTemplate->raise();
        addressQRCode->raise();
        privateKeyQRCode->raise();
        addressText->raise();
        privateKeyText->raise();
        printButton->raise();
        buttonBox->raise();
        label->raise();
        walletCount->raise();
        publicKey->raise();
        label_2->raise();

        retranslateUi(PaperWalletDialog);
        QObject::connect(buttonBox, SIGNAL(rejected()), PaperWalletDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(PaperWalletDialog);
    } // setupUi

    void retranslateUi(QDialog *PaperWalletDialog)
    {
        PaperWalletDialog->setWindowTitle(QApplication::translate("PaperWalletDialog", "Print Your Paper Wallets", 0, QApplication::UnicodeUTF8));
        privateKeyQRCode->setText(QString());
        addressQRCode->setText(QString());
        getNewAddress->setText(QApplication::translate("PaperWalletDialog", "New Address", 0, QApplication::UnicodeUTF8));
        addressText->setText(QString());
        privateKeyText->setText(QString());
        printButton->setText(QApplication::translate("PaperWalletDialog", "Print", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PaperWalletDialog", "Number of wallets", 0, QApplication::UnicodeUTF8));
        walletCount->clear();
        walletCount->insertItems(0, QStringList()
         << QApplication::translate("PaperWalletDialog", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PaperWalletDialog", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PaperWalletDialog", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PaperWalletDialog", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PaperWalletDialog", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PaperWalletDialog", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PaperWalletDialog", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PaperWalletDialog", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PaperWalletDialog", "9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PaperWalletDialog", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PaperWalletDialog", "11", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PaperWalletDialog", "12", 0, QApplication::UnicodeUTF8)
        );
        publicKey->setHtml(QApplication::translate("PaperWalletDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PaperWalletDialog", "Public Key:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PaperWalletDialog: public Ui_PaperWalletDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAPERWALLETDIALOG_H
