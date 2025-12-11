/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *save_TXT;
    QAction *save_JSON;
    QAction *action_3;
    QAction *action_4;
    QAction *action_5;
    QAction *action_6;
    QAction *action_7;
    QAction *action_8;
    QAction *search_a;
    QAction *load_TXT;
    QAction *load_JSON;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *langComboBox;
    QLabel *label_2;
    QComboBox *themeComboBox;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_4;
    QMenu *menu_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        save_TXT = new QAction(MainWindow);
        save_TXT->setObjectName(QString::fromUtf8("save_TXT"));
        save_JSON = new QAction(MainWindow);
        save_JSON->setObjectName(QString::fromUtf8("save_JSON"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        action_5 = new QAction(MainWindow);
        action_5->setObjectName(QString::fromUtf8("action_5"));
        action_6 = new QAction(MainWindow);
        action_6->setObjectName(QString::fromUtf8("action_6"));
        action_7 = new QAction(MainWindow);
        action_7->setObjectName(QString::fromUtf8("action_7"));
        action_8 = new QAction(MainWindow);
        action_8->setObjectName(QString::fromUtf8("action_8"));
        search_a = new QAction(MainWindow);
        search_a->setObjectName(QString::fromUtf8("search_a"));
        load_TXT = new QAction(MainWindow);
        load_TXT->setObjectName(QString::fromUtf8("load_TXT"));
        load_JSON = new QAction(MainWindow);
        load_JSON->setObjectName(QString::fromUtf8("load_JSON"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(0, 0));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        langComboBox = new QComboBox(groupBox);
        langComboBox->setObjectName(QString::fromUtf8("langComboBox"));

        formLayout->setWidget(1, QFormLayout::LabelRole, langComboBox);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        themeComboBox = new QComboBox(groupBox);
        themeComboBox->setObjectName(QString::fromUtf8("themeComboBox"));

        formLayout->setWidget(3, QFormLayout::LabelRole, themeComboBox);


        horizontalLayout->addWidget(groupBox);

        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        horizontalLayout->addWidget(plainTextEdit);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menu);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_4 = new QMenu(menu);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(menu_2->menuAction());
        menu->addAction(menu_4->menuAction());
        menu_2->addAction(save_TXT);
        menu_2->addAction(save_JSON);
        menu_4->addAction(load_TXT);
        menu_4->addAction(load_JSON);
        menu_3->addAction(action_3);
        menu_3->addAction(action_4);
        menu_3->addAction(action_5);
        menu_3->addAction(action_6);
        menu_3->addAction(action_7);
        menu_3->addAction(action_8);
        menu_3->addAction(search_a);

        retranslateUi(MainWindow);
        QObject::connect(action_3, SIGNAL(triggered()), plainTextEdit, SLOT(copy()));
        QObject::connect(action_4, SIGNAL(triggered()), plainTextEdit, SLOT(paste()));
        QObject::connect(action_5, SIGNAL(triggered()), plainTextEdit, SLOT(cut()));

        langComboBox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        save_TXT->setText(QApplication::translate("MainWindow", ".TXT", nullptr));
#ifndef QT_NO_SHORTCUT
        save_TXT->setShortcut(QApplication::translate("MainWindow", "Ctrl+T", nullptr));
#endif // QT_NO_SHORTCUT
        save_JSON->setText(QApplication::translate("MainWindow", ".JSON", nullptr));
#ifndef QT_NO_SHORTCUT
        save_JSON->setShortcut(QApplication::translate("MainWindow", "Ctrl+J", nullptr));
#endif // QT_NO_SHORTCUT
        action_3->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
#ifndef QT_NO_SHORTCUT
        action_3->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        action_4->setText(QApplication::translate("MainWindow", "\320\222\321\201\321\202\320\260\320\262\320\270\321\202\321\214", nullptr));
#ifndef QT_NO_SHORTCUT
        action_4->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_NO_SHORTCUT
        action_5->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\200\320\265\320\267\320\260\321\202\321\214", nullptr));
#ifndef QT_NO_SHORTCUT
        action_5->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_NO_SHORTCUT
        action_6->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
#ifndef QT_NO_SHORTCUT
        action_6->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", nullptr));
#endif // QT_NO_SHORTCUT
        action_7->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
#ifndef QT_NO_SHORTCUT
        action_7->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_NO_SHORTCUT
        action_8->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\321\202\320\276\321\200\320\270\321\202\321\214", nullptr));
#ifndef QT_NO_SHORTCUT
        action_8->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_NO_SHORTCUT
        search_a->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
#ifndef QT_NO_SHORTCUT
        search_a->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_NO_SHORTCUT
        load_TXT->setText(QApplication::translate("MainWindow", ".TXT", nullptr));
#ifndef QT_NO_SHORTCUT
        load_TXT->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_NO_SHORTCUT
        load_JSON->setText(QApplication::translate("MainWindow", ".JSON", nullptr));
#ifndef QT_NO_SHORTCUT
        load_JSON->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("MainWindow", "Language:", nullptr));
        langComboBox->setCurrentText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Theme", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272...", nullptr));
        menu_4->setTitle(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\272\320\260\320\272...", nullptr));
        menu_3->setTitle(QApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
