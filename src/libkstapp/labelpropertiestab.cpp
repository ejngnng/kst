/***************************************************************************
 *                                                                         *
 *   copyright : (C) 2008 The University of Toronto                        *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "labelpropertiestab.h"

#include "application.h"
#include "objectstore.h"
#include "mainwindow.h"
#include "document.h"

namespace Kst {

LabelPropertiesTab::LabelPropertiesTab(QWidget *parent)
  : DialogTab(parent) {

  setupUi(this);
  setTabTitle(tr("Label Properties"));

  _labelText->setObjectStore(kstApp->mainWindow()->document()->objectStore());

  connect(_labelText, SIGNAL(labelChanged(const QString &)), this, SIGNAL(modified()));
  connect(_labelFontScale, SIGNAL(valueChanged(double)), this, SIGNAL(modified()));
  connect(_labelColor, SIGNAL(changed(const QColor &)), this, SIGNAL(modified()));
}


LabelPropertiesTab::~LabelPropertiesTab() {
}


QString LabelPropertiesTab::labelText() const { 
  return _labelText->labelText(); 
}


void LabelPropertiesTab::setLabelText(const QString &text) {
  _labelText->setLabelText(text);
}


qreal LabelPropertiesTab::labelScale() const { 
  return _labelFontScale->value(); 
}


void LabelPropertiesTab::setLabelScale(const qreal scale) { 
  _labelFontScale->setValue(scale);
}


QColor LabelPropertiesTab::labelColor() const { 
  return _labelColor->color();
}


void LabelPropertiesTab::setLabelColor(const QColor &color) {
  _labelColor->setColor(color);
}

}
// vim: ts=2 sw=2 et
