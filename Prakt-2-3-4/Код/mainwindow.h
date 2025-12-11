/*
 * Copyright (c) 2019-2020 Waqar Ahmed -- <waqar.17a@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPlainTextEdit>
#include <QProcess>
#include <QThread>
#include <QTime>
#include <qsourcehighliter.h>

using namespace QSourceHighlite;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class ProgramThread : public QThread{
    Q_OBJECT

public:
        explicit ProgramThread(QString filePath, QObject *parent = nullptr);
        ~ProgramThread() override;
        QProcess* getProcess();

signals:
    void stopRequested();
    void output(const QString&);
    void errors(const QString&);
    void status(int, int);
    void timeout();

protected:
    void run() override;

    private:
        QString filePath;
        QProcess* t_program;
};


class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSourceHighlite::QSourceHighliter *highlighter;
    static QHash<QString, QSourceHighlite::QSourceHighliter::Language> _langStringToEnum;
    static QHash<QString, QSourceHighlite::QSourceHighliter::Themes> _themeStringToEnum;

    QSourceHighliter::Themes theme;
    QString termBack;

    QString currentSuffix;

    QToolBar* MainTools;

    QColor bgColor;

    ProgramThread *pyThread = nullptr;

//    QProcess program;


    /* FUNCTIONS */
    void initLangsEnum();
    void initLangsComboBox();
    void initThemesComboBox();

    QHash<QString, QJsonObject> userThemes;
    void loadUserThemes();

signals:
    void changeTermTheme(QSourceHighliter::Themes n_theme, QString n_back);

private slots:
    void themeChanged(int);
    void languageChanged(const QString &);
    void saveTXT_triggered();
    void saveJSON_triggered();
    void loadTXT_triggered();
    void loadJSON_triggered();
    void closeEvent(QCloseEvent*);
    void onFindText(const QString &);
    void onReplaceText(const QString &, const QString &);
    void onReplaceAll(const QString &, const QString &);
    void search_a_triggered();
    void applyEditorBackground(QSourceHighlite::QSourceHighliter::Themes theme);
    void new_theme_triggered();

    void python_program_run();
    void stopProcess();

protected:
    void keyPressEvent(QKeyEvent *e);

};

class SearchDialog : public QDialog
{
    Q_OBJECT

public:
    SearchDialog(QWidget*);
    ~SearchDialog();


private:
    QLineEdit* findLineEdit;
    QLineEdit* replaceLineEdit;
    QPushButton* findButton;
    QPushButton* replaceButton;
    QPushButton* replaceAllButton;
    QVBoxLayout* dlayout;

signals:
    void findNext(const QString &);
    void replaceText(const QString &, const QString &);
    void replaceAll(const QString &, const QString &);

private slots:
    void on_findButton_clicked();
    void on_replaceButton_clicked();
    void on_replaceAllButton_clicked();
};


class ThemeDialog : public QDialog
{
    Q_OBJECT

public:
    ThemeDialog(QWidget*);
    ~ThemeDialog();


private:
    QPushButton* Block;
    QPushButton* KeyWord;
    QPushButton* String;
    QPushButton* Comment;
    QPushButton* Type;
    QPushButton* NumLit;
    QPushButton* Other;
    QPushButton* BuiltIn;

    QLabel* HintBlock;
    QLabel* HintKeyWord;
    QLabel* HintString;
    QLabel* HintComment;
    QLabel* HintType;
    QLabel* HintNumLit;
    QLabel* HintOther;
    QLabel* HintBuiltIn;

    QPushButton* save;
    QPushButton* cancel;

    QColor blockColor;
    QColor keywordColor;
    QColor stringColor;
    QColor commentColor;
    QColor typeColor;
    QColor numlitColor;
    QColor otherColor;
    QColor builtinColor;


signals:

private slots:
    void color_clicked(QPushButton*);
    void Save();
};


class Terminal : public QWidget {
    Q_OBJECT
    public:
        Terminal(QSourceHighliter::Themes t_theme, QString t_back);
        ~Terminal();
        void addOutput(QString text);
    private:
        QSourceHighlite::QSourceHighliter *highlighter;
        QPlainTextEdit* output;
    public slots:
        void themeChanged(QSourceHighliter::Themes n_theme, QString n_back);
};


#endif // MAINWINDOW_H
