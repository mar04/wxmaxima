﻿// -*- mode: c++; c-file-style: "linux"; c-basic-offset: 2; indent-tabs-mode: nil -*-
//
//  Copyright (C) 2004-2015 Andrej Vodopivec <andrej.vodopivec@gmail.com>
//            (C) 2014-2018 Gunter Königsmann <wxMaxima@physikbuch.de>
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 2 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
//  SPDX-License-Identifier: GPL-2.0+

/*! \file
  This file declares the class SumCell

  SumCell is the MathCell type that represents maxima's <code>sum()</code>, 
  <code>lsum</code> and <code>product()</code> 
  commands.
*/

#ifndef SUMCELL_H
#define SUMCELL_H

#include "MathCell.h"

enum
{
  SM_SUM,
  SM_PROD
};

class SumCell : public MathCell
{
public:
  SumCell(MathCell *parent, Configuration **config, CellPointers *cellPointers);

  ~SumCell();
  
  std::list<MathCell *> GetInnerCells();

  MathCell *Copy();
  
  void RecalculateHeight(int fontsize);

  void RecalculateWidths(int fontsize);

  virtual void Draw(wxPoint point);

  void SetBase(MathCell *base);

  void SetUnder(MathCell *under);

  void SetOver(MathCell *name);

  void SetSumStyle(int style)
  {
    m_sumStyle = style;
  }

  wxString ToString();

  wxString ToTeX();

  wxString ToMathML();

  wxString ToXML();

  wxString ToOMML();

  void SetGroup(MathCell *parent);

protected:
  MathCell *m_base;
  MathCell *m_under;
  MathCell *m_over;
  int m_signSize;
  int m_signWidth;
  int m_sumStyle;
  int m_signWCenter;
  int m_signTop;
};

#endif // SUMCELL_H
