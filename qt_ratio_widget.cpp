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

#include "qt_ratio_widget.hpp"

#include <QStyleOption>
#include <QPainter>
#include <QResizeEvent>
#include <QLayout>

#include <iostream>
qt_ratio_widget::qt_ratio_widget(QWidget *parent) : QWidget(parent)
{
  setStyleSheet("background-color: rgb(0, 255,0)");
}


void qt_ratio_widget::ratio(double r)
{
  ratio_ = 1.0/r;
}

int qt_ratio_widget::heightForWidth(int w) const
{
  return static_cast<decltype(w)>( ratio_ * static_cast<decltype(ratio_)>(w));
}

bool qt_ratio_widget::hasHeightForWidth() const
{
  return true;
}

void qt_ratio_widget::paintEvent(QPaintEvent* event)
{
 QStyleOption opt;
 opt.init(this);
 QPainter p(this);
 style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

 QWidget::paintEvent(event);
}

void qt_ratio_widget::resizeEvent(QResizeEvent *event)
{
  QWidget::resizeEvent(event);

  auto s = event->size();
  s.setHeight(heightForWidth(s.width()));
  setMinimumHeight(s.height());

  if(layout())
  {
    auto r = layout()->geometry();
    r.setSize(s);
    layout()->setGeometry(r);
  }

  auto r = geometry();
  r.setSize(s);
  setGeometry(r);
}