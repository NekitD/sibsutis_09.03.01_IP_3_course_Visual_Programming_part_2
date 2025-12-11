/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_about
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QDialog *about)
    {
        if (about->objectName().isEmpty())
            about->setObjectName(QString::fromUtf8("about"));
        about->resize(508, 381);
        textBrowser = new QTextBrowser(about);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 491, 361));

        retranslateUi(about);

        QMetaObject::connectSlotsByName(about);
    } // setupUi

    void retranslateUi(QDialog *about)
    {
        about->setWindowTitle(QApplication::translate("about", "Dialog", nullptr));
        textBrowser->setHtml(QApplication::translate("about", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">\320\220\320\262\321\202\320\276\321\200\321\201\321\202\320\262\320\276: \320\224\320\276\321\200\320\276\320\263\320\270\320\275 \320\235\320\270\320\272\320\270\321\202\320\260 \320\230\320\237-312</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" f"
                        "ont-size:9pt;\">\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\265\321\200\320\262\320\276\320\265 \321\207\320\270\321\201\320\273\320\276, \320\262\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\276\320\277\320\265\321\200\320\260\321\206\320\270\321\216, \320\262\320\262\320\265\320\264\320\270\321\202\320\265 \320\262\321\202\320\276\321\200\320\276\320\265 \321\207\320\270\321\201\320\273\320\276 \320\270 \320\275\320\260\320\266\320\274\320\270\321\202\320\265 \321\201\320\270\320\275\320\270\321\216 \320\272\320\275\320\276\320\277\320\272\321\203 \321\201\320\276 \320\267\320\275\320\260\320\272\320\276\320\274 \321\200\320\260\320\262\320\265\320\275\321\201\321\202\320\262\320\260 \320\270 \320\277\320\276\320\273\321\203\321\207\320\270\321\202\320\265 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0"
                        "; text-indent:0px; font-size:9pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">\320\222\320\262\320\265\321\201\321\202\320\270 \321\207\320\270\321\201\320\273\320\260 \320\274\320\276\320\266\320\275\320\276 \320\272\320\260\320\272 \321\201 \320\272\320\273\320\260\320\262\320\270\320\260\321\202\321\203\321\200\321\213 \321\202\320\260\320\272 \320\270 \320\275\320\260\320\266\320\270\320\274\320\260\321\217 \320\275\320\260 \321\201\320\276\320\276\321\202\320\262\320\265\321\202\320\262\321\203\321\216\321\211\320\270\320\265 \320\272\320\275\320\276\320\277\320\272\320\270 \320\272\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200\320\260.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p>\n"
"<p style=\" margin-top:0"
                        "px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">\320\232\320\260\320\266\320\264\320\276\320\265 \320\262\321\213\321\207\320\270\321\201\320\273\320\265\320\275\320\275\320\276\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\277\320\276\320\274\320\265\321\211\320\260\320\265\321\202\321\201\321\217 \320\262 \320\270\321\201\321\202\320\276\321\200\320\270\321\216, \320\272\320\276\321\202\320\276\321\200\321\203\321\216 \320\274\320\276\320\266\320\275\320\276 \320\277\320\276 \320\266\320\265\320\273\320\260\320\275\320\270\321\216 \320\276\321\202\320\272\321\200\321\213\321\202\321\214, \320\267\320\260\320\272\321\200\321\213\321\202\321\214 \320\270\320\273\320\270 \320\276\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \321\201 \320\277\320\276\320\274\320\276\321\211\321\214\321\216 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\320\271 \320\275\320\260 \321\201\320\276\320"
                        "\276\321\202\320\262\320\265\321\202\321\201\321\202\320\262\321\203\321\216\321\211\320\265\320\271 \320\277\320\260\320\275\320\265\320\273\320\270, \320\260 \321\202\320\260\320\272\320\266\320\265 \321\201\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\270\320\267 \320\270\321\201\321\202\320\276\321\200\320\270\320\270.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">\320\223\320\276\321\200\321\217\321\207\320\270\320\272 \320\272\320\273\320\260\320\262\320\270\321\210\320\270 (Ctrl + ):</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span "
                        "style=\" font-size:9pt;\">O - \320\277\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\270\321\201\321\202\320\276\321\200\320\270\321\216.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">H - \321\201\320\272\321\200\321\213\321\202\321\214 \320\270\321\201\321\202\320\276\321\200\320\270\321\216.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">C - \320\276\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\270\321\201\321\202\320\276\321\200\320\270\321\216.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">S - \321\201\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\202\320\265\320\272\321\203\321\211\320\265\320\265"
                        " \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\277\320\260\320\275\320\265\320\273\320\270 \320\262\321\213\320\262\320\276\320\264\320\260 \320\262 \320\270\321\201\321\202\320\276\321\200\320\270\321\216.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">A - \320\276\321\202\320\272\321\200\321\213\321\202\321\214 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216 \320\276 \320\272\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200\320\265.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class about: public Ui_about {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
