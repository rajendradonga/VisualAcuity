/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/***************************************************************************
 *            lettermode.h
 *
 *  Tue Mar 13 17:00:00 UTC+1 2018
 *  Copyright 2018 Lars Bisballe
 *  larsbjensen@gmail.com
 ****************************************************************************/

/*
 *  This file is part of VisuTest.
 *
 *  VisuTest is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  VisuTest is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with VisuTest; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
 */
#ifndef __VISUTEST_LETTERMODE_H__
#define __VISUTEST_LETTERMODE_H__

#include "letterrow.h"
#include "lettersize.h"
#include "mainsettings.h"

#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsSimpleTextItem>

class LetterMode : public QGraphicsScene
{
  Q_OBJECT
    
public:
  LetterMode(MainSettings *mainSettings, QString chartFile, QObject *parent);
  ~LetterMode();

public slots:
  void updateAll();

protected:
  void keyPressEvent(QKeyEvent *event);

private:
  LetterSize *size;
  Settings *settings;
  int perRow = 5;
  int skew = 0;

  void refreshAllRows();
  void shuffleAllRows();
  void addRow();
  void removeRow();
  void setLogMARSize(double value);
  void increaseSize();
  void decreaseSize();
  void loadRowStrings(QString filename);  
  QList<QString> rowStrings;
  QList<LetterRow *> letterRows;
  QGraphicsSimpleTextItem *titleItem;
  QGraphicsSimpleTextItem *sizeItem;
  
};
#endif/*__VISUTEST_LETTERMODE_H__*/
