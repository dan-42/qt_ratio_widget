# Qt fix aspect ration widget
Sometimes you want your widget to be resizable but maintain a fixed aspect ratio.
For example: video-streams, images or charts

This is a small proof-of-concept, showing how this is done.

![example](./doc/images/example.png?raw=true)
 * Blue-Widget: the whole main-window
 * Green-Widget: The ``` class qt_ratio_widget; ```
 * Orange-Widget: Some user arbitrary user content

# DOCUMENTATION
## Usage
for just using it, you can use the ``` class qt_ratio_widget; ``` as a common widget.
 * By hand, see ``` main.cpp ```
 * By Designer, add a widget and ``` promote ``` it to ``` qt_ratio_widget ```

## Insight
As a ``` QLayout ```  handles how QWidgets ar positioned, the size-management is actually done by a QWidget.
Therefore the ``` qt_ratio_widget ``` is a QWidget.
The implementation is easy, once figured out where to put it. :-)

# FEATURES
 * Drop-In replacement of a current QWidget
 * extended with ``` void qt_ratio_widget::ratio(double r) ``` which can be: 
   * ``` r = 1.0 ``` for a square
   * ``` r = 16.0/9.0 ``` for a 16:9 ratio
 
# LICENSE
SPDX-License-Identifier:  MIT

Licensed under the MIT License <http://opensource.org/licenses/MIT>.
