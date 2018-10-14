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

#include "widget_main.hpp"
#include "widget_user_content.hpp"
#include "qt_ratio_widget.hpp"
#include <QApplication>

#include <QHBoxLayout>
int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  auto w = new widget_main{};

  auto uc = new widget_user_content{};

  auto fixed_ratio = new qt_ratio_widget{w};
  fixed_ratio->setLayout(new QHBoxLayout);
  fixed_ratio->ratio(16.0/9.0);
  fixed_ratio->layout()->addWidget(uc);

  w->layout()->addWidget(fixed_ratio);
  w->show();
  return a.exec();
}
