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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qsourcehighliter.h"
#include "qsourcehighliterthemes.h"

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QJsonObject>
#include <QJsonDocument>
#include <QTextDocument>
#include <QTextObject>
#include <QMessageBox>
#include <QPushButton>
#include <QToolBar>
#include <QLabel>
#include <QColorDialog>
#include <QTemporaryFile>
#include <QElapsedTimer>
#include <QTime>

using namespace QSourceHighlite;

QHash<QString, QSourceHighliter::Language> MainWindow::_langStringToEnum;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initLangsEnum();
    initLangsComboBox();
    initThemesComboBox();

    //set highlighter
    QFont f = QFontDatabase::systemFont(QFontDatabase::FixedFont);
    ui->plainTextEdit->setFont(f);
    highlighter = new QSourceHighliter(ui->plainTextEdit->document());

    MainTools = new QToolBar;
    QPushButton* openJsonTool = new QPushButton("Открыть JSON");
    QPushButton* openTxtTool = new QPushButton("Открыть TXT");
    QPushButton* saveJsonTool = new QPushButton("Сохранить JSON");
    QPushButton* saveTxtTool = new QPushButton("Сохранить TXT");
    QPushButton* searchTool = new QPushButton("Поиск");
    QPushButton* runTool = new QPushButton("Run");
    QPushButton* stopTool = new QPushButton("Stop");

    QHBoxLayout* toolLayout = new QHBoxLayout;

    MainTools->addWidget(openJsonTool);
    MainTools->addWidget(saveJsonTool);
    MainTools->addWidget(openTxtTool);
    MainTools->addWidget(saveTxtTool);
    MainTools->addWidget(searchTool);
    MainTools->addWidget(runTool);
    MainTools->addWidget(stopTool);


    toolLayout->addWidget(openJsonTool);
    toolLayout->addWidget(saveJsonTool);
    toolLayout->addWidget(openTxtTool);
    toolLayout->addWidget(saveTxtTool);
    toolLayout->addWidget(searchTool);
    toolLayout->addWidget(runTool);
    toolLayout->addWidget(stopTool);


    MainTools->resize(1000, 500);
    MainTools->setLayout(toolLayout);

    addToolBar(MainTools);

    MainTools->show();


    connect(ui->langComboBox,
            static_cast<void (QComboBox::*) (const QString&)>(&QComboBox::currentTextChanged),
            this, &MainWindow::languageChanged);
    connect(ui->themeComboBox,
            static_cast<void (QComboBox::*) (int)>(&QComboBox::currentIndexChanged),
            this, &MainWindow::themeChanged);

//    connect(ui->themeComboBox,
//            static_cast<void (QComboBox::*) (const QString&)>(&QComboBox::currentTextChanged),
//            this, &MainWindow::themeChanged);

    connect(ui->save_JSON, &QAction::triggered, this, &MainWindow::saveJSON_triggered);
    connect(ui->save_TXT, &QAction::triggered, this, &MainWindow::saveTXT_triggered);
    connect(ui->load_JSON, &QAction::triggered, this, &MainWindow::loadJSON_triggered);
    connect(ui->load_TXT, &QAction::triggered, this, &MainWindow::loadTXT_triggered);
    connect(ui->search_a, &QAction::triggered, this, &MainWindow::search_a_triggered);
    connect(ui->new_theme, &QAction::triggered, this, &MainWindow::new_theme_triggered);


    connect(saveJsonTool, &QPushButton::clicked, this, &MainWindow::saveJSON_triggered);
    connect(saveTxtTool, &QPushButton::clicked, this, &MainWindow::saveTXT_triggered);
    connect(openJsonTool, &QPushButton::clicked, this, &MainWindow::loadJSON_triggered);
    connect(openTxtTool, &QPushButton::clicked, this, &MainWindow::loadTXT_triggered);
    connect(searchTool, &QPushButton::clicked, this, &MainWindow::search_a_triggered);
    connect(runTool, &QPushButton::clicked, this, &MainWindow::python_program_run);
    connect(stopTool, &QPushButton::clicked, this, &MainWindow::stopProcess);

    ui->langComboBox->setCurrentText("Asm");
    languageChanged("Asm");
    //    connect(ui->plainTextEdit, &QPlainTextEdit::textChanged, this, &MainWindow::printDebug);


    const QIcon* saveIcon = new QIcon("C:\\Users\\Danik\\Desktop\\STUDY_SIBSUTIS_DOROGIN\\Visual.p2\\Prakt2-3\\Icons\\save.png");
    ui->menu_2->setIcon(*saveIcon);
    const QIcon* fileIcon = new QIcon("C:\\Users\\Danik\\Desktop\\STUDY_SIBSUTIS_DOROGIN\\Visual.p2\\Prakt2-3\\Icons\\create.png");
    ui->menu->setIcon(*fileIcon);
    const QIcon* openIcon = new QIcon("C:\\Users\\Danik\\Desktop\\STUDY_SIBSUTIS_DOROGIN\\Visual.p2\\Prakt2-3\\Icons\\open.png");
    ui->menu_4->setIcon(*openIcon);
    const QIcon* copyIcon = new QIcon("C:\\Users\\Danik\\Desktop\\STUDY_SIBSUTIS_DOROGIN\\Visual.p2\\Prakt2-3\\Icons\\copy.png");
    ui->action_3->setIcon(*copyIcon);
    const QIcon* pasteIcon = new QIcon("C:\\Users\\Danik\\Desktop\\STUDY_SIBSUTIS_DOROGIN\\Visual.p2\\Prakt2-3\\Icons\\paste.png");
    ui->action_4->setIcon(*pasteIcon);
    const QIcon* cutIcon = new QIcon("C:\\Users\\Danik\\Desktop\\STUDY_SIBSUTIS_DOROGIN\\Visual.p2\\Prakt2-3\\Icons\\cut.png");
    ui->action_5->setIcon(*cutIcon);
    const QIcon* searchIcon = new QIcon("C:\\Users\\Danik\\Desktop\\STUDY_SIBSUTIS_DOROGIN\\Visual.p2\\Prakt2-3\\Icons\\search.png");
    ui->search_a->setIcon(*searchIcon);
    const QIcon* repeatIcon = new QIcon("C:\\Users\\Danik\\Desktop\\STUDY_SIBSUTIS_DOROGIN\\Visual.p2\\Prakt2-3\\Icons\\repeat.png");
    ui->action_8->setIcon(*repeatIcon);
    const QIcon* clearIcon = new QIcon("C:\\Users\\Danik\\Desktop\\STUDY_SIBSUTIS_DOROGIN\\Visual.p2\\Prakt2-3\\Icons\\clear.png");
    ui->action_6->setIcon(*clearIcon);
    const QIcon* cancelIcon = new QIcon("C:\\Users\\Danik\\Desktop\\STUDY_SIBSUTIS_DOROGIN\\Visual.p2\\Prakt2-3\\Icons\\cancel.png");
    ui->action_7->setIcon(*cancelIcon);
}

MainWindow::~MainWindow()
{
    delete ui;
}

SearchDialog::SearchDialog(QWidget* parent): QDialog (parent){
    resize(400, 400);
    setWindowTitle("Поиск");
    findButton = new QPushButton("Найти");
    replaceButton = new QPushButton("Заменить");
    replaceAllButton = new QPushButton("Заменить всё");
    findLineEdit = new QLineEdit;
    replaceLineEdit = new QLineEdit;
    dlayout = new QVBoxLayout;
    dlayout->addWidget(findLineEdit);
    dlayout->addWidget(findButton);
    dlayout->addWidget(replaceLineEdit);
    dlayout->addWidget(replaceButton);
    dlayout->addWidget(replaceAllButton);
    setLayout(dlayout);

    connect(findButton, &QPushButton::clicked, this, &SearchDialog::on_findButton_clicked);
    connect(replaceButton, &QPushButton::clicked, this, &SearchDialog::on_replaceButton_clicked);
    connect(replaceAllButton, &QPushButton::clicked, this, &SearchDialog::on_replaceAllButton_clicked);
}

SearchDialog::~SearchDialog(){

}


ThemeDialog::ThemeDialog(QWidget* parent): QDialog (parent){
    resize(200, 300);
    setWindowTitle("Создание темы");

    Block = new QPushButton;
    KeyWord = new QPushButton;
    String = new QPushButton;
    Comment = new QPushButton;
    Type = new QPushButton;
    NumLit = new QPushButton;
    Other = new QPushButton;
    BuiltIn = new QPushButton;

    HintBlock = new QLabel("<h2>Фон</h2>");
    HintBlock->setAlignment(Qt::Alignment(4));
    HintKeyWord = new QLabel("<h2>int Ключевые слова</h2>");
    HintKeyWord->setAlignment(Qt::Alignment(4));
    HintString = new QLabel("<h2>''Строки''</h2>");
    HintString->setAlignment(Qt::Alignment(4));
    HintComment = new QLabel("<h2>//Комментарии</h2>");
    HintComment->setAlignment(Qt::Alignment(4));
    HintType = new QLabel("<h2>Обычный текст</h2>");
    HintType->setAlignment(Qt::Alignment(4));
    HintNumLit = new QLabel("<h2>0 Литералы</h2>");
    HintNumLit->setAlignment(Qt::Alignment(4));
    HintOther = new QLabel("<h2>Прочее</h2>");
    HintOther->setAlignment(Qt::Alignment(4));
    HintBuiltIn = new QLabel("<h2>#Встроенное</h2>");
    HintBuiltIn->setAlignment(Qt::Alignment(4));


    QWidget* centralWidget = new QWidget;
    QWidget* buttonsWidget = new QWidget;
    QVBoxLayout* buttonsLayout = new QVBoxLayout;
    QHBoxLayout* layout = new QHBoxLayout;

    QWidget* saveWidget = new QWidget;
    QHBoxLayout* saveLayout = new QHBoxLayout;

    QVBoxLayout* mainLayout = new QVBoxLayout;

    buttonsLayout->addWidget(Block);
    buttonsLayout->addWidget(KeyWord);
    buttonsLayout->addWidget(String);
    buttonsLayout->addWidget(Comment);
    buttonsLayout->addWidget(Type);
    buttonsLayout->addWidget(NumLit);
    buttonsLayout->addWidget(Other);
    buttonsLayout->addWidget(BuiltIn);

    buttonsWidget->setLayout(buttonsLayout);

    QWidget* labelsWidget = new QWidget;
    QVBoxLayout* labelsLayout = new QVBoxLayout;

    labelsLayout->addWidget(HintBlock);
    labelsLayout->addWidget(HintKeyWord);
    labelsLayout->addWidget(HintString);
    labelsLayout->addWidget(HintComment);
    labelsLayout->addWidget(HintType);
    labelsLayout->addWidget(HintNumLit);
    labelsLayout->addWidget(HintOther);
    labelsLayout->addWidget(HintBuiltIn);

    buttonsWidget->setLayout(buttonsLayout);
    labelsWidget->setLayout(labelsLayout);

    layout->addWidget(labelsWidget);
    layout->addWidget(buttonsWidget);

    centralWidget->setLayout(layout);

    save = new QPushButton("Сохранить");
    cancel = new QPushButton("Закрыть");

    saveLayout->addWidget(save);
    saveLayout->addWidget(cancel);

    saveWidget->setLayout(saveLayout);

    mainLayout->addWidget(centralWidget);
    mainLayout->addWidget(saveWidget);

    setLayout(mainLayout);

    blockColor = "white";
    keywordColor = "red";
    stringColor = "orange";
    commentColor = "grey";
    typeColor = "black";
    numlitColor = "blue";
    otherColor = "green";
    builtinColor = "purple";


    QString blockSheet = QString("QPushButton {background-color: %1;}").arg(blockColor.name());
    Block->setStyleSheet(blockSheet);
    QString keywordSheet = QString("QPushButton {background-color: %1;}").arg(keywordColor.name());
    KeyWord->setStyleSheet(keywordSheet);
    QString stringSheet = QString("QPushButton {background-color: %1;}").arg(stringColor.name());
    String->setStyleSheet(stringSheet);
    QString typeSheet = QString("QPushButton {background-color: %1;}").arg(typeColor.name());
    Type->setStyleSheet(typeSheet);
    QString numlitSheet = QString("QPushButton {background-color: %1;}").arg(numlitColor.name());
    NumLit->setStyleSheet(numlitSheet);
    QString commentSheet = QString("QPushButton {background-color: %1;}").arg(commentColor.name());
    Comment->setStyleSheet(commentSheet);
    QString otherSheet = QString("QPushButton {background-color: %1;}").arg(otherColor.name());
    Other->setStyleSheet(otherSheet);
    QString builtinSheet = QString("QPushButton {background-color: %1;}").arg(builtinColor.name());
    BuiltIn->setStyleSheet(builtinSheet);

    connect(save, &QPushButton::clicked, this, &ThemeDialog::Save);
    connect(cancel, &QPushButton::clicked, this, &ThemeDialog::close);
    connect(Block, &QPushButton::clicked, this, [this]() { color_clicked(Block); });
    connect(KeyWord, &QPushButton::clicked, this, [this]() { color_clicked(KeyWord); });
    connect(String, &QPushButton::clicked, this, [this]() { color_clicked(String); });
    connect(Comment, &QPushButton::clicked, this, [this]() { color_clicked(Comment); });
    connect(NumLit, &QPushButton::clicked, this, [this]() { color_clicked(NumLit); });
    connect(Type, &QPushButton::clicked, this, [this]() { color_clicked(Type); });
    connect(Other, &QPushButton::clicked, this, [this]() { color_clicked(Other); });
    connect(BuiltIn, &QPushButton::clicked, this, [this]() { color_clicked(BuiltIn); });

}

ThemeDialog::~ThemeDialog(){

}


void MainWindow::initLangsEnum()
{
    MainWindow::_langStringToEnum = QHash<QString, QSourceHighliter::Language> {
        { QLatin1String("Asm"), QSourceHighliter::CodeAsm },
        { QLatin1String("Bash"), QSourceHighliter::CodeBash },
        { QLatin1String("C"), QSourceHighliter::CodeC },
        { QLatin1String("C++"), QSourceHighliter::CodeCpp },
        { QLatin1String("CMake"), QSourceHighliter::CodeCMake },
        { QLatin1String("CSharp"), QSourceHighliter::CodeCSharp },
        { QLatin1String("Css"), QSourceHighliter::CodeCSS },
        { QLatin1String("Go"), QSourceHighliter::CodeGo },
        { QLatin1String("Html"), QSourceHighliter::CodeXML },
        { QLatin1String("Ini"), QSourceHighliter::CodeINI },
        { QLatin1String("Java"), QSourceHighliter::CodeJava },
        { QLatin1String("Javascript"), QSourceHighliter::CodeJava },
        { QLatin1String("Json"), QSourceHighliter::CodeJSON },
        { QLatin1String("Lua"), QSourceHighliter::CodeLua },
        { QLatin1String("Make"), QSourceHighliter::CodeMake },
        { QLatin1String("Php"), QSourceHighliter::CodePHP },
        { QLatin1String("Python"), QSourceHighliter::CodePython },
        { QLatin1String("Qml"), QSourceHighliter::CodeQML },
        { QLatin1String("Rhai"), QSourceHighliter::CodeRhai },
        { QLatin1String("Rust"), QSourceHighliter::CodeRust },
        { QLatin1String("Sql"), QSourceHighliter::CodeSQL },
        { QLatin1String("Typescript"), QSourceHighliter::CodeTypeScript },
        { QLatin1String("V"), QSourceHighliter::CodeV },
        { QLatin1String("Vex"), QSourceHighliter::CodeVex },
        { QLatin1String("Xml"), QSourceHighliter::CodeXML },
        { QLatin1String("Yaml"), QSourceHighliter::CodeYAML }
    };
}

void MainWindow::initThemesComboBox()
{
    ui->themeComboBox->addItem("Monokai", QSourceHighliter::Themes::Monokai);
    ui->themeComboBox->addItem("Light", QSourceHighliter::Themes::LightTheme);
    ui->themeComboBox->addItem("Dark", QSourceHighliter::Themes::DarkTheme);
    ui->themeComboBox->addItem("debug", QSourceHighliter::Themes::Monokai);  
    loadUserThemes();
}

void MainWindow::initLangsComboBox() {
    ui->langComboBox->addItem("Asm");
    ui->langComboBox->addItem("Bash");
    ui->langComboBox->addItem("C");
    ui->langComboBox->addItem("C++");
    ui->langComboBox->addItem("CMake");
    ui->langComboBox->addItem("CSharp");
    ui->langComboBox->addItem("Css");
    ui->langComboBox->addItem("Go");
    ui->langComboBox->addItem("Html");
    ui->langComboBox->addItem("Ini");
    ui->langComboBox->addItem("Javascript");
    ui->langComboBox->addItem("Java");
    ui->langComboBox->addItem("Lua");
    ui->langComboBox->addItem("Make");
    ui->langComboBox->addItem("Php");
    ui->langComboBox->addItem("Python");
    ui->langComboBox->addItem("Qml");
    ui->langComboBox->addItem("Rust");
    ui->langComboBox->addItem("Sql");
    ui->langComboBox->addItem("Typescript");
    ui->langComboBox->addItem("V");
    ui->langComboBox->addItem("Vex");
    ui->langComboBox->addItem("Xml");
    ui->langComboBox->addItem("Yaml");
}

void MainWindow::themeChanged(int) {
    theme = (QSourceHighliter::Themes)ui->themeComboBox->currentData().toInt();
    highlighter->setTheme(theme);
    applyEditorBackground(theme);
    emit changeTermTheme(theme, termBack);
}

void MainWindow::languageChanged(const QString &lang) {
    highlighter->setCurrentLanguage(_langStringToEnum.value(lang));
    highlighter->rehighlight();

//    QFile f(QDir::currentPath() + "/../test_files/" + lang + ".txt");
//    if (f.open(QIODevice::ReadOnly | QIODevice::Text)) {
//        const auto text = f.readAll();
//        ui->plainTextEdit->setPlainText(QString::fromUtf8(text));
//    }
//    f.close();
}


void MainWindow::saveTXT_triggered(){
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить TXT","C:\\Users\\Danik\\Desktop\\STUDY_SIBSUTIS_DOROGIN\\Visual.p2\\Prakt2-3\\Files", "TXT файлы (*.txt)");
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        ui->statusbar->showMessage("Ошибка! Не удалось открыть файл для записи.", 3000);
        return;
    }
    QTextStream out(&file);
    out << ui->plainTextEdit->toPlainText();
    file.close();
    ui->statusbar->showMessage("Сохранён файл " + fileName, 3000);
    ui->plainTextEdit->document()->setModified(false);
}


void MainWindow::saveJSON_triggered(){
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить JSON","C:\\Users\\Danik\\Desktop\\STUDY_SIBSUTIS_DOROGIN\\Visual.p2\\Prakt2-3\\Files", "JSON файлы (*.json)");
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        ui->statusbar->showMessage("Ошибка! Не удалось открыть файл для записи.", 3000);
        return;
    }
    QJsonObject root;
    root["language"] = ui->langComboBox->currentText();
    root["text"] = ui->plainTextEdit->toPlainText();
    root["theme"] = ui->themeComboBox->currentText() ;
    ui->plainTextEdit->modificationChanged(false);
    QJsonDocument doc(root);
    file.write(doc.toJson());
    file.close();
    ui->statusbar->showMessage("Сохранён файл " + fileName, 3000);
    ui->plainTextEdit->document()->setModified(false);
}

void MainWindow::loadTXT_triggered(){
    QString fileName = QFileDialog::getOpenFileName(this, "Открыть TXT","C:\\Users\\Danik\\Desktop\\STUDY_SIBSUTIS_DOROGIN\\Visual.p2\\Prakt2-3\\Files", "TXT файлы (*.txt)");
    QFile file(fileName);

    QFileInfo info(file);
    currentSuffix = info.completeSuffix();

    if(!file.open(QIODevice::ReadWrite | QIODevice::Text)){
        ui->statusbar->showMessage("Ошибка открытия файла", 3000);
        return;
    }

    QString text = file.readAll();
    file.close();


    ui->plainTextEdit->setPlainText(text);
    ui->statusbar->showMessage("Открыт файл " + info.fileName(), 3000);

}


void MainWindow::loadJSON_triggered(){
    QString fileName = QFileDialog::getOpenFileName(this, "Открыть JSON","C:\\Users\\Danik\\Desktop\\STUDY_SIBSUTIS_DOROGIN\\Visual.p2\\Prakt2-3\\Files", "JSON файлы (*.json)");
    QFile file(fileName);


    QFileInfo info(file);
    currentSuffix = info.completeSuffix();

    QJsonParseError error;

    if(!file.open(QIODevice::ReadWrite | QIODevice::Text)){
        ui->statusbar->showMessage("Ошибка открытия файла", 3000);
        return;
    }

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll(), &error);
    file.close();

    if(error.error != QJsonParseError::NoError){
        ui->statusbar->showMessage("Ошибка парсинга JSON", 3000);
        return;
    }

    QJsonObject obj = doc.object();
    QJsonValue jlang = obj["language"];
    QJsonValue jtext = obj["text"];
    QJsonValue jtheme = obj["theme"];
    QString lang = jlang.toString();
    QString text = jtext.toString();
    QString theme = jtheme.toString();

    ui->plainTextEdit->setPlainText(text);
    ui->plainTextEdit->setPlainText(text);
    ui->statusbar->showMessage("Открыт файл " + info.fileName(), 3000);



    if(!lang.isEmpty()){
        ui->langComboBox->setCurrentText(lang);
    }

    if(!theme.isEmpty()){
        ui->themeComboBox->setCurrentText(theme);
    }
}

void MainWindow::closeEvent(QCloseEvent *event){
    if(ui->plainTextEdit->document()->isModified()){
        QMessageBox offer_to_save(this);

        offer_to_save.setWindowTitle("Изменения");
        offer_to_save.setText("Остались несохранённые изменения. Сохранить?");

        QPushButton *yes = new QPushButton("Сохранить");
        QPushButton *no = new QPushButton("Не сохранять");
        QPushButton *cancel = new QPushButton("Отмена");

        offer_to_save.addButton(yes, QMessageBox::AcceptRole);
        offer_to_save.addButton(no, QMessageBox::DestructiveRole);
        offer_to_save.addButton(cancel, QMessageBox::RejectRole);

        offer_to_save.setDefaultButton(yes);

        offer_to_save.exec();

        QAbstractButton* clicked = offer_to_save.clickedButton();

        if (clicked == yes) {
            if(currentSuffix == "json") saveJSON_triggered();
            else saveTXT_triggered();
            event->accept();
        } else if (clicked == no) {
            event->accept();
        } else if (clicked == cancel) {
            event->ignore();
        }

    }
}



void SearchDialog::on_findButton_clicked(){
    emit findNext(findLineEdit->text());
}
void SearchDialog::on_replaceButton_clicked(){
    emit replaceText(findLineEdit->text(), replaceLineEdit->text());
}
void SearchDialog::on_replaceAllButton_clicked(){
    emit replaceAll(findLineEdit->text(), replaceLineEdit->text());
}

void MainWindow::onFindText(const QString &text){
    QTextCursor cursor = ui->plainTextEdit->textCursor();
    QString content = ui->plainTextEdit->toPlainText();

    int pos = content.indexOf(text, cursor.position(), Qt::CaseSensitive);

    if(pos >= 0){
        cursor.setPosition(pos);
        cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, text.length());
        ui->plainTextEdit->setTextCursor(cursor);
        ui->statusbar->showMessage("Найдено: "+text);
    } else {
        pos = content.indexOf(text, 0, Qt::CaseSensitive);
        if (pos >= 0){
            cursor.setPosition(pos);
            cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, text.length());
            ui->plainTextEdit->setTextCursor(cursor);
            ui->statusbar->showMessage("Поиск с начала. Найдено: "+text);
        } else {
            QMessageBox::information(this, "Поиск", "Совпадений не найдено.");
            ui->statusbar->showMessage(tr("Совпадений не найдено"), 3000);
       }
    }
}

void MainWindow::onReplaceText(const QString &find, const QString &replace){
    QTextDocument *doc = ui->plainTextEdit->document();
    //onFindText(find);
    QTextCursor cursor = ui->plainTextEdit->textCursor();
    QString selected = cursor.selectedText();

    if(!selected.isEmpty() && selected == find){
        cursor.insertText(replace);
        ui->plainTextEdit->setTextCursor(cursor);
        return;
    }

        int pos = cursor.position();
        QTextCursor found = doc->find(find, pos, QTextDocument::FindCaseSensitively);

        if(!found.isNull()){
            int start = found.selectionStart();
            //int end = found.selectionEnd();

            found.insertText(replace);

            QTextCursor newCursor = ui->plainTextEdit->textCursor();

            newCursor.setPosition(start);
            newCursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, replace.length());
            ui->plainTextEdit->setTextCursor(newCursor);
        } else {
            QMessageBox::information(this, "Поиск", "Совпадений не найдено.");
        }
        highlighter->rehighlight();
}


void MainWindow::onReplaceAll(const QString &find, const QString &replace){
    QString content = ui->plainTextEdit->toPlainText();
    QString newContent = content.replace(find, replace, Qt::CaseSensitive);
    ui->plainTextEdit->setPlainText(newContent);
    highlighter->rehighlight();
    QString message = (QString("Все вхождения '%1' заменены на '%2'").arg(find).arg(replace));
    ui->statusbar->showMessage(message, 3000);
}

void MainWindow::search_a_triggered(){
    SearchDialog dialog(this);
    connect(&dialog, &SearchDialog::findNext, this, &MainWindow::onFindText);
    connect(&dialog, &SearchDialog::replaceText, this, &MainWindow::onReplaceText);
    connect(&dialog, &SearchDialog::replaceAll, this, &MainWindow::onReplaceAll);
    dialog.exec();
}


void MainWindow::keyPressEvent(QKeyEvent *e) {
    switch (e->key()) {
        //Numbers
        case Qt::Key_F:
            search_a_triggered();
            break;
        case Qt::Key_T:
            saveTXT_triggered();
            break;
        case Qt::Key_J:
            saveJSON_triggered();
            break;
        case Qt::Key_E:
            loadTXT_triggered();
            break;
        case Qt::Key_S:
            loadJSON_triggered();
            break;
    }
}

void MainWindow::applyEditorBackground(QSourceHighliter::Themes theme){

    auto themeFormats = QSourceHighliterTheme::theme(theme);
    QTextCharFormat block = themeFormats.value(QSourceHighliter::Token::CodeBlock);

    bgColor = block.background().color();

    if(!bgColor.isValid()){
        bgColor = Qt::white;
    }

    QString styleSheet = QString("QPlainTextEdit {background-color: %1;}").arg(bgColor.name());
    termBack = styleSheet;
    ui->plainTextEdit->setStyleSheet(styleSheet);


}

void MainWindow::new_theme_triggered(){
    ThemeDialog* theme_dialog = new ThemeDialog(this);
    theme_dialog->show();
}


void ThemeDialog::color_clicked(QPushButton* button){
    QColor color = QColorDialog::getColor("white");
    if(!color.isValid()){
        color = "white";
        return;
    }
    QString style = QString("QPushButton {background-color: %1;}").arg(color.name());
    button->setStyleSheet(style);
}

void ThemeDialog::Save(){
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить тему","C:\\Users\\Danik\\Desktop\\STUDY_SIBSUTIS_DOROGIN\\Visual.p2\\Prakt2-3\\Themes", "JSON файлы (*.json)");
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        //ui->statusbar->showMessage("Ошибка! Не удалось открыть файл для записи.", 3000);
        return;
    }
    QJsonObject root;
    root["block"] = blockColor.name();
    root["keywords"] = keywordColor.name();
    root["string"] = stringColor.name();
    root["comments"] = commentColor.name();
    root["numlit"] = numlitColor.name();
    root["type"] = typeColor.name();
    root["other"] = otherColor.name();
    root["builtin"] = builtinColor.name();

    QJsonDocument doc(root);
    file.write(doc.toJson());
    file.close();

//    ui->statusbar->showMessage("Сохранён файл " + fileName, 3000);
//    ui->plainTextEdit->document()->setModified(false);
}

void MainWindow::loadUserThemes()
{
    QString themesPath = "C:\\Users\\Danik\\Desktop\\STUDY_SIBSUTIS_DOROGIN\\Visual.p2\\Prakt2-3\\Themes";
    QDir dir(themesPath);

    QFileInfoList files = dir.entryInfoList(QStringList() << "*.json", QDir::Files);

    for (const QFileInfo &fileInfo : files) {
        QFile file(fileInfo.filePath());
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) continue;

        QJsonParseError err;
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll(), &err);
        file.close();

        if (err.error != QJsonParseError::NoError || !doc.isObject()) continue;

        QJsonObject obj = doc.object();
        QString themeName = obj["name"].toString(fileInfo.baseName());

        userThemes.insert(themeName, obj);
        ui->themeComboBox->addItem(themeName, QVariant::fromValue(themeName));
    }
}

void MainWindow::python_program_run(){
    if(ui->langComboBox->currentText() != "Python"){
        ui->statusbar->showMessage("Функционал ограничен", 3000);
        return;
    }

    Terminal *term = new Terminal(theme, termBack);
    term->setWindowTitle("Терминал");
    term->resize(700, 700);
    term->show();

    connect(this, &MainWindow::changeTermTheme, term, &Terminal::themeChanged);

    QString filePath = QDir::tempPath() + "\\temp.py";
    QFile temp(filePath);
    if(!temp.open(QIODevice::WriteOnly | QIODevice::Text)){
        ui->statusbar->showMessage("Ошибка открытия файла", 3000);
        return;
    }
    QTextStream out(&temp);
    out << ui->plainTextEdit->toPlainText();

    temp.close();

    pyThread = new ProgramThread(filePath, this);
    connect(pyThread, &ProgramThread::output, term, &Terminal::addOutput);
    connect(pyThread, &ProgramThread::errors, term, &Terminal::addOutput);
    connect(pyThread, &ProgramThread::status, term, [term](int time, int code){term->addOutput("\n_________________________________________________________________________"); term->addOutput(QString("\nПрограмма завершена за %1 милисекунд с кодом %2").arg(time).arg(code));});
    connect(pyThread, &ProgramThread::timeout, term, [term](){term->addOutput("\n_________________________________________________________________________");term->addOutput("\n TIMEOUT");});
    connect(pyThread, &QThread::finished, this, [this]() { pyThread = nullptr; });
    pyThread->start();
}


Terminal::Terminal(QSourceHighliter::Themes t_theme, QString t_back){
    output = new QPlainTextEdit;
    output->setReadOnly(true);
    highlighter = new QSourceHighliter(output->document());
    highlighter->setTheme(t_theme);
    QString styleSheet = t_back;
    output->setStyleSheet(styleSheet);
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(output);
    setLayout(layout);
}

Terminal::~Terminal(){

}

void Terminal::themeChanged(QSourceHighliter::Themes n_theme, QString n_back) {
    highlighter->setTheme(n_theme);
    output->setStyleSheet(n_back);
}

void Terminal::addOutput(QString text){
    output->appendPlainText(text);
}

void MainWindow::stopProcess() {
    if (!pyThread) return;
    if (pyThread && pyThread->isRunning()) {
        emit pyThread->stopRequested();
    }
}

ProgramThread::ProgramThread(QString filePath, QObject *parent): QThread (parent), filePath(filePath){
    connect(this, &ProgramThread::stopRequested, this, [this]() {
        if (t_program && t_program->state() != QProcess::NotRunning) {
            t_program->kill();
        }
    }, Qt::DirectConnection);
}

ProgramThread::~ProgramThread(){
}

QProcess* ProgramThread::getProcess(){
    return t_program;
}

void ProgramThread::run(){
    t_program = new QProcess;
    t_program->start("python", QStringList() << filePath);
    if(!t_program->waitForStarted(2000)){
        emit errors("Python не найден или не запустился");
        return;
    }

    QTime start = QTime::currentTime();

    if(!t_program->waitForFinished(3000)){
        t_program->kill();
        emit timeout();
        t_program->waitForFinished();
        return;
    }

    int passed = start.msecsTo(QTime::currentTime());

    QString result = t_program->readAllStandardOutput();
    QString error = t_program->readAllStandardError();

    if (!result.isEmpty()){
        emit output(result);
    }
    if (!error.isEmpty()){
        emit errors(error);
    }
    emit status(passed, t_program->exitCode());
    t_program->deleteLater();
    filePath.clear();
//    QFile::remove(filePath);
}


