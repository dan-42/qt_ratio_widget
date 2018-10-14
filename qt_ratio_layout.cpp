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

#include "qt_ratio_layout.hpp"

#include <QWidget>
#include <iostream>

qt_ratio_layout::qt_ratio_layout()
  : QLayout{}
{
}

qt_ratio_layout::~qt_ratio_layout()
{
}

void qt_ratio_layout::inner(QLayout* i)
{
  inner_layout_ = i;
}

void qt_ratio_layout::ratio(double r)
{
  ratio_ = r;
}

void qt_ratio_layout::addItem(QLayoutItem *item)
{
  if(inner_layout_ != nullptr)
  {
    inner_layout_->addItem(item);
  }
}


QLayoutItem* qt_ratio_layout::itemAt(int index) const
{
  if(inner_layout_ != nullptr)
  {
    return inner_layout_->itemAt(index);
  }
  return nullptr;
}


QLayoutItem* qt_ratio_layout::takeAt(int index)
{
  if(inner_layout_ != nullptr)
  {
    return inner_layout_->takeAt(index);
  }
  return nullptr;
}

int qt_ratio_layout::count() const
{
  if(inner_layout_ != nullptr)
  {
    return inner_layout_->count();
  }
  return 0;
}

QSize qt_ratio_layout::sizeHint() const
{
  if(inner_layout_ != nullptr)
  {
    return inner_layout_->sizeHint();
  }
  return QSize{};
}

int qt_ratio_layout::heightForWidth(int w) const
{
  const auto h = static_cast<decltype(w)>(ratio_ * static_cast<decltype(ratio_)>(w));
  std::cout << "qt_ratio_layout::heightForWidth() w: " << w << " h: " << h << " r: " << (double)w/(double)h <<  std::endl;
  return h;
}

bool qt_ratio_layout::hasHeightForWidth() const
{
  return true;
}

int qt_ratio_layout::minimumHeightForWidth(int w) const
{
  std::cout << "qt_ratio_layout::minimumHeightForWidth() w: " << w << std::endl;
  return heightForWidth(w);
}

void qt_ratio_layout::setGeometry(const QRect& r)
{
  auto rect = r;
  rect.setHeight(heightForWidth(r.width()));
  std::cout << "qt_ratio_layout::setGeometry() rect "
            << rect.x() << ", "
            << rect.y() << ", "
            << rect.width() << ", "
            << rect.height()
            << " r: " << ((double)rect.width())/((double)rect.height()) << std::endl;
  if(inner_layout_ != nullptr)
  {
    inner_layout_->setGeometry(rect);
  }
  QLayout::setGeometry(rect);
}