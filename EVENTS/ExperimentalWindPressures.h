#ifndef EXPERIMENTAL_WIND_PRESSURES_H
#define EXPERIMENTAL_WIND_PRESSURES_H

/* *****************************************************************************
Copyright (c) 2016-2017, The Regents of the University of California (Regents).
All rights reserved.

Redistribution and use in source and binary forms, with or without 
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those
of the authors and should not be interpreted as representing official policies,
either expressed or implied, of the FreeBSD Project.

REGENTS SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
THE SOFTWARE AND ACCOMPANYING DOCUMENTATION, IF ANY, PROVIDED HEREUNDER IS 
PROVIDED "AS IS". REGENTS HAS NO OBLIGATION TO PROVIDE MAINTENANCE, SUPPORT, 
UPDATES, ENHANCEMENTS, OR MODIFICATIONS.

*************************************************************************** */

// Written: fmckenna, Sang-ri

#include <SimCenterAppWidget.h>
#include <WindForceSpectrum.h>
#include <stdio.h>
#include <set>
#include <TapsInputDelegate.h>

class SC_DoubleLineEdit;
class SC_IntLineEdit;
class SC_StringLineEdit;
class InputWidgetParameters;
class RandomVariablesContainer;
class QComboBox;
class QGridLayout;
class QVBoxLayout;
class QSpinBox;
class QLineEdit;
class LineEditRV;
class QGroupBox;
class QPushButton;

class ExperimentalWindPressures : public SimCenterAppWidget
{
    Q_OBJECT
public:
    explicit ExperimentalWindPressures(RandomVariablesContainer *theRandomVariableIW, QWidget *parent = 0);
    ~ExperimentalWindPressures();

    bool outputToJSON(QJsonObject &rvObject);
    bool inputFromJSON(QJsonObject &rvObject);
    bool outputAppDataToJSON(QJsonObject &rvObject);
    bool inputAppDataFromJSON(QJsonObject &rvObject);
    bool copyFiles(QString &dirName);
    bool outputCitation(QJsonObject &jsonObject);
signals:

public slots:
   void clear(void);
   void selectTaps(void);
//   void chooseFileName(void);

private:
   //std::set<int> getSelectedComponentIDs() const;
   //QString getComponentAnalysisList();
    TapsInputDelegate *selectedTaps;
//   SC_DoubleLineEdit *modePercent;
//   SC_DoubleLineEdit *modelScale;
//   SC_DoubleLineEdit *fullScaleSpeed;
//   SC_DoubleLineEdit *fullScaleDuration;
   SC_DoubleLineEdit *windowSize;
   SC_DoubleLineEdit *overlapPerc;
   SC_IntLineEdit *cpsdGroupSize;
//   SC_DoubleLineEdit *filename;
   SC_IntLineEdit *seed;
   WindForceSpectrum *theExpWidget;
   QLabel *citationQuoteLabel;
   RandomVariablesContainer *theRandomVariablesContainer;
   QStringList varNamesAndValues;
   QString prevText;
   std::set<int> selectedComponentIDs;
};

#endif // WIND_TUNNEL_EXPERIMENT_H