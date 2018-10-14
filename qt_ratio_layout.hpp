/**
SPDX-License-Identifier:  MIT
Licensed under the MIT License <http://opensource.org/licenses/MIT>.

Permission is hereby  granted, free of charge, to any  person obtaining a copy
of this software and associated  documentation files (the "Software"), to deal
in the Software  without restriction, including without  limitation the rights
to  use, copy,  modify, merge,  publish, distribute,  sublicense, and/or  sell
copies  of  the Software,  and  to  permit persons  to  whom  the Software  is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE  IS PROVIDED "AS  IS", WITHOUT WARRANTY  OF ANY KIND,  EXPRESS OR
IMPLIED,  INCLUDING BUT  NOT  LIMITED TO  THE  WARRANTIES OF  MERCHANTABILITY,
FITNESS FOR  A PARTICULAR PURPOSE AND  NONINFRINGEMENT. IN NO EVENT  SHALL THE
AUTHORS  OR COPYRIGHT  HOLDERS  BE  LIABLE FOR  ANY  CLAIM,  DAMAGES OR  OTHER
LIABILITY, WHETHER IN AN ACTION OF  CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE  OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Copyright 2018 github.com/dan-42
*/

#pragma once
#ifndef QT_RATIO_LAYOUT_HPP
#define QT_RATIO_LAYOUT_HPP

#include <QLayout>

class QWidget;

class qt_ratio_layout : public QLayout
{
public:
  qt_ratio_layout();
  ~qt_ratio_layout() override;

  void inner(QLayout* i);
  void ratio(double r);
// Overwrites QLayout
public:
  void addItem(QLayoutItem *item) override;
  QLayoutItem* itemAt(int index) const override;
  QLayoutItem* takeAt(int index) override;
  int count() const override;

// Overwrites QLayoutItem
public:
  QSize sizeHint() const override;
  int heightForWidth(int w) const override;
  bool hasHeightForWidth() const override;
  int minimumHeightForWidth(int) const override;
  void setGeometry(const QRect&) override;

private:
  double ratio_{1.0};
  QLayout* inner_layout_{nullptr};
};

#endif // QT_RATIO_LAYOUT_HPP