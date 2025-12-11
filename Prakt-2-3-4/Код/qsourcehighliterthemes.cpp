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

#include "qsourcehighliterthemes.h"

namespace QSourceHighlite {

static QHash<QSourceHighliter::Token, QTextCharFormat> formats()
{
    QHash<QSourceHighliter::Token, QTextCharFormat> _formats;

    QTextCharFormat defaultFormat = QTextCharFormat();

    _formats[QSourceHighliter::Token::CodeBlock] = defaultFormat;
    _formats[QSourceHighliter::Token::CodeKeyWord] = defaultFormat;
    _formats[QSourceHighliter::Token::CodeString] = defaultFormat;
    _formats[QSourceHighliter::Token::CodeComment] = defaultFormat;
    _formats[QSourceHighliter::Token::CodeType] = defaultFormat;
    _formats[QSourceHighliter::Token::CodeOther] = defaultFormat;
    _formats[QSourceHighliter::Token::CodeNumLiteral] = defaultFormat;
    _formats[QSourceHighliter::Token::CodeBuiltIn] = defaultFormat;

    return _formats;
}

static QHash<QSourceHighliter::Token, QTextCharFormat> monokai()
{
    QHash<QSourceHighliter::Token, QTextCharFormat> _formats = formats();

    _formats[QSourceHighliter::Token::CodeBlock].setForeground(QColor(155, 155, 0));
    _formats[QSourceHighliter::Token::CodeBlock].setBackground(QColor(255, 255, 255));
    _formats[QSourceHighliter::Token::CodeKeyWord].setForeground(QColor(185, 55, 85));
    _formats[QSourceHighliter::Token::CodeString].setForeground(QColor(0, 155, 155));
    _formats[QSourceHighliter::Token::CodeComment].setForeground(QColor(0, 200, 0));
    _formats[QSourceHighliter::Token::CodeType].setForeground(QColor(0, 0, 0));
    _formats[QSourceHighliter::Token::CodeOther].setForeground(QColor(185, 185, 0));
    _formats[QSourceHighliter::Token::CodeNumLiteral].setForeground(QColor(165, 45, 255));
    _formats[QSourceHighliter::Token::CodeBuiltIn].setForeground(QColor(255, 55, 185));

    return _formats;
}


static QHash<QSourceHighliter::Token, QTextCharFormat> dark()
{
    QHash<QSourceHighliter::Token, QTextCharFormat> _formats = formats();

    _formats[QSourceHighliter::Token::CodeBlock].setForeground(QColor(255, 255, 255));
    _formats[QSourceHighliter::Token::CodeBlock].setBackground(QColor(20, 20, 20));
    _formats[QSourceHighliter::Token::CodeKeyWord].setForeground(QColor(45, 155, 55));
    _formats[QSourceHighliter::Token::CodeString].setForeground(QColor(255, 155, 100));
    _formats[QSourceHighliter::Token::CodeComment].setForeground(QColor(0, 0, 255));
    _formats[QSourceHighliter::Token::CodeType].setForeground(QColor(255, 255, 255));
    _formats[QSourceHighliter::Token::CodeOther].setForeground(QColor(180, 135, 175));
    _formats[QSourceHighliter::Token::CodeNumLiteral].setForeground(QColor(20, 175, 200));
    _formats[QSourceHighliter::Token::CodeBuiltIn].setForeground(QColor(255, 20, 185));

    return _formats;
}

static QHash<QSourceHighliter::Token, QTextCharFormat> light()
{
    QHash<QSourceHighliter::Token, QTextCharFormat> _formats = formats();

    _formats[QSourceHighliter::Token::CodeBlock].setForeground(QColor(0, 155, 0));
    _formats[QSourceHighliter::Token::CodeBlock].setBackground(QColor(255, 255, 255));
    _formats[QSourceHighliter::Token::CodeKeyWord].setForeground(QColor(185, 55, 85));
    _formats[QSourceHighliter::Token::CodeString].setForeground(QColor(0, 155, 0));
    _formats[QSourceHighliter::Token::CodeComment].setForeground(QColor(0, 155, 0));
    _formats[QSourceHighliter::Token::CodeType].setForeground(QColor(0, 0, 0));
    _formats[QSourceHighliter::Token::CodeOther].setForeground(QColor(185, 100, 0));
    _formats[QSourceHighliter::Token::CodeNumLiteral].setForeground(QColor(0, 0, 255));
    _formats[QSourceHighliter::Token::CodeBuiltIn].setForeground(QColor(185, 55, 185));

    return _formats;
}


QHash<QSourceHighliter::Token, QTextCharFormat>
        QSourceHighliterTheme::theme(QSourceHighliter::Themes theme) {
    switch (theme) {
    case QSourceHighliter::Themes::Monokai:
        return monokai();
    case QSourceHighliter::Themes::DarkTheme:
        return dark();
    case QSourceHighliter::Themes::LightTheme:
        return light();
    default:
        return monokai();
    }
}

}
